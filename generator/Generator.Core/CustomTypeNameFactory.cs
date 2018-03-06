using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;
using Generator.Core.Model;

namespace Generator.Core
{
    public class CustomTypeNameFactory
    {
        public const string IdFieldReplacement = "idField";
        private readonly Func<StandardMessage, string> stdMessageNameCustomizer;
        private readonly Func<CustomType, string> customTypeNameCustomizer;
        private Dictionary<CustomType, string> tableNameDic;
        private readonly IEnumerable<CustomType> customTypes;

        public CustomTypeNameFactory(MetaInfo metaInfo, Func<StandardMessage, string> stdMessageNameCustomizer = null,
                                        Func<CustomType, string> customTypeNameCustomizer = null)
        {
            this.customTypeNameCustomizer = customTypeNameCustomizer;
            this.stdMessageNameCustomizer = stdMessageNameCustomizer;
            this.customTypes = metaInfo.StandardMessages.Concat(metaInfo.CustomTypes);

            this.CreateTableNameCache();
        }

        public CustomTypeNameFactory(IEnumerable<CustomType> customTypes,
            Func<StandardMessage, string> stdMessageNameCustomizer = null,
            Func<CustomType, string> customTypeNameCustomizer = null)
        {
            this.customTypeNameCustomizer = customTypeNameCustomizer;
            this.stdMessageNameCustomizer = stdMessageNameCustomizer;
            this.customTypes = customTypes;

            this.CreateTableNameCache();
        }

        public string GetName(CustomType ct)
        {
            return this.tableNameDic[ct];
        }

        public static string ValidateNameAsVariable(string name)
        {
            if (!Regex.IsMatch(name, @"[A-Za-z_][A-Za-z0-9_]*", RegexOptions.Compiled))
            {
                throw new Exception(String.Format("Invalid table name '{0}' provided.", name));
            }
            return name;
        }

        public static string ToLowerCamelCase(string s)
        {
            return Regex.Replace(s, "_([a-z])", match => match.Groups[1].Value.ToUpper()).Replace("_", "");
        }

        public static string ReplaceIdField(string s)
        {
            return s.ToLower() == "id" ? IdFieldReplacement : s;
        }

        private void CreateTableNameCache()
        {
            var lookup = this.customTypes.ToLookup(ct => ct.Name.ToLowerInvariant());
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
                            tableNameDic[ct] = ValidateNameAsVariable(this.stdMessageNameCustomizer((StandardMessage)ct) + i++);
                        }
                        else
                        {
                            tableNameDic[ct] = ValidateNameAsVariable(this.customTypeNameCustomizer(ct) + i++);
                        }
                    }
                }
                else
                {
                    var ct = l.First();
                    if (ct is StandardMessage)
                    {
                        tableNameDic[ct] = ValidateNameAsVariable(this.stdMessageNameCustomizer((StandardMessage)ct));
                    }
                    else
                    {
                        tableNameDic[ct] = ValidateNameAsVariable(this.customTypeNameCustomizer(ct));
                    }
                }
            }
            this.tableNameDic = tableNameDic;
        }

    }
}
