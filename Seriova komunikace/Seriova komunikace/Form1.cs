using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace Seriova_komunikace
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        static SerialPort Port = new SerialPort();
        int cislo;
        private void button1_Click(object sender, EventArgs e)
        {
            Port.PortName = "COM3";     //nastavení portu
            Port.BaudRate = 4800;       //nastavení baudratu
            Port.DataBits = 8;          
            if (textBox1.Text=="")      //ošetření prázdného políčka
            {
                MessageBox.Show("Zadej číslo 0-9");
            }
            else
            {
                if(textBox1.Text=="0"|| textBox1.Text == "1" || textBox1.Text == "2" || textBox1.Text == "3" || textBox1.Text == "4" || textBox1.Text == "5" || textBox1.Text == "6" || textBox1.Text == "7" || textBox1.Text == "8" || textBox1.Text == "9") //mohou se zadat jen číslice
                {
                    Port.Open();                        //otevření komunikace
                    cislo = int.Parse(textBox1.Text);   //zjištění čísla z texboxu
                    Port.Write(cislo.ToString());       //posílání na port
                }
                else
                {
                    MessageBox.Show("Špatně zadaný text, zadejte číslo 0-9");
                }
            }
        }
    }
}
