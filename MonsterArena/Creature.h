// Creature.h (Header File)

#ifndef CREATURE_H
#define CREATURE_H


#include "Profession.h"
#include "Race.h"
#include <iostream>

using std::cout;
using std::endl;

class Race;
class Profession;




class Creature {
private:
    // Creatre attributes
    Race* race;
    Profession* profession;

    std::string creatureName;
    std::string creatureAttack;

    bool abilityUsed;

    bool usedRace;
    bool usedPro;
   

    int strength;
    int dexterity;
    int health;
    int maxHealth;


    

public:
    // Creature constructor
    Creature(std::string name, Race* race, Profession* profession);

    // Creature attack methods 
    void action(Creature* target, Creature* target2);
    void basicAttack(Creature* target);
    void specialAttack(Creature* target, int damage);
    void printStatus();

    


    // Creature commands
    void restoreHealth(int amount);
    void increaseStrength(int amount);
    void increaseCooldownTimers(int ammount);
    void roundOver(Creature* target, Creature* target2);
    bool isAlive();


    //Getters
    std::string getName();
    std::string getCreatureAttack();
    int getHealth();
    int getMaxHealth();
    int getStrength();
    int getDexterity();
    int getRaceCooldown();
    int getProCooldown();

    
};

#endif // CREATURE_H
