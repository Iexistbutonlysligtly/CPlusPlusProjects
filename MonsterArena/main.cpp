#include "Utilities.h"
#include <iostream>
#include <cstdio>
#include <sstream>

int main() {

   
    
    // Initializers for the classes to use commands
    Utilities utils;
    Creature* cmd = nullptr;


    //Round counter
    int round = 1;

    std::ofstream outputFile("monster_arena_log.txt"); // Open the output file





    //Title
    std::cout << "********************************************************************************************************************" << std::endl;
    std::cout << "                                                            Monster Arena         " << std::endl;
    std::cout << "********************************************************************************************************************" << std::endl;


    //Title for .text file
#pragma region ForFile

    outputFile << "********************************************************************************************************************" << std::endl;
    outputFile << "                                                            Monster Arena         " << std::endl;
    outputFile << "********************************************************************************************************************" << std::endl << endl;
#pragma endregion


   //For .text file
#pragma region AbilityExplnations


    //Ability explanations for file

    outputFile << "Racial Abilities:\n";
    outputFile << "-----------------\n";
    outputFile << "Enrage\n";
    outputFile << "-------\n";
    outputFile << " Restores 20 health and increases strength by 1. Cooldown 3.\n\n";

    outputFile << "Charm\n";
    outputFile << "-------\n";
    outputFile << "Increases the opponent’s cooldown timers by 2. Cooldown 4.\n\n";

    outputFile << "Drain\n";
    outputFile << "-------\n";
    outputFile << "Deals damage equal to the ghoul’s dexterity and regains half as much health.Cooldown 4.\n\n\n";




    outputFile << "Professional  Abilities:\n";
    outputFile << "-----------------\n";
    outputFile << "Cleave\n";
    outputFile << "-------\n";
    outputFile << " Deals strength+dexterity damage. Cooldown 3.\n\n";

    outputFile << "Rush\n";
    outputFile << "-------\n";
    outputFile << "Deals 2*dexterity damage. Cooldown 4..\n\n";

    outputFile << "Bash\n";
    outputFile << "-------\n";
    outputFile << "Deals 2*strength damage. Cooldown 4.\n";





#pragma endregion


    


    std::cout << "\n \n \n \n";

    outputFile << endl << endl << endl << endl;


    // User can make two creatures
    std::cout << "Creature 1:\n";
    std::cout << "------------------------------------\n \n";

    Creature* creature1 = utils.createCreature();

    std::cout << "\n \n \n";

    std::cout << "\nCreature 2:\n";
    std::cout << "------------------------------------\n \n";
    Creature* creature2 = utils.createCreature();



    //// Roll dice to decide who goes first in each round
#pragma region RollDice

    std::cout << "\n \n \n";

    std::cout << "Press enter to roll dice. Even, then " << creature1->getName() <<  " starts, odd, then " <<  creature2->getName() << " starts.";


    std::cin.get();     // Wait for the user to press Enter

    std::cout << "\n";


    int diceRoll = utils.rollDice();

    std::cout << "The dice rolled: " << diceRoll << std::endl;

    // Check if the dice roll result is even or odd
    if (diceRoll % 2 == 0) {
        std::cout << "Even number rolled. " << creature1->getName() << " goes first in each round." << std::endl;

    }
    else {
        std::cout << "Odd number rolled. " << creature2->getName() << " goes first." << std::endl;
    }

    std::cout << "\n \n \n";



#pragma endregion


    ////The Countdown before the main game
#pragma region Countdown

    cout << endl << endl << "Game Starting In: " << endl;
    int gameCountdown = utils.countdown(5);

#pragma endregion



    //// The Game Loop
#pragma region GameLoop


    while (creature1->isAlive() && creature2->isAlive()) {



        // Announces the round
        std::cout << "\n \n \n \n";
        std::cout << "Round: " << round << "\n";
        std::cout << "------------------------------------\n";
        std::cout << "------------------------------------\n";

 //For .text file 
#pragma region ForFile


        outputFile << endl << endl << endl << endl;
        outputFile << "Round: " << round << "\n";
        outputFile << "------------------------------------\n";
        outputFile << "------------------------------------\n";


#pragma endregion



        // Both Creatures preforms their attacks
        if (diceRoll % 2 == 0) {

            creature1->action(creature1, creature2);
            creature2->action(creature2, creature1);


        }

        else {

            creature2->action(creature2, creature1);
            creature1->action(creature1, creature2);

        }








        if (diceRoll % 2 == 0) {

            // Prints the statuses

            utils.printStatus(creature1);
            utils.printStatus(creature2);


 //For .text file 
#pragma region ForFile


            utils.printStatusToFile(creature1, outputFile);
            utils.printStatusToFile(creature2, outputFile);

#pragma endregion

            




        }

        else {


            utils.printStatus(creature2);
            utils.printStatus(creature1);


//For .text file 
#pragma region ForFile


            utils.printStatusToFile(creature2, outputFile);
            utils.printStatusToFile(creature1, outputFile);


#pragma endregion


        }


        // Declares round over


       
        cmd->roundOver(creature1, creature2);
        round++;

        // Prints the attacks used 




        if (diceRoll % 2 == 0) {

            utils.printCreatureAttack(creature1);
            utils.printCreatureAttack(creature2);


 //For .text file 
#pragma region ForFile


            utils.printCreatureAttackToFile(creature1, outputFile);
            utils.printCreatureAttackToFile(creature2, outputFile);



#pragma endregion



        }


        else {


            utils.printCreatureAttack(creature2);
            utils.printCreatureAttack(creature1);

 //For .text file 
#pragma region ForFile


            utils.printCreatureAttackToFile(creature2, outputFile);
            utils.printCreatureAttackToFile(creature1, outputFile);


#pragma endregion




        }


        std::cout << endl;
        outputFile << endl;




    }


#pragma endregion

    //// Game End
#pragma region EndGame


    // Print the final winner

    if (creature1->isAlive()) {
        std::cout << creature1->getName() << " wins!\n";
        outputFile << creature1->getName() << " wins!" << endl;
    }
    else if (creature2->isAlive()) {
        std::cout << creature2->getName() << " wins!\n";
        outputFile << creature2->getName() << " wins!" << endl;
    }
    else {
        std::cout << "It's a tie!\n";
        outputFile << "It's a tie!" << endl;
    }

    // Clean up memory
    delete creature1;
    delete creature2;



#pragma endregion


    std::cout << endl << endl << endl << endl;



    std::cout << "\n \n \n \n";
    std::cout << "********************************************************************************************************************" << std::endl;
    std::cout << "                                                            Game Over         " << std::endl;
    std::cout << "********************************************************************************************************************" << std::endl << endl;



//For .text file 
#pragma region ForFile


    outputFile << endl << endl << endl << endl;
    outputFile << "********************************************************************************************************************" << std::endl;
    outputFile << "                                                            Game Over         " << std::endl;
    outputFile << "********************************************************************************************************************" << std::endl;




#pragma endregion


    std::cout << "A log of this game session will be saved at the directory";
    std::cout << "\n \n \n \n";

    outputFile.close(); // Close the output file


    return 0;
}
