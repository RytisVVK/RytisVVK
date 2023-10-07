#include "headeris.h"
int main() {
  std::fstream failas("kursiokai.txt");

  if (!failas.is_open()) {
    std::cerr << "Failas neatsidare, arba pasirinkote bloga faila." << std::endl;
    return 1; 
  }

  std::vector<studentas> stud_vec; // 
  std::string eilute;
  getline(failas, eilute); 

  while (getline(failas, eilute)) {
    std::istringstream iss(eilute);
    std::string Vardas, Pavarde;
    iss >> Pavarde >> Vardas;

    int paz;
    std::vector<int> paz_vec;
    while (iss >> paz) {
      paz_vec.push_back(paz);
    }

    studentas studentas(Vardas, Pavarde, paz_vec);
    stud_vec.push_back(studentas);
  }

  failas.close();

 
  std::cout << "Vardas     Pavarde        (Vid.)  (Med.)\n";
  std::cout << "----------------------------------------------------------\n";

 
  for (const studentas &stud_adresas : stud_vec) {
    stud_adresas.printInfo();
  }

  return 0;
}
