/*
Author: Zhou Yuchao
Date:12/08/2013
The adjacent list.
*/

#ifndef _LIST1_H
#define _LIST1_H

#include <string>
#include <stdio.h>
#include "node.h"

using namespace std;

class list
{	
public:
	node * first;
	int listSize;

	//constructor
	list();
	
	//destructor
	~list();
	
	//insert the connection at front
	void insert_at_front(string word);
	
	//get the size of the list
	int getListSize();
	
	//print out the list
	void print();
};
#endif
