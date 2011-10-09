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
            textBoxOutputPath.Text = Path.Combine(Environment.CurrentDirectory, "meta-data.xml");
            radioButtonFile_CheckedChanged(this, EventArgs.Empty);
        }

        private void buttonOutputPathBrowse_Click(object sender, EventArgs e)
        {
            saveFileDialogXml.InitialDirectory = Directory.Exists(textBoxOutputPath.Text)
                                                     ? textBoxOutputPath.Text
                                                     : null;
            if (saveFileDialogXml.ShowDialog() != DialogResult.OK)
            {
                return;
            }
            textBoxOutputPath.Text = saveFileDialogXml.FileName;
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

                var knownSize = metaInfo.StandardMessages.Where(m => m.Size != (int) SizeSpecialValues.Dynamic).ToList();
                var unknownSize = metaInfo.StandardMessages.Where(m => m.Size == (int) SizeSpecialValues.Dynamic).ToList();
                // serializing
                metaInfo.ToFile(textBoxOutputPath.Text);
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
