using Generator.Core.Model;

namespace Generator.Core
{
    public class SqlTableNameFactory
    {
        private readonly CustomTypeNameFactory tableNameProvider;

        public SqlTableNameFactory(MetaInfo metaInfo)
        {
            this.tableNameProvider = new CustomTypeNameFactory(metaInfo, s => "msg_" + s.Name, s => "ct_" + s.Name);
        }

        public string GetName(CustomType ct)
        {
            return this.tableNameProvider.GetName(ct);
        }
    }
}