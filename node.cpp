/*
Author: Zhou Yuchao
Date:12/08/2013
Implementation of the node of the adjacent list.
*/

#include<iostream>
#include<string>
#include "node.h"

using namespace std;

//constructor
node::node()
{
	words = "";
	next = NULL;
}

//constructor
node::node(string word)
{
 	words = word;
	next = NULL;
}

//destructor
node::~node()
{
	
}

//set the words
void node::setWords(string word)
{
	words = word;
}

//return the words
string node::getWords()
{
	return words;
}

