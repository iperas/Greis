using System;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Drawing;
using System.IO;
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

            theTabControl.SelectedIndex = 1;
            tbxPlainTextReferenceFilename.Text = Program.GetDefaultPathForKey(Program.PlainTextReferenceFileKey);
            tbxMetaInfoFile.Text = Program.GetDefaultPathForKey(Program.MetaInfoFileKey);
            tbxOutputDir.Text = Program.GetDefaultPathForKey(Program.OutputDirKey);
            radioButtonFile_CheckedChanged(this, EventArgs.Empty);
        }

        private void buttonOutputDirBrowse_Click(object sender, EventArgs e)
        {
            theFolderBrowserDialog.SelectedPath = Directory.Exists(tbxOutputDir.Text)
                                                     ? tbxOutputDir.Text
                                                     : null;
            if (theFolderBrowserDialog.ShowDialog() != DialogResult.OK)
            {
                return;
            }
            tbxOutputDir.Text = theFolderBrowserDialog.SelectedPath;
        }

        private void buttonCreateMetaInfo_Click(object sender, EventArgs e)
        {
            try
            {
                string text;
                if (radioButtonFile.Checked)
                {
                    if (!File.Exists(tbxPlainTextReferenceFilename.Text))
                    {
                        MessageBox.Show(this, string.Format("Файл '{0}' не найден!", tbxPlainTextReferenceFilename.Text), "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        return;
                    }
                    text = File.ReadAllText(tbxPlainTextReferenceFilename.Text, Encoding.Default);
                } else
                {
                    text = textBoxInputText.Text;
                }

                var metaInfo = MetaInfoGenerator.FromUserManual(text);

                //var knownSize = metaInfo.StandardMessages.Where(m => m.Size != (int) SizeSpecialValue.Dynamic).ToList();
                //var unknownSize = metaInfo.StandardMessages.Where(m => m.Size == (int) SizeSpecialValue.Dynamic).ToList();
                // serializing
                metaInfo.ToXmlFile(Path.Combine(tbxOutputDir.Text, "meta-info.xml"));
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
            openFileDialogAny.InitialDirectory = Directory.Exists(tbxPlainTextReferenceFilename.Text)
                                                     ? tbxPlainTextReferenceFilename.Text
                                                     : null;
            if (openFileDialogAny.ShowDialog() != DialogResult.OK)
            {
                return;
            }
            tbxPlainTextReferenceFilename.Text = openFileDialogAny.FileName;
        }

        private void radioButtonFile_CheckedChanged(object sender, EventArgs e)
        {
            var fromFile = radioButtonFile.Checked;

            tbxPlainTextReferenceFilename.Enabled = fromFile;
            btnPlainTextReferenceFilenameBrowse.Enabled = fromFile;
            textBoxInputText.Enabled = !fromFile;
        }

        private void buttonBaselineInputBrowse_Click(object sender, EventArgs e)
        {
            openFileDialogXml.InitialDirectory = Directory.Exists(tbxMetaInfoFile.Text)
                                                     ? tbxMetaInfoFile.Text
                                                     : null;
            if (openFileDialogXml.ShowDialog() != DialogResult.OK)
            {
                return;
            }
            tbxMetaInfoFile.Text = openFileDialogXml.FileName;
        }

        private void buttonCreateBaseline_Click(object sender, EventArgs e)
        {
            try
            {
                Program.MetaInfoFile = tbxMetaInfoFile.Text;
                Program.OutputDir = tbxOutputDir.Text;
                Program.GenerateBaseline();

                MessageBox.Show("Complete!");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnGenerateCppEnv_Click(object sender, EventArgs e)
        {
            Program.MetaInfoFile = tbxMetaInfoFile.Text;
            Program.OutputDir = tbxOutputDir.Text;
            Program.GenerateCppEnv();

            MessageBox.Show("Complete!");
        }
    }
}
