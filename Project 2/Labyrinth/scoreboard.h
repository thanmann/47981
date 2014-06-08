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

