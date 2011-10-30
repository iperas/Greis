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
            this.buttonOutputDirBrowse = new System.Windows.Forms.Button();
            this.textBoxOutputDir = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.textBoxInputText = new System.Windows.Forms.TextBox();
            this.buttonCreateMetaInfo = new System.Windows.Forms.Button();
            this.saveFileDialogXml = new System.Windows.Forms.SaveFileDialog();
            this.groupBoxMetaInfoInput = new System.Windows.Forms.GroupBox();
            this.radioButtonText = new System.Windows.Forms.RadioButton();
            this.radioButtonFile = new System.Windows.Forms.RadioButton();
            this.textBoxMetaInfoInput = new System.Windows.Forms.TextBox();
            this.buttonMetaInfoInputBrowse = new System.Windows.Forms.Button();
            this.openFileDialogAny = new System.Windows.Forms.OpenFileDialog();
            this.theFolderBrowserDialog = new System.Windows.Forms.FolderBrowserDialog();
            this.groupBoxMetaInfo = new System.Windows.Forms.GroupBox();
            this.groupBoxBaseline = new System.Windows.Forms.GroupBox();
            this.label2 = new System.Windows.Forms.Label();
            this.buttonBaselineInputBrowse = new System.Windows.Forms.Button();
            this.textBoxBaselineInput = new System.Windows.Forms.TextBox();
            this.openFileDialogXml = new System.Windows.Forms.OpenFileDialog();
            this.buttonCreateBaseline = new System.Windows.Forms.Button();
            this.groupBoxMetaInfoInput.SuspendLayout();
            this.groupBoxMetaInfo.SuspendLayout();
            this.groupBoxBaseline.SuspendLayout();
            this.SuspendLayout();
            // 
            // buttonOutputDirBrowse
            // 
            this.buttonOutputDirBrowse.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonOutputDirBrowse.Location = new System.Drawing.Point(378, 27);
            this.buttonOutputDirBrowse.Name = "buttonOutputDirBrowse";
            this.buttonOutputDirBrowse.Size = new System.Drawing.Size(75, 23);
            this.buttonOutputDirBrowse.TabIndex = 0;
            this.buttonOutputDirBrowse.Text = "Browse...";
            this.buttonOutputDirBrowse.UseVisualStyleBackColor = true;
            this.buttonOutputDirBrowse.Click += new System.EventHandler(this.buttonOutputDirBrowse_Click);
            // 
            // textBoxOutputDir
            // 
            this.textBoxOutputDir.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.textBoxOutputDir.Location = new System.Drawing.Point(12, 29);
            this.textBoxOutputDir.Name = "textBoxOutputDir";
            this.textBoxOutputDir.Size = new System.Drawing.Size(360, 20);
            this.textBoxOutputDir.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(85, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Output directory:";
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
            this.textBoxInputText.Size = new System.Drawing.Size(417, 164);
            this.textBoxInputText.TabIndex = 3;
            // 
            // buttonCreateMetaInfo
            // 
            this.buttonCreateMetaInfo.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonCreateMetaInfo.Location = new System.Drawing.Point(6, 260);
            this.buttonCreateMetaInfo.Name = "buttonCreateMetaInfo";
            this.buttonCreateMetaInfo.Size = new System.Drawing.Size(429, 23);
            this.buttonCreateMetaInfo.TabIndex = 4;
            this.buttonCreateMetaInfo.Text = "Create meta info";
            this.buttonCreateMetaInfo.UseVisualStyleBackColor = true;
            this.buttonCreateMetaInfo.Click += new System.EventHandler(this.buttonCreateMetaInfo_Click);
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
            this.groupBoxMetaInfoInput.Controls.Add(this.textBoxMetaInfoInput);
            this.groupBoxMetaInfoInput.Controls.Add(this.buttonMetaInfoInputBrowse);
            this.groupBoxMetaInfoInput.Location = new System.Drawing.Point(6, 19);
            this.groupBoxMetaInfoInput.Name = "groupBoxMetaInfoInput";
            this.groupBoxMetaInfoInput.Size = new System.Drawing.Size(429, 235);
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
            // textBoxMetaInfoInput
            // 
            this.textBoxMetaInfoInput.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.textBoxMetaInfoInput.Location = new System.Drawing.Point(57, 19);
            this.textBoxMetaInfoInput.Name = "textBoxMetaInfoInput";
            this.textBoxMetaInfoInput.Size = new System.Drawing.Size(285, 20);
            this.textBoxMetaInfoInput.TabIndex = 1;
            // 
            // buttonMetaInfoInputBrowse
            // 
            this.buttonMetaInfoInputBrowse.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonMetaInfoInputBrowse.Location = new System.Drawing.Point(348, 17);
            this.buttonMetaInfoInputBrowse.Name = "buttonMetaInfoInputBrowse";
            this.buttonMetaInfoInputBrowse.Size = new System.Drawing.Size(75, 23);
            this.buttonMetaInfoInputBrowse.TabIndex = 0;
            this.buttonMetaInfoInputBrowse.Text = "Browse...";
            this.buttonMetaInfoInputBrowse.UseVisualStyleBackColor = true;
            this.buttonMetaInfoInputBrowse.Click += new System.EventHandler(this.buttonMetaInfoInputBrowse_Click);
            // 
            // openFileDialogAny
            // 
            this.openFileDialogAny.Filter = "All files|*.*";
            // 
            // groupBoxMetaInfo
            // 
            this.groupBoxMetaInfo.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBoxMetaInfo.Controls.Add(this.groupBoxMetaInfoInput);
            this.groupBoxMetaInfo.Controls.Add(this.buttonCreateMetaInfo);
            this.groupBoxMetaInfo.Location = new System.Drawing.Point(12, 56);
            this.groupBoxMetaInfo.Name = "groupBoxMetaInfo";
            this.groupBoxMetaInfo.Size = new System.Drawing.Size(441, 292);
            this.groupBoxMetaInfo.TabIndex = 6;
            this.groupBoxMetaInfo.TabStop = false;
            this.groupBoxMetaInfo.Text = "meta-info.xml";
            // 
            // groupBoxBaseline
            // 
            this.groupBoxBaseline.Controls.Add(this.label2);
            this.groupBoxBaseline.Controls.Add(this.buttonCreateBaseline);
            this.groupBoxBaseline.Controls.Add(this.buttonBaselineInputBrowse);
            this.groupBoxBaseline.Controls.Add(this.textBoxBaselineInput);
            this.groupBoxBaseline.Location = new System.Drawing.Point(12, 354);
            this.groupBoxBaseline.Name = "groupBoxBaseline";
            this.groupBoxBaseline.Size = new System.Drawing.Size(441, 78);
            this.groupBoxBaseline.TabIndex = 7;
            this.groupBoxBaseline.TabStop = false;
            this.groupBoxBaseline.Text = "baseline.sql";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(9, 24);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(70, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Meta-info file:";
            // 
            // buttonBaselineInputBrowse
            // 
            this.buttonBaselineInputBrowse.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonBaselineInputBrowse.Location = new System.Drawing.Point(360, 19);
            this.buttonBaselineInputBrowse.Name = "buttonBaselineInputBrowse";
            this.buttonBaselineInputBrowse.Size = new System.Drawing.Size(75, 23);
            this.buttonBaselineInputBrowse.TabIndex = 0;
            this.buttonBaselineInputBrowse.Text = "Browse...";
            this.buttonBaselineInputBrowse.UseVisualStyleBackColor = true;
            this.buttonBaselineInputBrowse.Click += new System.EventHandler(this.buttonBaselineInputBrowse_Click);
            // 
            // textBoxBaselineInput
            // 
            this.textBoxBaselineInput.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.textBoxBaselineInput.Location = new System.Drawing.Point(85, 21);
            this.textBoxBaselineInput.Name = "textBoxBaselineInput";
            this.textBoxBaselineInput.Size = new System.Drawing.Size(269, 20);
            this.textBoxBaselineInput.TabIndex = 1;
            // 
            // openFileDialogXml
            // 
            this.openFileDialogXml.Filter = "Xml files (*.xml)|*.xml|All files (*.*)|*.*";
            // 
            // buttonCreateBaseline
            // 
            this.buttonCreateBaseline.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonCreateBaseline.Location = new System.Drawing.Point(6, 47);
            this.buttonCreateBaseline.Name = "buttonCreateBaseline";
            this.buttonCreateBaseline.Size = new System.Drawing.Size(429, 23);
            this.buttonCreateBaseline.TabIndex = 4;
            this.buttonCreateBaseline.Text = "Create baseline";
            this.buttonCreateBaseline.UseVisualStyleBackColor = true;
            this.buttonCreateBaseline.Click += new System.EventHandler(this.buttonCreateBaseline_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(465, 444);
            this.Controls.Add(this.groupBoxBaseline);
            this.Controls.Add(this.groupBoxMetaInfo);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxOutputDir);
            this.Controls.Add(this.buttonOutputDirBrowse);
            this.Name = "MainForm";
            this.Text = "Greis Reference Parser";
            this.groupBoxMetaInfoInput.ResumeLayout(false);
            this.groupBoxMetaInfoInput.PerformLayout();
            this.groupBoxMetaInfo.ResumeLayout(false);
            this.groupBoxBaseline.ResumeLayout(false);
            this.groupBoxBaseline.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonOutputDirBrowse;
        private System.Windows.Forms.TextBox textBoxOutputDir;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxInputText;
        private System.Windows.Forms.Button buttonCreateMetaInfo;
        private System.Windows.Forms.SaveFileDialog saveFileDialogXml;
        private System.Windows.Forms.GroupBox groupBoxMetaInfoInput;
        private System.Windows.Forms.RadioButton radioButtonText;
        private System.Windows.Forms.RadioButton radioButtonFile;
        private System.Windows.Forms.TextBox textBoxMetaInfoInput;
        private System.Windows.Forms.Button buttonMetaInfoInputBrowse;
        private System.Windows.Forms.OpenFileDialog openFileDialogAny;
        private System.Windows.Forms.FolderBrowserDialog theFolderBrowserDialog;
        private System.Windows.Forms.GroupBox groupBoxMetaInfo;
        private System.Windows.Forms.GroupBox groupBoxBaseline;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button buttonBaselineInputBrowse;
        private System.Windows.Forms.TextBox textBoxBaselineInput;
        private System.Windows.Forms.OpenFileDialog openFileDialogXml;
        private System.Windows.Forms.Button buttonCreateBaseline;
    }
}

