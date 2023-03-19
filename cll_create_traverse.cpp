#include <iostream>
using namespace std;

//node structure
class Node {
	public:
    int data;
    Node* next;
};

class LinkedList {
  public:
    Node* head;
  public:
    //constructor to create an empty LinkedList
    LinkedList(){
      head = NULL;
    }

    //display the content of the list
    void PrintList() {
      Node* temp = head;
      if(temp != NULL) {
        cout<<"The list contains: ";
        while(true) {
          cout<<temp->data<<" ";
          temp = temp->next;
          if(temp == head) 
            break;
        }
        cout<<endl;
      } else {
        cout<<"The list is empty.\n";
      }
    }     
};

// test the code  
int main() {
  //create an empty LinkedList
  LinkedList MyList;

  //Add first node.
  Node* first = new Node();
  first->data = 10;
  //linking with head node
  MyList.head = first;       
  //linking next of the node with head
  first->next = MyList.head;

  //Add second node.
  Node* second = new Node();
  second->data = 20;
  //linking with first node
  first->next = second; 
  //linking next of the node with head
  second->next = MyList.head;

  //Add third node.
  Node* third = new Node();
  third->data = 30;
  //linking with second node
  second->next = third;
  //linking next of the node with head
  third->next = MyList.head;

  //print the content of list
  MyList.PrintList();
  return 0; 
}
