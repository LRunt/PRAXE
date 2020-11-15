using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Piskvorky
{
    public partial class Form1 : Form
    {
        private Vypocty vypocet;
        private int velikostpolicka = 20;

        private Vypocty Vypocet
        {
            get
            {
                if (vypocet == null)
                    vypocet = new Vypocty(velikostpolicka);
                return vypocet;
            }
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Close();    //Zavírá program
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Informace oprogramu = new Informace();  //Vyskočí okénko s informacemi o produktu
            oprogramu.ShowDialog();
        }

    }
}
