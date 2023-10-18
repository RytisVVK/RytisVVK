#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <list>
#include <deque>

using std::ifstream;
using std::ofstream;
using std::string;
using std::to_string;
using std::cout;
using std::endl;
using std::vector;
using std::setprecision;// naujas
using std::fixed;//naujas
using std::chrono::high_resolution_clock; // naujas
using std::deque;//naujas
using std::list;//naujas
class Studentas {
public:
    Studentas(int numeris);

    string GetVardas() const {                //getteris
        return vardas;
    }
    string GetPavarde() const {                   //getteris   
        return pavarde;
    }
    double GetGalutinisBalas() const {        //getteris
        return galutinisBalas;
    }
    ~Studentas() {}
private:
    string vardas;
    string pavarde;
    double galutinisBalas;
    int numeris;
};
class failo_kurimas {
private:
    bool ArEgzistuoja(const string& stud_failas);
public:
    failo_kurimas();
   void SukurtiFailus();
    deque
        /*list*/
        /*vector*/
        <int> dydziai;

    void kieteku_suskirstymas();
    void vargsiuku_suskirstymas();
};