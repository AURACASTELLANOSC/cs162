#include "list.h"

using namespace std;

//default constructor
list::list()
{
  index  = nullptr;
}

//destructor
list::~list()
{
cout << "destructor" << endl;
   node *curr = index;
   while(curr != nullptr)
   {   
      index = curr->next;
      delete curr; 
      curr = index; 
   }   
   index = nullptr;

}

//copy constructor
/*list::list(const list&source)
{
    if(source->index == nullptr){
      index = nullptr;
    }
    else{
      //index = new word[source.size];    
      //this->index = source.index;
      //this->size = source.size;
      index = new node(source.index->data);

     
    }
}
*/
//copy assignment operator





//insert the new word
void list::insert(char * newWord)
{ 
   /*Create new instances*/
   node * newNode = new node();
   word  * myWord = new word();
   myWord->setData(newWord);
   myWord->setCount();
   newNode->data = myWord;
   /*Variables*/
   bool existWord = false;
   char * tempWord = nullptr;
   char * tempIndexWord = nullptr;

   /*Save head*/
   node * aux = index;
   while(index != nullptr){
      tempWord = new char[index->data->getLength() + 2]{0};
      index->data->getData(tempWord);
      if(strcmp(tempWord, newWord) == 0){ 
         index->data->setCount();
         existWord = true;
         delete []tempWord;
         tempWord = nullptr;
         break;
      }
      delete []tempWord;
      tempWord = nullptr;
      index = index->next;
   }
   index = aux;
   if(!existWord){
      if(index == nullptr){
         newNode->next = nullptr;
         index = newNode;
         size++;
      }else{


            // list is not empty
            node * currNode = index;
            node * prevNode = nullptr; 
            tempWord = new char[newNode->data->getLength() + 1]{0};
            currNode->data->getData(tempWord); 
            while (currNode != nullptr && strcmp(tempWord,newWord)<= 0) {
	       prevNode = currNode;
               currNode = currNode->next;
               if(currNode != nullptr){
                  delete []tempWord;
		  tempWord = nullptr;
		  tempWord = new char[newNode->data->getLength() + 1]{0};
                  currNode->data->getData(tempWord); 
	       }
	    }
	    delete []tempWord;
	    tempWord = nullptr;
            if (prevNode == nullptr) {
               index = newNode;
               newNode->next = currNode;
            }
            else {
               prevNode->next = newNode;
               newNode->next = currNode;
            }
          size++;
      }
   }
}

void list::print()
{
   node * aux = index;
   while (aux != nullptr)
   {
      aux->data->printWord();
      aux = aux->next;
   }
   

}
