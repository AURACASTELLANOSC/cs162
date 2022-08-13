#include "word.h"

using namespace std;

//default constructor
word::word()
{
   //allocate memory for data first
   data = nullptr; 
   count = 0;
}

//destructor
word::~word()
{
   //cout  << "Destructor" << endl;
   //deallocates memory for data
   if(data)
   {
      delete []data;
      data = nullptr;
   }
}

//may include const, acces, mutators and helpers
//mutators
void word::setData( char *newData)
{
   if(data)
   {
      delete []data;
      data = nullptr;
    }
    cout << newData << endl;
   data= new char[strlen(newData) + 1];
   memset(data, 0, strlen(newData) + 1); 
   strcpy(data, newData);
   cout << "data" << data << endl;
   delete [] newData; 
}

void word::setCount()
{
   //increment one every time the word is repeated
   count++; 
}

//accessor
void word::getData( char *returnData)
{ 
   strcpy(returnData, data);
  cout << "returndata " << returnData << endl;
}

int  word::getLength()
{
   if(data == nullptr)
   {
       return 0;
   }
   else 
   {
	   cout << data << endl;
      return strlen(data); 
   }
}
int  word::getCount()
{
   return count; 
}

//print
void word::printWord()
{
   cout << "word: " << data << " Count: " << count << endl;
}
