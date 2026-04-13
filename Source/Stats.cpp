#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <windows.h>


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