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
	/*void delete(int data){

	}*/
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
	/*void delete(int data, Node* leaf){

	}*/
};

	
int main(){
	BinaryTree btree;
	btree.insert(4);
	btree.insert(7);
	btree.insert(19);
	cout <<btree.exists(199)<<endl;
	return 0;
	}
