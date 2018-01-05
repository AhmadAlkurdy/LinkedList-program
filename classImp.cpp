#include <string>
#include <fstream>


#include "classDef.h"



nodeList::nodeList() 
{
    head = NULL;
	current = NULL;
	temp = NULL;
}
//insert function would build the linked list node by node and sort them alphabatically
void nodeList :: insert(char lastName[40], char firstName[40], int age)
{
	if(lastName == "" && firstName == "" && age == 0)
	{
		return;
	}
	if(lastName == "" || firstName == "" || age == 0)
	{
		cout << "Incompleted data. " << endl;
		return;
	}
	
	
	//declaring a new node to be added to the linked list and store the data in it
	node* newNode = new node;
	newNode -> next = NULL;
	newNode ->lastName = lastName;
	newNode ->firstName = firstName;
	newNode -> age = age;

	//if the linked list is empty 
	if(head == NULL)
	{
		head = newNode;
		return;
	}
	else
	{
		current = head;
		//if the head's last name bigger or equal the new node
		//then if the head's lastname is bigger it would swap
		//but if they are equal then the first name would be compared then the age
		if(current -> lastName > lastName || current -> lastName == lastName)
		{
			if(current -> lastName > lastName)
			{
			newNode -> next = current -> next;
			head = newNode;
			}
			else 
			{
				if(current -> firstName == firstName)
			          {
				        if(current -> age == age)
				           {
				         	cout << "Dublicated Name." << endl;
				           }
						else
				            {
				         	if(current -> age < age)
				         	{
					        	current -> next = newNode;
								return;
					        }
							else
					         {
						newNode -> next = current -> next;
		            	head = newNode;
		            	newNode -> next = current;
		            	return;
					          }
				            }
			}
					else
		            	{
				          if(current -> firstName < firstName )
				            {
				              	current -> next = newNode;
								return;
				             }
						  else
				              {
				             	newNode -> next = current -> next;
			                    head = newNode;
			                    newNode -> next = current;
			                     return;

			                	}
				     	}


			}
		}
		//if the head's lastName is not bigger then it is going to check with the next
		// node in the linked list and accodring to it either they swap or advance to the next
		// node in the linked list to be compared with and find its place
		else
		{
			
			while(current -> next != NULL)
			{
				temp = current -> next;

				if(temp -> lastName > lastName)
				{
					newNode -> next = current -> next;
					current -> next = newNode;
					return;
				}
				if(temp -> lastName == lastName)
				{
					if(temp -> firstName == firstName)
			          {
				        if(temp -> age == age)
				           {
				         	cout << "Dublicated Name." << endl;
				           }
						else
				            {
				         	if(temp -> age < age)
				         	{
					        	//current -> next = newNode;
								current = current -> next;
					        }
							else
					         {
						newNode -> next = current -> next;
			            current -> next = newNode;

						return;
					          }
				            }
			}
					else
		            	{
				          if(temp -> firstName < firstName )
				            {
				              
								current = current -> next;
				             }
						  else
				              {
				             	newNode -> next = current -> next;
				             	current -> next = newNode;
								return;
			                	}
				     	}


				}
				else
				{
					current = current -> next;
				}
			}
		

		}

		current -> next = newNode;




	}

		
	}


void nodeList ::deleteItem(char lastName[40], char firstName[40], int age)
{
	  current = head; // empty header
    //  current = head-> next; // the first valid node
    while(current != NULL) {
        if(current-> lastName == lastName && current -> firstName == firstName && current -> age == age)
		{ 
            break; 
        }
        else 
		{
			
            prev = current; 
            current = current-> next; // go to next value
        }
    }
	if(current == head)
	{
		prev = head;
		head = head -> next;
		
		cout << "The name " << prev -> lastName << " " << prev ->firstName << " " << prev -> age <<
			 " is deleted." << endl;
		delete prev;
		return;
	}

    if(current == NULL)
	{ // if we reached end of list or the list is empty
        cout << "Can't remove " << lastName << " " << firstName << " " << age << 
			": no match found.\n"; 
    }
	else
	{
        
        prev-> next = current-> next; // unlink the node you remove
		cout << "The name " << current -> lastName << " " << current ->firstName << " " << current -> age <<
			 " is deleted." << endl;
        delete current; // delete the node
    }

	}


void nodeList ::print()
{
	if(head == NULL)
	{
		cout << "The list is empty." << endl;
	}
	current = head;
	while (current != NULL)
{//print the node's info
		cout << current -> lastName << " " << current -> firstName << " " <<  current ->age << endl;
		
		current = current -> next;//advance the pointer to the next code
	
}

}

//this function will delete the linked list
void nodeList ::destroy()
{
	node* nodePtr;
	node* nextNode;
	nodePtr = head;
	while(nodePtr != 0)
	{
		nextNode = nodePtr -> next;
		delete nodePtr;
		nodePtr = nextNode;
	}
	head = NULL;
}
//deconstructor 
nodeList :: ~nodeList ()
{
	node* nodePtr;
	node* nextNode;
	nodePtr = head;
	while(nodePtr != 0)
	{
		nextNode = nodePtr -> next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}