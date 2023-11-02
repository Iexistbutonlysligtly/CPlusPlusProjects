
#ifndef RACE_H
#define RACE_H

#include "Creature.h"
#include <string>

class Creature; // Forward declaration

class Race {
protected:

    //Base values for the Race
    int baseStrength;
    int baseDexterity;
    int baseHealth;
    int cooldown; // The base cooldown for each ability
    int cooldownTimer; // The current cooldown for each ability in-game
    std::string abilityName;
public:
    
    // Main Constructor
    Race(int baseStrength, int baseDexterity, int baseHealth, int cooldown,int cooldownTimer, std::string abilityName);

    // Virtual method for the Race's ability
    virtual void racialAbility(Creature* target, Creature* target2) = 0;
    



     // Getters
    int getBaseStrength() const;
    int getBaseDexterity() const;
    int getBaseHealth() const;
    int getCooldownTimer() const; // Add this method
    int getAbilityCooldown() const; // Add this method
    std::string getRacialAbilityName() const;

    //Setters
    void setCooldownTimer(int timer);
  





};

// The Different Races

class Ogre : public Race {
public:
    // Ogre constructor and base stats
    Ogre()
        : Race(10, 2, 200, 3, 0, "Enrage") {}

   

    // Ogre ability method
    void racialAbility(Creature* target, Creature* target2);
};


class Sprite : public Race {
public:
    // Sprite constructor and base stats
    Sprite()
        : Race(2, 10, 150, 4, 0, "Charm") {}

    // Sprite ability method
    void racialAbility(Creature* target, Creature* target2);
};

class Ghoul : public Race {
public:
    // Ghoul constructor and base stats
    Ghoul()
         : Race(6, 6, 180, 4, 0, "Drain") {}

    //Ghoul ability method
    void racialAbility(Creature* target, Creature* target2);
};


#endif 
