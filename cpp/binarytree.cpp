#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(int dat,Node* lefty,Node* righty){
		data = dat;
		left = lefty;
		right = righty;
	}
};

class BinaryTree{
	Node* root=NULL;
public:
	BinaryTree(){}
	void insert(int data){
		if(root==NULL){
			root = new Node(data,NULL,NULL);
		}else{
			insert(data,root);
		}
	}
	

	bool exists(int key){
		if(root->data==key){
			return true;
		}else{
			return exists(key,root);
		}
	}

	void remove(int data){
		
			if(root != NULL){
			//if root node has the data, a whooping 30 lines 
			if(root->data == data){
				if(root->left != NULL){
					Node* to_delete = root;
					Node* new_left;
					if(root->left->left != NULL){
						new_left = root->left->left;
					}else if(root->left->right != NULL){
						new_left = root->left->right;
					}else{
						new_left = NULL;
					}
					root = to_delete->left;
					delete to_delete;
					root->left = new_left;
				}else if(root->right != NULL){
					Node* to_delete = root;
					Node* new_right;
					if(root->right->left != NULL){
						new_right = root->right->left;
					}else if(root->right->right != NULL){
						new_right = root->right->right;
					}else{
						new_right = NULL;
					}
					root = to_delete->right;
					delete to_delete;
					root->right = new_right;
				}else{
					root = NULL;
				}
			}else{
				remove(data,root);
			}
		}
	}

private:
	void insert(int data, Node* leaf){
		if(data < leaf->data){
			if(leaf->left == NULL){
				Node* new_node = new Node(data,NULL,NULL);
				leaf->left = new_node;
			}else{
				insert(data,leaf->left);
			}
		}else{
			if(leaf->right ==NULL){
				Node* new_node = new Node(data,NULL,NULL);
				leaf->right = new_node;
			}else{
				insert(data,leaf->right);
			}
		}
	}
	bool exists(int data, Node* leaf){
		if(leaf==NULL){
			return false;
		}
		else if(data==leaf->data){
			return true;
		}
		else if(data < leaf->data){
			return exists(data,leaf->left);
		}else if(data > leaf->data){
			return exists(data,leaf->right);
		}
		
	}
	
	void remove(int data, Node* leaf){
		
		if(leaf != NULL){
			//If the data was found
			if(leaf->data==data){
				if(leaf->left != NULL){
					Node* to_delete = leaf;
					Node* new_left;
					if(leaf->left->left != NULL){
						new_left = leaf->left->left;
					}else if(leaf->left->right != NULL){
						new_left = leaf->left->right;
					}else{
						new_left = NULL;
					}
					leaf = to_delete->left;
					delete to_delete;
					leaf->left = new_left;
				}else if(leaf->right != NULL){
					Node* to_delete = leaf;
					Node* new_right;
					if(leaf->right->left != NULL){
						new_right = leaf->right->left;
					}else if(leaf->right->right != NULL){
						new_right = leaf->right->right;
					}else{
						new_right = NULL;
					}
					leaf = to_delete->right;
					delete to_delete;
					leaf->right = new_right;
				}else{
					Node* to_delete = leaf;
					delete to_delete;
				}
			
			}else{
				if(leaf->left != NULL){
					remove(data,leaf->left);	
				}
				if(leaf->right != NULL){
					remove(data,leaf->right);
				}
			}
		}
	}
};

	
int main(){
	BinaryTree btree;
	btree.insert(4);
	btree.insert(7);
	btree.insert(19);
	cout <<btree.exists(199)<<endl;
	btree.remove(19);
	cout << btree.exists(19)<<endl;
	return 0;
}
