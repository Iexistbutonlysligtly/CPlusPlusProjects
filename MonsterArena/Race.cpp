
#include "Race.h"



//Race constructor initialisation
Race::Race(int strength, int dexterity, int health, int cooldown,int cooldownTimer, std::string aName)
    : baseStrength(strength), baseDexterity(dexterity), baseHealth(health), cooldown(cooldown),cooldownTimer(cooldownTimer), abilityName(aName) {}



// Ogre ability: Enrage method
void Ogre::racialAbility(Creature* target, Creature* target2) {
  
    //Restores health  //Increases strength  //Cooldown of 3

    target->restoreHealth(20);
    target->increaseStrength(1);

   
}

// Sprite ability: Charm method
void Sprite::racialAbility(Creature* target, Creature* target2) {

    //Increases the cooldowns for the opponent  //Cooldown 4

    target2->increaseCooldownTimers(2);

}

// Ghoul ability: Drain method
void Ghoul::racialAbility(Creature* target, Creature* target2) {

    //Attacks with the dexterity amount //Increases health by half that amount  //Cooldown of 4

    int damage = target->getDexterity();
    target->specialAttack(target2,damage);
    target->restoreHealth(damage / 2);

 
}

// Initializing Getters
int Race::getBaseStrength() const {
    return baseStrength;
}

int Race::getBaseDexterity() const {
    return baseDexterity;
}

int Race::getBaseHealth() const {
    return baseHealth;
}

int Race::getCooldownTimer() const {
    return cooldownTimer;
}

int Race::getAbilityCooldown() const {
    return cooldown;
}

std::string Race::getRacialAbilityName() const{

    return abilityName;

}

// Initializing Setters
void Race::setCooldownTimer(int timer) {
    cooldownTimer = timer;
}
