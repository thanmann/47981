/*
 * Code for Scoreboard
 */

//Libraries
#pragma once
#include "levelmenu.h"
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;

//Function Prototypes
void fillBoard(vector<int>&,string&);
void sortBoard(vector<int>&,string);
void printBoard(vector<int>&,string);
void storage(string &);

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

