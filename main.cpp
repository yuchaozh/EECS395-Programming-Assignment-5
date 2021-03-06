/*
Author: Zhou Yuchao
Date:12/03/2013
Implementation of the word ladder
*/

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cstring>
#include <queue>

#include "map.h"
#include "priorityQueue.h"

using namespace std;

int size = 0;
int total = 0;
vector<string> allWords;
queue<int> wordQueue;
int startIndex;
int endIndex;

int getIndex(string str)
{
	bool find = false;
	int index = 0;
	for (; index < total; index++)
	{
		if (allWords[index] == str)
		{
			find = true;
			break;
		}
	}
	if (find == true)
		return index;
	else
		return -1;
}

bool judge(string first, string second)
{
	bool oneletter = false;
	int differentCount = 0;
	int letterCount = first.length();
	for (int i = 0; i < letterCount; i++)
	{
		if (first[i] != second[i])
		{
			differentCount++;
		}
	}
	if (differentCount == 1)
		oneletter = true;
	return oneletter;
}

void function1(map* m, string sou, string tar, int ste)
{
	vector<string> flag;
	vector<int> previous;
	flag.resize(total);
	previous.resize(total);
	for (int i = 0; i < total; i++)
	{
		flag[i] = "F";
		previous[i] = -1;
	}
	map* ma = m;
	string source = sou;
	string target = tar;
	int count = ste;
	flag[startIndex] = "T";
	wordQueue.push(startIndex);
	while(!wordQueue.empty())
	{
		int index;
		index = wordQueue.front();
		wordQueue.pop();
		node* r;
		r = ma->maps[index].edges->first->next;
		while(r!=0)
		{
			int adjcentNodeIndex = getIndex(r->getWords());
			if (flag[adjcentNodeIndex] == "F")
			{
				flag[adjcentNodeIndex] = "T";
				previous[adjcentNodeIndex] = index;
				wordQueue.push(adjcentNodeIndex);
			}
			r = r->next;
		}
	}
	vector<string> process;
	bool sucess = false;
	int parent;	
	process.push_back(allWords[endIndex]);
	for (int i = 0; i < count; i++)
	{
		parent = previous[endIndex];
		if (allWords[parent] != allWords[startIndex])
		{
			if (judge(allWords[endIndex], allWords[parent]) == true)
			{
				process.push_back(allWords[parent]);
				endIndex = parent;
			}
			else
			{
				cout<<"Cannot convert"<<endl;
				break;	
			}
		}
		else
			sucess = true;
	}
	
	if (sucess == true)
	{
		process.push_back(allWords[startIndex]);
		cout<<"Convert Sucessfully"<<endl;
		for (int i = process.size() -1; i >= 0; i--)
		{
			cout<<process[i]<<endl;
		}
		cout<<endl;
	}
	if (sucess == false)
	{
		cout<<"Cannot convert"<<endl;
	}
}

int main(int argc, char *argv[])
{
	ifstream inputFile;
	
	string input;
	int count = -1;
	inputFile.open(argv[1]);
	while(inputFile>>input)
	{
		total++;
	}
	map m(total);
	inputFile.close();
	inputFile.open(argv[1]);
	while(inputFile>>input)
	{
		count++;
		m.addWord(count, input);
		allWords.push_back(input);
	}
	inputFile.close();
	size = m.maps[0].getWord().size();
	for (int i = 0; i < total; i++)
	{
		for (int a = 0; a < allWords.size(); a++)
		{
			if (judge(m.maps[i].getWord(), allWords[a]) == true)
			{
				m.addWords(i, allWords[a]);
			}
		}
	}
	
	bool running = true;
	while(running)
	{
		int choice;
		cout<<"Welcome to Word-Ladder"<<endl;
		cout<<"1) Start to play"<<endl;
		cout<<"0) Exit Word-Ladder"<<endl;
		cout<<endl;
		cout<<"Please choose an option:"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				string source;
				string target;
				int steps;
				cout<<"Please input one source word(string), one target word(string) and steps(int): "<<endl;
				cin>>source;
				cin>>target;
				cin>>steps;
				cout<<endl;
				startIndex = getIndex(source);
				endIndex = getIndex(target);
				if ((startIndex == -1) || (endIndex == -1))
				{
					cout<<"Cannot convert"<<endl<<endl;
				}
				else
					function1(&m, source, target, steps);
			}
				break;
			case 0:
				running = false;
				break;
			default:
				running = false;
				break;
		}
	}
}
	
