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
        private Dictionary<CustomType, string> _tableNameDic;

        public MysqlBaselineGenerator(MetaInfo metaInfo, string templateFilename, string databaseName)
        {
            _metaInfo = metaInfo;
            _templateFilename = templateFilename;
            _databaseName = databaseName;
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
            init();
            var encoding = Encoding.UTF8;
            var baseline = File.ReadAllText(_templateFilename, encoding);

            var useDatabase = string.Format("USE `{0}`;", _databaseName);
            var tableDrop = generateTableDrop();
            var tableCreation = this.tableCreation();
            var fillup = generateInitialFillup();

            baseline = baseline.Replace(PlaceholderUseDatabase, useDatabase).
                                Replace(PlaceholderTableDrop, tableDrop).
                                Replace(PlaceholderTableCreation, tableCreation).
                                Replace(PlaceholderInitialFillup, fillup);

            File.WriteAllText(outFilename, baseline, encoding);
        }

        private void init()
        {
            var lookup = _metaInfo.StandardMessages.Concat(_metaInfo.CustomTypes).
                ToLookup(ct => ct.Name.ToLowerInvariant());
            var tableNameDic = new Dictionary<CustomType, string>();
            foreach (var l in lookup)
            {
                if (l.Count() > 1)
                {
                    int i = 0;
                    foreach (var ct in l)
                    {
                        if (ct is StandardMessage)
                        {
                            tableNameDic[ct] = validatedTableName("msg_" + ct.Name + i++);
                        } else
                        {
                            tableNameDic[ct] = validatedTableName("ct_" + ct.Name + i++);
                        }
                    }
                } else
                {
                    var ct = l.First();
                    if (ct is StandardMessage)
                    {
                        tableNameDic[ct] = validatedTableName("msg_" + ct.Name);
                    }
                    else
                    {
                        tableNameDic[ct] = validatedTableName("ct_" + ct.Name);
                    }
                }
            }
            _tableNameDic = tableNameDic;
        }

        private string tableCreation()
        {
            // customTypes
            var tableCreationSb = new StringBuilder();
            const string queryCtFmt = "-- custom type '{0}'\r\n" +
                                      "CREATE TABLE `{1}` (\r\n" +
                                      "    id SERIAL, \r\n{2}" +
                                      "    PRIMARY KEY (`id`));\r\n\r\n";
            foreach (var ct in _metaInfo.CustomTypes)
            {
                var colDefs = new StringBuilder();
                foreach (var v in ct.Variables)
                {
                    colDefs.AppendFormat("    `{0}` {1}, \r\n", columnName(v), columnType(v));
                }

                var query = string.Format(queryCtFmt, ct.Name, tableName(ct), colDefs);
                tableCreationSb.Append(query);
            }
            // messages
            const string queryMsgFmt = "-- message '{0}': {1}\r\n" +
                                       "CREATE TABLE `{2}` (\r\n" +
                                       "    id SERIAL, \r\n" +
                                       "    idEpoch BIGINT UNSIGNED NOT NULL, \r\n{3}" +
                                       "    PRIMARY KEY (`id`), \r\n" +
                                       "    INDEX `idx_fk_{2}_idEpoch` (`idEpoch`), \r\n" +
                                       "    CONSTRAINT `fk_{2}_idEpoch` FOREIGN KEY (`idEpoch`) \r\n" +
                                       "        REFERENCES `epochs` (`id`));\r\n\r\n";
            foreach (var msg in _metaInfo.StandardMessages)
            {
                var colDefs = new StringBuilder();
                foreach (var v in msg.Variables)
                {
                    colDefs.AppendFormat("    `{0}` {1}, \r\n", columnName(v), columnType(v));
                }

                var query = string.Format(queryMsgFmt, msg.Name, msg.Title.Replace("\r", "").Replace('\n', ' '),
                                          tableName(msg), colDefs);
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
                tableDropSb.AppendFormat("DROP TABLE IF EXISTS `{0}`;\r\n", tableName(msg));
            }
            foreach (var ct in _metaInfo.CustomTypes)
            {
                tableDropSb.AppendFormat("DROP TABLE IF EXISTS `{0}`;\r\n", tableName(ct));
            }
            var tableDrop = tableDropSb.ToString();
            return tableDrop;
        }

        private string generateInitialFillup()
        {
            var sizeSpecialValuesFillup = string.Format("-- Наполнение классификатора sizeSpecialValuesClassifier\r\n" +
                                                        "INSERT INTO `sizeSpecialValuesClassifier` (`id`, `name`) \r\n" +
                                                        "    VALUES {0};\r\n\r\n",
                                                        string.Join(", \r\n           ",
                                                                    ((int[]) Enum.GetValues(typeof (SizeSpecialValues)))
                                                                        .Select(i => string.Format("({0}, '{1}')", i,
                                                                                                   Enum.GetName(
                                                                                                       typeof (SizeSpecialValues
                                                                                                           ), i)))));

            var messageValidationsFillup = string.Format("-- Наполнение классификатора messageValidationsClassifier\r\n" +
                                                         "INSERT INTO `messageValidationsClassifier` (`name`) \r\n" +
                                                         "    VALUES {0};\r\n\r\n",
                                                         string.Join(", \r\n           ",
                                                                     Enum.GetNames(typeof (ValidationTypes)).
                                                                         Select(s => string.Format("('{0}')", s))));

            var messageKindsFillup = string.Format("-- Наполнение классификатора messageKindsClassifier\r\n" +
                                                   "INSERT INTO `messageKindsClassifier` (`name`) \r\n" +
                                                   "    VALUES {0};\r\n\r\n",
                                                   string.Join(", \r\n           ", Enum.GetNames(typeof (MessageKinds)).
                                                                                        Select(s => string.Format("('{0}')", s))));

            var messagetypesFillup = string.Format("-- Наполнение классификатора messageTypesClassifier\r\n" +
                                                   "INSERT INTO `messageTypesClassifier` (`name`) \r\n" +
                                                   "    VALUES {0};\r\n\r\n",
                                                   string.Join(", \r\n           ", Enum.GetNames(typeof (MessageTypes)).
                                                                                        Select(s => string.Format("('{0}')", s))));
            // customTypesMeta
            var metaValues = new List<string>();
            var customTypeVariablesMetaValues = new List<string>();
            long customTypeId = 1;
            foreach (var ct in _metaInfo.CustomTypes)
            {
                foreach (var v in ct.Variables)
                {
                    var customTypeVariablesMetaInsert = string.Format("('{0}', '{1}', {2}, '{3}', {4})", v.Name, v.Type, v.Dimensions.Count, v.RequiredValue, customTypeId);
                    customTypeVariablesMetaValues.Add(customTypeVariablesMetaInsert);
                }
                var ctMetaInsert = string.Format("({3}, '{0}', {1}, '{2}')", ct.Name, ct.Size, tableName(ct), customTypeId);
                metaValues.Add(ctMetaInsert);
                customTypeId++;
            }
            var ctMetaFillup = string.Format("-- Наполнение мета-информации о пользовательских типах\r\n" +
                                             "INSERT INTO `customTypesMeta` (`id`, `name`, `size`, `tableName`) \r\n" +
                                             "    VALUES {0};\r\n\r\n", string.Join(", \r\n           ", metaValues));
            var customTypeVariablesMetaFillup =
                string.Format("INSERT INTO `customTypeVariablesMeta` (`name`, `type`, `dimensions`, `requiredValue`, `idCustomTypesMeta`) \r\n" +
                              "    VALUES {0};\r\n\r\n",
                              string.Join(", \r\n           ", customTypeVariablesMetaValues));

            // messagesMeta
            metaValues = new List<string>();
            var messageCodesValues = new List<string>();
            var messageVariablesMetaValues = new List<string>();
            long messageId = 1;
            foreach (var message in _metaInfo.StandardMessages)
            {
                foreach (var code in message.Codes)
                {
                    var messageCodesInsert = string.Format("('{0}', {1})", code, messageId);
                    messageCodesValues.Add(messageCodesInsert);
                }
                foreach (var v in message.Variables)
                {
                    var messageVariablesMetaInsert = string.Format("('{0}', '{1}', {2}, '{3}', {4})", v.Name, v.Type, v.Dimensions.Count, v.RequiredValue, messageId);
                    messageVariablesMetaValues.Add(messageVariablesMetaInsert);
                }
                var messageMetaInsert = string.Format("({0}, '{1}', '{2}', {3}, {4}, {5}, {6}, '{7}')", messageId,
                                                      message.Name, message.Title, message.Size,
                                                      (int) message.Validation, (int) MessageKinds.GreisStandardMessage,
                                                      (int) message.Type, tableName(message));
                metaValues.Add(messageMetaInsert);
                messageId++;
            }
            var messagesMetaFillup = string.Format("-- Наполнение мета-информации о сообщениях\r\n" +
                                                   "INSERT INTO `messagesMeta` (`id`, `name`, `title`, `size`, `idValidation`, `idKind`, `idType`, `tableName`) \r\n" +
                                                   "    VALUES {0};\r\n\r\n", string.Join(", \r\n           ", metaValues));
            var messageCodesFillup = string.Format("INSERT INTO `messageCodes` (`code`, `idMessagesMeta`) \r\n" +
                                                   "    VALUES {0};\r\n\r\n",
                                                   string.Join(", \r\n           ", messageCodesValues));
            var messageVariablesMetaFillup =
                string.Format("INSERT INTO `messageVariablesMeta` (`name`, `type`, `dimensions`, `requiredValue`, `idMessagesMeta`) \r\n" +
                              "    VALUES {0};\r\n\r\n",
                              string.Join(", \r\n           ", messageVariablesMetaValues));

            var fillup = sizeSpecialValuesFillup + messageValidationsFillup + messageKindsFillup +
                         messagetypesFillup + ctMetaFillup + messagesMetaFillup + messageCodesFillup +
                         messageVariablesMetaFillup + customTypeVariablesMetaFillup;
            return fillup;
        }

        private string tableName(CustomType ct)
        {
            return _tableNameDic[ct];
        }

        private static string validatedTableName(string tableName)
        {
            if (!Regex.IsMatch(tableName, @"[A-Za-z_][A-Za-z0-9_]*", RegexOptions.Compiled))
            {
                throw new Exception(string.Format("Invalid table name '{0}' provided.", tableName));
            }
            return tableName;
        }

        private static string columnName(Variable v)
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

        private string columnType(Variable v)
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
            const int maxVarcharLength = 1000;
            if (v.IsScalar)
            {
                if (greisTypesToSqlTypesMap.ContainsKey(v.Type))
                {
                    // One of standard types
                    return greisTypesToSqlTypesMap[v.Type];
                }
                // custom type, return id type (SERIAL)
                return idType;
            } else
            {
                if (greisTypesToSqlTypesMap.ContainsKey(v.Type))
                {
                    // One of standard types
                    if (v.Type == GreisTypes.a1.ToString())
                    {
                        if (v.Dimensions.Count > 1)
                        {
                            throw new NotSupportedException("Only single level dimensions (char str[N]) for char types is supported.");
                        }
                        // char[] to string
                        return string.Format("VARCHAR({0})", maxVarcharLength);
                    }
                    // semicolumn-separated string array ("2.2;3.6;123.5321") TODO: alternative solution without max array length
                    return string.Format("VARCHAR({0})", maxVarcharLength * 2);
                }
                if (v.Dimensions.Count > 1)
                {
                    throw new NotSupportedException("Only single level dimensions (type name[N]) for custom types is supported.");
                }
                // custom type, return id type (SERIAL)
                return idType;
            }
            /*
             * 
         CREATE TABLE `exampleMessage` (
         id SERIAL,
         idEpoch BIGINT UNSIGNED NOT NULL,
         -- message data. 1000 - max length for dynamic-length array
         _a1 CHAR,
         _uint1 TINYINT UNSIGNED,
         _int1 TINYINT,
         _uint2 SMALLINT UNSIGNED,
         _int2 SMALLINT,
         _uint4 INT UNSIGNED,
         _int4 INT,
         _f4 FLOAT,
         _f8 DOUBLE,
         numericArray VARCHAR(1000),
         fixedLengthStrArray VARCHAR(5),
         unknownLengthStrArray VARCHAR(1000),
         
         PRIMARY KEY (`id`),
         INDEX `idx_fk_epochs` (`idEpoch`),
         CONSTRAINT `fk_epochs` FOREIGN KEY (`idEpoch`) 
            REFERENCES `epochs` (`id`)
       );
             */
            return "INT";
        }
    }
}
