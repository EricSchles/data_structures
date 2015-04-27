#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int Adata,Node* Anext){
			data = Adata;
			next = Anext;
		}
		int GetData(){
			return data;
		}
		void setData(int dat){
			data = dat;
		}
		Node* GetNext(){
			return next;
		}
};

class List{
	Node* head;
	int size;
public:
	List(){ 
		head = NULL;
		size=0;
	}
	void Append(int data);
	void Prepend(int data);
	int GetByIndex(int index);
	bool Exists(int value);
	int NumOccurrences(int value);
};

void List::Append(int data){
	if(head == NULL){
		head = new Node(data,NULL);
	}else{
		Node* cur = head;
		while( cur->next !=NULL){
			cur=cur->next;
		}
		Node* new_node = new Node(data,NULL);
		cur->next = new_node;
		size++;
	}
	
}

void List::Prepend(int data){
	Node* new_head = new Node(data,head);
	if(head!=NULL){size++;}
	head = new_head;
}

int List::GetByIndex(int index){
	if(index <0){
		return -1; // indicates you input an incorrect value
	}
	if(size < index){
		return -1; //tried to index outside of the list
	}
	if(index == 0){
		return head->data;
	}else{
		Node* cur = head;
		int counter = 0;

		while(counter < index){
			cur=cur->next;
			counter++;
		}
		return cur->data;
	}
}

bool List::Exists(int value){
	if(head==NULL){
		return false;
	}else{
		if(head->data==value){
			return true;
		}else{
			Node* cur = head;
			while(cur != NULL){
				if(cur->data==value){
					return true;
				}else{
					cur = cur->next;
				}
			} 
		}
	}
}

int List::NumOccurrences(int value){
	int total=0;
	if(head==NULL){
		return total;
	}else{
		if(head->data==value){
			total++;
		}else{
			Node* cur = head;
			while(cur != NULL){
				if(cur->data==value){
					total++;
				}
				cur = cur->next;
				
			} 
		}
	}
	return total;	
}

int main(){
	/*
	Methods to check
	void Append(int data);
	void Prepend(int data);
	int GetByIndex(int index);
	bool Exists(int value);
	int NumOccurrences(int value);
	*/
	List list;
	list.Append(5);
	list.Append(6);
	cout << list.NumOccurrences(6)+list.NumOccurrences(5)<<endl; //should be 2
	list.Prepend(7);
	cout << list.NumOccurrences(7)<<endl;//should be 1
	cout << list.GetByIndex(1)<<endl;//should be 5
	cout << list.Exists(7)<<endl;//should be true
	return 0;
}