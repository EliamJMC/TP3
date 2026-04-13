#pragma once
#include<stdint.h>
#include<string>

// LES STRUCTURES DE DONNÉES IMPOSÉES

const size_t REPONDANTS_MAX = 500; // nombre maximun de répondants du sondage

struct Protection
{
	int  r2[REPONDANTS_MAX];
	char r3[REPONDANTS_MAX];
	char r4[REPONDANTS_MAX];
	char r5[REPONDANTS_MAX];
	char r6[REPONDANTS_MAX];
};

struct Infection
{
	bool r7;
	int	r8, r9, r10;
};

struct Repondant
{
	std::string ville;
	int age;
	int scolarite;
};

uint8_t stat01(bool r1[]);
size_t lireLesDonnéesDuSondage(bool r1[], Protection* pro, Infection inf[], Repondant rep[]);