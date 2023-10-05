#pragma once
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>
#include <stdio.h>
#include <fstream> // nauja biblioteka
#include <algorithm>
#include <sstream> //nauja stringstream biblioteka


using::std::sort;
using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::fixed;
using std::setprecision;
using std::domain_error;
using std::ifstream;//naujas

using std::ofstream;//naujas
using std::istringstream;//naujas


extern char skaiciavimo_strategija;
extern string eilute;

class studentas {
	string vard, pav;
	vector<int> paz;
	int egz;
	float rez;
private:
	std::string Vardas;
	std::string Pavarde;
	std::vector<int> Pazymiai;
	
public:
	studentas();
	studentas(string v, string p, vector<int> pp, int e);
	studentas(const studentas& temp);
	studentas& operator=(const studentas& temp);
	/*studentas(const std::string& vardas, const std::string& pavarde,
            const std::vector<int>
                &pazymiai) // konstantiniu nuorodu pagalba perduodame parametrus i private kintamuosius
      : Vardas(vardas), Pavarde(pavarde), Pazymiai(pazymiai){};
	  */
	~studentas();
	//getteris
	inline string getVardas() {
		return vard;
	}
	inline int getPazNr() {
		return paz.size();
	}
	//setteris
	inline void setVardas(string t) {
		vard = t;
	}
	void printas();
	void printasRez();
	void rezVid();
	void rezMed();
	double mediana(vector<int>vec);
	/*double gal_vid() const;
	void printInfo() const;
	double gal_med() const;
	double mediana(vector<double>vec) const;*/







};