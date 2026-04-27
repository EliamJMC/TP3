#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <windows.h>

#include "../Header/Stats.h"
#include "../Header/Liste.h"

extern size_t nb_repondants;

uint16_t stat_01(const bool* r1) {
	if (nb_repondants < 1) return 0;

	uint16_t count = 0;
	for (uint16_t i = 0; i < nb_repondants; i++) {
		if (*(r1+i) == true)
			count++;
	}

	return count;
}

uint16_t stat_02(const char r3[]) {
	if (nb_repondants < 1) return 0;

	uint16_t count = 0;
	for (uint16_t i = 0; i < nb_repondants; i++) {
		if (r3[i] == 'O')
			count++;
	}

	return count;
}

float stat_03(const int r2[], const Repondant* repondants) {
	if (nb_repondants < 1) return 0;

	float total = 0;
	uint16_t nbRepEntreTrenteEtQuarente = 0;
	for (uint16_t i = 0; i < nb_repondants; i++) {
		if ((repondants + i)->age > 29 && (repondants + i)->age < 40) {
			total += static_cast<float>(r2[i]);
			nbRepEntreTrenteEtQuarente++;
		}
	}

	if (nbRepEntreTrenteEtQuarente < 1) return 0.0f;

	return total / nbRepEntreTrenteEtQuarente;
}

float stat_04(const Protection& protection, const Repondant* repondants) {
	if (nb_repondants < 1) return 0;

	float total = 0; 
	uint16_t nbRepUtiliserDecoDormir = 0;
	for (uint16_t i = 0; i < nb_repondants; i++) {
		if (protection.r5[i] == 'O' || protection.r6[i] == 'O') {
			total += static_cast<float>((repondants + i)->age);
			nbRepUtiliserDecoDormir++;
		}
	}

	if (nbRepUtiliserDecoDormir < 1) return 0.0f;

	return total / nbRepUtiliserDecoDormir;
}

float stat_05(const int r2[], const Repondant* repondants) {
	if (nb_repondants < 1) return 0.0f;

	uint16_t nbRepVaudreuil = 0;
	uint16_t nbRepPlusQueUnMasque = 0;

	for (uint16_t i = 0; i < nb_repondants; i++) {
		if ((repondants + i)->ville == "Vaudreuil") {
			nbRepVaudreuil++;

			if (r2[i] > 1) nbRepPlusQueUnMasque++;
		}
	}

	if (nbRepVaudreuil < 1) return 0.0f;

	return static_cast<float>(nbRepPlusQueUnMasque) / nbRepVaudreuil * 100.0f;
}

float stat_06(const Infection* infection) {
	if (nb_repondants < 1) return 0.0f;

	uint16_t nbRepUtilDesinfectant = 0;

	for (uint16_t i = 0; i < nb_repondants; i++) {
		if ((infection + i)->r8 != 1) {
			nbRepUtilDesinfectant++;
		}
	}

	if (nb_repondants < 1) return 0.0f;

	return static_cast<float>(nbRepUtilDesinfectant) / nb_repondants * 100.0f;
}

const char* stat_07(const Infection* infection) {
	if (nb_repondants < 1) return "Pas de désinfectant";

	uint32_t counts[5] = { 0 };
	uint8_t maxIndex = 1;

	for (uint16_t i = 0; i < nb_repondants; i++) {
		uint8_t choix = infection[i].r8;
		if (choix >= 1 && choix <= 5)
			counts[choix - 1]++;
	}

	for (uint8_t i = 2; i < 5; i++) {
		if (counts[i] > counts[maxIndex])
			maxIndex = i;
	}

	static const char* desinfectants[5] = {
		"Pas de désinfectant",
		"Savon à vaisselle",
		"Purell",
		"Eau de Javel",
		"Alcool à friction"
	};

	return desinfectants[maxIndex];
}

uint16_t stat_08(const Protection& protection, const Infection* infection) {
	if (nb_repondants < 1) return 0;

	uint16_t nbRep = 0;

	for (uint16_t i = 0; i < nb_repondants; i++) {
		if ((infection + i)->r10 < 1 && (infection + i)->r8 == 1 && protection.r4[i] == 'O')
			nbRep++;
	}

	return nbRep;
}

float stat_09(const Protection& protection, const Infection* infection, const Repondant* repondants) {
	if (nb_repondants < 1) return 0.0f;

	float total = 0;
	uint16_t nbRepMtlInf = 0;

	for (uint16_t i = 0; i < nb_repondants; i++) {
		bool mtl = (repondants + i)->ville == "Montreal";
		bool infecte = (infection + i)->r9 == 1;
		bool masque = protection.r2[i] >= 1;
		bool desinfectant = (*(infection + i)).r8 != 1;

		if (mtl && infecte && (!masque || !desinfectant)) {
			total += static_cast<float>((repondants + i)->scolarite);
			nbRepMtlInf++;
		}
	}

	if (nbRepMtlInf < 1) return 0.0f;

	return total / nbRepMtlInf;
}

std::string stat_10(const Infection* infection, const Repondant* repondants) {
	LinkedList linkedList;

	for (int16_t i = 0; i < nb_repondants; i++) {
		Data data = { (repondants + i)->ville, static_cast<unsigned int>((infection + i)->r10) }; 
		lLUpdate(linkedList, data);
	}

	Node* highestNBTest = lLSearchHighestTest(linkedList);
	std::string ville = highestNBTest->data.ville;
	
	lLClear(linkedList);
	return ville;
}

void printStatsQuestions() {
	std::cout << "01) Combien de personnes toussent souvent ?" << std::endl;
	std::cout << "02) Combien de personnes veulent un masque dans leur auto ?" << std::endl;
	std::cout << "03) Combien de masques, en moyenne, ont les gens qui sont dans la trentaine ?" << std::endl;
	std::cout << "04) Quel est l'age moyen des gens qui se serviraient d’un masque pour decorer ou pour dormir ?" << std::endl;
	std::cout << "05) Quel pourcentage de repondants de Vaudreuil utilisent plus d'un masque ?" << std::endl;
	std::cout << "06) Quel pourcentage de la population utilise du desinfectant ?" << std::endl;
	std::cout << "07) Quel est le type de desinfectant le plus repandu ?" << std::endl;
	std::cout << "08) Combien de gens non testes et n’utilisant pas de desinfectant ont deja emprunte un masque ? " << std::endl;
	std::cout << "09) Combien d'annees de scolarite, en moyenne, ont les gens infectes de Montreal sans masque ou sans desinfectant" << std::endl;
	std::cout << "10) Quelle est la ville ayant fait subir le plus grand nombre de tests ? " << std::endl;
}

void printStatsResults(const Stats& stats) {
	std::cout << std::fixed << std::setprecision(1);

	std::cout << "01) = " << stats._01 << std::endl;
	std::cout << "02) = " << stats._02 << std::endl;
	std::cout << "03) = " << stats._03 << std::endl;
	std::cout << "04) = " << stats._04 << std::endl;
	std::cout << "05) = " << stats._05 << " %" << std::endl;
	std::cout << "06) = " << stats._06 << " %" << std::endl;
	std::cout << "07) = " << stats._07 << std::endl;
	std::cout << "08) = " << stats._08 << std::endl;
	std::cout << "09) = " << stats._09 << std::endl;
	std::cout << "10) = " << stats._10 << std::endl;
}

void setStats(Stats& stats, const bool* r1, const Protection* pro, const Infection* inf, const Repondant* rep) {
	stats._01 = stat_01(r1);
	stats._02 = stat_02(pro->r3);
	stats._03 = stat_03(pro->r2, rep);
	stats._04 = stat_04(*pro, rep);
	stats._05 = stat_05(pro->r2, rep);
	stats._06 = stat_06(inf);
	stats._07 = stat_07(inf);
	stats._08 = stat_08(*pro, inf);
	stats._09 = stat_09(*pro, inf, rep);
	stats._10 = stat_10(inf, rep);
}


size_t lireLesDonnéesDuSondage(bool r1[], Protection* pro, Infection inf[], Repondant rep[]) {
	std::string name = "C:/Temp/tests.txt";											// exemple avec un path "C:/dossier/C21-LAB-3-Sondage.txt"
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