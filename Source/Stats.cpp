#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <windows.h>

#include "../Header/Stats.h"

uint16_t stat01(const bool* r1, const size_t& nbRepondants) {
	if (nbRepondants < 1) return 0;
	uint16_t count = 0;
	for (uint16_t i = 0; i < nbRepondants; i++) {
		if (*(r1+i) == true)
			count++;
	}
	return count;
}
uint16_t stat02(const char r3[], const size_t& nbRepondants) {
	if (nbRepondants < 1) return 0;
	uint16_t count = 0;
	for (uint16_t i = 0; i < nbRepondants; i++) {
		if (r3[i] == 'O')
			count++;
	}
	return count;
}
uint8_t stat03(const int r2[], const Repondant* repondants, const size_t& nbRepondants) {
	if (nbRepondants < 1) return 0;
	uint16_t total = 0;
	uint16_t nbRepEntreTrenteEtQuarente = 0;
	for (uint16_t i = 0; i < nbRepondants; i++) {
		if ((repondants + i)->age > 29 && (repondants + i)->age < 40) {
			total += static_cast<uint16_t>(r2[i]);
			nbRepEntreTrenteEtQuarente++;
		}
	}
	return total / nbRepEntreTrenteEtQuarente;
}
float stat04(const Protection& protection, const Repondant* repondants, const size_t& nbRepondants) {
	if (nbRepondants < 1) return 0;
	float total = 0;
	uint16_t nbRepUtiliserDecoDormir = 0;
	for (uint16_t i = 0; i < nbRepondants; i++) {
		if (protection.r5[i] == 'O' || protection.r6[i] == 'O') {
			total += static_cast<float>((repondants + i)->age);
			nbRepUtiliserDecoDormir++;
		}
	}
	return total / nbRepUtiliserDecoDormir;
}
float stat05(const int r2[], const Repondant* repondants, const size_t nbRepondants) {
	if (nbRepondants < 1) return 0.0f;
	uint16_t nbRepVaudreuil = 0;
	uint16_t nbRepPlusQueUnMasque = 0;
	for (uint16_t i = 0; i < nbRepondants; i++) {
		if ((repondants + i)->ville == "Vaudreuil") {
			nbRepVaudreuil++;
			if (r2[i] > 1) {
				nbRepPlusQueUnMasque++;
			}
		}
	}
	return static_cast<float>(nbRepPlusQueUnMasque) / nbRepVaudreuil * 100.0f;
}


size_t lireLesDonnéesDuSondage(bool r1[], Protection* pro, Infection inf[], Repondant rep[])
{
	std::string name = "C21-LAB-3-Sondage.txt";											// exemple avec un path "C:/dossier/C21-LAB-3-Sondage.txt"
	std::fstream f(name, std::ios::in);

	if (f.fail()) // fichier ouvert ?
	{
		MessageBoxA(NULL, "Impossible d'ouvrir le fichier, Fin du programme", "Erreur", MB_OK | MB_ICONSTOP);
		exit(EXIT_FAILURE);
	}

	char c;
	size_t r;
	for (r = 0; r < REPONDANTS_MAX; ++r)											// lire les réponses de chaque répondant
	{
		f >> c;	if (c == 'O') r1[r] = true; else r1[r] = false;						// r1
		f >> pro->r2[r] >> pro->r3[r] >> pro->r4[r] >> pro->r5[r] >> pro->r6[r];	// r2 à r6
		f >> c; if (c == 'O') inf[r].r7 = true; else inf[r].r7 = false;				// r7
		f >> inf[r].r8 >> inf[r].r9 >> inf[r].r10;									// r8 à r10
		f >> rep[r].ville >> rep[r].age >> rep[r].scolarite;						// ville, age, scolarité
		if (f.fail()) { f.clear(); break; }
	}
	f.close();
	return r;
}