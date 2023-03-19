#include <iostream>
using namespace std;

//node structure
struct Node {
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
        while(temp != NULL) {
          cout<<temp->data<<" ";
          temp = temp->next;
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
  Node* first = new Node();//Add first node.
  Node* second = new Node();//Add second node.
  Node* third = new Node();//Add third node.
  
  MyList.head = first;//linking with head node
  first->data = 10;
  first->next=second;//linking with second node
  second->data = 20;
  second->next = third;//linking with third node
  third->data = 30;
  third->next=NULL;
  MyList.PrintList();//print the content of list
  
  
  

  
  
  return 0; 
}
