#pragma once
#include "word.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

class list
{
      private:
      struct node {
        word * data;
        node * next;
       };
        node * index;
      public:
      //default constructor
      list();
      //destructor
      ~list();
      //copy constructor
      list(const list&);
      //copy assignment operator
      list& operator=(const list&);
      //may in constr,acces, mutat, and helpe
      //insert() insert words into the index array
      void insert(char *newWord); 
      //print() display contents of the index aray
      void print(); 
};
