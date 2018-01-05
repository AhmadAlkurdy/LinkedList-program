//Ahmad Alkurdy
//Assignment number 4
// a linked list program that will read the names of 2 input data files from the command
//line 
//The data is to be placed in an ordered linked list by lastName, firstName, age.

//1)	Finish If an incomplete record is read in report the error and discard the input.

//2)	If a duplicate record is found report the duplicate but DO NOT put it in the list.

//3)	Finish If your program reads in a blank line, ignore it. DO NOT REPORT ANYTHING.

//4)	Once the sorted list is created, print it (to the screen). 

//The second file will contain a list of names to delete from the list 

//1)	If a name to delete is not found in the list, report it  and continue.

//2)	As you delete a name, report the deletion (the name/age).

//3)	Once all deletions are completed, print out the remaining list.

//4)	Delete the list and print the list out again. (Yes, you will be printing an empty list.)



#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


#include "classDef.h"

using namespace std;
//the main will read the argument from the command line
int main(int argc, char* argv[])
{
	//declare variables
	ifstream input;
	ifstream deletedFile;
	//declare an object from class nodeList
	nodeList list;
	
	//if the argument in command line does not have 3 file names then the if statment execute
	if(argc != 3)
	{
		cout << "Error, insert programName File1 File2 " << endl;
	}
	else
	{
		input.open (argv[1]);
		
		cout << endl << endl;
		cout << " The list of names sorted: " << endl << endl;
		while (input.good() )
		{
			//declare the variables 
			char lastName[40];
		char firstName[40];
		int age = 0;
		string line;
		//read the data from the file line by line
		getline(input,line);
		istringstream inputfile(line);
		inputfile >> lastName >> firstName >> age;


		

			//calling the function to insert the names and the age
			list.insert(lastName, firstName, age);
			//list.print();
			//cout << endl;

			
		}
		
		//calling the function to print the list
		list.print();
		cout << endl;
		cout << endl;
		cout << "The names that are deleted from the list: " << endl << endl;
		//opening the file of the names that will be deleted
		deletedFile.open (argv[2]);
		while(deletedFile.good())
		{
			char lastName[40];
	        char firstName[40];
	        int age = 0;
			
			string line;

		getline(deletedFile,line);
		istringstream deletefile(line);
		deletefile >> lastName >> firstName >> age;


			

		//calling the function from the class
		list.deleteItem(lastName, firstName, age);
		//list.print();
		//cout << endl;
		
		}
		cout << endl << endl;
		cout << "The list after the deleted names: " << endl << endl;
		//print the list
		list.print();
		cout << endl;
		//call the function to delete all the list
		list.destroy();
		cout << endl;
		cout << endl;
		//print the empty list
		list.print();
		cout << endl << endl;
		system("pause");
		return 0;
	}





}