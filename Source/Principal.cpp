#include<conio.h>
#include<iostream>

#include "c:/Temp/TP3/Header/cvm_23.h"
#include "c:/Temp/TP3/Header/Stats.h"

size_t nb_repondants;

int main()
{
	setcp(1252);

	bool* r1 = new bool[REPONDANTS_MAX] {};					// pour la  réponse  1
	Protection* pro = new Protection{};					// pour les réponses 2-3-4-5-6
	Infection* inf = new Infection[REPONDANTS_MAX]{};		// pour les réponses 7-8-9-10
	Repondant* rep = new Repondant[REPONDANTS_MAX]{};		// pour les réponses ville, age, scolarité

	nb_repondants = lireLesDonnéesDuSondage(r1, pro, inf, rep);

	uint16_t stat01		= stat_01(r1);
	uint16_t stat02		= stat_02(pro->r3);
	float stat03		= stat_03(pro->r2, rep);
	float stat04		= stat_04(*pro, rep);
	float stat05		= stat_05(pro->r2, rep);
	float stat06		= stat_06(inf);
	const char* stat07	= stat_07(inf);
	uint16_t stat08		= stat_08(*pro, inf);
	float stat09		= stat_09(*pro, inf, rep);
	const char* stat10	= stat_10(inf, rep);

	std::cout << stat01 << std::endl;
	std::cout << stat02 << std::endl;
	std::cout << stat03 << std::endl;
	std::cout << stat04 << std::endl;
	std::cout << stat05 << std::endl;
	std::cout << stat06 << std::endl;
	std::cout << stat07 << std::endl;
	std::cout << stat08 << std::endl;
	std::cout << stat09 << std::endl;
	std::cout << stat10 << std::endl;

	_getch();

	delete[] r1;
	delete pro;
	delete[] inf;
	delete[] rep;
}