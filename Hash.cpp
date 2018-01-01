#include<iostream>
#define MOD 13
using namespace std;

int hash[MOD] = {0};

int hash(int key){
	return key % MOD;
}

int hash1(int key){
	return key % (MOD-2) + 1;
}

void insert(int key, int val){
	int d = hash(key), h = hash1(key);
	int index = d;
	while(hash[index] != 0)
		index = (index+h) % MOD;
	hash[index] = val;
}

int main(){
	
	return 0;
}
