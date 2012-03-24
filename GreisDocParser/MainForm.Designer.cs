namespace GreisDocParser
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnOutputDirBrowse = new System.Windows.Forms.Button();
            this.tbxOutputDir = new System.Windows.Forms.TextBox();
            this.lblOutputDir = new System.Windows.Forms.Label();
            this.textBoxInputText = new System.Windows.Forms.TextBox();
            this.btnCreateMetaInfo = new System.Windows.Forms.Button();
            this.saveFileDialogXml = new System.Windows.Forms.SaveFileDialog();
            this.groupBoxMetaInfoInput = new System.Windows.Forms.GroupBox();
            this.radioButtonText = new System.Windows.Forms.RadioButton();
            this.radioButtonFile = new System.Windows.Forms.RadioButton();
            this.tbxPlainTextReferenceFilename = new System.Windows.Forms.TextBox();
            this.btnPlainTextReferenceFilenameBrowse = new System.Windows.Forms.Button();
            this.openFileDialogAny = new System.Windows.Forms.OpenFileDialog();
            this.theFolderBrowserDialog = new System.Windows.Forms.FolderBrowserDialog();
            this.label2 = new System.Windows.Forms.Label();
            this.btnCreateBaseline = new System.Windows.Forms.Button();
            this.buttonBaselineInputBrowse = new System.Windows.Forms.Button();
            this.tbxMetaInfoFile = new System.Windows.Forms.TextBox();
            this.openFileDialogXml = new System.Windows.Forms.OpenFileDialog();
            this.theTabControl = new System.Windows.Forms.TabControl();
            this.tabPageMetaInfo = new System.Windows.Forms.TabPage();
            this.tabPageXmlBased = new System.Windows.Forms.TabPage();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.tbxCppEnvOutputSublocation = new System.Windows.Forms.TextBox();
            this.btnGenerateCppEnv = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBoxMetaInfoInput.SuspendLayout();
            this.theTabControl.SuspendLayout();
            this.tabPageMetaInfo.SuspendLayout();
            this.tabPageXmlBased.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnOutputDirBrowse
            // 
            this.btnOutputDirBrowse.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btnOutputDirBrowse.Location = new System.Drawing.Point(409, 295);
            this.btnOutputDirBrowse.Name = "btnOutputDirBrowse";
            this.btnOutputDirBrowse.Size = new System.Drawing.Size(75, 23);
            this.btnOutputDirBrowse.TabIndex = 0;
            this.btnOutputDirBrowse.Text = "Browse...";
            this.btnOutputDirBrowse.UseVisualStyleBackColor = true;
            this.btnOutputDirBrowse.Click += new System.EventHandler(this.buttonOutputDirBrowse_Click);
            // 
            // tbxOutputDir
            // 
            this.tbxOutputDir.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tbxOutputDir.Location = new System.Drawing.Point(90, 297);
            this.tbxOutputDir.Name = "tbxOutputDir";
            this.tbxOutputDir.Size = new System.Drawing.Size(314, 20);
            this.tbxOutputDir.TabIndex = 1;
            // 
            // lblOutputDir
            // 
            this.lblOutputDir.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblOutputDir.AutoSize = true;
            this.lblOutputDir.Location = new System.Drawing.Point(4, 300);
            this.lblOutputDir.Name = "lblOutputDir";
            this.lblOutputDir.Size = new System.Drawing.Size(85, 13);
            this.lblOutputDir.TabIndex = 2;
            this.lblOutputDir.Text = "Output directory:";
            // 
            // textBoxInputText
            // 
            this.textBoxInputText.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.textBoxInputText.Location = new System.Drawing.Point(6, 65);
            this.textBoxInputText.MaxLength = 99999999;
            this.textBoxInputText.Multiline = true;
            this.textBoxInputText.Name = "textBoxInputText";
            this.textBoxInputText.Size = new System.Drawing.Size(452, 153);
            this.textBoxInputText.TabIndex = 3;
            // 
            // btnCreateMetaInfo
            // 
            this.btnCreateMetaInfo.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.btnCreateMetaInfo.Location = new System.Drawing.Point(3, 233);
            this.btnCreateMetaInfo.Name = "btnCreateMetaInfo";
            this.btnCreateMetaInfo.Size = new System.Drawing.Size(464, 23);
            this.btnCreateMetaInfo.TabIndex = 4;
            this.btnCreateMetaInfo.Text = "Create meta info";
            this.btnCreateMetaInfo.UseVisualStyleBackColor = true;
            this.btnCreateMetaInfo.Click += new System.EventHandler(this.buttonCreateMetaInfo_Click);
            // 
            // saveFileDialogXml
            // 
            this.saveFileDialogXml.Filter = "XML files|*.xml|All files|*.*";
            // 
            // groupBoxMetaInfoInput
            // 
            this.groupBoxMetaInfoInput.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBoxMetaInfoInput.Controls.Add(this.radioButtonText);
            this.groupBoxMetaInfoInput.Controls.Add(this.radioButtonFile);
            this.groupBoxMetaInfoInput.Controls.Add(this.textBoxInputText);
            this.groupBoxMetaInfoInput.Controls.Add(this.tbxPlainTextReferenceFilename);
            this.groupBoxMetaInfoInput.Controls.Add(this.btnPlainTextReferenceFilenameBrowse);
            this.groupBoxMetaInfoInput.Location = new System.Drawing.Point(3, 3);
            this.groupBoxMetaInfoInput.Name = "groupBoxMetaInfoInput";
            this.groupBoxMetaInfoInput.Size = new System.Drawing.Size(464, 224);
            this.groupBoxMetaInfoInput.TabIndex = 5;
            this.groupBoxMetaInfoInput.TabStop = false;
            this.groupBoxMetaInfoInput.Text = "Input";
            // 
            // radioButtonText
            // 
            this.radioButtonText.AutoSize = true;
            this.radioButtonText.Location = new System.Drawing.Point(7, 42);
            this.radioButtonText.Name = "radioButtonText";
            this.radioButtonText.Size = new System.Drawing.Size(70, 17);
            this.radioButtonText.TabIndex = 4;
            this.radioButtonText.Text = "Raw text:";
            this.radioButtonText.UseVisualStyleBackColor = true;
            // 
            // radioButtonFile
            // 
            this.radioButtonFile.AutoSize = true;
            this.radioButtonFile.Checked = true;
            this.radioButtonFile.Location = new System.Drawing.Point(7, 20);
            this.radioButtonFile.Name = "radioButtonFile";
            this.radioButtonFile.Size = new System.Drawing.Size(44, 17);
            this.radioButtonFile.TabIndex = 4;
            this.radioButtonFile.TabStop = true;
            this.radioButtonFile.Text = "File:";
            this.radioButtonFile.UseVisualStyleBackColor = true;
            this.radioButtonFile.CheckedChanged += new System.EventHandler(this.radioButtonFile_CheckedChanged);
            // 
            // tbxPlainTextReferenceFilename
            // 
            this.tbxPlainTextReferenceFilename.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tbxPlainTextReferenceFilename.Location = new System.Drawing.Point(57, 19);
            this.tbxPlainTextReferenceFilename.Name = "tbxPlainTextReferenceFilename";
            this.tbxPlainTextReferenceFilename.Size = new System.Drawing.Size(320, 20);
            this.tbxPlainTextReferenceFilename.TabIndex = 1;
            // 
            // btnPlainTextReferenceFilenameBrowse
            // 
            this.btnPlainTextReferenceFilenameBrowse.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnPlainTextReferenceFilenameBrowse.Location = new System.Drawing.Point(383, 17);
            this.btnPlainTextReferenceFilenameBrowse.Name = "btnPlainTextReferenceFilenameBrowse";
            this.btnPlainTextReferenceFilenameBrowse.Size = new System.Drawing.Size(75, 23);
            this.btnPlainTextReferenceFilenameBrowse.TabIndex = 0;
            this.btnPlainTextReferenceFilenameBrowse.Text = "Browse...";
            this.btnPlainTextReferenceFilenameBrowse.UseVisualStyleBackColor = true;
            this.btnPlainTextReferenceFilenameBrowse.Click += new System.EventHandler(this.buttonMetaInfoInputBrowse_Click);
            // 
            // openFileDialogAny
            // 
            this.openFileDialogAny.Filter = "All files|*.*";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(1, 8);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(70, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Meta-info file:";
            // 
            // btnCreateBaseline
            // 
            this.btnCreateBaseline.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnCreateBaseline.Location = new System.Drawing.Point(315, 12);
            this.btnCreateBaseline.Name = "btnCreateBaseline";
            this.btnCreateBaseline.Size = new System.Drawing.Size(144, 23);
            this.btnCreateBaseline.TabIndex = 4;
            this.btnCreateBaseline.Text = "Generate baseline.sql";
            this.btnCreateBaseline.UseVisualStyleBackColor = true;
            this.btnCreateBaseline.Click += new System.EventHandler(this.buttonCreateBaseline_Click);
            // 
            // buttonBaselineInputBrowse
            // 
            this.buttonBaselineInputBrowse.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonBaselineInputBrowse.Location = new System.Drawing.Point(392, 3);
            this.buttonBaselineInputBrowse.Name = "buttonBaselineInputBrowse";
            this.buttonBaselineInputBrowse.Size = new System.Drawing.Size(75, 23);
            this.buttonBaselineInputBrowse.TabIndex = 0;
            this.buttonBaselineInputBrowse.Text = "Browse...";
            this.buttonBaselineInputBrowse.UseVisualStyleBackColor = true;
            this.buttonBaselineInputBrowse.Click += new System.EventHandler(this.buttonBaselineInputBrowse_Click);
            // 
            // tbxMetaInfoFile
            // 
            this.tbxMetaInfoFile.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tbxMetaInfoFile.Location = new System.Drawing.Point(71, 5);
            this.tbxMetaInfoFile.Name = "tbxMetaInfoFile";
            this.tbxMetaInfoFile.Size = new System.Drawing.Size(317, 20);
            this.tbxMetaInfoFile.TabIndex = 1;
            // 
            // openFileDialogXml
            // 
            this.openFileDialogXml.Filter = "Xml files (*.xml)|*.xml|All files (*.*)|*.*";
            // 
            // theTabControl
            // 
            this.theTabControl.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.theTabControl.Controls.Add(this.tabPageMetaInfo);
            this.theTabControl.Controls.Add(this.tabPageXmlBased);
            this.theTabControl.Location = new System.Drawing.Point(6, 6);
            this.theTabControl.Name = "theTabControl";
            this.theTabControl.SelectedIndex = 0;
            this.theTabControl.Size = new System.Drawing.Size(478, 285);
            this.theTabControl.TabIndex = 8;
            // 
            // tabPageMetaInfo
            // 
            this.tabPageMetaInfo.Controls.Add(this.btnCreateMetaInfo);
            this.tabPageMetaInfo.Controls.Add(this.groupBoxMetaInfoInput);
            this.tabPageMetaInfo.Location = new System.Drawing.Point(4, 22);
            this.tabPageMetaInfo.Name = "tabPageMetaInfo";
            this.tabPageMetaInfo.Padding = new System.Windows.Forms.Padding(3);
            this.tabPageMetaInfo.Size = new System.Drawing.Size(470, 259);
            this.tabPageMetaInfo.TabIndex = 0;
            this.tabPageMetaInfo.Text = "meta-info.xml";
            this.tabPageMetaInfo.UseVisualStyleBackColor = true;
            // 
            // tabPageXmlBased
            // 
            this.tabPageXmlBased.Controls.Add(this.groupBox2);
            this.tabPageXmlBased.Controls.Add(this.groupBox1);
            this.tabPageXmlBased.Controls.Add(this.label2);
            this.tabPageXmlBased.Controls.Add(this.tbxMetaInfoFile);
            this.tabPageXmlBased.Controls.Add(this.buttonBaselineInputBrowse);
            this.tabPageXmlBased.Location = new System.Drawing.Point(4, 22);
            this.tabPageXmlBased.Name = "tabPageXmlBased";
            this.tabPageXmlBased.Padding = new System.Windows.Forms.Padding(3);
            this.tabPageXmlBased.Size = new System.Drawing.Size(470, 259);
            this.tabPageXmlBased.TabIndex = 1;
            this.tabPageXmlBased.Text = "XML-based content";
            this.tabPageXmlBased.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            this.groupBox2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox2.Controls.Add(this.tbxCppEnvOutputSublocation);
            this.groupBox2.Controls.Add(this.btnGenerateCppEnv);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Location = new System.Drawing.Point(2, 78);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(465, 69);
            this.groupBox2.TabIndex = 7;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "C++ environment";
            // 
            // tbxCppEnvOutputSublocation
            // 
            this.tbxCppEnvOutputSublocation.Location = new System.Drawing.Point(168, 41);
            this.tbxCppEnvOutputSublocation.Name = "tbxCppEnvOutputSublocation";
            this.tbxCppEnvOutputSublocation.Size = new System.Drawing.Size(291, 20);
            this.tbxCppEnvOutputSublocation.TabIndex = 6;
            // 
            // btnGenerateCppEnv
            // 
            this.btnGenerateCppEnv.Location = new System.Drawing.Point(315, 12);
            this.btnGenerateCppEnv.Name = "btnGenerateCppEnv";
            this.btnGenerateCppEnv.Size = new System.Drawing.Size(144, 23);
            this.btnGenerateCppEnv.TabIndex = 5;
            this.btnGenerateCppEnv.Text = "Generate C++ Environment";
            this.btnGenerateCppEnv.UseVisualStyleBackColor = true;
            this.btnGenerateCppEnv.Click += new System.EventHandler(this.btnGenerateCppEnv_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(6, 44);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(156, 13);
            this.label4.TabIndex = 2;
            this.label4.Text = "Location in the output directory:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 17);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(173, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Generate a Greis C++ environment:";
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox1.Controls.Add(this.btnCreateBaseline);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(2, 29);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(465, 43);
            this.groupBox1.TabIndex = 6;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "MySQL baseline";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 17);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(233, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Generate a baseline script for MySQL database:";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(490, 323);
            this.Controls.Add(this.theTabControl);
            this.Controls.Add(this.lblOutputDir);
            this.Controls.Add(this.tbxOutputDir);
            this.Controls.Add(this.btnOutputDirBrowse);
            this.Name = "MainForm";
            this.Text = "Greis Reference Parser";
            this.groupBoxMetaInfoInput.ResumeLayout(false);
            this.groupBoxMetaInfoInput.PerformLayout();
            this.theTabControl.ResumeLayout(false);
            this.tabPageMetaInfo.ResumeLayout(false);
            this.tabPageXmlBased.ResumeLayout(false);
            this.tabPageXmlBased.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnOutputDirBrowse;
        private System.Windows.Forms.TextBox tbxOutputDir;
        private System.Windows.Forms.Label lblOutputDir;
        private System.Windows.Forms.TextBox textBoxInputText;
        private System.Windows.Forms.Button btnCreateMetaInfo;
        private System.Windows.Forms.SaveFileDialog saveFileDialogXml;
        private System.Windows.Forms.GroupBox groupBoxMetaInfoInput;
        private System.Windows.Forms.RadioButton radioButtonText;
        private System.Windows.Forms.RadioButton radioButtonFile;
        private System.Windows.Forms.TextBox tbxPlainTextReferenceFilename;
        private System.Windows.Forms.Button btnPlainTextReferenceFilenameBrowse;
        private System.Windows.Forms.OpenFileDialog openFileDialogAny;
        private System.Windows.Forms.FolderBrowserDialog theFolderBrowserDialog;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button buttonBaselineInputBrowse;
        private System.Windows.Forms.TextBox tbxMetaInfoFile;
        private System.Windows.Forms.OpenFileDialog openFileDialogXml;
        private System.Windows.Forms.Button btnCreateBaseline;
        private System.Windows.Forms.TabControl theTabControl;
        private System.Windows.Forms.TabPage tabPageMetaInfo;
        private System.Windows.Forms.TabPage tabPageXmlBased;
        private System.Windows.Forms.Button btnGenerateCppEnv;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tbxCppEnvOutputSublocation;
        private System.Windows.Forms.Label label4;
    }
}

