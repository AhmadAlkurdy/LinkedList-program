#pragma once

#include <string>
#include <iostream>

using namespace std;

#ifndef classDef_h
#define classDef_h

//declare the class
class nodeList
{
private:
	//declare the node struct to build the nodes in the linked list
	struct node
	{
		string firstName;
		string lastName;
		int age;
		node* next;
	};
	node* head;
	node* current;
	node* temp;
	node* last;
	node* prev;
public:

	//delclare the function
	nodeList();
	void insert (char lastName[40] ,  char firstName[40], int age);
	void print ();
	void deleteItem(char lastName[40], char firstName[40], int age);
	void destroy();
	~nodeList();





};


#endif