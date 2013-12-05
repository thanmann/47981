/*
 * Timothy Hanmann
 * November 22, 13
 * Project 2 Labyrinth
 */

#include <windows.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
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
const char WIDTH = 30, HEIGHT = 30;


//Function Prototypes
unsigned char map1[HEIGHT][WIDTH]=  
                   {"############################",
                    "#@   #   *  #              #",
                    "# #   ######  #### ####### #",
                    "# #*   #       #    ##     #",
                    "# ###  #  ######*    #*  # #",
                    "#   *#     !########  #  # #",
                    "# ##  #     #      #  #  # #",
                    "# #*      *###  #  #  #  # #",
                    "# #########*    #  ####  # #",
                    "#            #  #*      *# #",
                    "############## *########## #",
                    "#                          #",
                    "#                          #",
                    "#                          #",
                    "############################"};

unsigned char currentMap[HEIGHT][WIDTH];
void printMap(int, int);
void clear();
//char player = '@';
//int playerX = 1, playerY = 1;
int timer(int, int);
void LevelMenu();

int main(int argc, char** argv) {
    
    //Declare variables
    int minutes,seconds;
    string newPlayer;
    int width, height,userinput ;
    int left,right,up,down;
    bool gameOver = false;
    int HP=0, MaxHp=100, gamespeed=100;
    char ans, choice;
    
    //Opens up file to save/load Times
    ofstream fout;
    fout.open("Save.dat", ios::app);
    
    ifstream infile;
    infile.open ("Save.dat");
    
    
    do{
        // Welcome/Explanation on Labyrinth
    cout << "The point of Labyrinth is to reach the end of the maze" << endl
                << "while avoiding obstacles and keeping your HP above 0."
                << endl << endl << endl;
    cout << "Are you new to the game?" << endl;
    cin >> choice;
    if (choice == 'Y' || choice == 'y'){
        cout << "What is your first name?" << endl;
        cin >> newPlayer;
        fout << newPlayer << endl;
        LevelMenu();
        cin >> userinput;
        
    } else{
           LevelMenu();
           cin >> userinput;
}          
                   
    

    
    
while (gameOver == false && choice == 1){
        for( int y=0;y<30;y++){
           cout << map1[y];
        }
      clear();
      //timer(minutes,seconds);
    for(int y = 0;y < 30;y++){
        for(int x = 0; x < 30;x++){
            
            switch(map1[y][x]){
                  case '#':{
                      map1[y][x] = 219;
                  }
              case '@':
              { //Arrow Mapping for Up Key
                if (GetAsyncKeyState (VK_UP) != 0){                    
                     int y2 = (y+1);
                  
                  switch (map1[y2][x]){
                         case ' ':
                              {
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
    }cout << "Would you like to play the game again?" << endl;
    cin >> ans;
 }while (ans == 'Y' || ans == 'y');
   system("PAUSE");
   return EXIT_SUCCESS;
}

void LevelMenu(){
     cout << "Which map would you like to choose?" << endl;
     cout << "Map 1: " << endl << endl
            <<      "############################\n" 
            <<      "#      *  #                #\n" 
            <<      "# #   ######  #### ####### #\n" 
            <<      "# #*   #       #    ##     #\n" 
            <<      "# ###  #  ######*    #*  # #\n" 
            <<      "#   *#     !########  #  # #\n" 
            <<      "# ##  #     #      #  #  # #\n" 
            <<      "# #*      *###  #  #  #  # #\n" 
            <<      "# #########*    #  ####  # #\n" 
            <<      "#            #  #*      *# #\n" 
            <<      "############## *########## #\n"
            <<      "#                          #\n"
            <<      "#                          #\n"
            <<      "#@                         #\n"
            <<      "############################\n" << endl;
}

int timer(int min,int sec){
    sec=0;
    min=0;
    for(sec=0;sec <=60;sec++){
                  cout << min<< ":" << sec << endl;
    if(sec == 60){           
           min += 1;
           sec=0;
    }
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
