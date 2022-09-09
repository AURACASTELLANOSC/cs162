#include "list.h"

using namespace std;

//default constructor
list::list()
{
  cout << "call default list"  << endl;
  size = 0;
  index  = nullptr;
}

//destructor
list::~list()
{
   if(index)
   {
      delete []  index;
      index = nullptr;
   }
}
//assignment operator
list& list::operator=(const list& source)
{
   if(this != &source)
   {
      if(index)
      {
         delete []index;
         index = nullptr;
      }
      index = new word[source.size];
      this->index = source.index;
      this->size = source.size;
   }
   return *this;
}
//copy constructor
list::list(const list&source)
{
      index = new word[source.size];    
      this->index = source.index;
     this->size = source.size;
}
//insert the new word
void list::insert(char * newWord)
{ 
   bool existWord = false;
   char * tempWord = nullptr; 
  
   for (int i = 0; i < size; i++)
   {
      tempWord = new char[index[i].getLength() + 2]{0};
      //Get data value from word instance in index[i]
      index[i].getData(tempWord);
      //If word exist then
      if(strcmp(tempWord, newWord) == 0){ 
        //Set count value 
         index[i].setCount();
         existWord = true;
         delete []tempWord;
	 tempWord = nullptr;
         break;
      }
     //Delete memory used by tempWord array
      delete []tempWord;
      tempWord = nullptr;
   }

   if(!existWord){
      //Re-size array
      //Memory size + 1 (space for element to be inserted)
      word *temp = new word[size+1];  
      //If size > zero then copy elementos of index 
      if(size > 0){
         for (int i = 0; i < (size); i++) {
           temp[i] = index[i];
         }
         //Delete memory of index array
         delete[] index;
	 index = nullptr;
      }
      //assign value of temp array to index array
      index = temp;
      temp = nullptr;
      //Create a new word instance
      word * myWord = new word();
      //Set value data in instance of word
      myWord->setData(newWord);
      //Increment word count (initial value = 1)
      myWord->setCount();
      //Insert word instance in the reserved space 
      index[size++] = *myWord;   
      delete myWord;
      myWord = nullptr;
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
