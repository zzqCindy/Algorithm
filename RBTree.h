#ifndef RBTREE_H
#define RBTREE_H
#include <iostream>
using namespace std;

typedef enum{
	RED = 0,
	BLACK
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
	
	RBNode* search(int);
	void rbInsertFix(RBNode*);
	void rbInsert(int);
	void rbRemoveFix(RBNode*,RBNode*);
	void rbRemove(int);
	
	void preorder(RBNode*);
	void inorder(RBNode*);
	void postorder(RBNode*);
	
	RBNode* getRoot();
	void print(RBNode*,int);
};

#endif 
