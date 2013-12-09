/*
Author: Zhou Yuchao
Date:12/04/2013
implementation of the min heap
*/


#include "priorityQueue.h"

priorityQueue::priorityQueue(int size)
{
	data = new int[size];
    heapSize = 0;
    arraySize = size;
}

priorityQueue::~priorityQueue()
{
	delete[] data;
}

int priorityQueue::getLeftChildIndex(int nodeIndex)
{
	return 2 * nodeIndex + 1;
}

int priorityQueue::getRightChildIndex(int nodeIndex)
{
	return 2 * nodeIndex + 2;
}

int priorityQueue::getParentIndex(int nodeIndex)
{
	return (nodeIndex - 1) / 2;
}

int priorityQueue::getMinimum()
{
	if (isEmpty())
    	throw string("Heap is empty");
    else
        return data[0];
}

bool priorityQueue::isEmpty()
{
	return (heapSize == 0);
}

void priorityQueue::insert(int end)
{
	if (heapSize == arraySize)
    	throw string("Heap's underlying storage is overflow");
    else
    {
    	//node* newNode = new node(end, distance, speed);
		heapSize++;
		data[heapSize - 1] = end;
        shiftUp(heapSize - 1);
    }
}

void priorityQueue::shiftUp(int nodeIndex)
{
	int parentIndex;
	int tmp;
    if (nodeIndex != 0) 
    {
    	parentIndex = getParentIndex(nodeIndex);
        if (data[parentIndex] > data[nodeIndex])
        {
        	tmp = data[parentIndex];
            data[parentIndex] = data[nodeIndex];
            data[nodeIndex] = tmp;
            shiftUp(parentIndex);
        }
    }
}

void priorityQueue::deleteMin()
{
	if (isEmpty())
    	throw string("Heap is empty");
    else 
    {
    	data[0] = data[heapSize - 1];
        heapSize--;
      	if (heapSize > 0)
        	shiftDown(0);
    }
    //return data[0].destination;
}

void priorityQueue::shiftDown(int nodeIndex)
{
	int leftChildIndex, rightChildIndex, minIndex;
	int tmp;
    leftChildIndex = getLeftChildIndex(nodeIndex);
    rightChildIndex = getRightChildIndex(nodeIndex);
    if (rightChildIndex >= heapSize) 
    {
    	if (leftChildIndex >= heapSize)
        	return;
        else
            minIndex = leftChildIndex;
    } 
    else 
    {
	    if (data[leftChildIndex] <= data[rightChildIndex])
        	minIndex = leftChildIndex;
        else
            minIndex = rightChildIndex;
    }
    if (data[nodeIndex] > data[minIndex]) 
    {
    	tmp = data[minIndex];
        data[minIndex] = data[nodeIndex];
        data[nodeIndex] = tmp;
        shiftDown(minIndex);
    }
}

		
	
