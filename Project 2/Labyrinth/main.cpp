/*
 * Timothy Hanmann
 * November 22, 13
 * Project 2 Labyrinth
 */

#include <windows.h>
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;

//Global Constants
const char WIDTH = 30, HEIGHT = 30;


//Function Prototypes
unsigned char map1[WIDTH][HEIGHT]=  
                   {"############################",
                    "#    #   *  #              #",
                    "# #   ######  #### ####### #",
                    "# #*   #       #    ##     #",
                    "# ###  #  ######*    #*  # #",
                    "#   *#     !########  #  # #",
                    "# ##  #     #      #  #  # #",
                    "# #*      *###  #  #  #  # #",
                    "# #########*    #  ####  # #",
                    "#            #  #*      *# #",
                    "############## *########## #",
                    "#..........................#",
                    "#..........................#",
                    "#..........................#",
                    "############################"};

unsigned char currentMap[WIDTH][HEIGHT];
void printMap(int, int);
bool stopGame(bool,int,int,int,int);
int NumKey(int,int,int,int);
char player = '@';
int playerX = 1, playerY = 1;

int main(int argc, char** argv) {
    
    //Declare variables
    int Level = 1;
    int width, height;
    int left, right,up,down;
    bool gameOver = false;
    
    
    printMap(width, height);
    
    
   // ArrowKey(left, right, up, down);
    
    //stopGame(gameOver, left, right,up, down);

  while(gameOver == false){
      currentMap[playerX][playerY] = player;
      if (GetAsyncKeyState (VK_NUMPAD8)){
          currentMap[playerX][playerY + 1];
          playerY++;   
      } if (GetAsyncKeyState (VK_NUMPAD2)){
          currentMap[playerX][playerY - 1];
          playerY--;   
      } if (GetAsyncKeyState (VK_NUMPAD6)){
          currentMap[playerX + 1][playerY];
          playerX++;   
      } if (GetAsyncKeyState (VK_NUMPAD4)){
          currentMap[playerX - 1][playerY];
          playerX--;   
      }
  }
    
   return 0;
}
void printMap(int x, int y){
    system("CLS");
   for(x = 0;x < WIDTH;x++){
        for( y = 0; y < HEIGHT;y++){
            currentMap[x][y] = map1[x][y];
        }
    }
  
  currentMap[playerX][playerY] = player;

for(x = 0; x < WIDTH;x++){
        cout << endl;
        for(y = 0;y < HEIGHT;y++){
            cout << currentMap[x][y];
        }
    }  
}

/*int ArrowKey(int x, int y, int Level, int HP){
 switch(currentMap[x][y]){
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
                          Level = 2;
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
                            Level = 2;
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
                            Level = 2;
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
                            Level = 2;
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
}*/
bool stopGame(bool go, int x, int y, int HP, int Level){
    while(go == false){
        switch(currentMap[x][y]){
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
                          Level = 2;
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
                            Level = 2;
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
                            Level = 2;
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
                            Level = 2;
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