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
   if(index)
   {
      delete []  index;
      index = nullptr;
   }
}

void list::insert(char * newWord)//amarillo
{ 
   //cout<<"Buffer list: "<<newWord<<endl;
   bool existWord = false;
   char * tempWord;
   for (int i = 0; i < size; i++) //1
   {
      tempWord = new char[index[i].getLength() + 1]{0};
      index[i].getData(tempWord);//Get data value from word instance in index[i]
      if(strcmp(tempWord, newWord) == 0){ //If word exist then
         index[i].setCount();//Set count value 
         existWord = true;
         break;
      }
      delete []tempWord;//Delete memory used by tempWord array
   }
   if(!existWord){
      //Re-size array
      word *temp;  //Temp array of type word class
      temp = new word[size+1]; //Memory size + 1 (space for element to be inserted)
      if(size > 0){//If size > zero then copy elementos of index array to temp array
         for (int i = 0; i < (size); i++) {
            temp[i] = index[i];//amarillo, azul
         }
         delete[] index;//Delete memory of index array         
         cout<<endl;
      }
      index = temp;//assign value of temp array to index array
      word *myWord = new word();//Create a new word instance
      myWord->setData(newWord);//Set value data in instance of word
      myWord->setCount();//Increment word count (initial value = 1)
      index[size++] = *myWord;//Insert word instance in the reserved space of index array from temp array    

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
