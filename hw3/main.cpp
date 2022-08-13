#include "main.h"

using namespace std;

//main function
int main()
{
   char fileName[50];
   //memset 0  
   cout << "Enter input file name:";
   cin.getline(fileName,'\n');   
   
   load(fileName); 
   cout << fileName << endl;

   return 0; 
}
//open the file
void load(char fileName[])
{
   fstream file;
   list alist; 

   //open the file
   file.open(fileName);
   //if the file cannot be opened, reprompt the user until
   while(!file)
   {
      cout << "File did not open" << endl;
      cout << "Enter input file name: ";
      cin.getline(fileName,'\n');
   }
   
   cout << "The file opened correctly" << endl; 
   
   char byte = 0; 
   char *buffer = nullptr;
   int size2 = 0;

   while(file.good() == true && file.peek() != EOF)
   {
      byte = file.get(); 
      //if byte is an space
      if(!isspace(byte))
      {
         if(buffer == nullptr)
         {
	    buffer = new char[size2 + 2];
	    memset(buffer, 0, size2 + 2);
	    buffer[size2] = byte;
	    size2++;
	     }
	   else 
	   {
	      char * temp = new char[size2 + 2];
	    strcpy(temp, buffer);
	    delete []buffer;
	    buffer = temp;
	    buffer[size2++] = byte;
	   }
      }
      else 
      {
        alist.insert(buffer);	
        delete []buffer;
	size2= 0; 
      }
      
   } 
   cout << endl;   
   file.close(); 
   
   alist.print(); 
}
//print 
	

