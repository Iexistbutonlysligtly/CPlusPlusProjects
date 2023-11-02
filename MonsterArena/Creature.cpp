
#include "Creature.h"
#include <iostream>





// Initializing Constructor
Creature::Creature(std::string name, Race* race, Profession* profession)
    : race(race), profession(profession), strength(0), dexterity(0), health(0), maxHealth(0) {

    // Calculating the attributes stats, based on race and profession
    creatureName = name;
    strength = race->getBaseStrength() + profession->getStrengthBonus();
    dexterity = race->getBaseDexterity() + profession->getDexterityBonus();
    maxHealth = race->getBaseHealth() + profession->getHealthBonus();
    health = maxHealth; // Setting initial health to maxHealth

   
}

// Creatures action method. Decides on which type of attack will be used 
void Creature::action(Creature* target, Creature* target2) {
    


         // Use racial ability if cooldown timer is 0
        if (target->race->getCooldownTimer() == 0) {
            target->race->racialAbility(target, target2);
            /* target->race->setCooldownTimer(target->race->getCooldownTimer());*/


            target->creatureAttack = target->race->getRacialAbilityName(); // Getting the name of ability used

            target->race->setCooldownTimer(target->race->getAbilityCooldown()); // Start the cooldown for the ability

          
     
        }

       

         // Use professional ability if cooldown timer is 0
        else if (target->profession->getCooldownTimer() == 0) {

            target->profession->professionalAbility(target, target2);
            /* target->profession->setCooldownTimer(target->profession->getCooldownTimer());*/

            target->creatureAttack = target->profession->getProfessionAbilityName(); // Getting the name of ability used


            target->profession->setCooldownTimer(target->profession->getAbilityCooldown()); // Start the cooldown for the ability


        }

    


        // Use basic attack if neither ability is available
        else {

            target->basicAttack(target2);
            target->creatureAttack = "basic attack";

        }
       


    

}

//Gets the name of the attack used
std::string attack(std::string name) {


    return name;


}


// The basic attack, deals damage from strength or dexterity depending on the greater value
void Creature::basicAttack(Creature* target) {
    
    // If Strength or Dexterity is grater , assign it to damage
    //Take the damage away from health

    int damage = (strength > dexterity) ? strength : dexterity; 
    target->health -= damage;

    //Resets back to 0 if it passes 0
    if (target->health < 0) {
        target->health = 0;
    }
}

// Abilities that deal damage
void Creature::specialAttack(Creature* target, int d) {

    int damage = d;
    target->health -= damage;

    if (target->health < 0) {
        target->health = 0;
    }
}



// Implement the printStatus method
void Creature::printStatus() {
    // Print the current status of the creature (health, strength, dexterity, cooldowns)

    
    cout << "Health: " << health << std::endl;
    cout << "Strength: " << strength << std::endl;
    cout << "Dexterity: " << dexterity << std::endl;
    cout << "Racial Ability Cooldown: " << race->getCooldownTimer() << std::endl;
    cout << "Professional Ability Cooldown: " << profession->getCooldownTimer() << std::endl;



}

//Adds to health
void Creature::restoreHealth(int amount) {
   
    
    //Increases the health
    health += amount;
    
   
    //Ensure that the health doesn't exceed the maxHealth
    if (health > maxHealth) {
        health = maxHealth;
    }
}

//Adds to Strength
void Creature::increaseStrength(int amount) {

    strength += amount;
}


//Adds to cooldown
void Creature::increaseCooldownTimers(int amount) {

   

    race->setCooldownTimer(race->getCooldownTimer() + amount);
    profession->setCooldownTimer(profession->getCooldownTimer() + amount);

   


}

//Triggers after the end of the second characters turn, end of a round
void Creature::roundOver(Creature* target, Creature* target2) {

    if (target->race->getCooldownTimer() > 0) {
        target->race->setCooldownTimer(target->race->getCooldownTimer() - 1);
    }
    if (target->profession->getCooldownTimer() > 0) {
        target->profession->setCooldownTimer(target->profession->getCooldownTimer() - 1);
    }


    if (target2->race->getCooldownTimer() > 0) {
        target2->race->setCooldownTimer(target2->race->getCooldownTimer() - 1);
    }
    if (target2->profession->getCooldownTimer() > 0) {
        target2->profession->setCooldownTimer(target2->profession->getCooldownTimer() - 1);
    }

   


   
   

}

// Initializing Getters
std::string Creature::getName() {

    return creatureName;

}

std::string Creature::getCreatureAttack() {

    return creatureAttack;

}



int Creature::getHealth() {


    return health;

}

int Creature::getMaxHealth() {


    return maxHealth;

}


int Creature::getStrength() {


    return strength;

}

int Creature::getDexterity() {


    return dexterity;

}

int Creature::getRaceCooldown() {


    return  race->getCooldownTimer();

}

int Creature::getProCooldown() {


    return profession->getCooldownTimer();

}

bool Creature::isAlive() {


    return health > 0;

}