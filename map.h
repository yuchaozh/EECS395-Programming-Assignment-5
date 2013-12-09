/*
Author: Zhou Yuchao
Date:12/02/2013
In store the word and the list of each outgoing edges
*/

#ifndef _MAP1_H
#define _MAP1_H

#include <string>
#include <stdio.h>
#include "wordArray.h"

using namespace std;

class map
{
public:
	//constructor
	map();
	map(int mapSize);
	//destructor
	~map();
	
	//add destination
	void addWord(int number, string str);
	
	//add vertex in the map
	void addWords(int number, string str);
	
	//get the size of the map
	int getMapSize();

	int mapSize;
	wordArray *maps;
};
#endif
