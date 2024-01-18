#include "headeris.h"

Studentas::Studentas(int numeris) : numeris(numeris) {
vardas = "Vardas" + to_string(numeris); //cia identifikuojame kaip faile bus surasyti duomenys, (vardas1,2... pavarde1,2.. numeris...)  
pavarde = "Pavarde" + to_string(numeris);
galutinisBalas = static_cast<double>(rand() % 101) / 10.0; // cia naudojame funkcija rand is bibliotekos <cstdlib> kad gautme skaiciu nuo 0 iki 10. Naudoju static_cast kad iskarto butu konvertuojami skaiciai i double kintamaji.
    }

    failo_kurimas::failo_kurimas() {
        dydziai = { 1000, 10000, 100000, 1000000 }; // irasu kiekiai jeigu reik dar papildomo kiekio irasu, galima prideti skaiciu
    }

    void failo_kurimas::SukurtiFailus() {
        for (int dydis : dydziai) {
            string kursiokai = "studentai_" + to_string(dydis) + ".txt";

            if (!ArEgzistuoja(kursiokai)) {
                cout << "\nVykdomas studentu " << kursiokai << " failu generavimas" << endl;

                auto pradzia = high_resolution_clock::now();
                ofstream kurisioku_failas(kursiokai);

                for (int i = 1; i <= dydis; ++i) {
                    Studentas studentas(i);
                    kurisioku_failas << studentas.GetVardas() << " " << studentas.GetPavarde() << " " << studentas.GetGalutinisBalas() << "\n";
                }

                kurisioku_failas.close();
                auto pabaiga = high_resolution_clock::now();
                auto trukme = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - pradzia);

                // Display file size
                ifstream file(kursiokai, std::ifstream::ate | std::ifstream::binary);
                double file_size_mb = static_cast<double>(file.tellg()) / (1024 * 1024);  // Convert to megabytes
                file.close();

                cout << "Sukurtas failas: " << kursiokai << " (truko " << fixed << setprecision(4) << trukme.count() << " s, " << fixed << setprecision(2) << file_size_mb << " MB)\n" << endl;
            }
            else {
                cout << "Kadangi failas " << kursiokai << " jau yra sukurtas, todel jis bus tik nuskaitomas." << endl;
            }
        }
        cout << "\nPradedamas studentu rusiavimas\n" << endl;
    }

    void failo_kurimas::kieteku_suskirstymas() {
        auto pradzia = high_resolution_clock::now();// laikmacio startavimas 

        for (int dydis : dydziai) { // nurodome naujaji kintamaji (dydis) kuris tures tokius pacius elementus kaip ir dydziai
            string kursiokai = "studentai_" + to_string(dydis) + ".txt"; //kuriamas string tipo kintamasis kuris yra studentu ir ju irasu tekstinis failas
            ifstream nuskait(kursiokai);//skaitymas is studentu failu 
            string kietiakaiFailas = "kietiakai_" + to_string(dydis) + ".txt"; // naudojame tapati principa kaip ir su kursioku tekstiniais failais
            ofstream kietiakaiOutput(kietiakaiFailas); // i kietiakiaiFailas bus irasyti duomenys, kuriu salygos yra apacioje
            string vardas, pavarde;
            double balas; //// inicializuojame kintamuosius 

            while (nuskait >> vardas >> pavarde >> balas) { //cia zymime kokie duomenys bus saugomi i tam tikrus kintamuosius (vardas i vardo, pavarde i pavardes ir tt{
                if (balas >= 5.0) { ///sukuriama salyga per kuria bus keliomi duomenys i kietiakiu faila
                    kietiakaiOutput << vardas << " " << pavarde << " " << balas << "\n";
                }
            }
            auto pabaiga = high_resolution_clock::now();// tabdomas laikmatis
            auto trukme = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - pradzia);

            cout << "Failo " << kietiakaiFailas << +" sukurimas ir sugrupavimas" << +"(truko: " << fixed << setprecision(4) << trukme.count() << "s)" << endl; // vel naudojame count funkcija kuri apskaiciuoja laika tarp pirmo ir antro tasko.

            nuskait.close();
            kietiakaiOutput.close(); // failai uzdaromi 
        }
    }
void failo_kurimas::vargsiuku_suskirstymas() {
        auto pradzia = high_resolution_clock::now();

        for (int dydis : dydziai) {
            string kursiokai = "studentai_" + to_string(dydis) + ".txt";
            ifstream input(kursiokai);
            string vargsiukaiFailas = "vargsiukai_" + to_string(dydis) + ".txt";
            ofstream vargsiukaiOutput(vargsiukaiFailas);
            string vardas, pavarde;
            double balas;

            while (input >> vardas >> pavarde >> balas) {
                if (balas < 5.0) { // cia nuadojama viskas taspat kaip ir kietiaku funkcijoje, taciau keiciasi tik salyga, jog cia keliauja mokiniai kuriu balas yra zemesnis uz 5.
                    vargsiukaiOutput << vardas << " " << pavarde << " " << balas << "\n";

                }
             
                
            }
            auto pabaiga = high_resolution_clock::now();
            auto trukme = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - pradzia);

            cout << "Failo " << vargsiukaiFailas << +" sukurimas ir sugrupavimas" << +"(truko: " << fixed << setprecision(4) << trukme.count() << "s)" << endl;
            input.close();
            vargsiukaiOutput.close();
        }
       
    }
 

    bool failo_kurimas::ArEgzistuoja(const string& stud_failas) {
        ifstream failas(stud_failas.c_str());
        return failas.good();  //naudojame funkcija .good kuri grazina true arba false reiksme jeigu failas yra pasiekiamas
    }
    

