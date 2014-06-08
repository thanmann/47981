/*
 * Code for Level Menu
 */
#pragma once
#include "scoreboard.h"
#include<iostream>
#include<fstream>


using namespace std;

//Function Prototypes
unsigned char map1[30][30]=  
                   {"############################",
                    "#@   #   *  #              #",
                    "# #   ######  #### ####### #",
                    "# #*   #       #    ##     #",
                    "# ###  #  ######*    #*  # #",
                    "#   *#   #  ########  #  # #",
                    "# ##  #     #      #  #  # #",
                    "# #*      *###  #  #  #  # #",
                    "# #########*    #  ####  # #",
                    "#            #  #*      *# #",
                    "### ##### #### *########## #",
                    "###   # # #  #    #    ##  #",
                    "##   ###     ### ## # # #  #",
                    "####           #  ##  #   !#",
                    "############################"};
unsigned char map2[30][30]=  
                   {"############################", 
                    "#!   ##     # ##############", 
                    "##       #  #              #", 
                    "# # ######     ######## #  #", 
                    "# ###    #######    #   #  #", 
                    "#  ## ##         #  #   #  #", 
                    "##    ## #########  #   #  #", 
                    "##               ##  ###   #", 
                    "###   ########    #        #", 
                    "###  ########     ##########", 
                    "### ####      ###   ##     #",
                    "#####  # ##########    ### #",
                    "######## ################# #",
                    "#@                         #",
                    "############################",};

/*void LevelMenu();
void clear();*/

//Function Definitions
void LevelMenu(){
   
    int mChoice, test;
    char choice;
    
    cout << test << endl;
    cout << "Map 1: " << endl << endl
            <<    "############################\n" 
            <<    "#@     *  #                #\n" 
            <<    "# #   ######  #### ####### #\n" 
            <<    "# #*   #       #    ##     #\n" 
            <<    "# ###  #  ######*    #*  # #\n" 
            <<    "#   *#      ########  #  # #\n" 
            <<    "# ##  #     #      #  #  # #\n" 
            <<    "# #*      *###  #  #  #  # #\n" 
            <<    "# #########*    #  ####  # #\n" 
            <<    "#            #  #*      *# #\n" 
            <<    "############## *########## #\n"
            <<    "###   # # #  #    #    ##  #\n"
            <<    "##   ###     ### ## # # #  #\n"
            <<    "####           #  ##  #   !#\n"
            <<    "############################\n" << endl;
    
    cout << "Which map would you like to choose?"<< endl;
    cout << "Press 2 to view the 2nd map." << endl;
    cin >> mChoice;
    
    
    switch(mChoice){
        case 1:
     cout << "Map 1: " << endl << endl
            <<    "############################\n" 
            <<    "#@     *  #                #\n" 
            <<    "# #   ######  #### ####### #\n" 
            <<    "# #*   #       #    ##     #\n" 
            <<    "# ###  #  ######*    #*  # #\n" 
            <<    "#   *#      ########  #  # #\n" 
            <<    "# ##  #     #      #  #  # #\n" 
            <<    "# #*      *###  #  #  #  # #\n" 
            <<    "# #########*    #  ####  # #\n" 
            <<    "#            #  #*      *# #\n" 
            <<    "############## *########## #\n"
            <<    "###   # # #  #    #    ##  #\n"
            <<    "##   ###     ### ## # # #  #\n"
            <<    "####           #  ##  #   !#\n"
            <<    "############################\n" << endl;
     cout << "\nDo you choose this map? Type Y.";
     cin >> choice;
         break;
        case 2: 
     cout << "Map 2: " << endl << endl
            <<    "############################\n" 
            <<    "#!   ##     # ##############\n" 
            <<    "##       #  #              #\n" 
            <<    "### ######     ######## #  #\n" 
            <<    "#####    #######    #   #  #\n" 
            <<    "# ### ##         #  #   #  #\n" 
            <<    "##    ## #########  #   #  #\n" 
            <<    "##               ##  ###   #\n" 
            <<    "###   ########    #        #\n" 
            <<    "###  ########     ##########\n" 
            <<    "### ####      ###   ##     #\n"
            <<    "#####  # ##########    ### #\n"
            <<    "######## ################# #\n"
            <<    "#@                         #\n"
            <<    "############################\n" << endl;
     cout << "\nDo you choose this map? Type Y.";
     cin >> choice;
     if(choice == 'N' || choice == 'n'){
         
     }
        break;
        default: cout << "That is not a map choice." << endl;
        break;
  }
}
    

void clear(){

#ifdef _WIN32
	if ( hConsoleOutput == 0 )
	{
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hConsoleOutput, &csbi);
	}
#endif

	 fflush(stdout);
#ifdef _WIN32
	{
		COORD point;
		DWORD dummy;
		DWORD count;

		point.X = 0;
		point.Y = 0;
		count	= csbi.dwSize.X * csbi.dwSize.Y;

		FillConsoleOutputCharacter(hConsoleOutput, ' ', count, point, &dummy);
		SetConsoleCursorPosition(hConsoleOutput, point);
	}
#else
		 printf("\033[H\033[2J");
#endif
	 fflush(stdout);
}