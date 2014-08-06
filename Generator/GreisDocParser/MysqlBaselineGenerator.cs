using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace GreisDocParser
{
    public class MysqlBaselineGenerator
    {
        private readonly MetaInfo _metaInfo;
        private readonly string _templateFilename;
        private readonly string _databaseName;

        private TableNameProvider _tableNames;

        public MysqlBaselineGenerator(MetaInfo metaInfo, string templateFilename, string databaseName)
        {
            _metaInfo = metaInfo;
            _templateFilename = templateFilename;
            _databaseName = databaseName;

            _tableNames = new TableNameProvider(_metaInfo);
        }

        private const string PlaceholderUseDatabase = "-- @{USE-DATABASE-HERE}@";
        private const string PlaceholderTableCreation = "-- @{TABLE-CREATION-HERE}@";
        private const string PlaceholderTableDrop = "-- @{TABLE-DROP-HERE}@";
        private const string PlaceholderInitialFillup = "-- @{INITIAL-FILLUP-HERE}@";
        private const string IdColumnSugar = "_sugar";

        /// <summary>
        /// Создать начальное наполнение
        /// </summary>
        /// <param name="outFilename">Выходной файл.</param>
        public void GenerateMysqlBaseline(string outFilename)
        {
            // Generate template content
            var useDatabase = generateUseDatabase();
            var tableDrop = generateTableDrop();
            var tableCreation = generateTableCreation();
            var fillup = generateInitialFillup();

            // Apply it and save as new baseline file
            var encoding = Encoding.UTF8;
            var baseline = File.ReadAllText(_templateFilename, encoding);
            
            baseline = baseline.Replace(PlaceholderUseDatabase, useDatabase).
                                Replace(PlaceholderTableDrop, tableDrop).
                                Replace(PlaceholderTableCreation, tableCreation).
                                Replace(PlaceholderInitialFillup, fillup);

            if (!File.Exists(outFilename) || File.ReadAllText(outFilename, encoding) != baseline)
            {
                File.WriteAllText(outFilename, baseline, encoding);
            }
        }

        #region Template entries content generators

        private string generateUseDatabase()
        {
            return string.Format("USE `{0}`;", _databaseName);
        }

        private string generateTableCreation()
        {
            // customTypes
            var tableCreationSb = new StringBuilder();
            const string queryCtFmt = "-- custom type '{0}'\r\n" +
                                      "CREATE TABLE `{1}` (\r\n" +
                                      "    id SERIAL, \r\n" +
                                      "    idEpoch BIGINT UNSIGNED NOT NULL, \r\n" +
                                      "    unixTimeEpoch BIGINT UNSIGNED NOT NULL, \r\n" +
                                      "    bodySize INT NOT NULL, \r\n{2}" +
                                      "    PRIMARY KEY (`id`), \r\n" +
                                      "    INDEX `idx_fk_{1}_unixTimeEpoch` (`unixTimeEpoch`));\r\n\r\n";
            foreach (var ct in _metaInfo.CustomTypes)
            {
                var colDefs = new StringBuilder();
                foreach (var v in ct.Variables)
                {
                    colDefs.AppendFormat("    `{0}` {1}, \r\n", GetColumnName(v), sqlType(v));
                }

                var query = string.Format(queryCtFmt, ct.Name, _tableNames.GetName(ct), colDefs);
                tableCreationSb.Append(query);
            }
            // messages
            const string queryMsgFmt = "-- message '{0}': {1}\r\n" +
                                       "CREATE TABLE `{2}` (\r\n" +
                                       "    id SERIAL, \r\n" +
                                       "    idEpoch BIGINT UNSIGNED NOT NULL, \r\n" +
                                       "    unixTimeEpoch BIGINT UNSIGNED NOT NULL, \r\n" +
                                       "    idMessageCode BIGINT UNSIGNED NOT NULL, \r\n" +
                                       "    bodySize INT NOT NULL, \r\n{3}" +
                                       "    PRIMARY KEY (`id`), \r\n" +
                                       "    INDEX `idx_fk_{2}_idEpoch` (`idEpoch`), \r\n" +
                                       "    INDEX `idx_fk_{2}_unixTimeEpoch` (`unixTimeEpoch`), \r\n" +
                                       "    INDEX `idx_fk_{2}_idMessageCode` (`idMessageCode`), \r\n" +
                                       "    CONSTRAINT `fk_{2}_idEpoch` FOREIGN KEY (`idEpoch`) \r\n" +
                                       "        REFERENCES `epoch` (`id`), \r\n" +
                                       "    CONSTRAINT `fk_{2}_idMessageCode` FOREIGN KEY (`idMessageCode`) \r\n" +
                                       "        REFERENCES `messageCode` (`id`));\r\n\r\n";
            foreach (var msg in _metaInfo.StandardMessages)
            {
                var colDefs = new StringBuilder();
                foreach (var v in msg.Variables)
                {
                    colDefs.AppendFormat("    `{0}` {1}, \r\n", GetColumnName(v), sqlType(v));
                }

                var query = string.Format(queryMsgFmt, msg.Name, msg.Title.Replace("\r", "").Replace('\n', ' '),
                                          _tableNames.GetName(msg), colDefs);
                tableCreationSb.Append(query);
            }

            var tableCreation = tableCreationSb.ToString();
            return tableCreation;
        }

        private string generateTableDrop()
        {
            var tableDropSb = new StringBuilder();
            foreach (var msg in _metaInfo.StandardMessages)
            {
                tableDropSb.AppendFormat("DROP TABLE IF EXISTS `{0}`;\r\n", _tableNames.GetName(msg));
            }
            foreach (var ct in _metaInfo.CustomTypes)
            {
                tableDropSb.AppendFormat("DROP TABLE IF EXISTS `{0}`;\r\n", _tableNames.GetName(ct));
            }
            var tableDrop = tableDropSb.ToString();
            return tableDrop;
        }

        private string generateInitialFillup()
        {
            // sizeSpecialValue, messageValidation, messageKind, messagetype
            var sizeSpecialValueFillup =
                string.Format("-- Наполнение классификатора sizeSpecialValueClassifier\r\n" +
                              "INSERT INTO `sizeSpecialValueClassifier` (`id`, `name`) \r\n" +
                              "    VALUES {0};\r\n\r\n",
                              string.Join(", \r\n           ", ((int[]) Enum.GetValues(typeof (SizeSpecialValue))).
                              Select(i => string.Format("({0}, '{1}')", i, Enum.GetName(typeof (SizeSpecialValue), i)))));

            var messageValidationFillup = 
                string.Format("-- Наполнение классификатора messageValidationClassifier\r\n" +
                              "INSERT INTO `messageValidationClassifier` (`id`, `name`) \r\n" +
                              "    VALUES {0};\r\n\r\n",
                              string.Join(", \r\n           ", Enum.GetNames(typeof (ValidationType)).
                              Select((s, i) => string.Format("({0}, '{1}')", i, s))));

            var messageKindFillup = string.Format("-- Наполнение классификатора messageKindClassifier\r\n" +
                                                   "INSERT INTO `messageKindClassifier` (`name`) \r\n" +
                                                   "    VALUES {0};\r\n\r\n",
                                                   string.Join(", \r\n           ", Enum.GetNames(typeof (MessageKinds)).
                                                                                        Select(s => string.Format("('{0}')", s))));

            var messageTypeFillup = string.Format("-- Наполнение классификатора messageTypeClassifier\r\n" +
                                                   "INSERT INTO `messageTypeClassifier` (`name`) \r\n" +
                                                   "    VALUES {0};\r\n\r\n",
                                                   string.Join(", \r\n           ", Enum.GetNames(typeof (MessageTypes)).
                                                                                        Select(s => string.Format("('{0}')", s))));
            // customTypeMeta, customTypeVariableMeta, customTypeVariableSizeForDimension
            var metaValues = new List<string>();
            var customTypeVariableMetaValues = new List<string>();
            var customTypeVariableSizeForDimensionInserts = new List<string>();
            long customTypeId = 1;
            long customTypeVariableId = 1;
            foreach (var ct in _metaInfo.CustomTypes)
            {
                var customTypeVariableSizeForDimensionValues = new List<string>();
                foreach (var v in ct.Variables)
                {
                    // customTypeVariableMeta
                    var customTypeVariableMetaInsert = string.Format("({0}, '{1}', '{2}', '{3}', {4})",
                        customTypeVariableId, v.Name, v.GreisType, v.RequiredValue, customTypeId);
                    customTypeVariableMetaValues.Add(customTypeVariableMetaInsert);

                    // customTypeVariableSizeForDimension
                    for (int i = 0; i < v.DimensionsCount; i++)
                    {
                        var insert = string.Format("({0}, {1}, {2})", customTypeVariableId, i + 1, v.GetSizeForDimension(i + 1));
                        customTypeVariableSizeForDimensionValues.Add(insert);
                    }

                    customTypeVariableId++;
                }
                if (customTypeVariableSizeForDimensionValues.Count > 0)
                {
                    var customTypeVariableSizeForDimensionInsert =
                        string.Format("-- Наполнение информации о размерностях для пользовательского типа `{0}`\r\n" +
                                      "INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) \r\n" +
                                      "    VALUES {1};\r\n\r\n", ct.Name,
                                      string.Join(", \r\n           ", customTypeVariableSizeForDimensionValues));
                    customTypeVariableSizeForDimensionInserts.Add(customTypeVariableSizeForDimensionInsert);
                    customTypeVariableSizeForDimensionValues.Clear();
                }

                var ctMetaInsert = string.Format("({3}, '{0}', {1}, '{2}')", ct.Name, ct.Size,
                                                 _tableNames.GetName(ct), customTypeId);
                metaValues.Add(ctMetaInsert);
                customTypeId++;
            }
            var ctMetaFillup = string.Format("-- Наполнение мета-информации о пользовательских типах\r\n" +
                                             "INSERT INTO `customTypeMeta` (`id`, `name`, `size`, `tableName`) \r\n" +
                                             "    VALUES {0};\r\n\r\n", string.Join(", \r\n           ", metaValues));
            var customTypeVariableMetaFillup =
                string.Format("INSERT INTO `customTypeVariableMeta` (`id`, `name`, `greisType`, `requiredValue`, `idCustomTypeMeta`) \r\n" +
                              "    VALUES {0};\r\n\r\n",
                              string.Join(", \r\n           ", customTypeVariableMetaValues));

            // messageMeta, messageVariableMeta, messageCode
            metaValues = new List<string>();
            var messageCodeValues = new List<string>();
            var messageVariableMetaValues = new List<string>();
            var messageVariableSizeForDimensionInserts = new List<string>();
            long messageId = 1;
            long messageVariableId = 1;
            foreach (var message in _metaInfo.StandardMessages)
            {
                var messageVariableSizeForDimensionValues = new List<string>();
                foreach (var code in message.Codes)
                {
                    var messageCodeInsert = string.Format("('{0}', {1})", code, messageId);
                    messageCodeValues.Add(messageCodeInsert);
                }
                foreach (var v in message.Variables)
                {
                    var messageVariableMetaInsert = string.Format("({0}, '{1}', '{2}', '{3}', {4})", messageVariableId,
                                                                  v.Name, v.GreisType, v.RequiredValue, messageId);
                    messageVariableMetaValues.Add(messageVariableMetaInsert);

                    // customTypeVariableSizeForDimension
                    for (int i = 0; i < v.DimensionsCount; i++)
                    {
                        var insert = string.Format("({0}, {1}, {2})", messageVariableId, i + 1,
                                                   v.GetSizeForDimension(i + 1));
                        messageVariableSizeForDimensionValues.Add(insert);
                    }

                    messageVariableId++;
                }
                if (messageVariableSizeForDimensionValues.Count > 0)
                {
                    var messageVariableSizeForDimensionInsert =
                        string.Format("-- Наполнение информации о размерностях для сообщения `{0}`\r\n" +
                                      "INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) \r\n" +
                                      "    VALUES {1};\r\n\r\n", message.Name,
                                      string.Join(", \r\n           ", messageVariableSizeForDimensionValues));
                    messageVariableSizeForDimensionInserts.Add(messageVariableSizeForDimensionInsert);
                    messageVariableSizeForDimensionValues.Clear();
                }

                var messageMetaInsert = string.Format("({0}, '{1}', '{2}', {3}, {4}, {5}, {6}, '{7}')", messageId,
                                                      message.Name, message.Title, message.Size,
                                                      (int) message.Validation, (int) MessageKinds.GreisStandardMessage,
                                                      (int)message.Type, _tableNames.GetName(message));
                metaValues.Add(messageMetaInsert);
                messageId++;
            }
            var messageMetaFillup = string.Format("-- Наполнение мета-информации о сообщениях\r\n" +
                                                   "INSERT INTO `messageMeta` (`id`, `name`, `title`, `size`, `idValidation`, `idKind`, `idType`, `tableName`) \r\n" +
                                                   "    VALUES {0};\r\n\r\n", string.Join(", \r\n           ", metaValues));
            var messageCodeFillup = string.Format("INSERT INTO `messageCode` (`code`, `idMessageMeta`) \r\n" +
                                                   "    VALUES {0};\r\n\r\n",
                                                   string.Join(", \r\n           ", messageCodeValues));
            var messageVariableMetaFillup =
                string.Format("INSERT INTO `messageVariableMeta` (`id`, `name`, `greisType`, `requiredValue`, `idMessageMeta`) \r\n" +
                              "    VALUES {0};\r\n\r\n",
                              string.Join(", \r\n           ", messageVariableMetaValues));

            // summarizing
            var fillup = sizeSpecialValueFillup + messageValidationFillup + messageKindFillup +
                         messageTypeFillup + ctMetaFillup + messageMetaFillup + messageCodeFillup +
                         messageVariableMetaFillup + customTypeVariableMetaFillup + string.Concat(customTypeVariableSizeForDimensionInserts)
                         + string.Concat(messageVariableSizeForDimensionInserts);
            return fillup;
        }

        #endregion

        public static string GetColumnName(Variable v)
        {
            var colName = v.Name;
            if (!Regex.IsMatch(colName, @"[A-Za-z_][A-Za-z0-9_]*", RegexOptions.Compiled))
            {
                throw new Exception(string.Format("Invalid column name '{0}' provided.", colName));
            }
            if (colName == "id")
            {
                colName += IdColumnSugar;
            }
            return colName;
        }

        private static string sqlType(Variable v)
        {
            var greisTypesToSqlTypesMap = new Dictionary<string, string>();
            greisTypesToSqlTypesMap[GreisTypes.a1.ToString()] = "CHAR";
            greisTypesToSqlTypesMap[GreisTypes.f4.ToString()] = "FLOAT";
            greisTypesToSqlTypesMap[GreisTypes.f8.ToString()] = "DOUBLE";
            greisTypesToSqlTypesMap[GreisTypes.i1.ToString()] = "TINYINT";
            greisTypesToSqlTypesMap[GreisTypes.i2.ToString()] = "SMALLINT";
            greisTypesToSqlTypesMap[GreisTypes.i4.ToString()] = "INT";
            greisTypesToSqlTypesMap[GreisTypes.u1.ToString()] = "TINYINT UNSIGNED";
            greisTypesToSqlTypesMap[GreisTypes.u2.ToString()] = "SMALLINT UNSIGNED";
            greisTypesToSqlTypesMap[GreisTypes.u4.ToString()] = "INT UNSIGNED";
            const string idType = "BIGINT UNSIGNED";
            const string arrayType = "BLOB";
            const int maxVarcharLength = 1000;
            if (v.IsScalar)
            {
                // One of standard types
                if (greisTypesToSqlTypesMap.ContainsKey(v.GreisType))
                {
                    return greisTypesToSqlTypesMap[v.GreisType];
                }
                // custom type, return id type (SERIAL)
                return idType;
            } else
            {
                // One of standard types
                if (greisTypesToSqlTypesMap.ContainsKey(v.GreisType))
                {
                    // char[] to string
                    if (v.GreisType == GreisTypes.a1.ToString())
                    {
                        if (v.DimensionsCount > 1)
                        {
                            throw new NotSupportedException("Only 1 level of dimensions (char str[N]) for char types is supported.");
                        }
                        return string.Format("VARCHAR({0})", maxVarcharLength);
                    }
                    // any standard type but char with any dimension level
                    // stores in binary serialized format: [i4 i4 i4 i4] = 16 bytes (LSB)
                    return arrayType;
                }
                if (v.DimensionsCount > 1)
                {
                    throw new NotSupportedException("Only 1 level of dimensions (type name[N]) for custom types is supported.");
                }
                // custom types 1 dim array
                return arrayType;
            }
        }
    }
}
