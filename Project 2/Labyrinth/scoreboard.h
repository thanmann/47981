/*
 * scoreboard.h prototypes
 */

//Libraries
#pragma once
#include "levelmenu.h"
#include<iostream>
#include<windows.h>
#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;

//Function Prototypes
void fillBoard(vector<int>&,string&);//

void sortBoard(vector<int>&,string);

void printBoard(vector<int>&,string);

void storage(); //stores players name/specific map times

float timer(float,float,bool); //timer for how long it takes player
                               //to finish maze

