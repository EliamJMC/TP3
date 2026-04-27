#include<conio.h>
#include<iostream>

#include "c:/Temp/TP3/Header/cvm_23.h"
#include "c:/Temp/TP3/Header/Stats.h"

size_t nb_repondants;

int main()
{
	setcp(1252);

	bool* r1 = new bool[REPONDANTS_MAX] {};					// pour la  réponse  1
	Protection* pro = new Protection{};					    // pour les réponses 2-3-4-5-6
	Infection* inf = new Infection[REPONDANTS_MAX]{};		// pour les réponses 7-8-9-10
	Repondant* rep = new Repondant[REPONDANTS_MAX]{};		// pour les réponses ville, age, scolarité

	nb_repondants = lireLesDonnéesDuSondage(r1, pro, inf, rep);

	Stats stats;
	setStats(stats, r1, pro, inf, rep);

	std::cout << "Resultats du sondage:  ( 100 respondants )";
	std::cout << std::endl << std::endl;
	std::cout << "Statistiques";
	std::cout << std::endl << std::endl;

	printStatsQuestions();

	std::cout << std::endl << std::endl;
	std::cout << "Resultats";
	std::cout << std::endl << std::endl;

	printStatsResults(stats);

	_getch();

	delete[] r1;
	delete pro;
	delete[] inf;
	delete[] rep;
}