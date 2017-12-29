#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using namespace std;

class TreeNode{
	
public:
	int val;
	TreeNode *left, *right;
	
	TreeNode(int v = 0, TreeNode* l = NULL, TreeNode* r = NULL);
	
	TreeNode* search_recur(TreeNode* root, int val);
	TreeNode* search_iter(TreeNode* root, int val);
	
	TreeNode* insert(TreeNode* root, int val);
	TreeNode* remove(TreeNode* root, int val);
	
	void preorder(TreeNode* root);
	void inorder(TreeNode* root);
	void postorder(TreeNode* root);
};

#endif
