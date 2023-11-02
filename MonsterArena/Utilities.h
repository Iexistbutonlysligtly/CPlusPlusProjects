#pragma once

#ifndef UTILS_H
#define UTILS_H

#include "Creature.h"
#include <chrono>
#include <thread>
#include <fstream>
#include <streambuf>
#include <ostream>



class Utilities {
public:
    // Utility methods
    static Creature* createCreature();
    static Race* promptUserForRace();
    static Profession* promptUserForProfession();
    static void printStatus(Creature* c);
    static void printCreatureAttack(Creature* c);
    static void printStatusToFile(Creature* c, std::ofstream& outputFile);
    static void printCreatureAttackToFile(Creature* c, std::ofstream& outputFile);
    static std::string typeName();

    static int rollDice();
    static int countdown(int gameCountdown);
  

    static int round;
};




#endif 
