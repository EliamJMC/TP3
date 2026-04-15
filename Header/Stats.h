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

uint16_t stat01(const bool* r1, const size_t& nbRepondants);
uint16_t stat02(const char r3[], const size_t& nbRepondants);

float stat03(const int r2[], const Repondant* repondants, const size_t& nbRepondants);
float stat04(const Protection& protection, const Repondant* repondants, const size_t& nbRepondants);
float stat05(const int r2[], const Repondant* repondants, const size_t nbRepondants);
float stat06(const Infection* infection, const size_t nbRepondants);

const char* stat07(const Infection* infection, const size_t& nbRepondants);

uint16_t stat08(const Protection& protection, const Infection* infection, const size_t nbRepondants);

float stat09(const Protection& protection, const Infection*, const Repondant* repondant, const size_t nbRepondant);

size_t lireLesDonnéesDuSondage(bool r1[], Protection* pro, Infection inf[], Repondant rep[]);