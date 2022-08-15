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
   if(data)
   {
      data = nullptr;
   }
}

//may include const, acces, mutators and helpers
//mutators
void word::setData(char *newData)
{
   data = new char[strlen(newData) + 1];
   memset(data, 0, strlen(newData) + 1); 
   strcpy(data, newData);
}

void word::setCount()
{
   count++; 
}

//accessor
void word::getData( char *returnData)
{ 
   strcpy(returnData, data);
  //cout << "returndata " << returnData << endl;
}

int  word::getLength()
{
   if(data == nullptr)
   {
       return 0;
   }
   else 
   {
	   //cout << data << endl;
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
   cout << "[Word]: " << data << " [Count]: " << count << endl;
}
