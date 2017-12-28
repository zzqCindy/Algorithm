#include<iostream>
#include<vector>
using namespace std;

int array[] = {34,52,3,14,23,84,25,91,21,24,5};
int size = sizeof(array) / sizeof(*array);

void printArray(){
	for(int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

// radix sort
int maxBit(int *array, int size){
	int count = 0, base = 1;
	bool flag = true;
	while(flag){
		flag = false;
		for(int i = 0; i < size; i++){
			if((array[i] / base) > 0){
				count++;
				base *= 10;
				flag = true;
				break;
			}
		}
	}
	return count;
}

void radix(int *array, int size){
	int bit = maxBit(array,size);
	
	int count[10];
	int tmp[size];
	int base = 1;
	
	for(int i = 0; i < bit; i++){
		for(int j = 0; j < 10; j++)
			count[j] = 0;
		
		for(int j = 0; j < size; j++)
			count[array[j] / base % 10]++;
		for(int j = 1; j < 10; j++)
			count[j] = count[j] + count[j-1];
		
		for(int j = size-1; j >= 0; j--){
			int index = array[j] / base % 10;
			tmp[count[index]-1] = array[j];
			count[index]--;
		}
		for(int j = 0; j < size; j++)
			array[j] = tmp[j];
		
		base *= 10;
	}
}

// link list
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val = 0, ListNode* next = NULL){
		this->val = val;
		this->next = next;
	}
};

// bucket sort(if the number is betwenn 1 and 100)
void bucket(int *array, int size){
	vector<ListNode*> bucket(10);
	
	for(int i = 0; i < size; i++){
		int index = array[i] / 10;
		ListNode* head = bucket[index];
		if(head == NULL) bucket[index] = new ListNode(array[i],NULL);
		else{
			ListNode* pre = new ListNode(0,head);
			ListNode* cur = head;
			while(cur != NULL && cur->val < array[i]){
				cur = cur->next;
				pre = pre->next;
			}
			pre->next = new ListNode(array[i],cur);
			if(head == cur) bucket[index] = pre->next;
		}
	}
	
	int index = 0;
	for(int i = 0; i < 10; i++){
		ListNode* head = bucket[i];
		while(head != NULL){
			array[index++] = head->val;
			head = head->next;
		}
	}
	
}

int main(){
	
	printArray();
	//radix(array,size);
	//bucket(array,size);
	printArray();
	
	return 0;
}

