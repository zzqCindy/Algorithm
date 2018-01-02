#ifndef RBTREE_H
#define RBTREE_H
#include <iostream>
using namespace std;

typedef enum{
	RED = 0;
	BLACK = 1;
}Color;

class RBNode{
public:
	Color color;
	int key;
	RBNode *right, *left, *parent;
	
	RBNode(Color c, int k, RBNode* p = NULL, RBNode* r = NULL, RBNode* l = NULL){
		color = c;
		key = k;
		right = r;
		left = l;
		parent = p;
	}
	
};

class RBTree{
private:
	RBNode* root;

public:
	void lRotate(RBNode*);
	void rRotate(RBNode*);
	
	void rbInsertFix(int);
	void rbInsert(int);
	void rbRemoveFix(int);
	void rbRemove(int);
};

#endif 
