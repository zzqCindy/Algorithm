#include<iostream>
using namespace std;

int array[] = {1,5,3,4,2};
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

//ascending
//bubble
void bubble(){
	cout << "Bubble\n";
	printArray();
	for(int i = 1; i < size; i++)
		for(int j = 0; j < size-1; j++)
			if(array[j] > array[j+1])
				swap(array[j],array[j+1]);
	printArray();
}

//selection
void selection(){
	cout << "Selection\n";
	printArray();
	for(int i = 0; i < size-1; i++){
		int min = array[i], index = i;
		for(int j = i+1; j < size; j++)
			if(min > array[j]){
				min = array[j];
				index = j;
			}
		swap(array[i],array[index]);
	}
	printArray();
}

//insertion
void insertion(){
	cout << "Insertion\n";
	printArray();
	for(int i = 1; i < size; i++){
		int tmp = array[i],j;
		for(j = i; j > 0; j--)
			if(array[j-1] > tmp)
				swap(array[j-1],array[j]);
			else
				break;
		array[j] = tmp;
	}
	printArray();
}

int main(){
	
	//bubble();
	//selection();
	//insertion();
	
	return 0;
} 
