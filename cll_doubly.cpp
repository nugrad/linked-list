#include <iostream>
using namespace std;

//node structure
class node {
	public:
		
    int data;
    node* next;
    node* prev;
};

class cll {
  public:
    node* head;
  public:
    //constructor to create an empty LinkedList
    cll(){
      head = NULL;
    }
    void athead(int val)
    {
    	//1. allocate node
       node* newNode = new node();
  
  //2. assign data element
      newNode->data = val;
  
       //3. assign null to the next and prev
      //   of the new node
      newNode->next = NULL;
      newNode->prev = NULL; 
  
  //4. Check the list is empty or not,
  //   if empty make the new node as head 
  if(head == NULL) {
    head = newNode;
    newNode->next = head;
    newNode->prev = head;
  } else {
    
    //5. Else, traverse to the last node
    node* temp = head;
    while(temp->next != head)
      temp = temp->next;
    
    //6. Adjust the links
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}
  //---------------------------
     void attail(int val)
     {
     	//1. allocate node
  node* newNode = new node();
  
  //2. assign data element
  newNode->data = val;
  
  //3. assign null to the next and prev
  //   of the new node
  newNode->next = NULL;
  newNode->prev = NULL; 
  
  //4. Check the list is empty or not,
  //   if empty make the new node as head 
  if(head == NULL) {
    head = newNode;
    newNode->next = head;
    newNode->prev = head;
  } else {
    
    //5. Else, traverse to the last node
    node* temp = head;
    while(temp->next != head)
      temp = temp->next;
    
    //6. Adjust the links
    temp->next = newNode;
    newNode->next = head;
    newNode->prev = temp;
    head->prev = newNode;
  }    
	 }
	 //---------------------------------------------
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
	//------------------------------------
	 
    
    	
	

    //display the content of the list
    void show() {
      node* temp = head;
      if(temp != NULL) {
        
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
	//-------------------------------------
	void reverseList() {
		    node* current = head;
		    node* next = NULL;
		    node* prev = NULL;
		    node*tail=NULL;
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
		//---------------------------------------
		void delf()
		{
			if(head != NULL) {
    
    //1. the list contains one node, delete
    //   make the head null
    if(head->next == head) {
      head = NULL;
    } else {
      
      //2. if the list contains more than one node,
      //   create two nodes - temp and firstNode, both
      //   pointing to head node
      node* temp = head;
      node* firstnode = head;
      
      //3. using temp node, traverse to the last node
      while(temp->next != head) {
        temp = temp->next;
      }
      
      //4. Make head as next of head, and 
      //   update links
      head = head->next;
      head->prev = temp;
      temp->next = head; 
      delete firstnode;
    }
  }
  
	}    
	//---------------------------------------
	void delt()
	{
		if(head != NULL) {
    
    //1. if head in not null and next of head
    //   is head, release the head
    if(head->next == head) {
      head = NULL;
    } else {
      
      //2. Else, traverse to the second last 
      //   element of the list
      node* temp = head;
      while(temp->next->next != head)
        temp = temp->next;
      
      //3. Update links of head and second 
      //   last node, and delete the last node
      node* lastnode = temp->next;
      temp->next = head;
      head->prev = temp;
      delete lastnode;
    }
  }
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
	//--------------------------
	int countNodes() {
  
  //1. create a temp node pointing to head
  node* temp = head;

  //2. create a variable to count nodes
  int i = 0;
  
  //3. if the temp node is not null increase 
  //   i by 1 and move to the next node, repeat
  //   the process till the temp becomes null
  if(temp != NULL) {
    i++;
    temp = temp->next;
  }
  while(temp != head) {
    i++;
    temp = temp->next;
  }

  //4. return the count
  return i;  
} 
//--------------------------
};

// test the code  
int main() {
	cll c;
	cout<<"at head :  ";
	c.athead(1);
	c.athead(3);
	c.athead(5);
	c.athead(7);
	c.show();
	cout<<"at tail : ";
	c.attail(9);
	c.attail(11);
	c.show();
	cout<<"insert 4 at position 3 : ";
	c.inserany(3,4);
	c.show();
	cout<<"reversse : ";
	c.reverseList();
	c.show();
	cout<<"delete at head : ";
	c.delf();
	c.show();
	cout<<"delete at tail : ";
	c.delt();
	c.show();
	cout<<"delete element at position 4";
	c.delany(4);
	c.show();
	cout<<"node count : ";
	cout<<c.countNodes();
  
}
