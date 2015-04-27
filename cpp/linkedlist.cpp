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
	void DeleteByValue(int value);
	void DeleteByIndex(int index);
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

void List::DeleteByValue(int value){
	if(head==NULL){
		return;
	}else{
		if(head->data==value){
			Node* to_delete;
			to_delete = head;
			head = to_delete->next;
			delete to_delete;
		}else{
			Node* cur = head;
			Node* prev = cur;
			cur = cur->next;
			while(cur != NULL && cur->next != NULL){
				if(cur->data==value){
					Node* to_delete;
					to_delete = cur;
					cur = to_delete->next;
					prev->next = cur;
					delete to_delete;
					break;
				}else if(cur != NULL && cur->next == NULL){
					if(cur->data==value){
						Node* to_delete;
						to_delete = cur;
						prev->next = NULL;
						delete to_delete;
						break;
					}
				}
				cur = cur->next;
				
			} 
		}
	}
}

void List::DeleteByIndex(int index){
	if(head==NULL){
		return;
	}else if(index >= size){
			return;
	}else{
		if(index==0){
			Node* to_delete;
			to_delete = head;
			head = to_delete->next;
			delete to_delete;
		}else{
			int counter = 1;
			Node* cur = head;
			Node* prev = cur;
			cur=cur->next;
			while(counter < index){
				cur = cur->next;
				prev = prev->next;
				counter++;
			}
			Node* to_delete = cur;
			cur = to_delete->next;
			prev->next = cur;
			delete to_delete;
		}
	}
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
	list.DeleteByValue(7);
	cout << list.Exists(7)<<endl;
	list.DeleteByIndex(0);
	cout << list.Exists(5);
	return 0;
}
