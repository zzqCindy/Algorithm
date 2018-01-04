#include "RBTree.h"

void RBTree::lRotate(RBNode* x){
	RBNode* y = x->right;
	x->right = y->left;
	if(y->left != NULL) y->left->parent = x;
	y->parent = x->parent;
	if(x->parent == NULL) root = y;
	else{
		if(x == x->parent->left) x->parent->left = y;
		else x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

void RBTree::rRotate(RBNode* y){
	RBNode* x = y->left;
	y->left = x->right;
	if(x->right != NULL) x->right->parent = y;
	x->parent = y->parent;
	if(y->parent == NULL) root = x;
	else{
		if(y->parent->left == y) y->parent->left = x;
		else y->parent->right = x;
	}
	x->right = y;
	y->parent = x;
}
             
RBNode* RBTree::search(int val){
	
	RBNode *cur = root;
	while(cur != NULL && cur->key != val){
		if(cur->key > val) cur = cur->left;
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
			RBNode* uncle = grandparent->right;
			
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
			parent->color = BLACK;
			grandparent->color = RED;
			rRotate(grandparent);
		}
		else{
			RBNode* uncle = grandparent->left;
			
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
			parent->color = BLACK;
			grandparent->color = RED;
			lRotate(grandparent);
		}
		
	}
	
	root->color = BLACK;
}

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
	if(y->key < val) y->right = ptr;
	else y->left = ptr;
	rbInsertFix(ptr);
	
}

// node and brother are both null?????
void RBTree::rbRemoveFix(RBNode* node, RBNode* parent){
	
	RBNode* brother;
	
	while(node != root && (node == NULL || root->color == BLACK)){

		if(node == parent->left){
			brother = parent->right;
			
			if(brother != NULL && brother->color == RED){
				brother->color = BLACK;
				node->parent->color = RED;
				lRotate(parent);
				brother = parent->right;
			}
			if((brother->left == NULL || brother->left->color == BLACK) && 
			   (brother->right == NULL || brother->right->color == BLACK)){
				brother->color = RED;
				node = parent;
			}
			else{
				if(brother->right == NULL || brother->right->color == BLACK){
					if(brother->left != NULL) brother->left->color = BLACK;
					brother->color = RED;
					rRotate(brother);
					brother = node->parent->right;
				}
				brother->color = node->parent->color;
				node->parent->color = BLACK;
				if(brother->right != NULL)brother->right->color = BLACK;
				lRotate(parent);
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
			if((brother->left == NULL || brother->left->color == BLACK) && 
			   (brother->right == NULL || brother->right->color == BLACK)){
				brother->color = RED;
				node = node->parent;
			}
			else{
				if(brother->right == NULL || brother->right->color == BLACK){
					if(brother->left != NULL) brother->right->color = BLACK;
					brother->color = RED;
					lRotate(brother);
					brother = node->parent->left; 
				}
				brother->color = node->parent->color;
				node->parent->color = BLACK;
				if(brother->left != NULL) brother->left->color = BLACK;
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
		
		if(color == BLACK) rbRemoveFix(child,parent);
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
	
	if(color == BLACK) rbRemoveFix(child,parent);
	delete node;
	
}

void RBTree::preorder(RBNode* root){
	if(root == NULL) return;
	cout << root->key << " ";
	if(root->color == RED) cout << "RED ";
	else cout << "BLACK ";
	preorder(root->left);
	preorder(root->right);
}

void RBTree::inorder(RBNode* root){
	if(root == NULL) return;
	inorder(root->left);
	cout << root->key;
	if(root->color == RED) cout << "RED ";
	else cout << "BLACK ";
	inorder(root->right);
}

void RBTree::postorder(RBNode* root){
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->key;
	if(root->color == RED) cout << "RED ";
	else cout << "BLACK ";
}

RBNode* RBTree::getRoot(){
	return root;
}

void RBTree::print(RBNode* root, int h = 0){
	if(root != NULL){
        print(root->right,h+1);
        for(int i=0; i<h; i++)
            cout << "  ";
        cout << root->key << " ";
        if(root->color == RED) cout << "RED ";
		else cout << "BLACK \n";
        print(root->left,h+1);
    }
    cout << endl;
}

int main(){
	
	int a[]= {50, 40, 30, 60, 90, 70, 20, 10, 80};
    int i;
    int ilen = (sizeof(a)) / (sizeof(a[0])) ;
    
    RBTree* tree=new RBTree();

    cout << "== 原始数据: ";
    for(i=0; i<ilen; i++)
        cout << a[i] <<" ";
    cout << endl;

    for(i=0; i<ilen; i++){
        tree->rbInsert(a[i]);

        cout << "== 添加节点: " << a[i] << endl;
        cout << "== 树的详细信息: " << endl;
        tree->print(tree->getRoot());
        cout << endl;
    }
     
    for(i=0; i<ilen; i++){
        tree->rbRemove(a[i]);

        cout << "== 删除节点: " << a[i] << endl;
        cout << "== 树的详细信息: " << endl;
        tree->print(tree->getRoot());
        cout << endl;
    }
    
	return 0;
}
