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
        [DllImport("SetSpeakerMode.dll", EntryPoint = "ToggleSpeakerPhone")]
        extern static int ToggleSpeakerPhone(bool bEnable);

        [DllImport("SetSpeakerMode2.dll", EntryPoint = "ToggleSpeakerPhone")]
        extern static int ToggleSpeakerPhone2(bool bEnable);

        public Form1()
        {
            InitializeComponent();
        }
    }
}