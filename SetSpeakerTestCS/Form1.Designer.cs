namespace SetSpeakerTestCS
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.MainMenu mainMenu1;

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
            this.mainMenu1 = new System.Windows.Forms.MainMenu();
            this.btnNormal1 = new System.Windows.Forms.Button();
            this.btnSpeaker1 = new System.Windows.Forms.Button();
            this.btnNormal2 = new System.Windows.Forms.Button();
            this.btnSpeaker2 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btnNormal1
            // 
            this.btnNormal1.Location = new System.Drawing.Point(53, 42);
            this.btnNormal1.Name = "btnNormal1";
            this.btnNormal1.Size = new System.Drawing.Size(125, 33);
            this.btnNormal1.TabIndex = 0;
            this.btnNormal1.Text = "Normal";
            // 
            // btnSpeaker1
            // 
            this.btnSpeaker1.Location = new System.Drawing.Point(53, 81);
            this.btnSpeaker1.Name = "btnSpeaker1";
            this.btnSpeaker1.Size = new System.Drawing.Size(125, 33);
            this.btnSpeaker1.TabIndex = 0;
            this.btnSpeaker1.Text = "Speaker";
            // 
            // btnNormal2
            // 
            this.btnNormal2.Location = new System.Drawing.Point(53, 167);
            this.btnNormal2.Name = "btnNormal2";
            this.btnNormal2.Size = new System.Drawing.Size(125, 33);
            this.btnNormal2.TabIndex = 0;
            this.btnNormal2.Text = "Normal";
            // 
            // btnSpeaker2
            // 
            this.btnSpeaker2.Location = new System.Drawing.Point(53, 206);
            this.btnSpeaker2.Name = "btnSpeaker2";
            this.btnSpeaker2.Size = new System.Drawing.Size(125, 33);
            this.btnSpeaker2.TabIndex = 0;
            this.btnSpeaker2.Text = "Speaker";
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(19, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(158, 19);
            this.label1.Text = "using WAV interface:";
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(20, 145);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(158, 19);
            this.label2.Text = "using ossvcs interface:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(96F, 96F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Dpi;
            this.AutoScroll = true;
            this.ClientSize = new System.Drawing.Size(240, 268);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btnSpeaker2);
            this.Controls.Add(this.btnNormal2);
            this.Controls.Add(this.btnSpeaker1);
            this.Controls.Add(this.btnNormal1);
            this.Menu = this.mainMenu1;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnNormal1;
        private System.Windows.Forms.Button btnSpeaker1;
        private System.Windows.Forms.Button btnNormal2;
        private System.Windows.Forms.Button btnSpeaker2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
    }
}

