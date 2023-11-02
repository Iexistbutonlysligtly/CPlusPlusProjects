

#include "Utilities.h"
#include <iostream>


// Prints the Status for the creature
void Utilities::printStatus(Creature* c) {
  

    
    std::cout << c->getName() << " Status:\n";
    std::cout << "-----------------\n";
    std::cout << "Health: " << c->getHealth() << "/" << c->getMaxHealth() << "\n";
    std::cout << "Strength: " << c->getStrength() << "\n";
    std::cout << "Dexterity: " << c->getDexterity() << "\n";
    std::cout << "Cooldown Timer: " << c->getRaceCooldown() << "\n";
    std::cout << "Profession Cooldown: " << c->getProCooldown() << "\n";
    std::cout << "-----------------\n";
    std::cout << "\n";

}   


// Prints the Status for the creature and adds it to a text file
void Utilities::printStatusToFile(Creature* c, std::ofstream& outputFile) {

    outputFile << c->getName() << " Status: " << endl;
    outputFile << "-----------------" << endl;
    outputFile << "Health: " << c->getHealth() << "/" << c->getMaxHealth() << endl;
    outputFile << "Strength: " << c->getStrength() << endl;
    outputFile << "Dexterity: " << c->getDexterity() << endl;
    outputFile << "Cooldown Timer: " << c->getRaceCooldown() << endl;
    outputFile << "Profession Cooldown: " << c->getProCooldown() << endl;
    outputFile << "----------------- " << endl;
    outputFile << endl;
}


// Exclaims what moves a creature has used
void Utilities::printCreatureAttack(Creature* c) {


   
    cout << c->getName() << ":" << std::endl;
    cout << "Performed Attack: " << c->getCreatureAttack() << std::endl;
    cout << std::endl;


}

// Exclaims what moves a creature has used and add sit to a text file
void Utilities::printCreatureAttackToFile(Creature* c, std::ofstream& outputFile) {
   
  
    outputFile << "Name: " << c->getName() << std::endl;
    outputFile << "Performed Attack: " << c->getCreatureAttack() << std::endl;
    outputFile << std::endl;

}

// Emulates a dice roll
int Utilities::rollDice() {
    // Seeds a random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generates a random number between 1 and 6
    int result = rand() % 6 + 1;

    return result;
}



// A countdown method
int Utilities::countdown(int gameCountdown) {



    int countdown = gameCountdown; // Initial countdown value

    while (countdown >= 0) {
        std::cout << "\r" << countdown << " "; // Print the countdown value with a carriage return to overwrite the previous value
        std::cout.flush(); // Flush the output buffer

        std::this_thread::sleep_for(std::chrono::seconds(1)); // Delay for 1 second

        countdown--; // Decrease the countdown value
    }

    std::cout << std::endl << endl; // Print a newline after the countdown finishes




    return countdown;


}




// Returns a name a user inputs as a string
std::string Utilities::typeName() {

    std::string name;
    std::cout << "Name the challenger:\n";
    std::cout << "-----------------\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   
    std::getline(std::cin, name);
    return name;


}



// Creates creature obj via using methods that returns a Race,Profession and Name
 Creature* Utilities::createCreature() {
    // Create a creature based on user input (race and profession)
    // Return the created creature

    Race* race = promptUserForRace();
    Profession* profession = promptUserForProfession();
    std::string cName = typeName();

    Creature* creature = new Creature(cName,race, profession);

    return creature;
}



// Lets users choose from the different Races
Race* Utilities::promptUserForRace() {
   
    //Asks For Race

    std::cout << "Select a race:\n";
    std::cout << "-----------------\n \n";

    std::cout << "1. Ogre\n";
    std::cout << "-------\n";
    std::cout << "Ability: Enrage \n";
    std::cout << "Restores 20 health and increases strength by 1: Cooldown 3. \n \n";

    std::cout << "2. Sprite\n";
    std::cout << "-------\n";
    std::cout << "Ability: Charm \n";
    std::cout << "Increases the opponent’s cooldown timers by 2: Cooldown 4 \n \n";

    std::cout << "3. Ghoul\n";
    std::cout << "-------\n";
    std::cout << "Ability: Drain \n";
    std::cout << "Deals damage equal to the ghouls dexterity and regains half as much health: Cooldown 4 \n \n";

    int raceChoice;
  //  std::cin >> raceChoice;

    while (true) {
        std::cout << "Enter a number: ";
        if (std::cin >> raceChoice) {
            // Input is a valid number
            break;
        }

        //In case of non integer input
        else {
            // Clear the input buffer
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number: " << std::endl;
        }
    }

    std::cout << "\n";


    //Assigns Race
    switch (raceChoice) {
    case 1:
        return new Ogre();
    case 2:
        return new Sprite();
    case 3:
        return new Ghoul();
    default:
        std::cout << "Invalid race choice. Defaulting to Troll.\n \n";
        return new Ogre();
    }
}

// Lets user choose from different Professions
Profession* Utilities::promptUserForProfession() {
   
    //Asks For Profession
    std::cout << "\n";
    std::cout << "Select a profession:\n";
    std::cout << "-----------------\n \n";

    std::cout << "1. Gladiator\n";
    std::cout << "-------\n";
    std::cout << "Ability: Cleave \n";
    std::cout << "Deals strength+dexterity damage: Cooldown 3 \n \n";


    std::cout << "2. Thug\n";
    std::cout << "-------\n";
    std::cout << "Ability: Rush \n";
    std::cout << "Deals 2*dexterity damage: Cooldown 4 \n \n";


    std::cout << "3. Brute\n";
    std::cout << "-------\n";
    std::cout << "Ability: Bash \n";
    std::cout << "Deals 2*strength damage: Cooldown 4 \n \n";

    int professionChoice;
 //   std::cin >> professionChoice;



    while (true) {
        std::cout << "Enter a number: ";
        if (std::cin >> professionChoice) {
            // Input is a valid number
            break;
        }

        //In case of non integer input
        else {
            // Clear the input buffer
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number: " << std::endl;
        }
    }




    std::cout << "\n";
    //Assigns Profession
    switch (professionChoice) {
    case 1:
        return new Gladiator();
    case 2:
        return new Thug();
    case 3:
        return new Brute();
    default:
        std::cout << "Invalid profession choice. Defaulting to Gladiator.\n \n";
        return new Gladiator();
    }
}