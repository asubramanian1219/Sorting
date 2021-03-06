// Subramanian_Abhinav_PA4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "PriorityQueueHeap.cpp"
#include <string>
#include "StopWatch.h"

using namespace std;

void swap(int i, int j, vector<int>& toSort) {
	int temp = toSort.at(i);
	toSort.at(i) = toSort.at(j);
	toSort.at(j) = temp;
}

vector<int> bubbleSort(vector<int>& toSort,int upperBound) {



	for (int i = 0; i < upperBound - 1; i++) {//swaps adjacent elements if they are out of order
		for(int j=0;j<upperBound-i-1;j++){
			if (toSort.at(j) > toSort.at(j + 1)) {
				swap(j, j + 1, toSort);
					
			}
		}
	}
	
	return toSort;
}
vector<int> heapSort(vector<int>& toSort,int upperBound) { //uses heapsort implemented in PA3 to sort the elements
	vector<int> heapVector;
	PriorityQueueHeap<int> heap;
	for (int i = 0; i < upperBound; i++) {
		heap.insertItem(toSort.at(i));
	}
	while (heap.size() != 0) {
		heapVector.push_back(heap.removeMin());
	}
	for (int i = 0; i < heapVector.size(); i++) {
		toSort.at(i) = heapVector.at(i);
	}
	return toSort;
}
void printVector(vector<int> nums,int upperBound) { //prints the vector
	for (int i = 0; i < upperBound; i++) {
		cout<<endl<< nums.at(i);
	}
}

void merge(vector<int>& toSort, int least, int mid, int greatest) {
	int i, j, k; //i is the index of the left subarray, j is the index of the right subarray,
	//k is the index of the full array being dealt with.
	int size1 = mid - least + 1; //determines the size of the left subvector
	int size2 = greatest - mid; //determines size of right subvector.
	vector<int> left, right; 
	for (i = 0; i < size1; i++) {
		left.push_back(toSort.at(least + i)); //copies elements into left subvector (from least to mid)
	}
	for (j = 0; j < size2; j++) {
		right.push_back(toSort.at(mid + j + 1)); //copies elements from mid+1 to greatest into right subarray.
	}
	i = 0; //set everything to the beginning of their respective arrays.
	j = 0;
	k = least;
	while (i < size1&&j < size2) { //if elements aren't out of bounds
		if (left.at(i) <= right.at(j)) {//if left element at i is less than right element at j
			toSort.at(k) = left.at(i); //set kth element of big array equal to left at i
			i++;//increment i, now all comparisons wil involve the next element in i
		}
		else { //insert element from right and make all future comparisons involve the next element of right
			toSort.at(k) = right.at(j);
			j++;
		}
		k++; //once an element's been inserted, move on to the next element in the big array until greatest has been hit
	}
	//these cover elements that might have been missed.
	
	while (i < size1)
	{
		toSort.at(k) = left.at(i);
		i++;
		k++;

	}
	while (j < size2) {
		toSort.at(k) = right.at(j);
		j++;
		k++;

	}
}

vector<int> mergeSort(vector<int>& toSort, int least, int greatest) {
	if (least < greatest) {
		int mid = (least + greatest) / 2;//determines midpoint
		
		mergeSort(toSort, least, mid); //sorts left half
		mergeSort(toSort, mid + 1, greatest);//sorts right half

		merge(toSort, least, mid, greatest); //merges everything together
	}
	return toSort;

}
int findPivot(vector<int>& toSort, int least, int greatest) { //this returns the index of where the pivot should be.
	int pivot = toSort.at(greatest); 
	int i = least - 1; //keeps track of the index before the pivot.

	for (int j = least; j < greatest; j++) {//finds the element right before the pivot index.
		if (toSort.at(j) <= pivot) {
			i++;
			swap(i, j, toSort); //puts the elements that need to be inplace before the pivot before the pivot.
		}
	}
	swap(i + 1, greatest, toSort);//puts the pivot in place
	return i + 1;
}
vector<int> quickSort(vector<int>& toSort, int least, int greatest) {
	if (least < greatest) {
		int pivot = findPivot(toSort, least, greatest);//finds the pivot
		quickSort(toSort, least, pivot - 1); //recursively sorts the left half
		quickSort(toSort, pivot + 1, greatest); //recursively sorts the right half.
	}
	return toSort;
	
}




int main()
{
	vector<int> nums;
	vector<int> toSort;
	ifstream fileOpen;
	string filePath;
	StopWatch time;
	vector<double> times;
	int num;
	cout << "Enter the file path of the numbers.txt file (Ex. C:\\Users\\numbers.txt).\n. Use double backslashes for the file path." << endl << endl;
	cin>>filePath;
	
	fileOpen.open(filePath);
	while (!fileOpen.eof()) {
		fileOpen >> num;
		nums.push_back(num);
	}
	int selection = nums.at(0);
	int size = nums.at(1);
	for (int i = 2; i < nums.at(1)+2; i++) {
		toSort.push_back(nums.at(i));
	}
	int j = 0;
	//while(j<size) {
		//time.start();
		if (selection == 1) {
			bubbleSort(toSort, size);


		}
		else if (selection == 2) {

			heapSort(toSort, size);
		}
		else if (selection == 3) {
			mergeSort(toSort, 0, size-1);
		}
		else {
			quickSort(toSort, 0, size-1);
		}
		/*time.stop();
		times.push_back(time.ms());
		j = j + 10;
	}*/

	printVector(toSort,size);
	system("pause");
	

}


