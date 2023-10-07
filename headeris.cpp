#include "headeris.h"

double studentas::gal_vid() const {
  int sum = 0;
  for (int pazym : Pazymiai) {
    sum += pazym;
  }
  return static_cast<double>(sum) / Pazymiai.size();
}

double studentas::gal_med() const {
  std::vector<int> pazym = Pazymiai;
  std::sort(pazym.begin(), pazym.end());
  int p = pazym.size();
  if (p % 2 == 0) {
    return (pazym[p / 2 - 1] + pazym[p / 2]) / 2.0;
  } else {
    return pazym[p / 2];
  }
}
void studentas::printInfo() const {
  std::cout << std::left << std::setw(12) << Pavarde << " " << std::setw(12)
            << Vardas << "Galutinis(Vid.): " << std::fixed
            << std::setprecision(2) << std::setw(18) << gal_vid()
            << "Galutinis(Med.): " << std::setw(5) << gal_med() << "\n";
}
