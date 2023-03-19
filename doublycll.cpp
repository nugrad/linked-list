#include <iostream>
using namespace std;

class Node
{
	public: 
		int data;
		Node* next;
		Node* prev;
		
		Node () 
		{
			data = 0;
			next = NULL;
			prev = NULL;
		}
		Node (int d, Node* n, Node* p)
		{
			data = d;
			next = n;
			prev = p;
		}
};

class CircularDoublyLinkedList{
	Node* tail;
	
	public:
		// Default constructor
	    CircularDoublyLinkedList() { tail = NULL; }
	  
	    // Function to print the circular linked list.
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
				cout << p -> data << "==>";
				p = p -> next;
			} while(p != tail->next);
			cout<<"\n";
		}
		
		// print list in reverse ???
		
		// Insert at the end
		void push_back(int data){
			
			// make new node and set its data and set its next as NULL
	  		Node* new_node = new Node(data, NULL, NULL);
	  		
	  		// If the Linked List is empty,
		    // then make the new node as head
		    // Diff
		    if (tail == NULL)
		    {
		        tail = new_node;
		        new_node->next = new_node;
		        new_node->prev = new_node;
		        return; 
		    }
	  		
	  		new_node->next = tail->next;	// Diff
	  		new_node->prev = tail;			// Diff
	  		tail->next = new_node;
	  		tail = new_node;
		}
		
		// Copy constructor
		CircularDoublyLinkedList(const CircularDoublyLinkedList& obj){
			tail = NULL;
			Node *temp_node = obj.tail->next;	// to iterate through obj's list	// Diff
			Node *obj_first = temp_node;
			Node *last_node, *n;
			Node *my_first;
			
			do{
				n = new Node(temp_node->data, NULL, NULL);
				
				if (tail == NULL){		// Diff
					my_first = n;
				}
				else{
					n->prev = last_node;	// Diff
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
	CircularDoublyLinkedList cdll;
	cdll.push_back(2);
	cdll.push_back(4);
	cdll.push_back(6);
	cdll.printList();
	
	CircularDoublyLinkedList cdll2(cdll);
	cdll2.printList();
}

