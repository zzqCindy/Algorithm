#include<iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left, right;
	TreeNode(int v = 0; TreeNode* l = NULL, TreeNode* r = NULL){
		val = val;
		left = l;
		right = r;
	}
};

TreeNode* BSTsearch_recur(TreeNode* root, int val){
	if(root == NULL) return NULL;
	if(root->val > val) return BSTsearch(root->left,val);
	else if(root->val == val) return root;
	else return BSTsearch(root->right,val);
}

TreeNode* BSTsearch_iter(TreeNode* root, int val){
	
	while(root != NULL){
		if(root == val) return root;
		else if(root->val > val) root = root->left;
		else root = root->right;
	}
	return NULL;
}

TreeNode* BSTinsert(TreeNode* root, int val){
	
}

TreeNode* BSTremove(TreeNode* root, int val){
	
	
}

void BSTpreorder(TreeNode* root){
	cout << root->val;
	BSTpreorder(root->left);
	BSTpreorder(root->right);
}

void BSTinorder(TreeNode* root){
	BSTinorder(root->left);
	cout << root->val;
	BSTinorder(root->right);
}

void BSTpostorder(TreeNode* root){
	BSTpostorder(root->left);
	BSTpostorder(root->right);
	cout << root->val;
}

int main(){
	
	return 0;
}

