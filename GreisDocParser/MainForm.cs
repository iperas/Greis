using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace GreisDocParser
{
    /*enum GreisType
    {
        a1, // a1 | ASCII character | 1
        i1, // i1 | signed integer | 1
        i2, // i2 | signed integer | 2
        i4, // i4 | signed integer | 4
        u1, // u1 | unsigned integer | 1
        u2, // u2 | unsigned integer | 2
        u4, // u4 | unsigned integer | 4
        f4, // f4 | IEEE-754 single precision floating point | 4
        f8, // f8 | IEEE-754 double precision floating point | 8
    }*/

    [Serializable]
    public class StandardMessage
    {
        public StandardMessage()
        {
            Codes = new List<string>();
            Variables = new List<Variable>();
            Size = DynamicSize;
        }

        public const int DynamicSize = -1;

        [XmlAttribute]
        public string Title { get; set; }
        [XmlAttribute]
        public string Name { get; set; }
        [XmlAttribute]
        public int Size { get; set; }
        public List<string> Codes { get; set; }
        public List<Variable> Variables { get; set; }
    }

    [Serializable]
    public class Variable
    {
        public Variable()
        {
            Dimensions = new List<int>();
        }

        public const int DynamicSize = -1;

        [XmlAttribute]
        public string Type { get; set; }
        [XmlAttribute]
        public string Name { get; set; }
        [XmlAttribute]
        public List<int> Dimensions { get; set; }
        [XmlAttribute]
        public string RequiredValue { get; set; }
        public string Comment { get; set; }
    }

    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();

            textBoxInputPath.Text = Path.Combine(Environment.CurrentDirectory, "input.txt");
            textBoxInputPath.Text = @"D:\Documents\svn_ifz_ipg\Projects\trunk\src\JpsParser\1.txt";
            textBoxOutputPath.Text = Path.Combine(Environment.CurrentDirectory, "output.txt");
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

                var messages = new List<StandardMessage>();
                var matches = Regex.Matches(text, @"^(?<title>\[(?<code>[\x30-\x7E]{2})\](,\s*\[(?<code>[\x30-\x7E]{2})\])*
                                                    ([^\r\n\d]|(?!\d+[\r\n])\d)+)
                                                    ((?![\r\n]\s*\[[\x30-\x7E]{2}\]).)*?
                                                    struct\s+(?<name>[^\s]+)\s*\{(?<size>[^\}]+)\}\s*\{(?<content>[^}]+)\}", 
                    RegexOptions.IgnoreCase | RegexOptions.Multiline | RegexOptions.Singleline | RegexOptions.ExplicitCapture | RegexOptions.IgnorePatternWhitespace);
                foreach (Match m in matches)
                {
                    // Parsing message meta-info
                    var msg = new StandardMessage();
                    msg.Title = m.Groups["title"].Value;
                    foreach (Capture capture in m.Groups["code"].Captures)
                    {
                        msg.Codes.Add(capture.Value);
                    }
                    msg.Name = m.Groups["name"].Value;
                    int size;
                    if (int.TryParse(m.Groups["size"].Value, out size))
                    {
                        msg.Size = size;
                    }

                    // Parsing variables
                    var content = m.Groups["content"].Value;
                    var lines = content.Split(new[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);

                    List<Variable> lastAddedVariables = null; // For comments-only lines
                    foreach (var line in lines.Where(s => Regex.IsMatch(s, "(;|//)")))
                    {
                        // extract comments and code
                        var lm = Regex.Match(line, @"^[\s!]*((?<code>((?!;?\s*//).)*?);)?\s*(//\s*(?<comment>.*)\s*)?$", RegexOptions.IgnoreCase |
                                                                                      RegexOptions.Singleline |
                                                                                      RegexOptions.ExplicitCapture |
                                                                                      RegexOptions.IgnorePatternWhitespace);
                        if (!lm.Success)
                        {
                            throw new Exception(string.Format("Invalid content string '{0}' (lm).", line));
                        }
                        var code = lm.Groups["code"].Value;
                        var comment = lm.Groups["comment"].Value;
                        if (string.IsNullOrWhiteSpace(code) && !string.IsNullOrWhiteSpace(comment))
                        {
                            if (lastAddedVariables != null)
                            {
                                foreach (var lastAddedVariable in lastAddedVariables)
                                {
                                    if (string.IsNullOrWhiteSpace(lastAddedVariable.Comment))
                                    {
                                        lastAddedVariable.Comment = comment;
                                    } else
                                    {
                                        lastAddedVariable.Comment = lastAddedVariable.Comment + Environment.NewLine +
                                                                    comment;
                                    }
                                }
                            }
                            continue;
                        }
                        // Parsing code
                        // variable pattern does not covers all cases. For example empty SIZE property in multidimension arrays causes a bug.
                        const string variablePattern = @"(?<name>[a-z][a-z0-9]*)
                                                         (?<sizePresented>\[(?<size>[^\]]*)\])*
                                                         (\s*=\s*([""\u201c\u201d](?<value>[^""\u201c\u201d]+)[""\u201c\u201d]|(?<value>[^\s,]+)))?";
                        var cm = Regex.Match(code, string.Format(@"^(?<type>[a-z][a-z0-9]*)\s+(?<var>{0})(\s*,\s*(?<var>{0}))*$", variablePattern),
                                             RegexOptions.IgnoreCase |
                                             RegexOptions.Singleline |
                                             RegexOptions.ExplicitCapture |
                                             RegexOptions.IgnorePatternWhitespace);
                        if (!cm.Success)
                        {
                            throw new Exception(string.Format("Invalid content string '{0}' (cm).", line));
                        }
                        var variables = new List<Variable>();
                        var vartype = cm.Groups["type"].Value;
                        foreach (Capture capture in cm.Groups["var"].Captures)
                        {
                            // Parsing variables names
                            var varname = capture.Value;
                            var vm = Regex.Match(varname, string.Format(@"^{0}$", variablePattern),
                                                 RegexOptions.IgnoreCase |
                                                 RegexOptions.Singleline |
                                                 RegexOptions.ExplicitCapture |
                                                 RegexOptions.IgnorePatternWhitespace);
                            if (!vm.Success)
                            {
                                throw new Exception(string.Format("Invalid content string '{0}' (vm).", line));
                            }
                            var variable = new Variable();
                            variable.Type = vartype;
                            variable.Name = vm.Groups["name"].Value;
                            variable.RequiredValue = vm.Groups["value"].Value;
                            variable.Comment = comment;

                            var dimensionsCount = vm.Groups["sizePresented"].Captures.Count;
                            if (dimensionsCount > 0)
                            {
                                for (int i = 0; i < dimensionsCount; i++)
                                {
                                    var sizeStr = vm.Groups["size"].Captures[i].Value;
                                    var sizePresented = !string.IsNullOrEmpty(vm.Groups["sizePresented"].Captures[i].Value);
                                    int varsize;
                                    if (!sizePresented)
                                    {
                                        varsize = 1;
                                    }
                                    else if (!int.TryParse(sizeStr, out varsize))
                                    {
                                        varsize = Variable.DynamicSize;
                                    }
                                    variable.Dimensions.Add(varsize);
                                }
                            }
                            else
                            {
                                variable.Dimensions.Add(1);
                            }

                            variables.Add(variable);
                        }
                        lastAddedVariables = variables;
                        msg.Variables.AddRange(variables);
                    }
                    messages.Add(msg);
                }
                var serializer = new XmlSerializer(typeof (List<StandardMessage>));
                using (var outFile = File.Create(textBoxOutputPath.Text))
                {
                    serializer.Serialize(outFile, messages);
                }
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
