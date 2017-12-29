#ifndef HEAP_H
#define HEAP_H

#include<iostream>
#include<vector>
using namespace std;

class Heap{
	
private:
	vector<int> heap;
	
	int parent(int);
	int left(int);
	int right(int);
	
	void up(int);
	void down(int);
	
public:
	Heap();
	Heap(vector<int>);
	
	int size();
	Heap buildHeap();
	Heap insert(int);
	Heap remove(int); 
	void print();
	
};

#endif
