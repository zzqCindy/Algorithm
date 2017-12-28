#include<iostream>
using namespace std;

int array[] = {23,24,12,15,56,72,38,92,2,14};
int size = sizeof(array) / sizeof(*array);

void printArray(){
	for(int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

void swap(int &i, int &j){
	int temp = j;
	j = i;
	i = temp;
}

//quicksort
int partition(int *array, int left, int right){
	int pivot = (left+right) / 2;
	swap(array[pivot],array[right]);
	int i = left, j = right-1;
	while(i < j){
		while(i < j && array[i] < array[right]) i++;
		while(i < j && array[j] > array[right]) j--;
		swap(array[i],array[j]);
	}
	if(array[i] > array[right])
		swap(array[i],array[right]);
	return i;
}

void qsort(int *array, int left, int right){
	if(left >= right) return;
	int index = partition(array,left,right);
	qsort(array, left, index-1);
	qsort(array, index+1, right);
}

//mergesort
//iteration
void merge_iter(int *array, int len){
	int b[len];
	for(int step = 2; step < len; step *= 2){
		for(int start = 0; start < len; start += 2*step){
			int end1 = min(start+step,len), end2 = (end1+step,len);
			int i = start, j = end1, k = start;
			while(i < end1 && j < end2)
				b[k++] = array[i] < array[j] ? array[i++] : array[j++];
			while(i < end1)
				b[k++] = array[i++];
			while(j < end2)
				b[k++] = array[j++];
		}
		for(int i = 0; i < len; i++)
			array[i] = b[i];
	}
}

// recursive
void merge_recursive(int *array1, int *array2, int start, int end){
	if(start >= end) return;
	int mid = (end - start) / 2 + start;
	merge_recursive(array1,array2,start, mid);
	merge_recursive(array1,array2,mid+1,end);
	
	int i = start, j = mid+1, k = start;
	while(i <= mid && j <= end)
		array2[k++] = array1[i] < array1[j] ? array1[i++] : array1[j++];
	while(i <= mid)
		array2[k++] = array1[i++];
	while(j <= end)
		array2[k++] = array1[j++];
	for(k = start; k <= end; k++)
		array1[k] = array2[k];
}

void merge_sort(int *array, int len){
	int b[size];
	merge_recursive(array, b, 0, len-1);
}


int main(){
	
	printArray();
	//qsort(array,0,size-1);
	//merge_iter(array,size);
	//merge_sort(array,size);
	
	printArray();
	
	return 0;
}

