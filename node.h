/*
Author: Zhou Yuchao
Date:12/08/2013
The node of the adjacent list.
*/

#ifndef _NODE1_H
#define _NODE1_H

#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

class node
{
public:
	string words;
	node *next;

	//constrctor
	node();
	node(string words);
	
	//destructor
	~node();
	
	//set words
	void setWords(string word);  

	//return words
	string getWords();  
};
#endif
