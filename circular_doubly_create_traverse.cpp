#include <iostream>
using namespace std;

//node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
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
  first->next = NULL;
  first->prev = NULL;
  //linking with head node
  MyList.head = first;
  //linking next of the node with head
  first->next = MyList.head;
  //linking prev of the head 
  MyList.head->prev = first;        

  //Add second node.
  Node* second = new Node();
  second->data = 20;
  second->next = NULL;
  //linking with first node
  second->prev = first;  
  first->next = second;
  //linking next of the node with head
  second->next = MyList.head;
  //linking prev of the head 
  MyList.head->prev = second;   

  //Add third node.
  Node* third = new Node();
  third->data = 30;
  third->next = NULL;
  //linking with second node
  third->prev = second;
  second->next = third;
  //linking next of the node with head
  third->next = MyList.head; 
  //linking prev of the head 
  MyList.head->prev = third; 

  //print the content of list
  MyList.PrintList();
  return 0; 
}
