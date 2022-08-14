#include "list.h"

using namespace std;

//default constructor
list::list()
{
  cout << "call default list"  << endl;
   index = nullptr; 
   size = 0;
}

//destructor
list::~list()
{
  // cout << "call to destructor" << endl;
   //deallocate memory for index
   cout<<"Test"<<endl;
   if(index)
   {
      delete []  index;
      index = nullptr;
   }
}

void list::insert(char * newWord)
{ 
   int i = 0;
   char *tempWord = nullptr;      
   bool wordExist = false;
   
   if (size == 0)
   {

      index[size].setData(newWord);
      index[size].setCount();
      size++; 
      wordExist = true; 
   }
   
   for(i = 0; i < size; i++)
   {
      tempWord = new char[index[i].getLength() + 1]{0};//init to 0  
      index[i].getData(tempWord);
      if(strcmp(newWord,tempWord) == 0)
      {
	      wordExist = true;
	      index[i].setCount(); 
	      break;  
      }
      delete []tempWord; 
   }
   if(!wordExist)
   {  
      //resize 
       //copy it 
    // word *tempindex = new word [++size]; 
    //  delete []index; 
    //  index = tempindex;  

      index[size - 1].setData(newWord);
      index[size - 1].setCount();
   }
}

void list::print()
{
   for(int i = 0; i < size; i++)
   {
      index[i].printWord();
      cout << endl;
   }
}
