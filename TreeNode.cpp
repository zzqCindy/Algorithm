#include "TreeNode.h"
using namespace std;

TreeNode::TreeNode(int v, TreeNode* l, TreeNode* r){
		val = val;
		left = l;
		right = r;
	}

TreeNode* TreeNode::search_recur(TreeNode* root, int val){
	if(root == NULL) return NULL;
	if(root->val > val) return root->search_iter(root->left,val);
	else if(root->val == val) return root;
	else return root->search_iter(root->right,val);
}

TreeNode* TreeNode::search_iter(TreeNode* root, int val){
	
	while(root != NULL){
		if(root->val == val) return root;
		else if(root->val > val) root = root->left;
		else root = root->right;
	}
	return NULL;
}

TreeNode* TreeNode::insert(TreeNode* root, int val){
	if(root == NULL) return new TreeNode(val);
	TreeNode *tmp, *cur = root;
	while(cur != NULL){
		tmp = cur;
		if(cur->val < val) cur = cur->right;
		else cur = cur->left;
	}
	if(tmp->val > val) tmp->left = new TreeNode(val);
	else tmp->right = new TreeNode(val);
	return root;
}

TreeNode* TreeNode::remove(TreeNode* root, int val){
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

void TreeNode::preorder(TreeNode* root){
	cout << root->val;
	root->preorder(root->left);
	root->preorder(root->right);
}

void TreeNode::inorder(TreeNode* root){
	root->inorder(root->left);
	cout << root->val;
	root->inorder(root->right);
}

void TreeNode::postorder(TreeNode* root){
	root->postorder(root->left);
	root->postorder(root->right);
	cout << root->val;
}

int main(){
	// did not test
	return 0;
}

