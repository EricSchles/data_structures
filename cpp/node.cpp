#include <iostream>
using namespace std;

class Node{
	public:
		int data;
	  	Node* next;
		Node(int Adata,Node* Anode){ 
			data = Adata;
			next = Anode;
		}  
};


int main(){

	Node* head;
	head = new Node(0,NULL);
	Node* cur;
	cur = head;
	for(int i=0;i<100;i++){
		Node* new_node = new Node(i,NULL);
		cur->next = new_node;
		cur = cur->next;
	}
	cur = head;
	while(cur!=NULL){
		cout<<cur->data<<endl;
		cur = cur->next;
	}	
	return 0;
}
