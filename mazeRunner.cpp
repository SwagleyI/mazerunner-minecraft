#include <iostream>

#include <mcpp/mcpp.h>

#include "menuUtils.h"
#include "Maze.h"
#include "Agent.h"

#define NORMAL_MODE 0
#define TESTING_MODE 1

mcpp::MinecraftConnection *mc_conn;

enum States {
    ST_Main,
    ST_GetMaze,
    ST_SolveMaze,
    ST_Creators,
    ST_Exit
};

int main(void){
    int selection;
    //bool mode = NORMAL_MODE;
    //read Mode

    

    mcpp::MinecraftConnection mc; 
    mc.doCommand("time set day"); 
    printStartText();
    States curState = ST_Main;

    //State machine for menu        
    while (curState != ST_Exit)
    {
       printMainMenu();
       std::cin >> selection;
        if (selection == 1){
            curState = ST_GetMaze;
            while (curState == ST_GetMaze){
                printGenerateMazeMenu();
                    //std::cin >> selection;
                    //if (selection == 1){
                    //     go to read maze
                    //if 2 go to random Maze
                    //if 3 curState = ST_Main
                    // add catch for number not between 1-5
                }
            }
        else if (selection == 2){
            //build maze function
            // just goes
        }
        else if (selection == 3){
            curState = ST_SolveMaze;
            while (curState == ST_GetMaze){
                printSolveMazeMenu();
                std::cin >> selection;
                if (selection == 2){
                    mcpp::Coordinate pos = (*mc_conn).getPlayerPosition();
                    Agent agent(pos);
                }

                // if 1 go to solve manually
                // if 2 go to show escape route 
                //if 3 curState = ST_Main
                // add catch for number not between 1-5
            }
        }
        else if (selection == 4){
            curState = ST_Creators;
            printTeamInfo();
            // show team info
            
        }
        else if (selection == 5){
            curState = ST_Exit;
        }
        else {
            std::cout << "Input Error: Enter a number between 1 and 5 ....";
        }
    }

    printExitMassage();


    return EXIT_SUCCESS;


}