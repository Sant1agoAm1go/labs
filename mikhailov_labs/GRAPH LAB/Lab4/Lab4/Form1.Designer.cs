namespace Lab4
{
    partial class Form1
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
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.numStart = new System.Windows.Forms.NumericUpDown();
            this.numEnd = new System.Windows.Forms.NumericUpDown();
            this.btnClear = new System.Windows.Forms.Button();
            this.tbResult = new System.Windows.Forms.TextBox();
            this.btnOstov = new System.Windows.Forms.Button();
            this.lblShortPath = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.numStart)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numEnd)).BeginInit();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(168, 31);
            this.button1.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(170, 37);
            this.button1.TabIndex = 0;
            this.button1.Text = "Кратчайший путь";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.btnShortPath_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(21, 184);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(44, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Начало";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(18, 234);
            this.label2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(38, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Конец";
            // 
            // numStart
            // 
            this.numStart.Location = new System.Drawing.Point(20, 199);
            this.numStart.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.numStart.Maximum = new decimal(new int[] {
            6,
            0,
            0,
            0});
            this.numStart.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numStart.Name = "numStart";
            this.numStart.Size = new System.Drawing.Size(92, 20);
            this.numStart.TabIndex = 6;
            this.numStart.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // numEnd
            // 
            this.numEnd.Location = new System.Drawing.Point(20, 250);
            this.numEnd.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.numEnd.Maximum = new decimal(new int[] {
            7,
            0,
            0,
            0});
            this.numEnd.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numEnd.Name = "numEnd";
            this.numEnd.Size = new System.Drawing.Size(92, 20);
            this.numEnd.TabIndex = 7;
            this.numEnd.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(18, 455);
            this.btnClear.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(89, 27);
            this.btnClear.TabIndex = 8;
            this.btnClear.Text = "Очистить";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // tbResult
            // 
            this.tbResult.Location = new System.Drawing.Point(18, 289);
            this.tbResult.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.tbResult.Multiline = true;
            this.tbResult.Name = "tbResult";
            this.tbResult.ReadOnly = true;
            this.tbResult.Size = new System.Drawing.Size(92, 45);
            this.tbResult.TabIndex = 9;
            this.tbResult.Visible = false;
            // 
            // btnOstov
            // 
            this.btnOstov.Location = new System.Drawing.Point(359, 31);
            this.btnOstov.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.btnOstov.Name = "btnOstov";
            this.btnOstov.Size = new System.Drawing.Size(170, 37);
            this.btnOstov.TabIndex = 10;
            this.btnOstov.Text = "Остов";
            this.btnOstov.UseVisualStyleBackColor = true;
            this.btnOstov.Click += new System.EventHandler(this.btnOstov_Click);
            // 
            // lblShortPath
            // 
            this.lblShortPath.AutoSize = true;
            this.lblShortPath.Location = new System.Drawing.Point(21, 150);
            this.lblShortPath.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lblShortPath.Name = "lblShortPath";
            this.lblShortPath.Size = new System.Drawing.Size(96, 13);
            this.lblShortPath.TabIndex = 11;
            this.lblShortPath.Text = "Кратчайший путь:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(680, 496);
            this.Controls.Add(this.lblShortPath);
            this.Controls.Add(this.btnOstov);
            this.Controls.Add(this.tbResult);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.numEnd);
            this.Controls.Add(this.numStart);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.MaximumSize = new System.Drawing.Size(855, 1022);
            this.Name = "Form1";
            this.Text = "GraphLab";
            ((System.ComponentModel.ISupportInitialize)(this.numStart)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numEnd)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.NumericUpDown numStart;
        private System.Windows.Forms.NumericUpDown numEnd;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.TextBox tbResult;
        private System.Windows.Forms.Button btnOstov;
        private System.Windows.Forms.Label lblShortPath;
    }
}

