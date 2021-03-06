using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using Generator.Core.Model;

namespace Generator.Core
{
    public class CppCodeGenerator
    {
        private const string StubToken = "// ${stub}";
        private const string MsgSerializationCodeStubToken = "// ${MsgSerializationCodeStub}";
        private const string CtSerializationCodeStubToken = "// ${CtSerializationCodeStub}";
        private const string IncludesStubToken = "// ${includes}";
        private const string ClassFieldsStubToken = "// ${ClassFieldsStub}";
        private const string ClassFieldsAccessorsStubToken = "// ${ClassFieldsAccessorsStub}";
        private const string ClassNameStubToken = "${ClassName}";
        private const string ToByteArrayStubToken = "// ${ToByteArrayStub}";
        private const string DeserializationConstructorStubToken = "// ${DeserializationConstructorStub}";
        private const string ValidateStubToken = "// ${ValidateStub}";
        private const string EMessageIdStubToken = "${EMessageId}";
        private const string ECustomTypeIdStubToken = "${ECustomTypeId}";
        private const string InsertersCreationCodeStubToken = "// ${InsertersCreationCode}";
        private const string ConstructMsgQueriesAndHandlersStubToken = "// ${ConstructMsgQueriesAndHandlers}";
        private const string ConstructCtQueriesAndHandlersStubToken = "// ${ConstructCtQueriesAndHandlers}";
        private const string RecalculateChecksumStubToken = "// ${RecalculateChecksumStub}";
        private const string StdMessagesDir = "StdMessage";
        private const string CustomTypesDir = "CustomType";
        private const string IncludeDir = "Greis";
        private const int CountOfCommonFieldsInMsgTable = 6;
        private const int CountOfCommonFieldsInCtTable = 4;
        private readonly MetaInfo metaInfo;
        private readonly string cppEnvTemplatesDir;
        private string targetDir;
        private readonly CustomTypeNameFactory stdMessagesNameProvider;
        private readonly CustomTypeNameFactory customTypeNameProvider;
        private readonly string[] simpleTypes = Enum.GetNames(typeof (GreisTypes));

        public CppCodeGenerator(MetaInfo metaInfo)
        {
            this.metaInfo = metaInfo;

            this.cppEnvTemplatesDir = Path.Combine(PathHelper.StartupPath, "Templates/Cpp");

            this.stdMessagesNameProvider = new CustomTypeNameFactory(this.metaInfo.StandardMessages,
                s => CustomTypeNameFactory.ToLowerCamelCase(s.Name));
            this.customTypeNameProvider = new CustomTypeNameFactory(this.metaInfo.CustomTypes, null,
                s => CustomTypeNameFactory.ToLowerCamelCase(s.Name));
        }

        public void Generate(string targetDir)
        {
            Directory.CreateDirectory(targetDir);
            this.targetDir = targetDir;

            this.GenerateMySqlSource();
            this.generateAllCustomTypesHeader();
            this.generateAllStdMessagesHeader();
            this.GenerateMySqlSink();
            this.generateEMessageId();
            this.generateECustomTypeId();
            this.generateStdMessageGeneratedMembers();
            this.generateStdMessageFactory();
            this.GenerateStdMessages();
            this.generateCustomTypes();
        }

        #region MySqlSourceGeneratedMembers.cpp

        private void GenerateMySqlSource()
        {
            var templatePath = Path.Combine(this.cppEnvTemplatesDir, "MySqlSourceGeneratedMembers.template.cpp");
            var templateStr = File.ReadAllText(templatePath, Encoding.Default);

            var codeIntend = GetCodeIntend(templateStr, ConstructCtQueriesAndHandlersStubToken);

            var constructCtQueriesAndHandlers = this.GenerateCtQueriesAndHandlersCode(codeIntend);
            var constructMsgQueriesAndHandlers = this.GenerateMsgQueriesAndHandlersCode(codeIntend);

            var fileContent = templateStr.Replace(ConstructMsgQueriesAndHandlersStubToken, constructMsgQueriesAndHandlers)
                                         .Replace(ConstructCtQueriesAndHandlersStubToken, constructCtQueriesAndHandlers);

            this.WriteGeneratedFile("MySqlSourceGeneratedMembers.cpp", fileContent);
        }

        private string GenerateCtQueriesAndHandlersCode(string codeIntend)
        {
            var tableNames = new SqlTableNameFactory(this.metaInfo);

            var handleCustomTypeLines = new List<string>();
            var ctMapLines = new List<string>();
            foreach (var ct in this.metaInfo.CustomTypes)
            {
                var tableName = tableNames.GetName(ct);

                const string predefinedMsgCols =
                    "`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, ";
                var colNames = ct.Variables.Select(
                    variable => string.Format("`{0}`", MySqlBaselineGenerator.GetColumnName(variable))).ToArray();
                var columns = predefinedMsgCols + string.Join(", ", colNames);

                var selectCommand = string.Format("SELECT {0} FROM `{1}`",
                                                  columns, tableName);

                var serCode = this.GenerateVariablesMySqlSourceSerializationContent(codeIntend, ct);

                var handleCustomTypeFields =
                    string.Format("[&serializer, this] (int size, const QSqlQuery& q, CustomType*& ct)\r\n{0}" +
                                  "{{\r\n{0}" +
                                  "    ct = new {1}(size);\r\n{0}" +
                                  "    auto c = dynamic_cast<{1}*>(ct);\r\n{0}" +
                                  "    {2}\r\n{0}" +
                                  "}}",
                                  codeIntend + "    ", this.GetClassName(ct), serCode);

                var handleCustomTypeLine = string.Format(
                    "auto query{3} = QString(\"{0}\");\r\n{2}" +
                    "auto handler{3} = {1};\r\n{2}",
                    selectCommand, handleCustomTypeFields, codeIntend, this.GetClassName(ct));

                handleCustomTypeLines.Add(handleCustomTypeLine);

                var mapLine = string.Format("_ctQueries.insert(ECustomTypeId::{1}, query{2});\r\n{0}" +
                                            "_ctHandlers.insert(ECustomTypeId::{1}, handler{2});",
                                            codeIntend, this.GetEnumName(ct), this.GetClassName(ct));
                ctMapLines.Add(mapLine);
            }

            var result = string.Join("\r\n" + codeIntend, handleCustomTypeLines) +
                         "\r\n" + codeIntend +
                         string.Join("\r\n" + codeIntend, ctMapLines);
            return result;
        }

        private string GenerateMsgQueriesAndHandlersCode(string codeIntend)
        {
            var tableNames = new SqlTableNameFactory(this.metaInfo);

            var handleMessageLines = new List<string>();
            var msgMapLines = new List<string>();

            foreach (var msg in this.metaInfo.StandardMessages)
            {
                // SELECT command
                var tableName = tableNames.GetName(msg);
                const string predefinedMsgCols =
                    "`id`, `idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, ";
                var colNames = msg.Variables.Select(
                    variable => string.Format("`{0}`", MySqlBaselineGenerator.GetColumnName(variable))).ToArray();
                var columns = predefinedMsgCols + string.Join(", ", colNames);
                var selectCommand = string.Format("SELECT {0} FROM `{1}`", columns, tableName);

                var serCode = this.GenerateVariablesMySqlSourceSerializationContent(codeIntend, msg);

                // Handler
                var handleMessageFields =
                    string.Format("[&serializer, this] (const std::string& id, int bodySize, const QSqlQuery& q)\r\n{0}" +
                                  "{{\r\n{0}" +
                                  "    auto c = new {1}(id, bodySize);\r\n{0}" +
                                  "    {2}\r\n{0}" +
                                  "    return (Message*)c;\r\n{0}" +
                                  "}}",
                                  codeIntend + "    ", this.GetClassName(msg), serCode);
                var handleMessageLine = string.Format(
                    "auto query{3} = QString(\"{0}\");\r\n{2}" +
                    "auto handler{3} = {1};\r\n{2}",
                    selectCommand, handleMessageFields, codeIntend, this.GetClassName(msg));
                handleMessageLines.Add(handleMessageLine);

                // Mapping
                var mapLine = string.Format("_msgQueries.insert(EMessageId::{1}, query{2});\r\n{0}" +
                                            "_msgHandlers.insert(EMessageId::{1}, handler{2});",
                                            codeIntend, this.GetEnumName(msg), this.GetClassName(msg));
                msgMapLines.Add(mapLine);
            }

            var result = string.Join("\r\n" + codeIntend, handleMessageLines) +
                         "\r\n" + codeIntend +
                         string.Join("\r\n" + codeIntend, msgMapLines);
            return result;
        }

        private string GenerateVariablesMySqlSourceSerializationContent(string codeIntend, CustomType ct)
        {
            string linesStr;
            if (ct.Size != (int) SizeSpecialValue.Dynamic)
            {
                // optional data block
                Variable firstOptionalDataBlock = null;
                Variable lastOptionalDataBlock = null;
                var fullSize = 0;
                bool insideOptionalDataBlock = false;
                if (ct.Size == (int) SizeSpecialValue.FixedWithOptionalDataBlock)
                {
                    firstOptionalDataBlock = ct.FirstOptionalDataBlockVariable;
                    lastOptionalDataBlock = ct.LastOptionalDataBlockVariable;
                    fullSize = ct.Variables.Sum(v =>
                                                {
                                                    if (v.IsScalar)
                                                    {
                                                        return this.GetItemSizeForVariable(v);
                                                    }
                                                    int itemsCount = v.SizeOfDimensions.
                                                        Aggregate(1, (current, dSize) => current*dSize);
                                                    return itemsCount * this.GetItemSizeForVariable(v);
                                                });
                }
                // end of optional data block

                var lines = new List<string>();
                var indexInQuery = ct is StandardMessage
                                   ? CountOfCommonFieldsInMsgTable
                                   : CountOfCommonFieldsInCtTable;
                foreach (var variable in ct.Variables)
                {
                    // Optional Data Block begins
                    if (variable == firstOptionalDataBlock)
                    {
                        lines.Add(string.Format("if (bodySize == {0})\r\n        {1}" +
                                                "{{\r\n        {1}" +
                                                "    // Optional Data Block", fullSize, codeIntend));
                        insideOptionalDataBlock = true;
                    }

                    string line;
                    if (variable.IsScalar)
                    {
                        if (variable.GreisType == GreisTypes.a1.ToString())
                        {
                            // Types::a1
                            line = string.Format("serializer.DeserializeChar(q.value({1}), c->{0}());",
                                                 this.GetAccessorNameForVariable(variable),
                                                 indexInQuery);
                        }
                        else if (this.simpleTypes.Contains(variable.GreisType))
                        {
                            // other Greis types
                            line = string.Format("serializer.Deserialize(q.value({1}), c->{0}());",
                                                 this.GetAccessorNameForVariable(variable),
                                                 indexInQuery);
                        }
                        else
                        {
                            // custom type
                            var varType = this.GetCustomTypeForVariable(variable);
                            line = string.Format("c->{0}() = this->extractCustomType<{3}>" +
                                                 "(ECustomTypeId::{2}, q.value({1}).toInt());",
                                                 this.GetAccessorNameForVariable(variable),
                                                 indexInQuery,
                                                 this.GetEnumName(varType),
                                                 this.GetClassName(varType));
                        }
                    }
                    else if (variable.IsLinearArray)
                    {
                        if (this.simpleTypes.Contains(variable.GreisType))
                        {
                            // string and other Greis types
                            line = string.Format("serializer.Deserialize(q.value({1}), c->{0}());",
                                                 this.GetAccessorNameForVariable(variable),
                                                 indexInQuery);
                        }
                        else
                        {
                            // custom type deserializeAndGetCustomTypes
                            var varType = this.GetCustomTypeForVariable(variable);
                            line = string.Format("c->{0}() = this->deserializeAndGetCustomTypes<{3}>" +
                                                 "(ECustomTypeId::{2}, q.value({1}));",
                                                 this.GetAccessorNameForVariable(variable),
                                                 indexInQuery,
                                                 this.GetEnumName(varType),
                                                 this.GetClassName(varType));
                        }
                    }
                    else
                    {
                        throw new NotSupportedException("Multi-dim arrays are not supported.");
                    }
                    indexInQuery++;

                    // Optional Data Block intendation
                    if (insideOptionalDataBlock)
                    {
                        line = "    " + line;
                    }

                    lines.Add(line);

                    // Closing optional data block 'if' statement
                    if (variable == lastOptionalDataBlock)
                    {
                        insideOptionalDataBlock = false;
                        lines.Add("}");
                    }
                }
                linesStr = string.Join("\r\n        " + codeIntend, lines);
            }
            else
            {
                linesStr = string.Format("\r\n        {0}/*throw Common::NotImplementedException();*/", codeIntend);
            }
            return linesStr;
        }

        private int GetItemSizeForVariable(Variable variable)
        {
            if (this.simpleTypes.Contains(variable.GreisType))
            {
                // Simple type
                var size = int.Parse(variable.GreisType.Substring(1));
                return size;
            }
            else
            {
                var ct = this.GetCustomTypeForVariable(variable);
                Debug.Assert(ct.Size > 0);
                return ct.Size;
            }
        }

        private CustomType GetCustomTypeForVariable(Variable variable)
        {
          try{
            return this.metaInfo.CustomTypes.Single(c => c.Name == variable.GreisType);
          } catch (System.InvalidOperationException e)
          {
            throw new Exception(String.Format("CustomType error: {0}", variable.GreisType));
          }
        }

        #endregion

        #region MySqlSinkGeneratedMembers.cpp

        private void GenerateMySqlSink()
        {
            var templatePath = Path.Combine(this.cppEnvTemplatesDir, "MySqlSinkGeneratedMembers.template.cpp");
            var templateStr = File.ReadAllText(templatePath, Encoding.Default);

            var codeIntend = GetCodeIntend(templateStr, InsertersCreationCodeStubToken);

            var insertersCreationCode = this.GenerateInsertersCreationCodeContent(codeIntend);

            var msgSerializationContent = this.GenerateMsgMySqlSinkSerializationContent(codeIntend);
            var ctSerializationContent = this.GenerateCtMySqlSinkSerializationContent(codeIntend);

            var fileContent = templateStr.Replace(InsertersCreationCodeStubToken, insertersCreationCode)
                                         .Replace(MsgSerializationCodeStubToken, msgSerializationContent)
                                         .Replace(CtSerializationCodeStubToken, ctSerializationContent);

            this.WriteGeneratedFile("MySqlSinkGeneratedMembers.cpp", fileContent);
        }

        private string GenerateMsgMySqlSinkSerializationContent(string codeIntend)
        {
            var serializationContentList = new List<string>();
            foreach (var msg in this.metaInfo.StandardMessages.OrderBy(m => m.Name))
            {
                var linesStr = this.GenerateVariablesMySqlSinkSerializationContent(codeIntend, msg);

                var msgSerializationContent =
                    string.Format("case EMessageId::{2}:\r\n{0}" +
                                  "    {{\r\n{0}" +
                                  "        auto c = dynamic_cast<{3}*>(msg);\r\n{0}" +
                                  "        {1}\r\n{0}" +
                                  "    }}\r\n{0}" +
                                  "    break;", codeIntend, linesStr,
                                  this.GetEnumName(msg), this.GetClassName(msg));
                serializationContentList.Add(msgSerializationContent);
            }
            var serializationContent = string.Join("\r\n" + codeIntend, serializationContentList);
            return serializationContent;
        }

        private string GenerateCtMySqlSinkSerializationContent(string codeIntend)
        {
            var serializationContentList = new List<string>();
            foreach (var ct in this.metaInfo.CustomTypes.OrderBy(m => m.Name))
            {
                var linesStr = this.GenerateVariablesMySqlSinkSerializationContent(codeIntend, ct);

                var ctSerializationContent =
                    string.Format("case ECustomTypeId::{2}:\r\n{0}" +
                                  "    {{\r\n{0}" +
                                  "        auto c = dynamic_cast<{3}*>(ct);\r\n{0}" +
                                  "        {1}\r\n{0}" +
                                  "    }}\r\n{0}" +
                                  "    break;", codeIntend, linesStr,
                                  this.GetEnumName(ct), this.GetClassName(ct));
                serializationContentList.Add(ctSerializationContent);
            }
            var serializationContent = string.Join("\r\n" + codeIntend, serializationContentList);
            return serializationContent;
        }

        private string GenerateVariablesMySqlSinkSerializationContent(string codeIntend, CustomType msg)
        {
            string linesStr;
            if (msg.Size != (int) SizeSpecialValue.Dynamic)
            {
                // optional data block
                Variable firstOptionalDataBlock = null;
                Variable lastOptionalDataBlock = null;
                int fullSize = 0;
                bool insideOptionalDataBlock = false;
                var nullValueODBLines = new List<string>();
                if (msg.Size == (int)SizeSpecialValue.FixedWithOptionalDataBlock)
                {
                    firstOptionalDataBlock = msg.FirstOptionalDataBlockVariable;
                    lastOptionalDataBlock = msg.LastOptionalDataBlockVariable;
                    fullSize = msg.Variables.Sum(v =>
                    {
                        if (v.IsScalar)
                        {
                            return this.GetItemSizeForVariable(v);
                        }
                        int itemsCount = v.SizeOfDimensions.
                            Aggregate(1, (current, dSize) => current * dSize);
                        return itemsCount * this.GetItemSizeForVariable(v);
                    });
                }
                // end of optional data block
                var lines = new List<string>();
                foreach (var variable in msg.Variables)
                {
                    // Optional Data Block begins
                    if (variable == firstOptionalDataBlock)
                    {
                        lines.Add(string.Format("if (c->BodySize() == {0})\r\n        {1}" +
                                                "{{\r\n        {1}" +
                                                "    // Optional Data Block", fullSize, codeIntend));
                        insideOptionalDataBlock = true;
                    }

                    string line;
                    string nullValueLine;
                    if (variable.IsScalar)
                    {
                        if (variable.GreisType == GreisTypes.a1.ToString())
                        {
                            // Types::a1
                            line = string.Format("out << _serializer.SerializeChar(c->{0}());",
                                                 this.GetAccessorNameForVariable(variable));
                            nullValueLine = "out << QVariant(QVariant::Char);";
                        }
                        else if (this.simpleTypes.Contains(variable.GreisType))
                        {
                            // other Greis types
                            line = string.Format("out << _serializer.Serialize(c->{0}());",
                                                 this.GetAccessorNameForVariable(variable));
                            switch ((GreisTypes) Enum.Parse(typeof(GreisTypes), variable.GreisType))
                            {
                            case GreisTypes.a1:
                                nullValueLine = "out << QVariant(QVariant::Char);";
                                break;
                            case GreisTypes.i1:
                            case GreisTypes.i2:
                            case GreisTypes.i4:
                                nullValueLine = "out << QVariant(QVariant::Int);";
                                break;
                            case GreisTypes.u1:
                            case GreisTypes.u2:
                            case GreisTypes.u4:
                                nullValueLine = "out << QVariant(QVariant::UInt);";
                                break;
                            case GreisTypes.f4:
                            case GreisTypes.f8:
                                nullValueLine = "out << QVariant(QVariant::Double);";
                                break;
                            default:
                                throw new ArgumentOutOfRangeException();
                            }
                        }
                        else
                        {
                            // custom type
                            line = string.Format("out << addCustomType(c->{0}().get());",
                                                 this.GetAccessorNameForVariable(variable));
                            nullValueLine = "out << QVariant(QVariant::Int);";
                        }
                    }
                    else if (variable.IsLinearArray)
                    {
                        if (variable.GreisType == GreisTypes.a1.ToString())
                        {
                            nullValueLine = "out << QVariant(QVariant::String);";
                        } else
                        {
                            nullValueLine = "out << QVariant(QVariant::ByteArray);";
                        }

                        if (this.simpleTypes.Contains(variable.GreisType))
                        {
                            // string and other Greis types
                            line = string.Format("out << _serializer.Serialize(c->{0}());",
                                                 this.GetAccessorNameForVariable(variable));
                        }
                        else
                        {
                            // custom type
                            line = string.Format("out << addCustomTypesAndSerialize(c->{0}());",
                                                 this.GetAccessorNameForVariable(variable));
                        }
                    }
                    else
                    {
                        throw new NotSupportedException("Multi-dim arrays are not supported.");
                    }

                    // Optional Data Block intendation
                    if (insideOptionalDataBlock)
                    {
                        line = "    " + line;
                        nullValueODBLines.Add(nullValueLine);
                    }

                    lines.Add(line);

                    // Closing optional data block 'if' statement
                    if (variable == lastOptionalDataBlock)
                    {
                        insideOptionalDataBlock = false;
                        lines.Add("} else {");
                        lines.AddRange(nullValueODBLines.Select(odbLine => string.Format("    {0}", odbLine)));
                        lines.Add("}");
                    }
                }
                linesStr = string.Join("\r\n        " + codeIntend, lines);
            }
            else
            {
                linesStr = string.Format("\r\n        {0}/*throw Common::NotImplementedException();*/", codeIntend);
            }
            return linesStr;
        }

        private string GenerateInsertersCreationCodeContent(string codeIntend)
        {
            var tableNames = new SqlTableNameFactory(this.metaInfo);

            var inserterVars = new List<string>();
            var addChildOps = new List<string>();
            var insertionsIntoMaps = new List<string>();
            foreach (var ct in this.metaInfo.StandardMessages.OrderBy(m => m.Name).
                Concat(this.metaInfo.CustomTypes.OrderBy(c => c.Name)))
            {
                var tableName = tableNames.GetName(ct);

                string predefinedCols;
                int predefinedColsCount;
                if (ct is StandardMessage)
                {
                    predefinedCols = "`idEpoch`, `epochIndex`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, ";
                    predefinedColsCount = 5;
                }
                else
                {
                    predefinedCols = "`id`, `idEpoch`, `unixTimeEpoch`, `bodySize`, ";
                    predefinedColsCount = 4;
                }
                var colNames = ct.Variables.Select(
                    variable => string.Format("`{0}`", MySqlBaselineGenerator.GetColumnName(variable))).ToArray();
                var columns = predefinedCols + string.Join(", ", colNames);

                var fieldsCount = ct.Variables.Count + predefinedColsCount;
                var valuesSb = new StringBuilder("?");
                for (int i = 1; i < fieldsCount; i++)
                {
                    valuesSb.Append(", ?");
                }

                var insertCommand = string.Format("INSERT INTO `{0}` ({1}) VALUES ({2})", tableName, columns, valuesSb);

                var inserterVar = string.Format("auto {0} = std::make_shared<DataBatchInserter>(\r\n{1}    " +
                                                "\"{2}\", \r\n{1}    " +
                                                "{4}, _connection, \"{3}\", _inserterBatchSize);",
                                                this.GetInserterVarName(ct), codeIntend, insertCommand, tableName,
                                                fieldsCount);
                inserterVars.Add(inserterVar);

                var children = ct.Variables.Where(v => this.metaInfo.CustomTypes.Any(c => c.Name == v.GreisType)).
                    Select(v => this.metaInfo.CustomTypes.Single(c => c.Name == v.GreisType));
                foreach (var child in children)
                {
                    var op = string.Format("{0}->AddChild({1});", this.GetInserterVarName(ct), this.GetInserterVarName(child));
                    addChildOps.Add(op);
                }
                addChildOps.Add(string.Format("{0}->AddChild(_epochInserter);", this.GetInserterVarName(ct)));

                string insertionIntoMaps;
                if (ct is StandardMessage)
                {
                    insertionIntoMaps = string.Format("_msgInserters[EMessageId::{0}] = {1};",
                                                      this.GetEnumName(ct), this.GetInserterVarName(ct));
                }
                else
                {
                    insertionIntoMaps = string.Format("_ctInserters[ECustomTypeId::{0}] = {1};",
                                                      this.GetEnumName(ct), this.GetInserterVarName(ct));
                }
                insertionsIntoMaps.Add(insertionIntoMaps);
            }
            /*// inserting raw data
            var rawDataInserterVar = string.Format(
                "auto {0} = std::make_shared<DataBatchInserter>(\r\n{1}    " +
                "\"{2}\", \r\n{1}    " +
                "{4}, _connection, \"{3}\", _inserterBatchSize);",
                getInserterVarName(ct),
                codeIntend,
                string.Format("INSERT INTO `rawBinaryMessages` (`idEpoch`, `unixTimeEpoch`, `idMessageCode`, `bodySize`, {0}) VALUES ({1})", columns, valuesSb),
                "rawBinaryMessages",
                fieldsCount);
            inserterVars.Add(rawDataInserterVar);*/

            var ctCurrentMaxIds = new List<string>();
            foreach (var ct in this.metaInfo.CustomTypes.OrderBy(c => c.Name))
            {
                var tableName = tableNames.GetName(ct);

                var ctCurrentMaxId = string.Format(
                    "int maxIdFor{0} = _dbHelper->ExecuteSingleValueQuery(\"SELECT MAX(`id`) FROM `{1}`\").toInt();\r\n{2}" +
                    "_ctCurrentMaxId[ECustomTypeId::{0}] = maxIdFor{0};", this.GetEnumName(ct), tableName,
                    codeIntend);
                ctCurrentMaxIds.Add(ctCurrentMaxId);
            }
            string insertersCreationCode = string.Join("\r\n" + codeIntend, inserterVars) + "\r\n\r\n" + codeIntend +
                                           string.Join("\r\n" + codeIntend, addChildOps) + "\r\n\r\n" + codeIntend +
                                           string.Join("\r\n" + codeIntend, insertionsIntoMaps) + "\r\n\r\n" + codeIntend +
                                           string.Join("\r\n" + codeIntend, ctCurrentMaxIds);
            return insertersCreationCode;
        }

        #endregion

        #region ConcreteStdMessage.(h/cpp)

        private class CustomTypeStubsContent
        {
            public string Includes { get; set; }
            public string ClassFields { get; set; }
            public string ClassFieldsAccessors { get; set; }
            public string ToByteArrayCode { get; set; }
            public string DeserializationConstructorCode { get; set; }
        }

        private void GenerateStdMessages()
        {
            var concreteStdMsgHTemplatePath = Path.Combine(this.cppEnvTemplatesDir, "ConcreteStdMessage.template.h");
            var concreteStdMsgCppTemplatePath = Path.Combine(this.cppEnvTemplatesDir, "ConcreteStdMessage.template.cpp");
            var templateStrH = File.ReadAllText(concreteStdMsgHTemplatePath, Encoding.Default);
            var templateStrCpp = File.ReadAllText(concreteStdMsgCppTemplatePath, Encoding.Default);

            var fieldsListIntendation = Regex.Match(templateStrH, @"([ \t]*)" + Regex.Escape(ClassFieldsStubToken)).
                Groups[1].Value;
            var fieldsAccessorsListIntendation = Regex.Match(templateStrH, @"([ \t]*)" +
                Regex.Escape(ClassFieldsAccessorsStubToken)).Groups[1].Value;
            var codeIntendation = Regex.Match(templateStrCpp, @"([ \t]*)" +
                Regex.Escape(DeserializationConstructorStubToken)).Groups[1].Value;

            foreach (var msg in this.metaInfo.StandardMessages)
            {
                var className = this.GetClassName(msg);

                var content = this.generateCustomTypeStubsContent(msg, fieldsAccessorsListIntendation,
                    fieldsListIntendation, codeIntendation);

                // EMessageIdName
                var eMessageIdName = this.GetEnumName(msg);

                // ValidateStubToken
                string validationCode;
                string recalculateChecksumCode;
                if (msg.Validation == ValidationType.Checksum)
                {
                    validationCode =
                        string.Format("\r\n" +
                                      "\r\n{0}auto message = ToByteArray();" +
                                      "\r\n{0}return validateChecksum8Bin(message.data(), message.size());",
                                      codeIntendation);
                    recalculateChecksumCode =
                        string.Format("auto message = ToByteArray();\r\n{1}" +
                                      "{0} = ChecksumComputer::ComputeCs8(message, message.size() - 1);",
                                      this.GetFieldNameForVariable(msg.Variables.Last()), codeIntendation);
                }
                else if (msg.Validation == ValidationType.ChecksumAsHexAscii)
                {
                    validationCode =
                        string.Format("\r\n" +
                                      "\r\n{0}auto message = ToByteArray();" +
                                      "\r\n{0}return validateChecksum8Ascii(message.data(), message.size());",
                                      codeIntendation);
                    recalculateChecksumCode =
                        string.Format("auto message = ToByteArray();\r\n{1}" +
                                      "auto cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);\r\n{1}" +
                                      "auto ba = QString::number(cs, 16).toLatin1();\r\n{1}" +
                                      "{0}[0] = ba[0]; {0}[1] = ba[1];",
                                      this.GetFieldNameForVariable(msg.Variables.Last()), codeIntendation);
                } else
                {
                    validationCode = string.Format("\r\n" +
                                                   "\r\n{0}return true;", codeIntendation);
                    recalculateChecksumCode = "";
                }

                var fileHContent = templateStrH.Replace(IncludesStubToken, content.Includes).
                    Replace(ClassFieldsStubToken, content.ClassFields).
                    Replace(ClassFieldsAccessorsStubToken, content.ClassFieldsAccessors).
                    Replace(EMessageIdStubToken, eMessageIdName).
                    Replace(ClassNameStubToken, className);
                var fileCppContent = templateStrCpp.Replace(ClassNameStubToken, className).
                    Replace(ToByteArrayStubToken, content.ToByteArrayCode).
                    Replace(ValidateStubToken, validationCode).
                    Replace(RecalculateChecksumStubToken, recalculateChecksumCode).
                    Replace(DeserializationConstructorStubToken, content.DeserializationConstructorCode);

                // Write
                this.WriteGeneratedFile(Path.Combine(StdMessagesDir, className + ".h"), fileHContent);
                this.WriteGeneratedFile(Path.Combine(StdMessagesDir, className + ".cpp"), fileCppContent);
            }
        }

        private void generateCustomTypes()
        {
            var concreteCtHTemplatePath = Path.Combine(this.cppEnvTemplatesDir, "ConcreteCustomType.template.h");
            var concreteCtCppTemplatePath = Path.Combine(this.cppEnvTemplatesDir, "ConcreteCustomType.template.cpp");
            var templateStrH = File.ReadAllText(concreteCtHTemplatePath, Encoding.Default);
            var templateStrCpp = File.ReadAllText(concreteCtCppTemplatePath, Encoding.Default);

            var fieldsListIntendation = Regex.Match(templateStrH, @"([ \t]*)" + Regex.Escape(ClassFieldsStubToken)).
                Groups[1].Value;
            var fieldsAccessorsListIntendation = Regex.Match(templateStrH, @"([ \t]*)" +
                Regex.Escape(ClassFieldsAccessorsStubToken)).Groups[1].Value;
            var codeIntendation = Regex.Match(templateStrCpp, @"([ \t]*)" +
                Regex.Escape(DeserializationConstructorStubToken)).Groups[1].Value;

            foreach (var ct in this.metaInfo.CustomTypes)
            {
                var className = this.GetClassName(ct);

                var content = this.generateCustomTypeStubsContent(ct, fieldsAccessorsListIntendation,
                    fieldsListIntendation, codeIntendation);

                // EMessageIdName
                var eCustomTypeIdName = this.GetEnumName(ct);

                // ClassNameStubToken
                var fileHContent = templateStrH.Replace(IncludesStubToken, content.Includes).
                    Replace(ClassFieldsStubToken, content.ClassFields).
                    Replace(ClassFieldsAccessorsStubToken, content.ClassFieldsAccessors).
                    Replace(ECustomTypeIdStubToken, eCustomTypeIdName).
                    Replace(ClassNameStubToken, className);
                var fileCppContent = templateStrCpp.Replace(ClassNameStubToken, className).
                    Replace(ToByteArrayStubToken, content.ToByteArrayCode).
                    Replace(DeserializationConstructorStubToken, content.DeserializationConstructorCode);

                // Write
                this.WriteGeneratedFile(Path.Combine(CustomTypesDir, className + ".h"), fileHContent);
                this.WriteGeneratedFile(Path.Combine(CustomTypesDir, className + ".cpp"), fileCppContent);
            }
        }

        private CustomTypeStubsContent generateCustomTypeStubsContent(CustomType msg,
            string fieldsAccessorsListIntendation, string fieldsListIntendation, string codeIntendation)
        {
            var content = new CustomTypeStubsContent();

            // IncludesStubToken
            var includeLines = msg.Variables.Where(v => !this.simpleTypes.Contains(v.GreisType)).
                Select(v => string.Format("#include \"{2}/{1}/{0}CustomType.h\"", GetLowerCamelCase(v.GreisType), CustomTypesDir, IncludeDir)
                ).ToArray();
            var contentIncludes = string.Join("\r\n", includeLines);
            if (includeLines.Length > 0)
            {
                contentIncludes = "\r\n\r\n" + contentIncludes;
            }
            content.Includes = contentIncludes;

            // ClassFieldsStubToken
            var fields = new List<string>();
            foreach (var variable in msg.Variables)
            {
                var field = string.Format("{0} {1};",
                                          this.GetTypeNameForVariable(variable), this.GetFieldNameForVariable(variable));

                fields.Add(field);
            }
            content.ClassFields = string.Join("\r\n" + fieldsListIntendation, fields.ToArray());

            // ClassFieldsAccessorsStubToken
            var fieldsAccessors = new List<string>();
            foreach (var variable in msg.Variables)
            {
                var getter = string.Format("const {0}& {1}() const {{ return {2}; }}",
                                           this.GetTypeNameForVariable(variable),
                                           this.GetAccessorNameForVariable(variable),
                                           this.GetFieldNameForVariable(variable));
                string setter = string.Format("{0}& {1}() {{ return {2}; }}",
                                              this.GetTypeNameForVariable(variable),
                                              this.GetAccessorNameForVariable(variable),
                                              this.GetFieldNameForVariable(variable));
                string comments = "// " + variable.Comment.
                                              Replace("\n", "\r\n" + fieldsAccessorsListIntendation + "// ");
                string alltogether = string.Format("{0}\r\n{2}{1}\r\n{2}{3}\r\n", comments, getter,
                                                   fieldsAccessorsListIntendation, setter);
                fieldsAccessors.Add(alltogether);
            }
            content.ClassFieldsAccessors = string.Join("\r\n" + fieldsAccessorsListIntendation,
                                                fieldsAccessors.ToArray()).TrimEnd();

            //### ToByteArrayStubToken ###
            {
                // optional data block
                Variable firstOptionalDataBlock = null;
                Variable lastOptionalDataBlock = null;
                int fullSize = 0;
                bool insideOptionalDataBlock = false;
                if (msg.Size == (int) SizeSpecialValue.FixedWithOptionalDataBlock)
                {
                    firstOptionalDataBlock = msg.FirstOptionalDataBlockVariable;
                    lastOptionalDataBlock = msg.LastOptionalDataBlockVariable;
                    fullSize = msg.Variables.Sum(v =>
                                                 {
                                                     if (v.IsScalar)
                                                     {
                                                         return this.GetItemSizeForVariable(v);
                                                     }
                                                     int itemsCount = v.SizeOfDimensions.
                                                         Aggregate(1, (current, dSize) => current*dSize);
                                                     return itemsCount*this.GetItemSizeForVariable(v);
                                                 });
                }
                // end of optional data block
                var serializationLines = new List<string>();
                foreach (var variable in msg.Variables)
                {
                    // Optional Data Block begins
                    if (variable == firstOptionalDataBlock)
                    {
                        serializationLines.Add(string.Format("if (BodySize() == {0})\r\n{1}" +
                                                             "{{\r\n{1}" +
                                                             "    // Optional Data Block", fullSize, codeIntendation));
                        insideOptionalDataBlock = true;
                    }

                    var line = string.Format("_serializer.Serialize({0}, result);", this.GetFieldNameForVariable(variable));

                    // Optional Data Block intendation
                    if (insideOptionalDataBlock)
                    {
                        line = "    " + line;
                    }

                    serializationLines.Add(line);

                    // Closing optional data block 'if' statement
                    if (variable == lastOptionalDataBlock)
                    {
                        insideOptionalDataBlock = false;
                        serializationLines.Add("}");
                    }
                }
                content.ToByteArrayCode = string.Join("\r\n" + codeIntendation, serializationLines.ToArray());
            }

            // DeserializationConstructorStubToken
            if (msg.Size != (int)SizeSpecialValue.Dynamic)
            {
                // optional data block
                Variable firstOptionalDataBlock = null;
                Variable lastOptionalDataBlock = null;
                int fullSize = 0;
                bool insideOptionalDataBlock = false;
                if (msg.Size == (int)SizeSpecialValue.FixedWithOptionalDataBlock)
                {
                    firstOptionalDataBlock = msg.FirstOptionalDataBlockVariable;
                    lastOptionalDataBlock = msg.LastOptionalDataBlockVariable;
                    fullSize = msg.Variables.Sum(v =>
                    {
                        if (v.IsScalar)
                        {
                            return this.GetItemSizeForVariable(v);
                        }
                        int itemsCount = v.SizeOfDimensions.
                            Aggregate(1, (current, dSize) => current * dSize);
                        return itemsCount * this.GetItemSizeForVariable(v);
                    });
                }
                // end of optional data block

                var arraySizeInUniformFillFields = this.getArraySizeInUniformFillFieldsLine(msg, codeIntendation);
                var deserializationLines = new List<string>();
                foreach (var variable in msg.Variables)
                {
                    // Optional Data Block begins
                    if (variable == firstOptionalDataBlock)
                    {
                        deserializationLines.Add(string.Format("if (BodySize() == {0})\r\n{1}" +
                                                             "{{\r\n{1}" +
                                                             "    // Optional Data Block", fullSize, codeIntendation));
                        insideOptionalDataBlock = true;
                    }

                    string line = this.generateDeserializationLine(codeIntendation, variable);

                    // Optional Data Block intendation
                    if (insideOptionalDataBlock)
                    {
                        line = "    " + line.Replace("\r\n", "\r\n    ");
                    }

                    deserializationLines.Add(line);

                    // Closing optional data block 'if' statement
                    if (variable == lastOptionalDataBlock)
                    {
                        insideOptionalDataBlock = false;
                        deserializationLines.Add("}");
                    }
                }
                content.DeserializationConstructorCode = arraySizeInUniformFillFields +
                    string.Join("\r\n" + codeIntendation, deserializationLines.ToArray());
            }
            else
            {
                content.DeserializationConstructorCode = "/*throw Common::NotImplementedException();*/";
            }

            return content;
        }

        private string getArraySizeInUniformFillFieldsLine(CustomType msg, string codeIntendation)
        {
            int sizeOfFieldsWithKnownSize = 0;
            var sizeOfGreisTypes = new Dictionary<string, int>();
            sizeOfGreisTypes["a1"] = 1;
            sizeOfGreisTypes["u1"] = 1;
            sizeOfGreisTypes["u2"] = 2;
            sizeOfGreisTypes["u4"] = 4;
            sizeOfGreisTypes["i1"] = 1;
            sizeOfGreisTypes["i2"] = 2;
            sizeOfGreisTypes["i4"] = 4;
            sizeOfGreisTypes["f4"] = 4;
            sizeOfGreisTypes["f8"] = 8;
            var greisTypesNames = Enum.GetNames(typeof (GreisTypes));
            int summarySizeOfFillFields = 0;
            foreach (var variable in msg.Variables)
            {
                // typeSize
                int typeSize;
                if (greisTypesNames.Contains(variable.GreisType))
                {
                    typeSize = sizeOfGreisTypes[variable.GreisType];
                }
                else
                {
                    var customType = this.metaInfo.CustomTypes.Single(ct => ct.Name == variable.GreisType);
                    Debug.Assert(customType.Size > 0, "Custom types with fixed size are only supported.");
                    typeSize = customType.Size;
                }
                // check if field is dynamic
                bool fillField = false;
                for (int i = 1; i <= variable.DimensionsCount; ++i)
                {
                    if (variable.GetSizeForDimension(i) == (int) SizeSpecialValue.Fill)
                    {
                        fillField = true;
                    }
                }
                if (fillField)
                {
                    summarySizeOfFillFields += typeSize;
                }
                else
                {
                    // altering sizeOfFieldsWithKnownSize
                    if (variable.IsScalar)
                    {
                        sizeOfFieldsWithKnownSize += typeSize;
                    }
                    else
                    {
                        int fieldItemsCount = 1;
                        for (int i = 1; i <= variable.DimensionsCount; ++i)
                        {
                            fieldItemsCount *= variable.GetSizeForDimension(i);
                        }
                        sizeOfFieldsWithKnownSize += typeSize*fieldItemsCount;
                    }
                }
            }

            if (summarySizeOfFillFields == 0)
            {
                return "";
            }

            var sizeVal = msg is StandardMessage
                              ? "BodySize()"
                              : "Size()";
            var arraySizeInUniformFillFields =
                string.Format("int arraySizeInUniformFillFields = ({3} - {0}) / {1};\r\n\r\n{2}",
                    sizeOfFieldsWithKnownSize, summarySizeOfFillFields, codeIntendation, sizeVal);
            return arraySizeInUniformFillFields;
        }

        private string generateDeserializationLine(string codeIntendation, Variable variable)
        {
            string line;
            const string arraySizeInUniformFillFields = "arraySizeInUniformFillFields";

            if (Enum.GetNames(typeof (GreisTypes)).Contains(variable.GreisType))
            {
                // ### one of Greis types ###
                if (variable.IsScalar)
                {
                    // scalar greis type deserialization
                    line = string.Format("_serializer.Deserialize(p_message, {0});\r\n{1}" +
                                         "p_message += sizeof({0});", this.GetFieldNameForVariable(variable),
                                         codeIntendation);
                }
                else if (variable.IsLinearArray && variable.GreisType == GreisTypes.a1.ToString())
                {
                    // character array (string) deserialization
                    string arraySize;
                    switch (variable.GetSizeForDimension(1))
                    {
                    case (int) SizeSpecialValue.Dynamic:
                        throw new FormatException("`Dynamic` is impossible value for fields.");
                    case (int) SizeSpecialValue.Fill:
                        arraySize = arraySizeInUniformFillFields;
                        break;
                    default:
                        arraySize = variable.GetSizeForDimension(1).ToString(CultureInfo.InvariantCulture);
                        break;
                    }
                    line = string.Format("_serializer.Deserialize(p_message, {2}, {0});\r\n{1}" +
                                         "p_message += {2};", this.GetFieldNameForVariable(variable),
                                         codeIntendation, arraySize);
                }
                else
                {
                    Debug.Assert(variable.IsLinearArray, "Linear arrays of Greis types are only supported for now.");
                    // array of any dimensions
                    string countOfItemsInFieldStr;
                    switch (variable.GetSizeForDimension(1))
                    {
                    case (int) SizeSpecialValue.Dynamic:
                        throw new FormatException("`Dynamic` is impossible value for fields.");
                    case (int) SizeSpecialValue.Fill:
                        Debug.Assert(variable.IsLinearArray, "Only linear arrays for `Fill` size is supported.");
                        countOfItemsInFieldStr = arraySizeInUniformFillFields;
                        break;
                    default:
                        int countOfItemsInField = 1;
                        for (int i = 1; i <= variable.DimensionsCount; i++)
                        {
                            countOfItemsInField *= variable.GetSizeForDimension(i);
                        }
                        countOfItemsInFieldStr = countOfItemsInField.ToString(CultureInfo.InvariantCulture);
                        break;
                    }
                    line = string.Format(
                        "_serializer.Deserialize(p_message, sizeof({3}::value_type) * {2}, {0});\r\n{1}" +
                        "p_message += sizeof({3}::value_type) * {2};", this.GetFieldNameForVariable(variable),
                        codeIntendation, countOfItemsInFieldStr, this.GetTypeNameForVariable(variable));
                }
            }
            else
            {
                var customType = this.metaInfo.CustomTypes.Single(ct => ct.Name == variable.GreisType);
                // ### CustomType ###
                if (variable.IsScalar)
                {
                    // scalar custom type deserialization
                    Debug.Assert(customType.Size > 0, "Custom types with fixed size are only supported.");
                    line = string.Format("_serializer.Deserialize(p_message, {2}, {0});\r\n{1}" +
                                         "p_message += {2};", this.GetFieldNameForVariable(variable),
                                         codeIntendation, customType.Size);
                }
                else
                {
                    Debug.Assert(variable.IsLinearArray, "Linear arrays of custom types are only supported.");
                    // array of any dimensions
                    string countOfItemsInFieldStr;
                    switch (variable.GetSizeForDimension(1))
                    {
                    case (int) SizeSpecialValue.Dynamic:
                        throw new FormatException("`Dynamic` is impossible value for fields.");
                    case (int) SizeSpecialValue.Fill:
                        countOfItemsInFieldStr = arraySizeInUniformFillFields;
                        break;
                    default:
                        int countOfItemsInField = 1;
                        for (int i = 1; i <= variable.DimensionsCount; i++)
                        {
                            countOfItemsInField *= variable.GetSizeForDimension(i);
                        }
                        countOfItemsInFieldStr = countOfItemsInField.ToString(CultureInfo.InvariantCulture);
                        break;
                    }
                    line = string.Format("_serializer.Deserialize(p_message, {3} * {2}, {3}, {0});\r\n{1}" +
                                         "p_message += {3} * {2};", this.GetFieldNameForVariable(variable),
                                         codeIntendation, countOfItemsInFieldStr, customType.Size);
                }
            }
            return line;
        }

        #endregion

        #region StdMessageFactory.cpp

        private void generateStdMessageFactory()
        {
            var stdMessageFactoryTemplatePath = Path.Combine(this.cppEnvTemplatesDir, "StdMessageFactory.template.cpp");
            var templateStr = File.ReadAllText(stdMessageFactoryTemplatePath, Encoding.Default);

            var intendation = Regex.Match(templateStr, @"([ \t]*)" + Regex.Escape(StubToken)).Groups[1].Value;
            var lines = this.metaInfo.StandardMessages.OrderBy(msg => msg.Name).
                Select((msg, i) =>
                       string.Format("case EMessageId::{0}:\r\n" +
                                     "{1}    return StdMessage::UniquePtr_t(new {0}StdMessage(p_message, p_length));",
                                     this.stdMessagesNameProvider.GetName(msg), intendation)
                ).ToArray();
            var stubContent = string.Join("\r\n" + intendation, lines);
            var fileContent = templateStr.Replace(StubToken, stubContent);

            this.WriteGeneratedFile("StdMessageFactory.cpp", fileContent);
        }

        #endregion

        #region AllStdMessages.h

        private void generateAllStdMessagesHeader()
        {
            var templatePath = Path.Combine(this.cppEnvTemplatesDir, "AllStdMessages.template.h");
            var templateStr = File.ReadAllText(templatePath, Encoding.Default);

            var includeLines = this.metaInfo.StandardMessages.OrderBy(msg => msg.Name).
                Select((msg, i) =>
                       string.Format("#include \"{2}/{0}/{1}StdMessage.h\"", StdMessagesDir,
                                     this.stdMessagesNameProvider.GetName(msg), IncludeDir)).ToArray();

            var includesContent = string.Join("\r\n", includeLines);
            var fileContent = templateStr.Replace(IncludesStubToken, includesContent);

            this.WriteGeneratedFile("AllStdMessages.h", fileContent);
        }

        #endregion

        #region AllCustomTypes.h

        private void generateAllCustomTypesHeader()
        {
            var templatePath = Path.Combine(this.cppEnvTemplatesDir, "AllCustomTypes.template.h");
            var templateStr = File.ReadAllText(templatePath, Encoding.Default);

            var includeLines = this.metaInfo.CustomTypes.OrderBy(ct => ct.Name).
                Select((ct, i) =>
                       string.Format("#include \"{2}/{0}/{1}CustomType.h\"", CustomTypesDir,
                                     this.customTypeNameProvider.GetName(ct), IncludeDir)).ToArray();

            var includesContent = string.Join("\r\n", includeLines);
            var fileContent = templateStr.Replace(IncludesStubToken, includesContent);

            this.WriteGeneratedFile("AllCustomTypes.h", fileContent);
        }

        #endregion

        #region StdMessageGeneratedMembers.cpp

        private void generateStdMessageGeneratedMembers()
        {
            var stdMessageGeneratedMembersTemplatePath = Path.Combine(this.cppEnvTemplatesDir, "StdMessageGeneratedMembers.template.cpp");
            var templateStr = File.ReadAllText(stdMessageGeneratedMembersTemplatePath, Encoding.Default);

            var intendation = Regex.Match(templateStr, @"([ \t]*)" + Regex.Escape(StubToken)).Groups[1].Value;
            var lines = this.metaInfo.StandardMessages.OrderBy(msg => msg.Name).
                SelectMany((msg, i) =>
                           msg.Codes.Select(
                               code => string.Format("cache[CHAR2_TO_USHORT(\"{0}\")] = EMessageId::{1};", code,
                                                     this.stdMessagesNameProvider.GetName(msg)))
                ).ToArray();
            var stubContent = string.Join("\r\n" + intendation, lines);
            var fileContent = templateStr.Replace(StubToken, stubContent);

            this.WriteGeneratedFile("StdMessageGeneratedMembers.cpp", fileContent);
        }

        #endregion

        #region EMessageId.h

        private void generateEMessageId()
        {
            var eMessageIdTemplatePath = Path.Combine(this.cppEnvTemplatesDir, "EMessageId.template.h");
            var templateStr = File.ReadAllText(eMessageIdTemplatePath, Encoding.Default);

            var intendation = Regex.Match(templateStr, @"([ \t]*)" + Regex.Escape(StubToken)).Groups[1].Value;
            var lastIndex = this.metaInfo.StandardMessages.Count - 1;
            var lines = this.metaInfo.StandardMessages.OrderBy(msg => msg.Name).
                Select((msg, i) => this.GetEnumName(msg) + (lastIndex == i ? " // " : ", // ") + msg.Title).
                ToArray();
            var stubContent = string.Join("\r\n" + intendation, lines);
            var fileContent = templateStr.Replace(StubToken, stubContent);

            this.WriteGeneratedFile("EMessageId.h", fileContent);
        }

        #endregion

        #region ECustomTypeId.h

        private void generateECustomTypeId()
        {
            var eCtIdTemplatePath = Path.Combine(this.cppEnvTemplatesDir, "ECustomTypeId.template.h");
            var templateStr = File.ReadAllText(eCtIdTemplatePath, Encoding.Default);

            var intendation = Regex.Match(templateStr, @"([ \t]*)" + Regex.Escape(StubToken)).Groups[1].Value;
            var lastIndex = this.metaInfo.CustomTypes.Count - 1;
            var lines = this.metaInfo.CustomTypes.OrderBy(ct => ct.Name).
                Select((ct, i) => this.GetEnumName(ct) + (lastIndex == i ? "" : ",")).
                ToArray();
            var stubContent = string.Join("\r\n" + intendation, lines);
            var fileContent = templateStr.Replace(StubToken, stubContent);

            this.WriteGeneratedFile("ECustomTypeId.h", fileContent);
        }

        #endregion

        private void WriteGeneratedFile(string filename, string content)
        {
            var path = Path.Combine(this.targetDir, filename);
            var dirName = Path.GetDirectoryName(path);
            if (dirName != null)
            {
                Directory.CreateDirectory(dirName);
            }

            if (!File.Exists(path) || File.ReadAllText(path, Encoding.Default) != content)
            {
                File.WriteAllText(path, content, Encoding.Default);
            }
        }

        private string GetClassName(CustomType ct)
        {
            if (ct is StandardMessage)
            {
                return this.stdMessagesNameProvider.GetName(ct) + "StdMessage";
            } else
            {
                return this.customTypeNameProvider.GetName(ct) + "CustomType";
            }
        }

        private string GetInserterVarName(CustomType ct)
        {
            string name = this.GetEnumName(ct);
            name = char.ToLower(name[0]) + name.Substring(1);
            return name + "Inserter";
        }

        private static string GetCodeIntend(string templateStr, string stubToken)
        {
            return Regex.Match(templateStr, @"([ \t]*)" + Regex.Escape(stubToken)).Groups[1].Value;
        }

        private string GetEnumName(CustomType ct)
        {
            if (ct is StandardMessage)
            {
                return this.stdMessagesNameProvider.GetName(ct as StandardMessage);
            }
            return this.customTypeNameProvider.GetName(ct);
        }

        private string GetTypeNameForVariable(Variable variable)
        {
            string typeName = this.simpleTypes.Contains(variable.GreisType)
                                  ? string.Format("Types::{0}", variable.GreisType)
                                  : string.Format("{0}CustomType::UniquePtr_t", GetLowerCamelCase(variable.GreisType));
            if (!variable.IsScalar)
            {
                if (variable.GreisType == GreisTypes.a1.ToString())
                {
                    if (variable.DimensionsCount > 1)
                    {
                        throw new NotSupportedException();
                    }
                    typeName = "std::string";
                }
                else
                {
                    for (int i = 0; i < variable.DimensionsCount; i++)
                    {
                        typeName = string.Format("std::vector<{0}>", typeName);
                    }
                }
            }
            return typeName;
        }

        private string GetFieldNameForVariable(Variable variable)
        {
            return "_" + GetLowerCamelCase(variable.Name);
        }

        private string GetVarNameForVariable(Variable variable)
        {
            return GetLowerCamelCase(variable.Name);
        }

        private string GetAccessorNameForVariable(Variable variable)
        {
            var fieldName = GetLowerCamelCase(variable.Name);
            return char.ToUpper(fieldName[0]) + fieldName.Substring(1);
        }

        private static string GetLowerCamelCase(string s)
        {
            return CustomTypeNameFactory.ValidateNameAsVariable(
                CustomTypeNameFactory.ReplaceIdField(
                    CustomTypeNameFactory.ToLowerCamelCase(s)));
        }
    }
}
