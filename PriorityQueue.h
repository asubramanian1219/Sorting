#pragma once
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <exception>


using namespace std;

/**
* Note: in order to try to make things easier, the queue below will only have a single type of value
* in it instead of a (key, value) pair.  You could still store a (key, value) pair, but you would
* make a priority queue that stored an object with both the key/value in it and a comparison operator
* that only compared the keys.
*/

template <class Type>
class PriorityQueue
{
private:
	// data here

public:
	PriorityQueue() {};

	~PriorityQueue() {};

	bool isEmpty() {};

	int size() {};

	// inserts a piece of data into the priority queue
	void insertItem(Type data) {};

	// removes and returns the minimum value in the queue
	// throws an exception if the queue is empty
	Type removeMin() {};

	// return the minimum value in the queue without removing it
	// throws an exception if the queue is empty
	Type minValue() {};
};

#endif
