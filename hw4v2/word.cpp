#include "word.h"

using namespace std;

//default constructor
word::word()
{
   //allocate memory for data first
   data = new char[9];
   strcpy(data, "new data"); 
   count = 0;
}

//destructor
word::~word()
{
   if(data)
   {
        delete []data; 
	data  =nullptr;
   }
}
//assignment operator
word& word::operator=(const word& source)
{
   if(this !=&source)
   {
	   this->setData(source.data);
	   this->count = source.count; 
   }
   return *this;
}
//copy constructor
word::word(const word&source)
{
   if(this !=&source)
   {
      data = new char[strlen(source.data)+ 1];
      *this = source; 
   }
}

//may include const, acces, mutators and helpers
//mutators
void word::setData( char *newData)
{
  if(data){
      	  delete [] data; 
     data = nullptr;
  }
  int sizenew = sizeof(newData); 
  data = new char [sizenew + 2];
  strcpy(this->data, newData);
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
}

int  word::getLength()
{
   if(data == nullptr)
   {
       return 0;
   }
   else 
   {
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
