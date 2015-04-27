#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node* prev;
	Node(int dat, Node* nexter,Node* previous){
		data = dat;
		next = nexter;
		prev = previous;
	}
};

class Queue{
	Node* head=NULL;
	Node* tail=NULL;	
public:
	Queue(){}
	void push(int data){
		if(head==NULL){
			Node* new_node = new Node(data,head,NULL);
			head = new_node;
			tail = new_node;
		}else{
			Node* new_node = new Node(data,head,NULL);
			head->prev = new_node;
			head = new_node;
		}
	}
	int pop(){
		Node* to_delete;
		int data = tail->data;
		to_delete = tail;
		tail = to_delete->prev;
		delete to_delete;
		return data;
	}
};

int main(){

	Queue q;
	q.push(4);
	q.push(5);
	cout << q.pop()<<endl;

	return 0;
} 
