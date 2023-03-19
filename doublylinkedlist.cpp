#include <iostream>
using namespace std;

class node
{
	public: 
		int data;
		node* next;
		node* prev;
		
		
};

class dll{
	node* head;
	node* tail;
	int size;
	
	public:
		
	    dll() { head = NULL; tail = NULL; }
	  
	    
	    void printList(){
	    	node* temp = head;
		    while (temp != NULL) {
		        cout << temp->data << " ";
		        temp = temp->next;
		    }
		    cout << "\n";
		}
		void athead(int val)
		{
			node* newnode=new node();
			newnode->data=val;
			if(head == NULL) {
            head = newnode; 
			}
            
   
   else {
			
			
			newnode->prev=NULL;
			newnode->next=head;
			head->prev=newnode;
			
			head=newnode;
		}
	}
	void atend(int val){
		node* newnode = new node();
  
  
  newnode->data = val;
  
  
  newnode->next = NULL; 
  newnode->prev = NULL;

   
  if(head == NULL) {
    head = newnode;
  } else {
    
    
    node* temp = head;
    while(temp->next != NULL)
      temp = temp->next;
    
    
    temp->next = newnode;
    newnode->prev = temp;
  }    
}
    void inserany(int pos,int ele)
    {
    	
  node* newnode = new node(); 
  newnode->data = ele;
  newnode->next = NULL;
  newnode->prev = NULL;

  
  
    if (pos == 1) {
  
  
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
  } else {

   
    node* temp = head;
    for(int i = 1; i < pos-1; i++) {
      if(temp != NULL) {
        temp = temp->next;
      }
    }
 
    
    if(temp != NULL) {
      newnode->next = temp->next;
      newnode->prev = temp;
      temp->next = newnode;
      if(newnode->next != NULL)
        newnode->next->prev = newnode;  
    } else {
      
      
      cout<<"\nThe previous node is null.";
    } 
  }
	}
	void delf()
	{
		node* newnode=head;
		head=head->next;
		head->prev=NULL;
		newnode->next=NULL;
		delete newnode;
	}
	void delt()
	{
		node*newnode=head;
		node*pre;
		while(newnode->next!=NULL)
		{
			pre=newnode;
			newnode=newnode->next;
			newnode->prev=pre;
		}
		newnode->prev=NULL;
		pre->next=NULL;
		delete newnode;
	}
	bool isInList(int val){
			node* temp = head;
			while(temp != NULL){
				if (temp->data == val){
					return true;
				}
				temp = temp->next;
			}
			return false;
		}
		void reverseList() {
		    node* current = head;
		    node* next = NULL;
		    node* prev = NULL;
		    
		    while (current != NULL) {
		    	
		    	// Set tail // Diff
		    	if (current->prev == NULL){
		    		tail = current;
				}
				
		    	// keep head pointing to current
		    	head = current;
		    	
		    	// save next before reversing link 
				// otherwise next node cannot be accessed
		    	next = current->next;
		    	
		    	// reverse link
		    	current->next = prev;
		    	current->prev = next;	// Diff
		    	
		    	// move previous and current to their respective next nodes
		    	prev = current;
		    	current = next;		        
		    }
		}
		void deleteAllNodes() {
  
  //1. create a temp node
  node* temp = new node();
  
  //2. if the head is not null make temp as head and 
  //   move head to head next, then delete the temp,
  //   continue the process till head becomes null
  while(head != NULL) {
    temp = head;
    head = head->next;
    delete temp;
  }

  cout<<"All nodes are deleted successfully.\n";  
}
       void delany(int position){
       	node*temp=new node();
       	node*pre;
       	node*curr=head;
       	for(int i=1;i<position;i++)
       	{
       		pre=curr;
       		curr=curr->next;
       		curr->prev=pre;
		   }
		   temp=curr->next;
		   pre->next=temp;
		   temp->prev=pre;
		   curr->prev=NULL;
		   curr->next=NULL;
		   delete curr;
	   }
  
   
  
int countNodes() {
  
  //1. create a temp node pointing to head
  node* temp = head;

  //2. create a variable to count nodes
  int i = 0;
  
  //3. if the temp node is not null increase 
  //   i by 1 and move to the next node, repeat
  //   the process till the temp becomes null
  while(temp != NULL) {
    i++;
    temp = temp->next;
  }

  //4. return the count
  return i;  
}   
  
	
		
		
		
		
		
		
		
};

int main(){
	dll d;
	cout<<"at head ::   ";
	d.athead(10);
	d.athead(11);
	d.athead(12);
	d.athead(20);
	d.printList();
	cout<<"at tail ::    ";
	d.atend(11);
	d.atend(33);
	d.atend(44);
	d.printList();
	cout<<"insert 7 at position 3 ::   ";
	d.inserany(3,7);
	d.printList();
	cout<<"reverse ::";
	d.reverseList();
	d.printList();
	cout<<"delete at head ::   ";
	d.delf();
	d.printList();
	cout<<"delete at tail :: ";
	d.delt();
	d.printList();
	cout<<"delete at position 4 : ";
	d.delany(2);
	d.printList();
	cout<<"search 11 ::";
	cout<<d.isInList(11)<<endl;
	cout<<"delete all : ";
	d.deleteAllNodes();
	d.printList();
	cout<<"node count : ";
	cout<<d.countNodes();
	
	
//	d.delany(3);
//	d.printList();
	
	
	
	
	
}
