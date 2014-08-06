namespace GreisDocParser
{
    public class SqlTableNameFactory
    {
        private readonly CustomTypeNameFactory _tableNameProvider;

        public SqlTableNameFactory(MetaInfo metaInfo)
        {
            _tableNameProvider = new CustomTypeNameFactory(metaInfo, s => "msg_" + s.Name, s => "ct_" + s.Name);
        }

        public string GetName(CustomType ct)
        {
            return _tableNameProvider.GetName(ct);
        }
    }
}