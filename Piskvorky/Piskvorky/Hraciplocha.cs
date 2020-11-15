using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Piskvorky
{
    public partial class Hraciplocha : UserControl
    {
        private int velikost = 19;              //počet políček
        private int velikostpolicka = 20;       //velikost políčka v pixelech
        private Color barvamrize = Color.Black; //barva mřížky
        private Color barvaX = Color.Red;       //barva, kterou se bude vykreslovat křížek
        private Color barvaO = Color.Blue;      //barva, kterou se bude vykreslovat kolečko
        private Gamepiece hrac = Gamepiece.X;   //hráč, který začína (X)
        private Vypocty vypocet;
        private int a = 0;                      //počet figurek ve sloupci
        private int b = 0;
        private int c = 0;
        private int d = 0;
        private int f = 0;
        private int g = 0;
        private int h = 0;
        private int i = 0;
        private int j = 0;
        private int k = 0;
        private int l = 0;
        private int m = 0;
        private int n = 0;
        private int o = 0;
        private int p = 0;
        private int q = 0;
        private int r = 0;
        private int s = 0;
        private int t = 0;
        private int u = 0;
        public int w = 20 * 20;                   //počet políček v mřížce

        private Vypocty Vypocet
        {
            get
            {
                if (vypocet == null)
                    vypocet = new Vypocty(velikostpolicka);
                return vypocet;
            }
        }

        private Gamepiece Protihrac     //střídání hráčů
        {
            get
            {
                if (hrac == Gamepiece.X) return Gamepiece.O;    //když hrál X, vracím O
                if (hrac == Gamepiece.O) return Gamepiece.X;    //když hrál O, vracím X
                throw new Exception("Prázdné pole není hráč");  //Ošetření výjimky
            }
        }

        public int Velikost                    // aby se dala měnit velikost dynamicky 
        {
            get { return velikost; }
            set
            {
                velikost = value;
                Refresh();
            }
        }

        public int Velikostpolicka             // aby se dala měnit velikostpolicka dynamicky
        {
            get { return velikostpolicka; }
            set
            {
                velikostpolicka = value;
                Refresh();
            }
        }

        public Color Barvamrize                 // aby se dala měnit Barvamříže dynamicky
        {
            get { return barvamrize; }
            set
            {
                barvamrize = value;
                Refresh();
            }
        }

        #region pera
        private Pen pero;       //nové pero
        public Pen Pero
        {
            get
            {
                if (pero == null)
                    pero = new Pen(barvamrize);
                return pero;
            }
        }

        private Pen peroX;       //nové pero
        public Pen PeroX
        {
            get
            {
                if (peroX == null)
                    peroX = new Pen(barvaX, 1);
                return peroX;
            }
        }

        private Pen peroO;       //nové pero
        public Pen PeroO
        {
            get
            {
                if (peroO == null)
                    peroO = new Pen(barvaO, 1);
                return peroO;
            }
            #endregion pera

        }

        public Hraciplocha()
        {
            InitializeComponent();
        }

        private void Hraciplocha_Paint(object sender, PaintEventArgs e)         //Vykresluje mříž a X nebo O
        {
            Nakresli(e.Graphics);
            DrawPieces(e.Graphics);
        }

        private void Nakresli(Graphics g)
        {
            for (int i = 0; i <= velikost; i++)                //cyklus aby tabulka byla velká  velikost*velikost
            {
                pero = new Pen(barvamrize, 1);
                g.DrawLine(pero, 0, i * velikostpolicka, velikost * velikostpolicka, i * velikostpolicka);      //Horizontální čáry mřížky
                g.DrawLine(pero, i * velikostpolicka, 0, i * velikostpolicka, velikost * velikostpolicka);      //Vertikální čáry mřížky
            }
        }
        public void DrawPieces(Graphics g)  //vykreslení značek (figurek X a O)
        {
            for (int x = 0; x < velikostpolicka; x++)
                for (int y = 0; y < velikostpolicka; y++)
                    Nakresliznak(g, Vypocet.Piecesonboard[x, y], x, y);
                    
        }
        private void Nakresliznak(Graphics g, Gamepiece piece, int x, int y)
        {
            if (!Vypocet.Jevrozmezi(x, y))  //Zkouším jestli je vykreslované pole v hracím poly
                throw new Exception("Souřadnice jsou mimo hrací plochu"); //Ošetření výjimky
            if (piece== Gamepiece.X)
            {
                g.DrawLine(PeroX, x * velikostpolicka + 1, y * velikostpolicka + 1, x * velikostpolicka + velikostpolicka - 1, y * velikostpolicka + velikostpolicka - 1); //kreslím 1. čáru křížku (Z levého horního rohu do dolního pravého rohu) 
                g.DrawLine(PeroX, x * velikostpolicka + 1, y * velikostpolicka + velikostpolicka - 1, x * velikostpolicka + velikostpolicka - 1, y * velikostpolicka + 1); //kreslím 2. čáru křížku (Z levého dolního rohu do horního pravého rohu) 
            }
            if (piece==Gamepiece.O)
            {
                g.DrawEllipse(PeroO, x * velikostpolicka + 1, y * velikostpolicka + 1, velikostpolicka - 2, velikostpolicka - 2); //kreslím kolečko
            }
        }

        private void Hraciplocha_MouseClick(object sender, MouseEventArgs e)
        {
            int x = e.X / velikostpolicka;  //Zjišťuji souřadnici kliknutí x
            int y = e.Y / velikostpolicka;  //Zjišťuji souřadnici klisnutí y
            if (!Vypocet.Jevrozmezi(x,y))   //testuji jsetli se kliklo do mřížky
                return;
            if (x==0)                  //Testuji jestli se kliklo do prvního sloupečku
            {
                y = (velikost-1) - a;                    //nastavuji y aby bylo jako nejnižší volné pole v mřížce
                a = a + 1;                               //zaznamenávám že je obsazeno další políčko
                if (y <= -1)                             //testuji jestli je sloupec plný
                {
                    MessageBox.Show("Sloupec je plný"); //když je sloupec plný vyskoší okénko
                    return;                             //informaci posílám do výpočtů
                }
                else
                {
                    w = w - 1;      //když není sloupec plný zaznamenávám, že je o jedno volné políčko méně (identifikace remízy)
                }
            }
            if (x == 1)
            {
                y = (velikost - 1) - b;
                b = b + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            if (x == 2)
            {
                y = (velikost - 1) - c;
                c = c + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            if (x == 3)
            {
                y = (velikost - 1) - d;
                d = d + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            if (x == 4)
            {
                y = (velikost - 1) - f;
                f = f + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            if (x == 5)
            {
                y = (velikost - 1) - g;
                g = g + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            if (x == 6)
            {
                y = (velikost - 1) - h;
                h = h + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            if (x == 7)
            {
                y = (velikost - 1) - i;
                i = i + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            if (x == 8)
            {
                y = (velikost - 1) - j;
                j = j + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            if (x == 9)
            {
                y = (velikost - 1) - k;
                k = k + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            if (x == 10)
            {
                y = (velikost - 1) - l;
                l = l + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            if (x == 11)
            {
                y = (velikost - 1) - m;
                m = m + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            if (x == 12)
            {
                y = (velikost - 1) - n;
                n = n + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            if (x == 13)
            {
                y = (velikost - 1) - o;
                o = o + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            if (x == 14)
            {
                y = (velikost - 1) - p;
                p = p + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            if (x == 15)
            {
                y = (velikost - 1) - q;
                q = q + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            if (x == 16)
            {
                y = (velikost - 1) - r;
                r = r + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            if (x == 17)
            {
                y = (velikost - 1) - s;
                s = s + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            if (x == 18)
            {
                y = (velikost - 1) - t;
                t = t + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            if (x == 19)
            {
                y = (velikost - 1) - u;
                u = u + 1;
                if (y <= -1)
                {
                    MessageBox.Show("Sloupec je plný");
                    return;
                }
                else
                {
                    w = w - 1;
                }
            }
            Vysledek vysledekhry = Vypocet.Pridejfigurku(x, y, hrac);   //zaznamenávám x souřadnici, y souřadnici, a hráče (X nebo O)
            Refresh();                                                  //Zapisuje figurku (obnovuje komponentu)
            if (vysledekhry == Vysledek.Vyhra)                          //testuji jestli vypočet nezaznamenal výhru
                MessageBox.Show("Vyhrál hráč který měl: " + hrac);      //když zjistím, že někdo vyhrál vyskočí okénko
            if (w == 0)                                                 //testuji jestli je ještě nejaké políčko volné
                MessageBox.Show("Remíza, žádný z hráčů nevyhrává");     //když zjistím, že žádné políčko není volné, vyskočí okénko remíza
            hrac = Protihrac; //střídání X a O
        }

        private void Hraciplocha_Load(object sender, EventArgs e)
        {

        }
    }
}
