using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Dil_A4_Runt_Lukas_E
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public static void pridejuzivatele(string id, string jmeno, string prijmeni, string pkniha, string filepath) //Ukládání uživatele
        {
            try
            {
                using (StreamWriter file = new StreamWriter(filepath, true)) //Ukládání do CSV(filepath=název souboru v debugu, true znamená, že se soubor nebude přepisovat) 
                {
                    file.WriteLine(id + ";" + jmeno + ";" + prijmeni + ";" + pkniha);
                }
            }
            catch (Exception ex) //"Chytání chyby"
            {
                throw new ApplicationException("Error", ex);
            }
        }
        public static void vypis(string idu, string jmeno, string prijmeni, string idk, string nazev, string autor,string cesta)
        {
            try
            {
                using (StreamWriter file = new StreamWriter(cesta, true)) //Ukládání do CSV(filepath=název souboru v debugu, true znamená, že se soubor nebude přepisovat)
                {
                    file.WriteLine("ID Uzivatele: "+idu);
                    file.WriteLine("Jmeno: " + jmeno+" " + prijmeni);
                    file.WriteLine("ID pujcene knihy: " + idk);
                    file.WriteLine("Nazev: " + nazev);
                    file.WriteLine("Autor: " + autor);
                }
            }
            catch (Exception ex) //"Chytání chyby"
            {
                throw new ApplicationException("Error", ex);
            }
        }
        public static void pridejknihu(string id, string nazev, string autor, string stav, string cesta) //Ukládání knihy
        {
            try
            {
                using (StreamWriter file = new StreamWriter(cesta, true)) //Ukládání do CSV(filepath=název souboru v debugu, true znamená, že se soubor nebude přepisovat)
                {
                    file.WriteLine(id + ";" + nazev + ";" + autor + ";" + stav);
                }
            }
            catch (Exception ex) //"Chytání chyby"
            {
                throw new ApplicationException("Error", ex);
            }
        }
        public static string[] ctiuzivatele(string znak, string filepath, int pozice) //Čtení uživatele z CSV souboru
        {
            pozice--; //Čtu z prvního sloupce, C# začíná počítat od nuly
            string[] recordnotfound = { "Uživatel nenalezen" }; //Když není uživatel nalezen
            try
            {
                string[] line = File.ReadAllLines(filepath); //Čte řádek po řádku
                for (int i = 0; i < line.Length; i++)
                {
                    string[] radek = line[i].Split(';'); //Rozdělení CSV textu na jednotlivé hodnoty, aby se ID oddělilo od jména..
                    string id = radek[0];
                    string jmeno = radek[1];
                    string prijmeni = radek[2];
                    if (najdi(znak, radek, pozice)) //Porovnávání ID(znak) na určitém řádnku v určitém sloupci
                    {
                        return radek; //Když je ID nalezeno, uloží se číslo řádku
                    }
                }
                return recordnotfound; //Když není ID nalezeno
            }
            catch (Exception ex) //"Chytání chyb"
            {
                throw new ApplicationException("Error", ex);
            }
        }
        public static string[] ctiknihu(string znk, string cesta, int pozce) //Čtení knihy z CSV souboru
        {
            pozce--; //Čtu z prvního sloupce, C# začíná počítat od nuly
            string[] zaznamnenalezen = { "Kniha nenalezena" }; //Když není kniha nalezena
            try
            {
                string[] linka = File.ReadAllLines(cesta); //Čte řádek po řádku
                for (int i = 0; i < linka.Length; i++)
                {
                    string[] rdek = linka[i].Split(';'); //Rozdělení CSV textu na jednotlivé hodnoty, aby se ID oddělilo od jména..
                    string id = rdek[0];
                    string nazev = rdek[1];
                    string autor = rdek[2];
                    if (najdi(znk, rdek, pozce)) //Porovnávání ID(znak) na určitém řádnku v určitém sloupci
                    {
                        return rdek; //Když je ID nalezeno, vypíše se řádek
                    }
                }
                return zaznamnenalezen; //Když není ID nalezeno
            }
            catch (Exception ex) //"Chytání chyb"
            {
                throw new ApplicationException("Error", ex);
            }
        }
        public static void prepis(string searchterm, string cesta, int positionofterm) //Přepisování hodnoty (mazání)
        {
            positionofterm--; //Čtu z prvního sloupce, C# začíná počítat od nuly
            string tempfile = "temp.csv"; //Soubor kam se budou ukládat hodnoty které nechci přepsat
            bool detected = false; //Ukazatel jsetli se bude hodnota přepisovat
            try
            {
                string[] lines = File.ReadAllLines(cesta); //Čte řádek po řádku, hledání ID které má být přepsáno
                for (int i = 0; i < lines.Length; i++)
                {
                    string[] fields = lines[i].Split(';'); //Rozdělení CSV textu na jednotlivé hodnoty, aby se ID oddělilo od jména..
                    if (!(najdi(searchterm, fields, positionofterm)) || detected)
                    {
                        pridejknihu(fields[0], fields[1], fields[2], fields[3], tempfile); //Když toto není požadovaná kniha, ukládám do pomocného souboru
                    }
                    else
                    {
                        detected = true; //když se ID shodu je s hledaným ID,požadované Id se neuloží do pomocného souboru
                    }
                }
                File.Delete(cesta); //Smazaní 
                File.Move(tempfile, cesta); //Nahrání pomocného souboru do požadovaného souboru
            }
            catch (Exception ex) //"Chytání chyb"
            {
                throw new ApplicationException("Error", ex);
            }
        }
        public static bool najdi(string znak, string[] zaznam, int pozice)  //Hledání zanaku
        {
            if (zaznam[pozice].Equals(znak))
            {
                return true; //Když se znak rovná požadovanému znaku 
            }
            return false; //Když se znak nerovná požadovanému znaku
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string a = string.Join("", ctiuzivatele(textBox1.Text, "uzivatel.csv", 1)); //Čtení ID z formu, porovnávání ID jestlim se už ID nevyskytuje v CSV souboru
            if (a == "Uživatel nenalezen") //Když není uživatel nalezen -> nový uživatel se uloží
            {
                pridejuzivatele(textBox1.Text, textBox2.Text, textBox3.Text, " ", "uzivatel.csv");   //Ukládání hodnot do CSV
                MessageBox.Show("Uživatel Uložen");
                textBox1.Clear();                                                                   //Vyčištění Teboxů v groupboxu Nový uživatel
                textBox2.Clear();
                textBox3.Clear();
            }
            else
            {
                MessageBox.Show("Id obsazeno");                //Oznámení chyby (V CSV souboru je stejné ID)
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox3.Clear(); //vyčistím textbox3 
            textBox3.Text = string.Join(";", ctiuzivatele(textBox5.Text, "uzivatel.csv", 1)); //Najdu uživatele a vypíšu do texboxu3
            string uzivatel = textBox3.Text;    //Uklásám text z textboxu do proměnné
            textBox3.Clear(); //čistím textbox3
            if (uzivatel == "Uživatel nenalezen") //když není ID nalezeno 
            {
                MessageBox.Show("Uživatel neexistuje");
                label7.Text = " ";                 //když byl předtím zobrazen uživatel zbyde po něm data -> vyčistím data
                label8.Text = " ";
                label20.Text = " ";
            }
            else
            {
                IList<string> uzivatele = new List<string>(); //ukládám uživatele do listu
                uzivatele.Add(uzivatel);
                string[] rozdeleno = uzivatel.Split(';');  //rozděluji text na jednotlivé části ID, Jméno....
                string id = rozdeleno[0];                  //ukládám jednotlivé části 
                string jmeno = rozdeleno[1];
                string prijmeni = rozdeleno[2];
                string pkniha = rozdeleno[3];
                label7.Text = jmeno;                        //vypisuji jednotlivé části
                label8.Text = prijmeni;
                label20.Text = pkniha;
            }
            textBox7.Clear();   //vyčistím textbox3
            textBox7.Text = string.Join(";", ctiknihu(textBox8.Text, "kniha.csv", 1));  //Najdu uživatele a vypíšu do texboxu3
            string kniha = textBox7.Text;       //Ukládám text z textboxu do proměnné
            textBox7.Clear();   //čistím textbox7
            if (kniha == "Kniha nenalezena") //když není ID nalezeno
            {
                MessageBox.Show("Kniha neexistuje");
                label15.Text = " ";             //když byl předtím zobrazen uživatel zbyde po něm data -> vyčistím data
                label16.Text = " ";
                label17.Text = " ";
            }
            else
            {
                IList<string> knihy = new List<string>();   //ukládám uživatele do listu
                knihy.Add(kniha);
                string[] rozdeleno = kniha.Split(';');       //rozděluji text na jednotlivé části ID, Jméno....
                string idk = rozdeleno[0];                   //ukládám jednotlivé části 
                string nazev = rozdeleno[1];
                string autor = rozdeleno[2];
                string stav = rozdeleno[3];
                label15.Text = nazev;                        //vypisuji jednotlivé části
                label16.Text = autor;
                label17.Text = stav;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string b = string.Join("", ctiknihu(textBox4.Text, "kniha.csv", 1)); //Čtení ID z formu, porovnávání ID jestlim se už ID nevyskytuje v CSV souboru
            if (b == "Kniha nenalezena")        //Když není uživatel nalezen -> nový uživatel se uloží
            {
                pridejknihu(textBox4.Text, textBox6.Text, textBox7.Text, "Dostupna", "kniha.csv"); //Ukládání hodnot do CSV
                MessageBox.Show("Kniha Uložena");
                textBox4.Clear();                               //vyčištění texboxu v groupboxu Nova kniha
                textBox6.Clear();
                textBox7.Clear();
            }
            else
            {
                MessageBox.Show("Id obsazeno");    //Oznámení chyby (V CSV souboru je stejné ID)
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (label17.Text == "Nedostupna") //Zkouší jestli náhodou není kniha půjčena
            {
                MessageBox.Show("Kniha nelze pujčit, protože je půjčená");
            }
            else
            {
                if (label20.Text != " ") //Zkouší jestli už uživatel nemá půjčenou nejakou knihu
                {
                    MessageBox.Show("Tento uživatel už má půjčenou nějakou jinou knihu");
                }
                else
                {
                    prepis(textBox8.Text, "kniha.csv", 1);  //přepisování(mazání) Záznamu knihy
                    pridejknihu(textBox8.Text, label15.Text, label16.Text, "Nedostupna", "kniha.csv"); //Přepisování záznamu knihy (založení nového řádku se změneným stavem)
                    MessageBox.Show("Kniha půjčena");
                    prepis(textBox5.Text, "uzivatel.csv", 1); //přepisování(mazání) yáznamu uzivatele
                    pridejuzivatele(textBox5.Text, label7.Text, label8.Text, textBox8.Text, "uzivatel.csv");    //Přepisování záznamu uzivatele (založení nového řádku s pujcenou knihou)
                    label20.Text = textBox8.Text; //Změněmí hodnot ve formu
                    label17.Text = "Nedostupna";
                }
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (label17.Text == "Dostupna") //Zkouška jestli je kniha pujcena
            {
                MessageBox.Show("Kniha nelze vratit, protože je v knihovně");
            }
            else
            {
                if (label20.Text != textBox8.Text) //Zkouska jestli má uzivatel pujcenou tuto knihu
                {
                    MessageBox.Show("Tento uživatel nemá půjčenou tuto knihu");
                }
                else
                {
                    prepis(textBox8.Text, "kniha.csv", 1);  //přepisování(mazání) Záznamu knihy
                    pridejknihu(textBox8.Text, label15.Text, label16.Text, "Dostupna", "kniha.csv");    //Přepisování záznamu knihy (založení nového řádku se změneným stavem)
                    MessageBox.Show("Kniha Vrácena");
                    prepis(textBox5.Text, "uzivatel.csv", 1); //přepisování(mazání)záznamu uzivatele
                    pridejuzivatele(textBox5.Text, label7.Text, label8.Text, " ", "uzivatel.csv"); //Přepisování záznamu uzivatele (založení nového řádku s půjčenou knihou)
                    label20.Text = " ";     //Změněmí hodnot ve formu
                    label17.Text = "Dostupna";
                }
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            string c = label20.Text;
            textBox8.Text = c;
            button2_Click(sender,e);
            if(textBox5.Text!=" ")
             {
                File.Delete("Vypis.txt");
                vypis(textBox5.Text, label7.Text, label8.Text, textBox8.Text, label16.Text, label15.Text, "Vypis.txt");
             }
        }

        private void groupBox3_Enter(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
