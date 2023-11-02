
#include "Profession.h"


// Initializing constructor
Profession::Profession(int strengthBonus, int dexterityBonus, int healthBonus, int cooldown,int cooldownTimer, std::string aName)
    : strengthBonus(strengthBonus), dexterityBonus(dexterityBonus), healthBonus(healthBonus), cooldown(cooldown),cooldownTimer(cooldownTimer), abilityName(aName) {}



// Gladiator ability: Cleave method
void Gladiator::professionalAbility(Creature* target, Creature* target2) {
   
    //Attacks with the sum of strength and dexterity //Cooldown 3
    int damage = target->getStrength() + target->getDexterity();
    target->specialAttack(target2, damage);

  


}

// Thug ability: Rush method
void Thug::professionalAbility(Creature* target, Creature* target2) {
    
    //Attacks with double the dexterity damage
    int damage = target->getDexterity() * 2;
    target->specialAttack(target2, damage);

   
}

// Brute ability: Bash method
void Brute::professionalAbility(Creature* target, Creature* target2) {
    
    //Attacks with double strength damage
    int damage = target->getStrength() * 2;
    target->specialAttack(target2, damage);


}






// Initializing Getters
int Profession::getStrengthBonus() const {
    return strengthBonus;
}

int Profession::getDexterityBonus() const {
    return dexterityBonus;
}

int Profession::getHealthBonus() const {
    return healthBonus;
}

int Profession::getAbilityCooldown() const {

    return cooldown;
}

int Profession::getCooldownTimer() const {
    return cooldownTimer;
}

std::string Profession::getProfessionAbilityName() const {

    return abilityName;

}


// Initializing Setters
void Profession::setCooldownTimer(int timer) {
    cooldownTimer = timer;
}


