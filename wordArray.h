/*
Author: Zhou Yuchao
Date:12/08/2013
This is the cell of the map_array
*/

#ifndef _WORDARRAY1_H
#define _WORDARRAY1_H

#include<iostream>
#include<string>
#include <stdio.h>
#include "list.h"
#include "node.h"

using namespace std;

class wordArray
{
public:
	list *edges;
	
	//constructor
	wordArray();
	
	//destructor
	~wordArray();
	
	//set word
	void setWord(string word);
	
	//set the outgoing words in correspoing list
	void setList(string word);
	
	//return the word in the array cell
	string getWord();
	
	//return the list
	list* getList();
	
	string wordNode;
};
#endif
