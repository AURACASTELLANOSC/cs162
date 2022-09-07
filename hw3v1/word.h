#pragma once
#include <fstream>
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

class word
{
     public:
     //default constructor
     word();
     //destructor
     ~word();
     //copy constructor
     word(const word& source);
     //copy assignment operator
     word& operator=(const word& source);
     //mutators
     void setData(char *newData);
     void setCount();
     //accessors
     int getLength(); 
     void getData(char *returnData);
     int getCount();
     void printWord();
     private:
     char *data; //dynamic c-string contains word text
     int count;  //number of times the word appears in the input file
};

