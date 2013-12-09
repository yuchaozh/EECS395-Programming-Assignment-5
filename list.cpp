/*
Author: Zhou Yuchao
Date:12/08/2013
Implement the adjacent list. the node in the adjacent list is called node
*/

#include <string>
#include <iostream>
#include <stdio.h>
#include "list.h"

using namespace std;

//constructor
list::list()
{
	first = new node();
	listSize = 0;
	first->next = NULL;
}

//destructor
list::~list()
{	
	node* current;
	while(first)
	{
		current = first->next;
		delete first;
		first = current;
	}
}

//insert the vertex at the front of the adjacent list
void list::insert_at_front(string word)
{
	node* newWord = new node(word);
	newWord->next = first->next;
	first->next = newWord;
	listSize++;
}

//print out the adjacent list
void list::print()
{
	node* current = first->next;
	while(current)
	{
		cout<<current->getWords()<<"  ";
		current = current->next;
	}
	cout<<endl;
}

int list::getListSize()
{
	return listSize;
}














