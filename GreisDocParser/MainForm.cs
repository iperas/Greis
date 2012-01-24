using System;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace GreisDocParser
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();

#if DEBUG
            textBoxMetaInfoInput.Text = Path.Combine(Environment.CurrentDirectory, "input.txt");
            textBoxMetaInfoInput.Text = @"D:\Documents\svn_ifz_ipg\Projects\trunk\src\JpsParser\1.txt";
            textBoxBaselineInput.Text = @"D:\Documents\svn_ifz_ipg\Projects\trunk\src\JpsParser\meta-info.xml";
#endif
            textBoxOutputDir.Text = Environment.CurrentDirectory;
            radioButtonFile_CheckedChanged(this, EventArgs.Empty);
        }

        private void buttonOutputDirBrowse_Click(object sender, EventArgs e)
        {
            theFolderBrowserDialog.SelectedPath = Directory.Exists(textBoxOutputDir.Text)
                                                     ? textBoxOutputDir.Text
                                                     : null;
            if (theFolderBrowserDialog.ShowDialog() != DialogResult.OK)
            {
                return;
            }
            textBoxOutputDir.Text = theFolderBrowserDialog.SelectedPath;
        }

        private void buttonCreateMetaInfo_Click(object sender, EventArgs e)
        {
            try
            {
                string text;
                if (radioButtonFile.Checked)
                {
                    if (!File.Exists(textBoxMetaInfoInput.Text))
                    {
                        MessageBox.Show(this, string.Format("Файл '{0}' не найден!", textBoxMetaInfoInput.Text), "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        return;
                    }
                    text = File.ReadAllText(textBoxMetaInfoInput.Text, Encoding.Default);
                } else
                {
                    text = textBoxInputText.Text;
                }

                var metaInfo = MetaInfoGenerator.FromUserManual(text);

                //var knownSize = metaInfo.StandardMessages.Where(m => m.Size != (int) SizeSpecialValue.Dynamic).ToList();
                //var unknownSize = metaInfo.StandardMessages.Where(m => m.Size == (int) SizeSpecialValue.Dynamic).ToList();
                // serializing
                metaInfo.ToXmlFile(Path.Combine(textBoxOutputDir.Text, "meta-info.xml"));
                // end
                MessageBox.Show("Parsing successfully complete!");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void buttonMetaInfoInputBrowse_Click(object sender, EventArgs e)
        {
            openFileDialogAny.InitialDirectory = Directory.Exists(textBoxMetaInfoInput.Text)
                                                     ? textBoxMetaInfoInput.Text
                                                     : null;
            if (openFileDialogAny.ShowDialog() != DialogResult.OK)
            {
                return;
            }
            textBoxMetaInfoInput.Text = openFileDialogAny.FileName;
        }

        private void radioButtonFile_CheckedChanged(object sender, EventArgs e)
        {
            var fromFile = radioButtonFile.Checked;

            textBoxMetaInfoInput.Enabled = fromFile;
            buttonMetaInfoInputBrowse.Enabled = fromFile;
            textBoxInputText.Enabled = !fromFile;
        }

        private void buttonBaselineInputBrowse_Click(object sender, EventArgs e)
        {
            openFileDialogXml.InitialDirectory = Directory.Exists(textBoxBaselineInput.Text)
                                                     ? textBoxBaselineInput.Text
                                                     : null;
            if (openFileDialogXml.ShowDialog() != DialogResult.OK)
            {
                return;
            }
            textBoxBaselineInput.Text = openFileDialogXml.FileName;
        }

        private void buttonCreateBaseline_Click(object sender, EventArgs e)
        {
            try
            {
                // take meta-info
                var metaInfo = MetaInfo.FromXmlFile(textBoxBaselineInput.Text);

                // take template file path
                var baselineTemplateFile = ConfigurationManager.AppSettings["baselineTemplateFile"];
                if (baselineTemplateFile.StartsWith("\\"))
                {
                    baselineTemplateFile = baselineTemplateFile.Substring(1);
                }
                if (!Path.IsPathRooted(baselineTemplateFile))
                {
                    baselineTemplateFile = Path.Combine(Application.StartupPath, baselineTemplateFile);
                }
                baselineTemplateFile = Path.GetFullPath(baselineTemplateFile);

                // generate script
                var baselineGenerator = new MysqlBaselineGenerator(metaInfo, baselineTemplateFile, "world");
                baselineGenerator.GenerateMysqlBaseline(Path.Combine(textBoxOutputDir.Text, "baseline.sql"));
                // end
                MessageBox.Show("Complete!");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
