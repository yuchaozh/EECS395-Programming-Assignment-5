/*
Author: Zhou Yuchao
Date:12/04/2013
Min Heap
*/

#ifndef _PRIORITYQUEUE_H
#define _PRIORITYQUEUE_H

#include <iostream>
#include <string>
#include "node.h"

using namespace std;

class priorityQueue
{
public:
	priorityQueue(int size);
	~priorityQueue();
	bool isEmpty();
	void deleteMin();
	void shiftDown(int nodeIndex);
	void insert(int end, double distance, double speed, double time);
	void shiftUp(int nodeIndex);
	node getMinimum();
	int getLeftChildIndex(int nodeIndex);
	int getRightChildIndex(int nodeIndex);
	int getParentIndex(int nodeIndex);
	
	int* data;
	int arraySize;
	int heapSize;
};
#endif 
