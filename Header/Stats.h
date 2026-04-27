#pragma once
#include <stdint.h>
#include <string>

const size_t REPONDANTS_MAX = 500; // Nombre maximun de répondants du sondage

struct Stats {
    uint16_t _01 = 0;
    uint16_t _02 = 0;
    uint16_t _08 = 0;
    float _03 = 0.0f;
    float _04 = 0.0f;
    float _05 = 0.0f;
    float _06 = 0.0f;
    float _09 = 0.0f;
    const char* _07 = nullptr;
    std::string _10 = "";
};

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
    int r8, r9, r10;
};

struct Repondant
{
    std::string ville;
    int age;
    int scolarite;
};

uint16_t    stat_01(const bool* r1);
uint16_t    stat_02(const char r3[]);

float       stat_03(const int r2[], const Repondant* repondants);
float       stat_04(const Protection& protection, const Repondant* repondants);
float       stat_05(const int r2[], const Repondant* repondants);
float       stat_06(const Infection* infection);

const char* stat_07(const Infection* infection);

uint16_t    stat_08(const Protection& protection, const Infection* infection);

float       stat_09(const Protection& protection, const Infection* infection, const Repondant* repondants);

std::string stat_10(const Infection* infection, const Repondant* repondants);

void setStats(Stats& stats, const bool* r1, const Protection* pro, const Infection* inf, const Repondant* rep);

void printStatsQuestions();

void printStatsResults(const Stats& stats);

size_t lireLesDonnéesDuSondage(bool r1[], Protection* pro, Infection inf[], Repondant rep[]);