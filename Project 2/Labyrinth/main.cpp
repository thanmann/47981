/*
 * Timothy Hanmann
 * November 22, 13
 * Project 2 Labyrinth
 */

#include <windows.h>
#include <iomanip>
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
                    "### ######     ######## #  #", 
                    "#####    #######    #   #  #", 
                    "# ### ##         #  #   #  #", 
                    "##    ## #########  #   #  #", 
                    "##               ##  ###   #", 
                    "###   ########    #        #", 
                    "###  ########     ##########", 
                    "### ####      ###   ##     #",
                    "#####  # ##########    ### #",
                    "######## ################# #",
                    "#@                         #",
                    "############################",};

void clear();
float timer(float,float,bool);
void LevelMenu();

int main(int argc, char** argv) {
    
    //Declare variables
    string newPlayer;
    int mChoice,sec,min;
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
    
    //Level choice for player
    if (choice == 'Y' || choice == 'y'){
        cout << "What is your first name?" << endl;
        cin >> newPlayer;
        fout << newPlayer << endl;
        LevelMenu();
        cin >> mChoice;
        
    } else{
           LevelMenu();
           cin >> mChoice;
}             
   while (gameOver == false && mChoice == 1){
        for( int y=0;y<30;y++){
           cout << map1[y] << endl;  
        }        
    for(int y = 0;y < 30;y++){
        for(int x = 0; x < 30;x++){
            

            switch(map1[y][x]){
                  case '#':{
                      map1[y][x] = 219;
                  }
              case '@':
              { //Arrow Mapping for Up Key
                if (GetAsyncKeyState (VK_UP) != 0){                    
                     int y2 = (y-1);
                  
                  switch (map1[y2][x]){
                         case ' ':
                              {
                                  map1[y][x] = ' ';
                                  y -= 1;
                                  map1[y2][x]= '@';
                                  }break;
                      case '!':{
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
              for(int i = 0;i <= 60;i++){
        sec = i;
        min = 0;
        if(sec == 60 || gameOver == false){
            min += 1;           
        }
        
    }
         }
       }
    Sleep(gamespeed);
    clear();
    }
 while (gameOver == false && mChoice == 2){
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
             }
              for(int i = 0;i <= 60;i++){
        sec = i;
        min = 0;
        if(sec == 60){
            min++;
            sec = 0;
        }
        
    }
         }
       }
    Sleep(gamespeed);
    clear();
    }cout << "Would you like to play the game again?" << endl;
    cin >> ans;
    cout << min << ":" << sec << endl;

 }while (ans == 'Y' || ans == 'y');
 
 return 0;
}

void LevelMenu(){
     cout << "Which map would you like to choose?" << endl;
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
}

/*float timer(float sec,float min, bool sub){
    sub == false;
    for(sec = 0; sec >= 60;sec++){
        if (sec == 60 && sub == false){
            min += 1;
            sec = 0;
        }
        cout << min << " ; " << sec << endl;
    }
}*/

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
