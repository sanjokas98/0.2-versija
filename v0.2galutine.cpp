#include <iostream> //Išvedimo/Įvedimo biblioteka.
#include <stdlib.h> //apibrėžia keturis kintamuosius tipus.
#include <string.h> // Leidžia dirbti su tekstais.
#include <conio.h>

using namespace std;

struct User {
	char name[20];
	char sname[20];
	int n;
	int nd[50];
	int egz;
	double ig;
	double avg;
	double med;
};

const int N = 50;

int main() {

	system("chcp 1251");

	User std[N];

	int n;
	char ch;

	do {
		system("cls");
		cout << "Skaitome is failo arba ivedame su klaviatura?" << endl;
		cout << "[1] - Ivedame\n[2] - Skaitome\n" << endl;
		ch = getch();
	} while (ch < '1' || ch > '2');

	if (ch == '1') {
		cout << "Nurodikite informacija apie keliu studentu ivesime: ";
		(cin >> n).get();
		for (int i = 0; i < n; i++) {
			cout << "Iveskite informacija apie " << i + 1 << "o(es) studento:" << endl;
			cout << "Vardas: ";
			cin.getline(std[i].name, 20);
			cout << "Pavarde: ";
			cin.getline(std[i].sname, 20);
			cout << "Kiekis padarytu namu darbu: ";
			cin >> std[i].n;
			cout << "Rezultatai is " << std[i].n << " namu darbu (per tarpa):" << endl;
			std[i].avg = 0;
			for (int j = 0; j < std[i].n; j++) {
				cin >> std[i].nd[j];
				std[i].avg += std[i].nd[j];
			}
			cout << "Egzameno rezultatas: ";
			(cin >> std[i].egz).get();
			std[i].avg /= std[i].n;
			std[i].ig = 0.4 * std[i].avg + 0.6 * std[i].egz;
			for(int k = 0; k < std[i].n - 1; k++) {
				for(int j = k + 1; j < std[i].n; j++) {
					if (std[i].nd[k] > std[i].nd[j]) {
						int t = std[i].nd[k];
						std[i].nd[k] = std[i].nd[j];
						std[i].nd[j] = t;
					}
				}
			}
			int k = std[i].n / 2;
			if (std[i].n % 2 != 0)
				std[i].med = std[i].nd[k];
			else
				std[i].med = (std[i].nd[k] + std[i].nd[k - 1]);
		}
	}
	else {
		FILE *in = fopen("kursiokai.txt", "r");
		n = 0;
		while (fscanf(in, "%s%s%d%d%d%d%d%d", &std[n].name, &std[n].sname, &std[n].nd[0], &std[n].nd[1], &std[n].nd[2], &std[n].nd[3], &std[n].nd[4], &std[n].egz) != EOF) {
			std[n].n = 5;
			std[n].avg = (std[n].nd[0] + std[n].nd[1] + std[n].nd[2] + std[n].nd[3] + std[n].nd[4]);
			std[n].avg /= std[n].n;
			std[n].ig = 0.4 * std[n].avg + 0.6 * std[n].egz;
			for(int k = 0; k < std[n].n - 1; k++) {
				for(int j = k + 1; j < std[n].n; j++) {
					if (std[n].nd[k] > std[n].nd[j]) {
						int t = std[n].nd[k];
						std[n].nd[k] = std[n].nd[j];
						std[n].nd[j] = t;
					}
				}
			}
			int k = std[n].n / 2;
			if (std[n].n % 2 != 0)
				std[n].med = std[n].nd[k];
			else
				std[n].med = (std[n].nd[k] + std[n].nd[k - 1]);

			n++;
		}
		fclose(in);
	}
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if (strcmp(std[i].name, std[j].name) > 0) {
				User t = std[i];
				std[i] = std[j];
				std[j] = t;
			}
		}
	}
	printf("%12s%12s%27s%27s\n", "Vardas", "Pavarde", "Galutinis (vidutinis)", "Galutinis (Mediana)");
	printf("------------------------------------------------------------------------------\n");
	for (int i = 0; i < n; i++) {
		printf("%12s%12s%27.2lf%27.2lf\n", std[i].name, std[i].sname, std[i].ig, std[i].med);
	}
	cout << endl;
	system("pause");
	return 0;
}
