#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int dat,Node* nexter){
		data = dat;
		next = nexter;
	}

};

class Stack{
public:
	Node* head;
	Stack(){}
	void push(int data){
		Node* new_node = new Node(data,head);
		head = new_node;
	}
	int pop(){
		int data = head->data;
		Node* to_delete;
		to_delete = head;
		head = to_delete->next;
		delete to_delete;
		return data; 
	}
};

int main(){

	Stack s;
	s.push(5);
	s.push(7);
	cout << s.pop()<<endl;
	return 0;
}

