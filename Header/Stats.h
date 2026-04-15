#pragma once
#include<stdint.h>
#include<string>

const size_t REPONDANTS_MAX = 500; // Nombre maximun de répondants du sondage

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

uint16_t stat_01(const bool* r1);
uint16_t stat_02(const char r3[]);

float stat_03(const int r2[], const Repondant* repondants);
float stat_04(const Protection& protection, const Repondant* repondants);
float stat_05(const int r2[], const Repondant* repondants);
float stat_06(const Infection* infection);

const char* stat_07(const Infection* infection);

uint16_t stat_08(const Protection& protection, const Infection* infection);

float stat_09(const Protection& protection, const Infection* infection, const Repondant* repondants);

size_t lireLesDonnéesDuSondage(bool r1[], Protection* pro, Infection inf[], Repondant rep[]);