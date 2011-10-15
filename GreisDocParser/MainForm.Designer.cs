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
            this.buttonParse = new System.Windows.Forms.Button();
            this.saveFileDialogXml = new System.Windows.Forms.SaveFileDialog();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.radioButtonText = new System.Windows.Forms.RadioButton();
            this.radioButtonFile = new System.Windows.Forms.RadioButton();
            this.textBoxInputPath = new System.Windows.Forms.TextBox();
            this.buttonInputPathBrowse = new System.Windows.Forms.Button();
            this.openFileDialogAny = new System.Windows.Forms.OpenFileDialog();
            this.theFolderBrowserDialog = new System.Windows.Forms.FolderBrowserDialog();
            this.groupBox1.SuspendLayout();
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
            this.textBoxInputText.Size = new System.Drawing.Size(429, 164);
            this.textBoxInputText.TabIndex = 3;
            // 
            // buttonParse
            // 
            this.buttonParse.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonParse.Location = new System.Drawing.Point(12, 297);
            this.buttonParse.Name = "buttonParse";
            this.buttonParse.Size = new System.Drawing.Size(441, 23);
            this.buttonParse.TabIndex = 4;
            this.buttonParse.Text = "PARSE";
            this.buttonParse.UseVisualStyleBackColor = true;
            this.buttonParse.Click += new System.EventHandler(this.buttonParse_Click);
            // 
            // saveFileDialogXml
            // 
            this.saveFileDialogXml.Filter = "XML files|*.xml|All files|*.*";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.radioButtonText);
            this.groupBox1.Controls.Add(this.radioButtonFile);
            this.groupBox1.Controls.Add(this.textBoxInputText);
            this.groupBox1.Controls.Add(this.textBoxInputPath);
            this.groupBox1.Controls.Add(this.buttonInputPathBrowse);
            this.groupBox1.Location = new System.Drawing.Point(12, 56);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(441, 235);
            this.groupBox1.TabIndex = 5;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Input";
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
            // textBoxInputPath
            // 
            this.textBoxInputPath.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.textBoxInputPath.Location = new System.Drawing.Point(57, 19);
            this.textBoxInputPath.Name = "textBoxInputPath";
            this.textBoxInputPath.Size = new System.Drawing.Size(297, 20);
            this.textBoxInputPath.TabIndex = 1;
            // 
            // buttonInputPathBrowse
            // 
            this.buttonInputPathBrowse.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonInputPathBrowse.Location = new System.Drawing.Point(360, 17);
            this.buttonInputPathBrowse.Name = "buttonInputPathBrowse";
            this.buttonInputPathBrowse.Size = new System.Drawing.Size(75, 23);
            this.buttonInputPathBrowse.TabIndex = 0;
            this.buttonInputPathBrowse.Text = "Browse...";
            this.buttonInputPathBrowse.UseVisualStyleBackColor = true;
            this.buttonInputPathBrowse.Click += new System.EventHandler(this.buttonInputPathBrowse_Click);
            // 
            // openFileDialogAny
            // 
            this.openFileDialogAny.Filter = "All files|*.*";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(465, 332);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.buttonParse);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxOutputDir);
            this.Controls.Add(this.buttonOutputDirBrowse);
            this.Name = "MainForm";
            this.Text = "Greis Reference Parser";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonOutputDirBrowse;
        private System.Windows.Forms.TextBox textBoxOutputDir;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxInputText;
        private System.Windows.Forms.Button buttonParse;
        private System.Windows.Forms.SaveFileDialog saveFileDialogXml;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton radioButtonText;
        private System.Windows.Forms.RadioButton radioButtonFile;
        private System.Windows.Forms.TextBox textBoxInputPath;
        private System.Windows.Forms.Button buttonInputPathBrowse;
        private System.Windows.Forms.OpenFileDialog openFileDialogAny;
        private System.Windows.Forms.FolderBrowserDialog theFolderBrowserDialog;
    }
}

