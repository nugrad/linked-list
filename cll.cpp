#include<iostream>

using namespace std;

class Node {
	public: 
		int data;
		Node* next;
		
		Node () 
		{
			data = 0;
			next = NULL;
		}
		Node (int d, Node* n)
		{
			data = d;
			next = n;
		}
};

class CircularSinglyLinkedList {
	public:
		// use only tail because adding or removing nodes
		// from front and back become easier compared to
		// maintaining head.
		Node * tail;
	
		CircularSinglyLinkedList() {
			tail = NULL;
  		}
		
		//traverse the circular linked list and print list
		void printList() {
			Node *p;
			
			// If list is empty, return.
			if (tail == NULL) {
				cout << "Circular linked List is empty." << endl;
				return;
			}
			p = tail -> next; // Point to the first Node in the list.
			
			// Traverse the list starting from first node 
			// until first node is visited again
			do {
				cout << p -> data << " ";
				p = p -> next;
			} while(p != tail->next);
			cout<<"\n";
		}
		
		// Insert at the front
		void push_front(int new_data)
		{
			//create a new node
			Node *new_node = new Node(new_data, NULL);	
			
			//if list is empty then assign node to tail
			if (tail == NULL){
				tail = new_node;
				tail->next = new_node;
				return;
			}
		  
		   //set new data to node
		   new_node -> next = tail -> next;
		   tail -> next = new_node;
		}
		
		// Insert after a given node - same as SLL
		
		/*
		 Insert at the end:
		 	
			make new node
			if tail is null: 
				make tail new node, 
				set it's next to new node and return
			set next of new node to next of tail
			set next of tail to new node
			set tail to new node
		*/
		
		/* 
		Delete from head:
			if tail is null, return
			if next of tail is tail (only one node case):
				hold tail to temp pointer
				set tail to null
				delete temp
			hold next of tail in temp ptr
			set next of tail to next of next of tail
			delete temp ptr
		*/
		
		// delete node with a value (first occurence)
		//		same as SLL, just difference in traversal logic
		
		// Delete from tail - need to traverse?
		
		// Copy constructor
		CircularSinglyLinkedList(const CircularSinglyLinkedList& obj){
			tail = NULL;
			Node *temp_node = obj.tail->next;	// to iterate through obj's list	// Diff
			Node *obj_first = temp_node;
			Node *last_node, *n;
			Node *my_first;
			
			do{
				n = new Node(temp_node->data, NULL);
				
				if (tail == NULL){		// Diff
					my_first = n;
				}
				else{
					last_node->next = n;
				}
				tail = n;
				last_node = n;
				temp_node = temp_node->next;
			} while(temp_node != obj_first);
			
			last_node->next = my_first;	// Diff
		}
};

int main(){
	CircularSinglyLinkedList csll;
	csll.push_front(2);
	csll.push_front(4);
	csll.push_front(6);
	csll.printList();
	
	CircularSinglyLinkedList csll2(csll);
	csll2.printList();
}

