#include "headeris.h"
char skaiciavimo_strategija = 'v';
int main() {
	cout << "Kaip skaiciuoti galutini v/m?\n";
	cin >> skaiciavimo_strategija;


	cout << "Iveskite studenta:\n";

	vector<studentas> grupe;
	for (int i = 0; i < 1; i++) {
		studentas K;
		grupe.push_back(K);
		K.~studentas();
	}
	cout << endl << grupe.size() << endl;
	printf("|%-10s|%20s|", "Vardas", "Pavarde");
	for (int i = 0; i < grupe[0].getPazNr(); i++)
		printf("%s%d|", "ND", i + 1);
	printf("%10s|\n", "Egzaminas");
	for (auto& a : grupe) a.printas();
	cout << endl;

	printf("|%-10s|%20s|", "Vardas", "Pavarde");
	printf("%10s|\n", skaiciavimo_strategija == 'm' ? "Galutine mediana - m" : "Galuitinis vidurkis v ");

	for (auto& a : grupe) a.printasRez(); {
		cout << endl;
	}


	/*std::fstream failas("kursiokai.txt");

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

	// Print the header for the table
	std::cout << "Vardas     Pavarde        (Vid.)  (Med.)\n";
	std::cout << "----------------------------------------------------------\n";

	// Print student information
	for (const studentas& stud_adresas : stud_vec) {
		stud_adresas.printInfo();
	}

	return 0;*/


	system("pause");
}