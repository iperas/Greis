using System;
using System.ComponentModel;
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

            textBoxInputPath.Text = Path.Combine(Environment.CurrentDirectory, "input.txt");
            textBoxInputPath.Text = @"D:\Documents\svn_ifz_ipg\Projects\trunk\src\JpsParser\1.txt";
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

        private void buttonParse_Click(object sender, EventArgs e)
        {
            try
            {
                string text;
                if (radioButtonFile.Checked)
                {
                    if (!File.Exists(textBoxInputPath.Text))
                    {
                        MessageBox.Show(this, string.Format("Файл '{0}' не найден!", textBoxInputPath.Text), "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        return;
                    }
                    text = File.ReadAllText(textBoxInputPath.Text, Encoding.Default);
                } else
                {
                    text = textBoxInputText.Text;
                }

                var metaInfo = MetaInfoGenerator.FromUserManual(text);

                //var knownSize = metaInfo.StandardMessages.Where(m => m.Size != (int) SizeSpecialValues.Dynamic).ToList();
                //var unknownSize = metaInfo.StandardMessages.Where(m => m.Size == (int) SizeSpecialValues.Dynamic).ToList();
                // serializing
                metaInfo.ToFile(Path.Combine(textBoxOutputDir.Text, "meta-info.xml"));
                // end
                MessageBox.Show("Parsing successfully complete!");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void buttonInputPathBrowse_Click(object sender, EventArgs e)
        {
            openFileDialogAny.InitialDirectory = Directory.Exists(textBoxInputPath.Text)
                                                     ? textBoxInputPath.Text
                                                     : null;
            if (openFileDialogAny.ShowDialog() != DialogResult.OK)
            {
                return;
            }
            textBoxInputPath.Text = openFileDialogAny.FileName;
        }

        private void radioButtonFile_CheckedChanged(object sender, EventArgs e)
        {
            var fromFile = radioButtonFile.Checked;

            textBoxInputPath.Enabled = fromFile;
            buttonInputPathBrowse.Enabled = fromFile;
            textBoxInputText.Enabled = !fromFile;
        }
    }
}
