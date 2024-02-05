using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Diagnostics; // kad butu galimas isvesti teksta i konsole.

namespace Pilnai_Veikiantis_ir_perdarytas
{
    public partial class Form1 : Form
    {


        List<Button> playerPositionButtons; // zaidejo mygtukai
        List<Button> enemyPositionButtons;  //kompiuterio mygtukai 

        Random rand = new Random(); // iniciopjamae atsitiktinio skaiciaus generavima

        int totalShips = 4; // laivu skaicius
        int round = 100; //ejimu skaicius
        int playerScore; // zaidejo taskai
        int enemyScore; // prieso taskai 




        public Form1()
        {
            InitializeComponent();
            RestartGame(); //naujo zaidimo metodas
        }

        private void EnemyPlayTimerEvent(object sender, EventArgs e)
        {

            if (playerPositionButtons.Count > 0 && round > 0)
            {
                round -= 1; // minusuojamas ejimas

                txtRounds.Text = "Ejimai: " + round; // formsuose atspausdinamas ejimu likutis

                int index = rand.Next(playerPositionButtons.Count); // atsitiktinis kompiuterio atakavimas

                if ((string)playerPositionButtons[index].Tag == "playerShip") 
                {
                    playerPositionButtons[index].BackgroundImage = Properties.Resources.fireIcon; // jeigu pataiko i laiva, tuomet udedamas fire iconas
                    enemyMove.Text = playerPositionButtons[index].Text; // atspausdinamas kokia koordinate pasirenka kompiuteirs
                    playerPositionButtons[index].Enabled = false; // jeigu pasirinko kazkoki mygtuka, jis bus isjungiamas
                    playerPositionButtons[index].BackColor = Color.DarkBlue;
                    playerPositionButtons.RemoveAt(index); // pasalinamas mygtukas kuris buvo pasirinktas
                    enemyScore += 1;
                    txtEnemy.Text = enemyScore.ToString();
                    EnemyPlayTimer.Stop();
                }
                else
                {
                    playerPositionButtons[index].BackgroundImage = Properties.Resources.missIcon; // jeigu nepataiko uzdedamas x iconas
                    enemyMove.Text = playerPositionButtons[index].Text; // aspausdinama koordinate
                    playerPositionButtons[index].Enabled = false; // isjungiamas mygtukas
                    playerPositionButtons[index].BackColor = Color.DarkBlue;
                    playerPositionButtons.RemoveAt(index); // pasalinamas is saraso
                    EnemyPlayTimer.Stop();
                }
            }

            if (round < 1 || enemyScore > 3 || playerScore > 3) // if statementas su keliomis salygomis su loginiu operatoriumi ||
            {

                if (playerScore > enemyScore)       
                {
                    MessageBox.Show("Jūs laimėjote", "Jūsų pergalė!");
                    RestartGame();
                }
                else if (enemyScore > playerScore)
                {
                    MessageBox.Show("Jūsų laivai buvo nuskandinti, jūs pralaimėjote!", "Pralaimėjote");
                    RestartGame();
                }
                else if (enemyScore == playerScore)
                {
                    MessageBox.Show("Niekas nelaimėjo, lygiosios", "Lygiosios");
                    RestartGame();
                }
            }



        }

        private void AttackButtonEvent(object sender, EventArgs e)
        {
            button2.Text = ("Per naują");
            if (EnemyLocationListBox.Text != "")
            {

                var attackPosition = EnemyLocationListBox.Text.ToLower(); //sukuriamas kintamasis ir priskiriama jam reiksme is Enemylocationlistbox kuri pasirenka zaidejas

                int index = enemyPositionButtons.FindIndex(a => a.Name == attackPosition); // ieskomas indeksas sarase enemypositionsbuttons kuris sutaps su attackPosition kintamojo reiksme

                if (enemyPositionButtons[index].Enabled && round > 0) // tikrinama ar mygtukas is saraso yra ijungtas ir ar ejimu skaicius yra >0
                {
                    round -= 1; //jeigu raundu skaicius>0 atimamas 1 is ejimu skaiciaus
                    txtRounds.Text = "Ejimai: " + round; // atspausdinamas ejimu likutis


                    if ((string)enemyPositionButtons[index].Tag == "enemyShip") //jeigu pataikoma
                    {

                        enemyPositionButtons[index].Enabled = false; // isjungiamas mygtukas
                        enemyPositionButtons[index].BackgroundImage = Properties.Resources.fireIcon; // udedamas iconas
                        enemyPositionButtons[index].BackColor = Color.DarkBlue;
                        playerScore += 1;
                        txtPlayer.Text = playerScore.ToString();
                        EnemyPlayTimer.Start();

                    }
                    else
                    {
                        enemyPositionButtons[index].Enabled = false; // jeigu nepataikoma isjungiama
                        enemyPositionButtons[index].BackgroundImage = Properties.Resources.missIcon; // uzdedamas miss iconas
                        enemyPositionButtons[index].BackColor = Color.DarkBlue;
                        EnemyPlayTimer.Start();
                     }
                }
        }
            else
            {
                MessageBox.Show("Pirma pasirinkite koordinates kurias atakuosite!");
            }
        }

        private void PlayerPositionButtonsEvent(object sender, EventArgs e)
        {

            if (totalShips > 0) // tikrinama ar dar yra laivu statymui
            {
                var button = (Button)sender; // gaunama nuoroda ant kurio buvo paspausta issiunciant ivikio senderi

                button.Enabled = false;
                button.Tag = "playerShip"; // uzdedama papildoma informacija .Tag
                button.BackColor = Color.Orange; // pasirinktam mygtukui pakeiciama spalva
                totalShips -= 1; 
            }

            if (totalShips == 0) // jeigu pastatyti visi laivai 
            {
                btnAttack.Enabled = true; //ijungiamas atakuoti mygtukas
                btnAttack.BackColor = Color.Red; // nudazmoas raudonai, o tekstas baltai 
                btnAttack.ForeColor = Color.White;

                txtHelp.Text = "2) Dabar pasirinkite koordinates kurias atakuosite!"; // zaidejo vedlio informacija
            }


        }


        private void RestartGame() // naujo zaidimo incijavimas
        {
            playerPositionButtons = new List<Button> { w1, w2, w3, w4, x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4 };//inicijuojami reiso mygtukai
            enemyPositionButtons = new List<Button> { a1, a2, a3, a4, b1, b2, b3, b4, c1, c2, c3, c4, d1, d2, d3, d4 };
            EnemyLocationListBox.Items.Clear();  
            EnemyLocationListBox.Text = null;     
            txtHelp.Text = "1) Pasirinkite " + totalShips + " skirtingas koordinates, kurios bus jūsų laivai!!"; //vedlio informacija
            for (int i = 0; i < enemyPositionButtons.Count; i++)
            {
                enemyPositionButtons[i].Enabled = true; // ijungiami visi mygtukai norint atakuoti prieso laivyna
                enemyPositionButtons[i].Tag = null; // nunulinami visi tag'ai
                enemyPositionButtons[i].BackColor = Color.White; // uzdedama pradine spalva
                enemyPositionButtons[i].BackgroundImage = null; 
                EnemyLocationListBox.Items.Add(enemyPositionButtons[i].Text);
            }
            for (int i = 0; i < playerPositionButtons.Count; i++) 
            {
                playerPositionButtons[i].Enabled = true;
                playerPositionButtons[i].Tag = null;
                playerPositionButtons[i].BackColor = Color.White; // nunulinamos visos mygtuku savybes
                playerPositionButtons[i].BackgroundImage = null;
            }
            playerScore = 0;
            enemyScore = 0;
            round = 10;
            totalShips = 4;
            txtPlayer.Text = playerScore.ToString();
            txtEnemy.Text = enemyScore.ToString();
            enemyMove.Text = "";
            btnAttack.Enabled = false; // pradine atakavimo kygtuko reiksme
            enemyLocationPicker();  // inicijuojama kompiuterio pasirenkama laivu vieta
        }

        private void enemyLocationPicker()
        {

            for (int i = 0; i < 4; i++) // nustamo kiek laivu tures prieso laivynas
            {
                int index = rand.Next(enemyPositionButtons.Count); // pasirenkamas atsitiktinis indeksas kuris bus vieta kur bus laivai

                if (enemyPositionButtons[index].Enabled == true && (string)enemyPositionButtons[index].Tag == null)
                {
                    enemyPositionButtons[index].Tag = "enemyShip"; // i pasirinktas vietas uzdedama papildoma informacija

                    Debug.WriteLine("Priešo pasirinkimas: " + enemyPositionButtons[index].Text); // testavimui, kad patikrinti ar viskas veikia pridedame biblioteka system.diagnostics. debug. funkcija leidzia atspausdinti i veikiancia konsole kokias koordinates priesas pasirinko
                }
                else
                {
                    index = rand.Next(enemyPositionButtons.Count); // jeigu salyga neivygdoma toliau naudojamas atsitiktinis indekso generavimas
                }
            }
        }

        private void txtEnemy_Click(object sender, EventArgs e)
        {

        }

        private void txtRounds_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("1) Žaidimo pradžioje žaidėjas pasirenka 4 laivu koordinates kuriose jis statys savo laivus." +
                "                        \n 2) Paspaudes mygtukus, kurie bus jo laivai, jis pasirenka laivo koordinate kurią jis atakuos. " +
                "                        \n 3) Pirmas sugriovęs 4 laivus žaidimą laimės." +
                "                        \n 4) Pasirinkus ne tą langelį arba norint žaisti per naują, spausti mygtukus (Per naują/Perstatyti)","Taisyklės");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            RestartGame();
        }
    }
}