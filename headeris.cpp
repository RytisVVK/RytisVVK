#include "headeris.h"
extern char skaiciavimo_strategija;
studentas::studentas() {
	cout << "Ivesk varda: ";
	cin >> vard;
	cout << "Ivesk pavarde: ";
	cin >> pav;
	cout << "Kiek pazymiu buvo semestre?: ";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cout << "Ivesk " << i + 1 << " semestro pazymi: ";
		cin >> k;
		paz.push_back(k);
	}
	cout << "Ivesk egzamino pazymi: ";
	cin >> egz;
	skaiciavimo_strategija == 'm' ? rezMed() : rezVid();
}
studentas::studentas(string v, string p, vector<int>pp, int e) {
	vard = v;
	pav = p;
	paz = pp;
	egz = e;
	skaiciavimo_strategija == 'm' ? rezMed() : rezVid();
}
studentas::studentas(const studentas& temp) {
	vard = temp.vard;
	pav = temp.pav;
	paz = temp.paz;
	egz = temp.egz;
	skaiciavimo_strategija == 'm' ? rezMed() : rezVid();
}
studentas& studentas::operator=(const studentas& temp) {
	if (this == &temp) return*this;
	vard = temp.vard;
	pav = temp.pav;
	paz = temp.paz;
	egz = temp.egz;
	skaiciavimo_strategija == 'm' ? rezMed() : rezVid();
	return *this;
}
studentas::~studentas() {
	vard.clear();
	pav.clear();
	paz.clear();
	egz = 0;
	rez = 0;
}
void studentas::printas() {
	printf("|%-10s|%20s|", vard.c_str(), pav.c_str());
	for (auto& a : paz) printf("%3d|", a);
	printf("%10d\n", egz);
}
void studentas::printasRez() {
	printf("|%-10s|%20s|", vard.c_str(), pav.c_str());
	printf("%10f|\n", rez);
}
void studentas::rezVid() {
	float sum = std::accumulate(paz.begin(), paz.end(), 0.0);
	rez = sum / paz.size() * 0.4 + egz * 0.6;
}
void studentas::rezMed() {
	rez = mediana(paz) * 0.4 + egz * 0.6;
}
/*void studentas::printInfo() const {
	std::cout << std::left << std::setw(12) << Pavarde << " " << std::setw(12)
		<< Vardas << "Galutinis(Vid.): " << std::fixed
		<< std::setprecision(2) << std::setw(18) << gal_vid()
		<< "Galutinis(Med.): " << std::setw(5) << gal_med() << "\n";
}

double studentas::gal_vid() const {
  double sum = 0;
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
*/

double studentas::mediana(vector<int>vec) {
	typedef vector<double>::size_type vecSize;
	vecSize size = vec.size();
	if (size == 0)
		throw std::domain_error("Negalima skaiciuoti medianos tuciu vektoriumi");
	sort(vec.begin(), vec.end());
	vecSize vid = size / 2;
	return size % 2 == 0 ? (vec[vid] + vec[vid - 1]) / 2.0 : vec[vid] / 1.0; 
}
