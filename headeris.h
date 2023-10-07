#pragma once

#include <algorithm>
#include <array>
#include <fstream> // nauja biblioteka
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream> //nau
#include <stdio.h>
#include <string>
#include <vector>

using std::array;
using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::fixed;
using std::ifstream; // naujas
using std::left;
using std::right;
using std::setprecision;
using std::setw;
using ::std::sort;
using std::string;
using std::vector;

using std::istringstream; // naujas
using std::ofstream;      // naujas

class studentas {
private:
  std::string Vardas;
  std::string Pavarde;
  std::vector<int> Pazymiai; // yra

public:
  studentas(const std::string &vardas, const std::string &pavarde,
            const std::vector<int>
                &pazymiai) // konstantiniu nuorodu pagalba perduodame parametrus
                           // i private kintamuosius
      : Vardas(vardas), Pavarde(pavarde), Pazymiai(pazymiai){};



  double gal_vid() const;
  void printInfo() const;
  double gal_med() const;
  double mediana(vector<double>vec) const;
};
