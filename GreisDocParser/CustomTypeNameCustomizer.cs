using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace GreisDocParser
{
    public class CustomTypeNameCustomizer
    {
        private readonly Func<StandardMessage, string> _stdMessageNameCustomizer;
        private readonly Func<CustomType, string> _customTypeNameCustomizer;
        private Dictionary<CustomType, string> _tableNameDic;
        private readonly IEnumerable<CustomType> _customTypes;

        public CustomTypeNameCustomizer(MetaInfo metaInfo, Func<StandardMessage, string> stdMessageNameCustomizer = null,
                                        Func<CustomType, string> customTypeNameCustomizer = null)
        {
            _customTypeNameCustomizer = customTypeNameCustomizer;
            _stdMessageNameCustomizer = stdMessageNameCustomizer;
            _customTypes = metaInfo.StandardMessages.Concat(metaInfo.CustomTypes);

            createTableNameCache();
        }

        public CustomTypeNameCustomizer(IEnumerable<CustomType> customTypes,
            Func<StandardMessage, string> stdMessageNameCustomizer = null,
            Func<CustomType, string> customTypeNameCustomizer = null)
        {
            _customTypeNameCustomizer = customTypeNameCustomizer;
            _stdMessageNameCustomizer = stdMessageNameCustomizer;
            _customTypes = customTypes;

            createTableNameCache();
        }

        public string GetName(CustomType ct)
        {
            return _tableNameDic[ct];
        }

        private void createTableNameCache()
        {
            var lookup = _customTypes.ToLookup(ct => ct.Name.ToLowerInvariant());
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
                            tableNameDic[ct] = validatedTableName(_stdMessageNameCustomizer((StandardMessage)ct) + i++);
                        }
                        else
                        {
                            tableNameDic[ct] = validatedTableName(_customTypeNameCustomizer(ct) + i++);
                        }
                    }
                }
                else
                {
                    var ct = l.First();
                    if (ct is StandardMessage)
                    {
                        tableNameDic[ct] = validatedTableName(_stdMessageNameCustomizer((StandardMessage)ct));
                    }
                    else
                    {
                        tableNameDic[ct] = validatedTableName(_customTypeNameCustomizer(ct));
                    }
                }
            }
            _tableNameDic = tableNameDic;
        }

        private static string validatedTableName(string tableName)
        {
            if (!Regex.IsMatch(tableName, @"[A-Za-z_][A-Za-z0-9_]*", RegexOptions.Compiled))
            {
                throw new Exception(string.Format("Invalid table name '{0}' provided.", tableName));
            }
            return tableName;
        }
    }
}
