#include<conio.h>

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

	_getch();

	delete[] r1;
	delete pro;
	delete[] inf;
	delete[] rep;
}