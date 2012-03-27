using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace GreisDocParser
{
    public class CustomTypeNameCustomizer
    {
        public const string IdFieldReplacement = "idField";
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

        public static string ValidateNameAsVariable(string name)
        {
            if (!Regex.IsMatch(name, @"[A-Za-z_][A-Za-z0-9_]*", RegexOptions.Compiled))
            {
                throw new Exception(String.Format("Invalid table name '{0}' provided.", name));
            }
            return name;
        }

        public static string NormalizeNameToLowerCamelCase(string s)
        {
            return Regex.Replace(s, "_([a-z])", match => match.Groups[1].Value.ToUpper()).Replace("_", "");
        }

        public static string ReplaceIdField(string s)
        {
            return s.ToLower() == "id" ? IdFieldReplacement : s;
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
                            tableNameDic[ct] = ValidateNameAsVariable(_stdMessageNameCustomizer((StandardMessage)ct) + i++);
                        }
                        else
                        {
                            tableNameDic[ct] = ValidateNameAsVariable(_customTypeNameCustomizer(ct) + i++);
                        }
                    }
                }
                else
                {
                    var ct = l.First();
                    if (ct is StandardMessage)
                    {
                        tableNameDic[ct] = ValidateNameAsVariable(_stdMessageNameCustomizer((StandardMessage)ct));
                    }
                    else
                    {
                        tableNameDic[ct] = ValidateNameAsVariable(_customTypeNameCustomizer(ct));
                    }
                }
            }
            _tableNameDic = tableNameDic;
        }

    }
}
