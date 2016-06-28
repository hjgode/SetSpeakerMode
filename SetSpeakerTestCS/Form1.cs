using System;
using System.Linq;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using System.Runtime.InteropServices;

namespace SetSpeakerTestCS
{
    public partial class Form1 : Form
    {
        //using DeviceIoControl with WAV device
        [DllImport("SetSpeakerMode2.dll", EntryPoint = "ToggleSpeakerPhone")]
        extern static int ToggleSpeakerPhone(bool bEnable);

        // using undocumented ossvc functions
        [DllImport("SetSpeakerMode2.dll", EntryPoint = "ToggleSpeakerPhone2")]
        extern static int ToggleSpeakerPhone2(bool bEnable);

        public Form1()
        {
            InitializeComponent();
        }

        private void btnNormal1_Click(object sender, EventArgs e)
        {
            ToggleSpeakerPhone(false);
        }

        private void btnSpeaker1_Click(object sender, EventArgs e)
        {
            ToggleSpeakerPhone(true);
        }

        private void btnNormal2_Click(object sender, EventArgs e)
        {
            ToggleSpeakerPhone2(false);

        }

        private void btnSpeaker2_Click(object sender, EventArgs e)
        {
            ToggleSpeakerPhone2(true);

        }
    }
}