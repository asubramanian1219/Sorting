#include "stdafx.h"
#include "PriorityQueue.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <class Type>
class PriorityQueueHeap :PriorityQueue<Type> {
private:
	vector<Type> heapPQ;
public:
	PriorityQueueHeap() {

	}
	~PriorityQueueHeap() {
		
	}
	bool isEmpty() {
		if (heapPQ.size() == 0) {
			return true;//return true if size is 0
		}
		return false;
	}
	int size() {
		return heapPQ.size(); //return the number of element in the heap
	}
	void insertItem(Type data) {
		//insert element at end
		heapPQ.push_back(data);
		//fix the min heap by swapping the inserted element with its parent if it is less than its parent. 
		int i = heapPQ.size() - 1;
		while (i != 0 && heapPQ.at((i - 1) / 2) > heapPQ.at(i)) {
			swapElements(i, ((i - 1) / 2));
			i = (i - 1) / 2;
		}
	}
	Type removeMin() {
		if (heapPQ.size() == 0) {
			cout << "Empty queue exception!"; //cannot remove anything from an empty queue

		}
		else if (heapPQ.size() == 1) {
			Type temp = heapPQ.at(0);
			heapPQ.erase(heapPQ.begin()); //remove and return the first element
			return temp;
		}
		else {
			Type temp = heapPQ.at(0); 
			heapPQ.at(0) = heapPQ.at(heapPQ.size() - 1); //move the last node to the top
			heapPQ.pop_back(); //and remove it in its previous position
			heapConv(0); //fixes the heap after the removal.

			return temp;
		}



	}
	void heapConv(int i) {
		int toSwap = i; //parent
		int left = 2 * i + 1; //left child
		int right = 2 * i + 2; //right child
		
		if (left < heapPQ.size() && (heapPQ.at(left) < heapPQ.at(i))) { 
			toSwap = left; //if the left child is less than its parent and its index doesn't go out of bounds,
			               //the left node will be swapped with its parent provided the next if statement is false.
		}
		if (right < heapPQ.size() && (heapPQ.at(right) < heapPQ.at(toSwap))) {
			toSwap = right; //if the right child is less than the left child OR the parent, the right child will be swapped instead.
		}

		if (toSwap != i) { //if something isn't in the right place
			swapElements(i, toSwap); //swaps the node to be swapped with its parent
			heapConv(toSwap); //recursively makes sure the subtree of the swapped node is still good to go and fixes it if it isn't.
		}
	}
	void swapElements(int x, int y) {
		Type temp = heapPQ.at(x);
		heapPQ.at(x) = heapPQ.at(y);
		heapPQ.at(y) = temp;
	}
};