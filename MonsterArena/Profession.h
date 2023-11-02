
#ifndef PROFESSION_H
#define PROFESSION_H


#include "Creature.h"
#include <string>


class Creature; // Forward declaration

class Profession {
protected:

    //Base values for the Profession
    int strengthBonus;
    int dexterityBonus;
    int healthBonus;
    int cooldown;  // The base cooldown for each ability
    int cooldownTimer; // The current cooldown for each ability in-game

    std::string abilityName;

public:
    // Profession Constructor
    Profession(int strengthBonus, int dexterityBonus, int healthBonus, int cooldown,int cooldownTimer, std::string abilityName);

    // Virtual method for the Profession's ability
    virtual void professionalAbility(Creature* target, Creature* target2) = 0;



    // Getters
    int getStrengthBonus() const;
    int getDexterityBonus() const;
    int getHealthBonus() const;
    int getAbilityCooldown() const; // Add this method
    int getCooldownTimer() const; 
    std::string getProfessionAbilityName() const;

    //Setters
    void setCooldownTimer(int timer);


};

// The Different Professions
class Gladiator : public Profession {
public:
    // Gladiator constructor and base stats
    Gladiator()
        : Profession(5, 5, 150, 3, 0, "Cleave") {}

    // Gladiator ability method
    void professionalAbility(Creature* target, Creature* target2);
};


class Thug : public Profession {
public:
    // Thug constructor and base stats
    Thug()
        : Profession(2, 10, 80, 4,0, "Rush") {}

    // Thug ability method
    void professionalAbility(Creature* target, Creature* target2);
};

class Brute : public Profession {
public:
    // Brute constructor and base stats
    Brute()
        : Profession(10, 2 , 150, 4,0, "Bash") {}

    // Brute ability method
    void professionalAbility(Creature* target, Creature* target2);
};





#endif 
