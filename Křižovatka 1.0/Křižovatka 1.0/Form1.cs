using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace Křižovatka_1._0
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        int mode = 0;
        int noc = 0;
        int den = 0;
        private class K8055D_dll
        {
            [DllImport("K8055D.dll")] //otevírání spojení s kartou
            public static extern int OpenDevice(int CardAddress);
            [DllImport("K8055D.dll")]
            public static extern void CloseDevice();
            [DllImport("K8055D.dll")]
            public static extern void WriteAllDigital(int Data);
            [DllImport("K8055D.dll")]
            public static extern bool ReadDigitalChannel(int Channel);
            [DllImport("K8055D.dll")]
            public static extern int SetCurrentDevice(int lngCardAddress);
        }

        private void Start()
        {
            AboutBox1 info = new AboutBox1(); //Zobrazení informací o programu
            info.ShowDialog();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            Close(); //Zavření aplikace
        }

        private void button2_Click(object sender, EventArgs e)
        {
            AboutBox1 info = new AboutBox1(); //Zobrazení informací o programu
            info.ShowDialog();
        }

        private void timer1_Tick(object sender, EventArgs e) //Zobrazování stavů každé 2s jeden stav
        {           
            if (mode == 2)
            {
                switch (noc) //noční režim
                {
                    case 0: //Všechny světla vypnuty
                        K8055D_dll.SetCurrentDevice(0);
                        K8055D_dll.WriteAllDigital(00000000);
                        K8055D_dll.SetCurrentDevice(1);
                        K8055D_dll.WriteAllDigital(00000000);
                        button4.BackColor = Color.Black;
                        button16.BackColor = Color.Black;
                        button19.BackColor = Color.Black;
                        button22.BackColor = Color.Black;
                        button25.BackColor = Color.Black;
                        button37.BackColor = Color.Black;
                        noc = noc + 1;
                        break;
                    case 1: //Svítí všechny žlutá světla
                        button4.BackColor = Color.Yellow;
                        button16.BackColor = Color.Yellow;
                        button19.BackColor = Color.Yellow;
                        button22.BackColor = Color.Yellow;
                        button25.BackColor = Color.Yellow;
                        button37.BackColor = Color.Yellow;
                        K8055D_dll.SetCurrentDevice(0);
                        K8055D_dll.WriteAllDigital(01000000);
                        K8055D_dll.SetCurrentDevice(1);
                        K8055D_dll.WriteAllDigital(01000000);
                        noc = 0;
                        break;
                }    
            }
            if (mode==1)
            {
                switch (den)  //denní režim
                {
                    case 0: //Připrav(čevená a žlutá) se hlavní rovně a doprava, zelená chodci vedlejší, ostatní čevená 
                        K8055D_dll.SetCurrentDevice(0);
                        K8055D_dll.WriteAllDigital(00010110);
                        K8055D_dll.SetCurrentDevice(1);
                        K8055D_dll.WriteAllDigital(01100001);
                        button9.BackColor = Color.Lime;
                        button8.BackColor = Color.Lime;
                        button32.BackColor = Color.Lime;
                        button33.BackColor = Color.Lime;
                        button11.BackColor = Color.Red;
                        button13.BackColor = Color.Red;
                        button29.BackColor = Color.Red;
                        button27.BackColor = Color.Red;
                        button17.BackColor = Color.Red;
                        button26.BackColor = Color.Red;
                        button23.BackColor = Color.Red;
                        button20.BackColor = Color.Red;
                        button3.BackColor = Color.Red;
                        button36.BackColor = Color.Red;
                        button25.BackColor = Color.Yellow;
                        button16.BackColor = Color.Yellow;
                        button4.BackColor = Color.Black;
                        button37.BackColor = Color.Black;
                        button14.BackColor = Color.Black;
                        button30.BackColor = Color.Black;
                        button12.BackColor = Color.Black;
                        button28.BackColor = Color.Black;
                        button7.BackColor = Color.Black;
                        button10.BackColor = Color.Black;
                        button31.BackColor = Color.Black;
                        button34.BackColor = Color.Black;
                        den = den + 1;
                        break;
                    case 1: //Zelená hlavní rovně a doprava, zelená chodci vedlejší ostatní červená
                        K8055D_dll.SetCurrentDevice(0);
                        K8055D_dll.WriteAllDigital(00010110);
                        K8055D_dll.SetCurrentDevice(1);
                        K8055D_dll.WriteAllDigital(10000001);
                        button17.BackColor = Color.Black;
                        button26.BackColor = Color.Black;
                        button25.BackColor = Color.Black;
                        button16.BackColor = Color.Black;
                        button15.BackColor = Color.Lime;
                        button24.BackColor = Color.Lime;
                        den = den + 1;
                        break;
                    case 2: //Žlutá hlavní rovně a doprava, zelená chodci vedlejší ostatní červená
                        K8055D_dll.SetCurrentDevice(0);
                        K8055D_dll.WriteAllDigital(00010110);
                        K8055D_dll.SetCurrentDevice(1);
                        K8055D_dll.WriteAllDigital(01000001);
                        button15.BackColor = Color.Black;
                        button24.BackColor = Color.Black;
                        button25.BackColor = Color.Yellow;
                        button16.BackColor = Color.Yellow;
                        den = den + 1;
                        break;
                    case 3: //Připrav se hlavní doleva, ostatní červená 
                        K8055D_dll.SetCurrentDevice(0);
                        K8055D_dll.WriteAllDigital(00010101);
                        K8055D_dll.SetCurrentDevice(1);
                        K8055D_dll.WriteAllDigital(00100011);
                        button9.BackColor = Color.Black;
                        button8.BackColor = Color.Black;
                        button32.BackColor = Color.Black;
                        button33.BackColor = Color.Black;
                        button7.BackColor = Color.Red;
                        button10.BackColor = Color.Red;
                        button31.BackColor = Color.Red;
                        button34.BackColor = Color.Red;
                        button19.BackColor = Color.Yellow;
                        button22.BackColor = Color.Yellow;
                        button25.BackColor = Color.Black;
                        button16.BackColor = Color.Black;
                        button17.BackColor = Color.Red;
                        button26.BackColor = Color.Red;
                        den = den + 1;
                        break;
                    case 4: //Zelená hlavní doleva, Zelená vedlejší doprava, ostatní červená
                        K8055D_dll.SetCurrentDevice(0);
                        K8055D_dll.WriteAllDigital(01010101);
                        K8055D_dll.SetCurrentDevice(1);
                        K8055D_dll.WriteAllDigital(00100100);
                        button5.BackColor = Color.Lime;
                        button35.BackColor = Color.Lime;
                        button23.BackColor = Color.Black;
                        button20.BackColor = Color.Black;
                        button19.BackColor = Color.Black;
                        button22.BackColor = Color.Black;
                        button21.BackColor = Color.Lime;
                        button18.BackColor = Color.Lime;
                        den = den + 1;
                        break;
                    case 5: //Žlutá hlavní doleva, zelená vedlejší, ostatní červená
                        K8055D_dll.SetCurrentDevice(0);
                        K8055D_dll.WriteAllDigital(01010101);
                        K8055D_dll.SetCurrentDevice(1);
                        K8055D_dll.WriteAllDigital(00100010);
                        button21.BackColor = Color.Black;
                        button18.BackColor = Color.Black;
                        button19.BackColor = Color.Yellow;
                        button22.BackColor = Color.Yellow;
                        den = den + 1;
                        break;
                    case 6: //Připrav se vedlejší, hlavní chodci zelená, ostatní červená
                        K8055D_dll.SetCurrentDevice(0);
                        K8055D_dll.WriteAllDigital(01111001);
                        K8055D_dll.SetCurrentDevice(1);
                        K8055D_dll.WriteAllDigital(00100001);
                        button19.BackColor = Color.Black;
                        button22.BackColor = Color.Black;
                        button11.BackColor = Color.Black;
                        button13.BackColor = Color.Black;
                        button29.BackColor = Color.Black;
                        button27.BackColor = Color.Black;
                        button14.BackColor = Color.Lime;
                        button30.BackColor = Color.Lime;
                        button12.BackColor = Color.Lime;
                        button28.BackColor = Color.Lime;
                        button4.BackColor = Color.Yellow;
                        button37.BackColor = Color.Yellow;
                        button23.BackColor = Color.Red;
                        button20.BackColor = Color.Red;
                        den = den + 1;
                        break;
                    case 7: //Zelená vedlejší, hlavní chodci zelená, ostatní červená
                        K8055D_dll.SetCurrentDevice(0);
                        K8055D_dll.WriteAllDigital(10001001);
                        K8055D_dll.SetCurrentDevice(1);
                        K8055D_dll.WriteAllDigital(00100001);
                        button3.BackColor = Color.Black;
                        button36.BackColor = Color.Black;
                        button6.BackColor = Color.Lime;
                        button38.BackColor = Color.Lime;
                        button4.BackColor = Color.Black;
                        button37.BackColor = Color.Black;
                        button5.BackColor = Color.Black;
                        button35.BackColor = Color.Black;
                        den = den + 1;
                        break;
                    case 8: //Žlutá vedlejší, zelená chodci hlavní, ostatní červená
                        K8055D_dll.SetCurrentDevice(0);
                        K8055D_dll.WriteAllDigital(00101001);
                        K8055D_dll.SetCurrentDevice(1);
                        K8055D_dll.WriteAllDigital(00100001);
                        button6.BackColor = Color.Black;
                        button38.BackColor = Color.Black;
                        button4.BackColor = Color.Yellow;
                        button37.BackColor = Color.Yellow;
                        den = 0;
                        break;
                }
                    
            }
            if(mode==0)     //Když není vybrán žádný mód
            {
                button3.BackColor = Color.Black;
                button4.BackColor = Color.Black;
                button5.BackColor = Color.Black;
                button6.BackColor = Color.Black;
                button7.BackColor = Color.Black;
                button8.BackColor = Color.Black;
                button9.BackColor = Color.Black;
                button10.BackColor = Color.Black;
                button11.BackColor = Color.Black;
                button12.BackColor = Color.Black;
                button13.BackColor = Color.Black;
                button14.BackColor = Color.Black;
                button15.BackColor = Color.Black;
                button16.BackColor = Color.Black;
                button17.BackColor = Color.Black;
                button18.BackColor = Color.Black;
                button19.BackColor = Color.Black;
                button20.BackColor = Color.Black;
                button21.BackColor = Color.Black;
                button22.BackColor = Color.Black;
                button23.BackColor = Color.Black;
                button24.BackColor = Color.Black;
                button25.BackColor = Color.Black;
                button26.BackColor = Color.Black;
                button27.BackColor = Color.Black;
                button28.BackColor = Color.Black;
                button29.BackColor = Color.Black;
                button30.BackColor = Color.Black;
                button31.BackColor = Color.Black;
                button32.BackColor = Color.Black;
                button33.BackColor = Color.Black;
                button34.BackColor = Color.Black;
                button35.BackColor = Color.Black;
                button36.BackColor = Color.Black;
                button37.BackColor = Color.Black;
                button38.BackColor = Color.Black;
            }
        }

        private void button39_Click(object sender, EventArgs e) //Vyresetování všech "světel" v aplikaci
        {
            timer1.Stop();
            timer1.Start();
            button3.BackColor = Color.Black;
            button4.BackColor = Color.Black;
            button5.BackColor = Color.Black;
            button6.BackColor = Color.Black;
            button7.BackColor = Color.Black;
            button8.BackColor = Color.Black;
            button9.BackColor = Color.Black;
            button10.BackColor = Color.Black;
            button11.BackColor = Color.Black;
            button12.BackColor = Color.Black;
            button13.BackColor = Color.Black;
            button14.BackColor = Color.Black;
            button15.BackColor = Color.Black;
            button16.BackColor = Color.Black;
            button17.BackColor = Color.Black;
            button18.BackColor = Color.Black;
            button19.BackColor = Color.Black;
            button20.BackColor = Color.Black;
            button21.BackColor = Color.Black;
            button22.BackColor = Color.Black;
            button23.BackColor = Color.Black;
            button24.BackColor = Color.Black;
            button25.BackColor = Color.Black;
            button26.BackColor = Color.Black;
            button27.BackColor = Color.Black;
            button28.BackColor = Color.Black;
            button29.BackColor = Color.Black;
            button30.BackColor = Color.Black;
            button31.BackColor = Color.Black;
            button32.BackColor = Color.Black;
            button33.BackColor = Color.Black;
            button34.BackColor = Color.Black;
            button35.BackColor = Color.Black;
            button36.BackColor = Color.Black;
            button37.BackColor = Color.Black;
            button38.BackColor = Color.Black;
            mode = 0;
        }

        private void timer2_Tick(object sender, EventArgs e) //Vybírání dne nebo noci pomocí tlačítka na periferii
        {
            K8055D_dll.SetCurrentDevice(0);
            if (K8055D_dll.ReadDigitalChannel(1)) mode = 2;
            if (K8055D_dll.ReadDigitalChannel(0)) mode = 1;
        }

        private void button40_Click(object sender, EventArgs e) //Vybírání dne nebo noci pomocí tlačítka v aplikaci
        {
            if (radioButton1.Checked)
            {
                mode = 1;
            }
            if (radioButton2.Checked)
            {
                mode = 2;
            }
        }
    }
}
