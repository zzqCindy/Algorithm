#include "Heap.h"

int Heap::parent(int index){
	return (index-1) >> 1;
}

int Heap::left(int index){
	return index << 1 + 1;
}

int Heap::right(int index){
	return index << 1 + 2;
}


void Heap::up(int val){
	
}

void Heap::down(int val){
	
}
     
Heap::Heap(){
	
}

Heap::Heap(vector<int> data){
	
}

int Heap::size(){
	return heap.size();
}

Heap Heap::buildHeap(){
	return *this;
}

Heap Heap::insert(int val){
	return *this;
}

Heap Heap::remove(int val){
	return *this;
}

void Heap::print(){
	
}

int main(){
	
	return 0;
} 
