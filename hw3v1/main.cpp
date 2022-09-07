#include "main.h"
using namespace std;

// main function
int main()
{
   char fileName[50];
   cout << "Enter input file name:";
   cin.getline(fileName, '\n');
   fstream file; 
   // if the file cannot be opened, reprompt the user until
   while(!openFile(file,fileName))
   {
      cout << "File did not open!" << endl; 
      cout << "Enter input file name:";
      cin.getline(fileName, '\n');  
   }
   cout << "The file opened correctly" << endl;
   load(file);
   cout << fileName << endl;

   return 0;
}
bool openFile(fstream &file, char fileName[])
{
   file.open(fileName);
   if(!file)
   {
      return false;
   }
   return true; 
}
// open the file
void load(fstream &file)
{
   list myList;

   char byte = 0;
   char *buffer = nullptr;
   int size2 = 0;
   int h = 0; 

   while (file.good() == true && file.peek() != EOF)
   {
      byte = file.get();
      if (!isspace(byte))
      {
         if (buffer == nullptr)
         {
            buffer = new char[size2 + 1];
            memset(buffer, 0, size2 + 1); 
    	    buffer[0] = byte;
            size2 = 1;
         }
         else
	 {
           char *temp = nullptr;
           temp = new char[size2 + 1]; 
	   memset(temp, 0, size2 + 1); 
           for(int j =0; j < size2;  j++)
	   {
	      temp[j] = buffer[j]; 
	   }
	   delete []buffer; 
	   buffer = nullptr;
	   buffer = temp; 
	   buffer[size2++] = byte;   
	 }
      }
      else
      {
	myList.insert(buffer);
       	delete[] buffer;
	buffer = nullptr;
        size2 = 0;
      }
   }
   delete [] buffer;
   cout << endl;
   file.close();
   myList.print();
}
