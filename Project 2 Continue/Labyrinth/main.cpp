/*
 * Timothy Hanmann
 * October 13, 2013
 * Purpose: Labyrinth Puzzle/Challenge game
 */



//Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;


//Global Constants
char map[30][30]=  {"#############################",
                    "#    #   *  #               #",
                    "# *#   ######  #### ####### #",
                    "#  #*   #       #    ##     #",
                    "#  ###  #  ######*    #*  # #",
                    "#    *#     !########  #  # #",
                    "#  ##  #     #      #  #  # #",
                    "#  #*      *###  #  #  #  # #",
                    "#  #########*    #  ####  # #",
                    "#*            #  #*      *# #",
                    "############### *########## #",
                    "#                           #",
                    "#                           #",
                    "#@                          #",
                    "#############################"};
//No Function Prototypes

//Program starts here
int main(int argc, char** argv) {
    
    //Declare variables
    char ans, choice;
    int startTime, Level = 1, endTime;
    string newPlayer, oldPlayer;
    bool stopgame = false;
    int Gamespeed = 100, HP = 100, MaxHP = 100;
    
    do{
    //Opens up file to save/load Times
    ofstream fout;
    fout.open("Save.dat", ios::app);
    
    ifstream infile;
    infile.open ("Save.dat");
    
    // Welcome/Explanation on Labyrinth
    cout << "The point of Labyrinth is to reach the end of the maze" << endl
                << "while avoiding obstacles and keeping your HP above 0."
                << endl << endl << endl;
    
    
    //User inputs whether a new player or old player
    cout << "Is this your first time playing? (Y/N)" << endl;
    cin >> choice;
    
    //Brief introduction 
    if (choice == 'Y' || choice == 'y'){         
        cout << "What is your first name?" << endl;
        cin >> newPlayer;
        fout << newPlayer << endl;
        
        cout << "Welcome " << newPlayer << endl;       
       
    } else if (choice == 'N' || choice == 'n'){
    
        cout << "What is the name you used to save your progress?" << endl;
        cin >> oldPlayer;
        infile >> oldPlayer;
        cout << "Welcome back " << oldPlayer;        
    } else{ 
    
        cout << "Wrong choice of input." << endl;           
    }
    
   
    
    //User uses Arrow Keys to move
    while (stopgame == false && Level == 1){
          //system("cls");
          for (int y = 0; y < 30; y++)
          {
              cout << map[y] << endl;
          }
          cout << "HP: " << HP << "/" << MaxHP << endl;
          
          //If HP reaches 0 = Game Over.
          if (HP == 0){
              system("pause");
              cout << "You Have Ran Out Of Health Points. Game Over." << endl;
              return EXIT_SUCCESS;
          }
          //Mapping for @ to keep within walls
          for (int y = 0; y < 30; y++){
              for (int x = 0; x < 30; x++){
                  
              
              switch(map[y][x]){
                  case '#':{
                      map[y][x] = 219;
                  }
              case '@':
              { //Arrow Mapping for Up Key
                if (GetAsyncKeyState (VK_UP) != 0)
             {                    
                     int y2 = (y-1);
                  
                  switch (map[y2][x]){
                         case ' ':
                              {
                                  map[y][x] = ' ';
                                  y -= 1;
                                  map[y2][x]= '@';
                                  }break;
                      case '!':{
                          Level = 2;
                      }break;
                      case '*':{//Loss of HP
                                  HP -= 20;
                                  map[y][x] = ' ';
                                  y -= 1;
                                  map[y2][x]= '@';
                      }break;
                         }
                   }//Arrow Mapping for Down Key
                if(GetAsyncKeyState (VK_DOWN) != 0){
                    
                    int y2 = (y + 1);
                    
                    switch(map[y2][x]){
                        case ' ':{
                                 map[y][x] = ' ';
                                 y += 1;
                                 map[y2][x]= '@'; 
                        }break;
                        case '!':{
                            Level = 2;
                        }break;
                        case '*':{//Loss of HP
                                  HP -= 20;
                                  map[y][x] = ' ';
                                  y += 1;
                                  map[y2][x]= '@';
                        }break;
                    }
                } //Arrow Mapping for Right Key
                if (GetAsyncKeyState (VK_RIGHT) != 0){
                    int x2 = (x + 1);
                    
                    switch(map[y][x2]){
                        case ' ':{
                                 map[y][x] = ' ';
                                 x += 1;
                                 map[y][x2]= '@';
                        }break;
                        case '!':{
                            Level = 2;
                        }break;
                        case '*':{//Loss of HP
                                  HP -= 20;
                                  map[y][x] = ' ';
                                  x += 1;
                                  map[y][x2]= '@';
                        }break;
                    }
                } //Arrow Mapping for Left Key
                if (GetAsyncKeyState (VK_LEFT) !=0){
                    int x2 = (x - 1);
                    
                    switch (map[y][x2]){
                        case ' ':{
                                  map[y][x] = ' ';
                                  x -= 1;
                                  map[y][x2]= '@';
                        }break;
                        case '!':{
                            Level = 2;
                        }break;
                        case '*':{//Loss of HP
                                  HP -= 20;
                                  map[y][x] = ' ';
                                  x -= 1;
                                  map[y][x2]= '@';
                        }break;
                    }
                }
                
                }break;
             }
          }
       }
          Sleep(Gamespeed);
   }cout << "Would you like to play the game again?" << endl;
   cin >> ans;
 } while (ans == 'Y' || ans == 'y');
    return 0;
}

