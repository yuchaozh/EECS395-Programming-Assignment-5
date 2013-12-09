/*
Author: Zhou Yuchao
Date:12/08/2013
Implement the wordArray (the cell of the array)
*/

#include <string>
#include <iostream>
#include <stdio.h>
#include "wordArray.h"

using namespace std;

//constructor
wordArray::wordArray()
{
	edges = new list();
	wordNode = "";
}

//destructor
wordArray::~wordArray()
{
	delete edges;
}

//set word in the cell
void wordArray::setWord(string word)
{
	wordNode = word;
}

//set words into the adjacent list
void wordArray::setList(string word)
{
	edges->insert_at_front(word);
}

//return the word
string wordArray::getWord()
{
	return wordNode;
}

//return the adjacent list
list* wordArray::getList()
{
	return edges;
}
