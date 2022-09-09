#pragma once
#include "list.h"
#include "word.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

//prototypes
int main();
//open the file
bool openFile(fstream &file, char fileName[]); 
//load the file
void load(fstream &file);



