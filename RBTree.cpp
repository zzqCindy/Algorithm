#include "RBTree.h"

void RBTree::lRotate(RBNode* x){
	RBNode* y = x->right;
	x->right = y->left;
	if(y->left != NULL) y->left->parent = x;
	y->parent = x->parent;
	if(x->parent == NULL) root = y;
	else if(x == x->parent->left) x->parent->left = y;
	else x->parent->right = y;
	y->left = x;
	x->parent = y;
}

void RBTree::rRotate(RBNode* y){
	RBNode* x = y->left;
	y->left = x->right;
	if(x->right != NULL) x->right->parent = y;
	x->parent = y->parent;
	if(y->parent == NULL) root = x;
	else if(y->parent->left == y) y->parent->left = x;
	else y->parent->right = x;
	x->right = y;
	y->parent = x;
}
             
RBNode* RBTree::search(int val){
	
	RBNode *cur = root;
	while(cur != NULL && cur->key != val){
		if(cur->key < val) cur = cur->left;
		else cur = cur->right;
	}
	return cur;
}

// change the color 
void RBTree::rbInsertFix(RBNode* ptr){
	
	RBNode *parent = ptr->parent, *grandparent;
	
	while(parent != NULL && parent->color == RED){
		
		grandparent = parent->parent;
		
		if(parent == grandparent->left){
			RBNode* uncle = parent->right;
			
			if(uncle != NULL && uncle->color == RED){
				parent->color = BLACK;
				grandparent->color = RED;
				uncle->color = BLACK;
				ptr = grandparent;
				continue;
			}
			
			if(parent->right == ptr){
				lRotate(parent);
				RBNode* tmp = parent;
				parent = ptr;
				ptr = tmp;
				
			}
			else{
				parent->color = BLACK;
				grandparent->color = RED;
				rRotate(grandparent);
			}
		}
		else{
			RBNode* uncle = parent->left;
			
			if(uncle != NULL && uncle->color == RED){
				parent->color = BLACK;
				grandparent->color = RED;
				uncle->color = BLACK;
				ptr = grandparent;
				continue;
			}
			
			if(parent->left == ptr){
				rRotate(parent);
				RBNode* tmp = parent;
				parent = ptr;
				ptr = tmp;
				
			}
			else{
				parent->color = BLACK;
				grandparent->color = RED;
				lRotate(grandparent);
			}
		}
		
	}
	
	root->color = BLACK;
}

// insert like a BST
void RBTree::rbInsert(int val){
	if(root == NULL){
		root = new RBNode(BLACK, val);
		return;
	}
	
	RBNode *x = root, *y;
	
	while(x != NULL){
		y = x;
		if(x->key < val) x = x->right;
		else x = x->left;
	}
	
	RBNode *ptr = new RBNode(RED, val, y);
	rbInsertFix(ptr);
	
}

void RBTree::rbRemoveFix(RBNode* node){
	
	RBNode* brother;
	
	while(node != root && root->color == BLACK){
		
		if(node == node->parent->left){
			brother = node->parent->right;
			
			if(brother->color == RED){
				brother->color = BLACK;
				node->parent->color = RED;
				lRotate(node->parent);
				brother = node->parent->right;
			}
			if(brother->left->color == BLACK && brother->right->color == BLACK){
				brother->color = RED;
				node = node->parent;
			}
			else{
				if(brother->right->color == BLACK){
					brother->left->color = BLACK;
					brother->color = RED;
					rRotate(brother);
					brother = node->parent->right;
				}
				brother->color = node->parent->color;
				node->parent->color = BLACK;
				brother->right->color = BLACK;
				lRotate(node->parent);
				break;
			}
		}
		else{
			brother = node->parent->left;
			
			if(brother->color == RED){
				brother->color = BLACK;
				node->parent->color = RED;
				rRotate(node->parent);
				brother = node->parent->left;
			}
			if(brother->left->color == BLACK && brother->right->color == BLACK){
				brother->color = RED;
				node = node->parent;
			}
			else{
				if(brother->left->color == BLACK){
					brother->right->color = BLACK;
					brother->color = RED;
					lRotate(brother);
					brother = node->parent->left; 
				}
				brother->color = node->parent->color;
				node->parent->color = BLACK;
				brother->left->color = BLACK;
				rRotate(node->parent);
				break;
			}
		}
		
	}
	
	node->color = BLACK;
}

void RBTree::rbRemove(int val){
	
	RBNode *node = search(val);
	RBNode *child, *parent;
	Color color;
	
	if(node->left != NULL && node->right != NULL){
		
		RBNode *head = node->left;
		
		while(head->right != NULL) head = head->right;
		
		if(node != root){
			if(node->parent->left == node) node->parent->left = head;
			else node->parent->right = head;
		}
		else
			root = head;
			
		child = head->left;
		parent = head->parent;
		color = head->color;
		if(node == parent) parent = head;
		else{
			if(child) child->parent = parent;
			parent->right = child;
			head->left = node->left;
			node->left->parent = head;
		}
		
		head->right = node->right;
		node->right->parent = head;
		head->color = node->color;
		head->parent = node->parent;
		
		if(color == BLACK) rbRemoveFix(child);
		delete node;
		
		return ;
	}
	
	if(node->left != NULL) child = node->left;
	else child = node->right;
	
	parent = node->parent;
	color = node->color;
	
	if(parent){
		if(parent->left == node) parent->left = child;
		else parent->right = child;
		if(child) child->parent = parent;
	}
	else root = child;
	
	if(color == BLACK) rbRemoveFix(child);
	delete node;
	
}


int main(){
	
	return 0;
}
