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
             
// change the color 
void rbInsertFix(RBNode* ptr){
	
	RBNode *parent = ptr->parent, *grandparent;
	
	while(parent != NULL && parent->color == RED){
		
		grandparent = parent->parent;
		
		if(parent == grandparent->left){
			RBNode* uncle = parent->right;
			
			if(uncle != NULL && uncle->color == RED){
				parent->color = BLACK;
				grandparent->color = RED;
				uncle = BLACK;
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
				uncle = BLACK;
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

void RBTree::rbRemoveFix(RBNode* ptr){
	
}

void RBTree::rbRemove(int val){
	
	// binary tree remove
	TreeNode *tmp, *cur = root;
	while(cur->val != val){
		tmp = cur;
		if(cur->val < val) cur = cur->right;
		else cur = cur->left;
	}
	if(cur == root){
		tmp = root;
		if(cur->left == NULL && cur->right == NULL) return NULL;
		else if(cur->left == NULL){
			cur = cur->right;
			delete tmp;
			return cur;
		}
		else if(cur->right == NULL){
			cur = cur->left;
			delete tmp;
			return cur;
		}
		else{
			cur = tmp = root->left;
			while(cur->right != NULL){
				tmp = cur;
				cur = cur->right;
			}
			if(tmp == cur){
				cur->right = root->right;
				delete root;
				return cur;
			}
			else{
				tmp->right = cur->left;
				cur->left = root->left;
				cur->right = root->right;
				delete root;
				return cur;
			}
		}
	}
	else{
		if(cur->left == NULL && cur->right == NULL)
			delete cur;
		else if(cur->left == NULL){
			if(tmp->val < cur->val) tmp->right = cur->right;
			else tmp->left = cur->right;
		}
		else if(cur->right == NULL){
			if(tmp->val < cur->val) tmp->right = cur->left;
			else tmp->left = cur->left;
		}
		else{
			TreeNode *head = cur, *pre;
			cur = pre = head->left;
			while(cur->right != NULL){
				pre = cur;
				cur = cur->right;
			}
			if(pre == cur){
				cur->right = head->right;
				if(head->val < tmp->val) tmp->left = cur;
				else tmp->right = cur;
				delete head;
			}
			else{
				pre->right = cur->left;
				cur->left = head->left;
				cur->right = head->right;
				if(head->val < tmp->val) tmp->left = cur;
				else tmp->right = cur;
				delete head;
			}
		}
		return root;
	}
}


int main(){
	
	return 0;
}
