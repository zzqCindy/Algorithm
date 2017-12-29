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

void Heap::swap(int &i, int &j){
	int tmp = i;
	i = j;
	j = tmp;
}

void Heap::up(int index){
	int par = parent(index);
	if(heap[par] < heap[index]){
		swap(heap[par],heap[index]);
		up(par);
	}
}

void Heap::down(int index){
	int l = left(index), r = right(index);
	bool flag = false, left = false;
	if(l < size()){
		flag = true;
		left = true;
	}
	else{
		flag = true;
		left = false;
	}
	
	if(!flag) return;
	if(!left){
		if(heap[r] <= heap[index]) return;
		swap(heap[r],heap[index]);
		down(r);
	}
	else{
		if(heap[l] > heap[r]){
			if(heap[l] <= heap[index]) return;
			swap(heap[l],heap[index]);
			down(l);
		}
		else{
			if(heap[r] <= heap[index]) return;
			swap(heap[r],heap[index]);
			down(r);
		}
	}
	
}
     
Heap::Heap(){
	
}

Heap::Heap(vector<int> data){
	heap = data;
}

int Heap::size(){
	return heap.size();
}

void Heap::buildHeap(){
	int index = parent(size()-1);
	for(; index >= 0; index--)
		down(index);
}

void Heap::insert(int val){
	heap.push_back(val);
	up(size()-1);
}

void Heap::remove(int index){
	swap(heap[index],heap[size()-1]);
	heap.erase(heap.begin()+heap.size()-1);
	if(size() == index) return;
	down(index);
}

void Heap::print(){
	for(int i = 0; i < size(); i++)
		cout << heap[i] << " ";
	cout << endl;
}

int main(){
	// test
	
	
	return 0;
} 
