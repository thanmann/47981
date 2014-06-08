/*
 * Timothy Hanmann
 * November 22, 13
 * Project 2 Labyrinth CSC 7
 */

//Libraries
#include "scoreboard.h"
#include "levelmenu.h"
#include <windows.h>
#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstdlib>
//Function from Joshua Camacho don't credit for line count
#ifdef _WIN32
#endif
#ifdef _WIN32
static HANDLE                     hConsoleOutput = 0;
static CONSOLE_SCREEN_BUFFER_INFO csbi;
#endif
using namespace std;

//Global Constants



//Function Prototypes
void clear();
//float timer(float,float,bool);
//void LevelMenu();
void Scoreboard();

//Execution starts here
int main(int argc, char** argv) {
    
    //Declare variables
    string newPlayer;
    int sec,min;
     bool gameOver = false;
    int HP=100, MaxHP=100, gamespeed=100;
    char ans,choice;
    time_t start = 0;
    time_t end = 0;
    time_t elapsed = 0;
    vector<int> numPlayers;
    string namePlayers;
    
    
    

    
    
    do{
        
    storage(namePlayers);
    //fillBoard(numPlayers, namePlayers);
    //printBoard(numPlayers, namePlayers);
           
        /*// Welcome/Explanation on Labyrinth
    cout << "The point of Labyrinth is to reach the end of the maze" << endl
                << "while avoiding obstacles and keeping your HP above 0."
                << endl << endl << endl;
    cout << "Are you new to the game?" << endl;
    cin >> choice;
    
    //Level choice for player
    if (choice == 'Y' || choice == 'y'){
        cout << "The controls for the game are the arrow keys." << endl; //Controls
        cout << "What is your first name?" << endl;
        cin >> newPlayer;
        fout << newPlayer << endl;
        LevelMenu();
        cin >> mChoice;
        start = time(NULL);      
    } else{
         cout << "The controls for the game are the arrow keys." << endl; //Controls
           LevelMenu();
           cin >> mChoice;
           start = time(NULL);
}   */
   //Arrow keys for Map 1
   while (gameOver == false && choice == 'Y' || choice == 'y'){
       
       for( int y=0;y<30;y++){
           cout << map1[y] << endl;  
        }
       
       cout << "Time: " << time << endl;
       cout << "HP:  " << HP << "/" << MaxHP << endl;
    for(int y = 0;y < 30;y++){
        for(int x = 0; x < 30;x++){
            
            //Walls
            switch(map1[y][x]){
                  case '#':{
                      map1[y][x] = 219;
                  }
              case '@': //The Player
              { //Arrow Mapping for Up Key
                if (GetAsyncKeyState (VK_UP) != 0){                    
                     int y2 = (y-1);
                  
                  switch (map1[y2][x]){
                         case ' ':
                              {
                                  map1[y][x] = ' ';//old space
                                  y -= 1;
                                  map1[y2][x]= '@';//Occupies new space
                                  }break;
                      case '!':{//When the end is reached
                          gameOver=true;
                      }break;
                      case '*':{//Loss of HP
                                  HP -= 20;
                                  map1[y][x] = ' ';
                                  y -= 1;
                                  map1[y2][x]= '@';
                      }break;
                         }
                   }//Arrow Mapping for Down Key
                if(GetAsyncKeyState (VK_DOWN) != 0){
                    
                    int y2 = (y + 1);
                    
                    switch(map1[y2][x]){
                        case ' ':{
                                 map1[y][x] = ' ';
                                 y += 1;
                                 map1[y2][x]= '@';
                        }break;
                        case '!':{
                            gameOver=true;
                        }break;
                        case '*':{//Loss of HP
                                  HP -= 20;
                                  map1[y][x] = ' ';
                                  y += 1;
                                  map1[y2][x]= '@';
                        }break;
                    }
                } //Arrow Mapping for Right Key
                if (GetAsyncKeyState (VK_RIGHT) != 0){
                    int x2 = (x + 1);
                    
                    switch(map1[y][x2]){
                        case ' ':{
                                 map1[y][x] = ' ';
                                 x += 1;
                                 map1[y][x2]= '@';
                        }break;
                        case '!':{
                            gameOver=true;
                        }break;
                        case '*':{//Loss of HP
                                  HP -= 20;
                                  map1[y][x] = ' ';
                                  x += 1;
                                  map1[y][x2]= '@';
                        }break;
                    }
                } //Arrow Mapping for Left Key
                if (GetAsyncKeyState (VK_LEFT) !=0){
                    int x2 = (x - 1);
                    
                    switch (map1[y][x2]){
                        case ' ':{
                                  map1[y][x] = ' ';
                                  x -= 1;
                                  map1[y][x2]= '@';
                        }break;
                        case '!':{
                           gameOver=true;
                        }break;
                        case '*':{//Loss of HP
                                  HP -= 20;
                                  map1[y][x] = ' ';
                                  x -= 1;
                                  map1[y][x2]= '@';  
                        }break;
                    }
                }
                
                }break;
             }          
         }
       }
       Sleep(gamespeed);
       // end = time(NULL);
        //elapsed = end - start;      
    clear();
    }
    //cout << "This is how long it took you: " << elapsed << " seconds" << endl << endl;
    //Arrow Keys for Map 2
 /*while (gameOver == false && mChoice == 2){
        for( int y=0;y<30;y++){
           cout << map2[y] << endl;  
        }        
    for(int y = 0;y < 30;y++){
        for(int x = 0; x < 30;x++){
            

            switch(map2[y][x]){
                  case '#':{
                      map2[y][x] = 219;
                  }
              case '@':
              { //Arrow Mapping for Up Key
                if (GetAsyncKeyState (VK_UP) != 0){                    
                     int y2 = (y-1);
                  
                  switch (map2[y2][x]){
                         case ' ':
                              {
                                  map2[y][x] = ' ';
                                  y -= 1;
                                  map2[y2][x]= '@';
                                  }break;
                      case '!':{
                          gameOver=true;
                      }break;
                      case '*':{//Loss of HP
                                  HP -= 20;
                                  map2[y][x] = ' ';
                                  y -= 1;
                                  map2[y2][x]= '@';
                      }break;
                         }
                   }//Arrow Mapping for Down Key
                if(GetAsyncKeyState (VK_DOWN) != 0){
                    
                    int y2 = (y + 1);
                    
                    switch(map2[y2][x]){
                        case ' ':{
                                 map2[y][x] = ' ';
                                 y += 1;
                                 map2[y2][x]= '@';
                        }break;
                        case '!':{
                            gameOver=true;
                        }break;
                        case '*':{//Loss of HP
                                  HP -= 20;
                                  map2[y][x] = ' ';
                                  y += 1;
                                  map2[y2][x]= '@';
                        }break;
                    }
                } //Arrow Mapping for Right Key
                if (GetAsyncKeyState (VK_RIGHT) != 0){
                    int x2 = (x + 1);
                    
                    switch(map2[y][x2]){
                        case ' ':{
                                 map2[y][x] = ' ';
                                 x += 1;
                                 map2[y][x2]= '@';
                        }break;
                        case '!':{
                            gameOver=true;
                        }break;
                        case '*':{//Loss of HP
                                  HP -= 20;
                                  map2[y][x] = ' ';
                                  x += 1;
                                  map2[y][x2]= '@';
                        }break;
                    }
                } //Arrow Mapping for Left Key
                if (GetAsyncKeyState (VK_LEFT) !=0){
                    int x2 = (x - 1);
                    
                    switch (map2[y][x2]){
                        case ' ':{
                                  map2[y][x] = ' ';
                                  x -= 1;
                                  map2[y][x2]= '@';
                        }break;
                        case '!':{
                           gameOver=true;
                        }break;
                        case '*':{//Loss of HP
                                  HP -= 20;
                                  map2[y][x] = ' ';
                                  x -= 1;
                                  map2[y][x2]= '@';  
                        }break;
                    }
                }
                
                }break;
             }   *  
         }
       }
        end = time(NULL);
        elapsed = end - start;
    Sleep(gamespeed);
    clear();
    cout << "This is how long it took you: " << elapsed << " seconds" << endl << endl;
    }*///cout << "Would you like to play the game again?" << endl;
   // cin >> ans;
 }while (ans == 'Y' || ans == 'y');
 
 return 0;
}

//Function Definitions
void storage(string &playerName){
    
    char uChoice;
//    int &test;
    
    //Opens up file to save/load Times
    ofstream fout;
    fout.open("SavedPlayers.txt", ios::app);
    
    ifstream infile;
    infile.open ("SavedPlayers.txt");
    
    
    
    
    //Prompt for new player
    cout << "Are you are new player to the game? Y or N" << endl;
    cin >> uChoice;
    
    //If new player, adds you too save file
     if(uChoice == 'Y' || uChoice == 'y'){
            cout << "What is your name?" << endl;
             cin >> playerName;
             fout << playerName << endl;
             LevelMenu();          
        }else
            cout << "What is your saved name?" << endl;
            
        }
            
        

void fillBoard(vector<int>&numPlayers,string &playerName){
    
    char uChoice;
 
    storage(playerName);
    cout << "Are you are new player to the game? Y or N" << endl;
    cin >> uChoice;
    
    switch(uChoice){
        case 1: if (uChoice == 'Y' || uChoice == 'y'){
            cout << "What is your name?" << endl;
        }
    }
    
     //Players name       
    for(int i = 0;i < numPlayers.size();i++){
        cout << endl << "Enter the names of players: ";
        cin >> playerName;
       
    }
    
}

void printBoard(vector<int>&numPlayers,string playerName){
    
    cout << "Scoreboard:  " << endl;     
    for(int i = 0;i < numPlayers.size();i++){
        for(int y = 0;y < numPlayers.size();y++){
          cout << numPlayers[y] << " " << playerName[i] << endl;  
        }
        
    }
}


void LevelMenu(){
   
    int mChoice, test;
    char choice;
    
   // cout << test << endl;
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
     if(choice == 'N' || choice == 'n'){
     cout << "\nDo you choose this map? Type Y.";
     cin >> choice;
    }break;
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
     if(choice == 'N' || choice == 'n'){
     cout << "\nDo you choose this map? Type Y.";
     cin >> choice;
     }break;
        default: cout << "That is not a map choice." << endl;
        break;
  }
}
  


float timer(float sec,float min, bool sub){
    sub == false;
    for(sec = 0; sec >= 60;sec++){
        if (sec == 60 && sub == false){
            min += 1;
            sec = 0;
        }
        cout << min << " ; " << sec << endl;
    }
}

//Function from Joshua Camacho don't credit for line count
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
