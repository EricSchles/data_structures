#include <iostream>
using namespace std;

//make use of this: http://en.wikipedia.org/wiki/Red%E2%80%93black_tree
class Node{
public:
	int data;
	string color;
	Node* left;
	Node* right;
	Node(int datum, string coloring,Node* lefty,Node* righty){
		data = datum;
		color = coloring;
		left = lefty;
		right = righty;
	}
};



class RedBlackTree{
public:
	Node* root;
	RedBlackTree(){}
	void insert(int data){
		if(root=NULL){
			root = new Node(data,"black",NULL,NULL);
		}
	}
	void remove(int data);
private:
	void insert(int data, Node* leaf);
	void remove(int data, Node* leaf);
};

int main(){
	cout << "Hello";
	return 0;
}
