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
	//cout<<total<<endl;
	for (; index < total; index++)
	{
		if (allWords[index] == str)
		{
			find = true;
			break;
		}
	}
	//cout<<"the query word: "<<str<<"  index: "<<index<<endl;
	if (find == true)
		return index;
	else
		return -1;
}

bool judge(string first, string second)
{
	//cout<<"first word: "<<first<<"  second word: "<<second;
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
	//cout<<"  "<<oneletter<<endl;
	return oneletter;
}

void function1(map* m)
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
	string source;
	string target;
	cout<<"Please input one source word and one target word: "<<endl;
	cin>>source;
	cin>>target;
	cout<<endl;
	startIndex = getIndex(source);
	endIndex = getIndex(target);
	if ((startIndex == -1) || (endIndex == -1))
	{
		cout<<"Cannot convert"<<endl;
		exit(0);
	}
		
	cout<<"startIndex: "<<startIndex<<endl;
	cout<<"endIndex: "<<endIndex<<endl;
	flag[startIndex] = "T";
	wordQueue.push(startIndex);
	cout<<wordQueue.front();
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
	cout<<endl;
	for (int i = 0; i < previous.size(); i++)
	{
		cout<<"index: "<<i<<"  "<<previous[i]<<endl;
	}
	vector<string> process;
	bool sucess = false;
	int parent;	
	cout<<"the target word: "<<allWords[endIndex]<<" "<<endIndex<<endl;
	process.push_back(allWords[endIndex]);
	for (int i = 0; i < 6; i++)
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
		cout<<"yes"<<endl;
		process.push_back(allWords[startIndex]);
		for (int i = process.size() -1; i >= 0; i--)
		{
			cout<<process[i]<<endl;
		}
	}
}

int main()
{
	ifstream inputFile;
	
	string input;
	int count = -1;
	inputFile.open("Program4AlternativeFall2013words.txt");
	while(inputFile>>input)
	{
		total++;
	}
	cout<<total<<endl;
	map m(total);
	inputFile.close();
	inputFile.open("Program4AlternativeFall2013words.txt");
	while(inputFile>>input)
	{
		count++;
		m.addWord(count, input);
		allWords.push_back(input);
		cout<<count<<"  words: "<<m.maps[count].getWord()<<"  |  "<<allWords[count]<<endl;
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
	for (int i = 0; i < total; i++)
	{
		cout<<m.maps[i].getWord()<<" :  ";
		m.maps[i].getList()->print();
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
				function1(&m);
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
	
