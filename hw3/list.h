#pragma once
#include "word.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

class list
{
      public:
      //default constructor
      list();
      //destructor
      ~list();
      //copy constructor
     // list(const list&);
      //copy assignment operator

      //may in constr,acces, mutat, and helpe
      //insert() insert words into the index array
      void insert( char *newWord); 
      //print() display contents of the index aray
      void print(); 
      private:
      word *index; //dynamic array of word objects
      int size; //num of elements in the array
};
