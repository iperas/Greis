namespace GreisDocParser
{
    public class TableNameProvider
    {
        private readonly CustomTypeNameCustomizer _tableNameProvider;

        public TableNameProvider(MetaInfo metaInfo)
        {
            _tableNameProvider = new CustomTypeNameCustomizer(metaInfo, s => "msg_" + s.Name, s => "ct_" + s.Name);
        }

        public string GetName(CustomType ct)
        {
            return _tableNameProvider.GetName(ct);
        }
    }
}