#include <iostream>
using namespace std;

//node structure
class node {
	public:
    int data;
    node* next;
};

class cll {
  public:
    node* head;
    node* tail;
  public:
    //constructor to create an empty LinkedList
    LinkedList(){
      head = NULL;
    }

    //display the content of the list
    void PrintList() {
      node* temp = head;
 
    
    if (head != NULL) {
 
        
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
    } 
	void athead(int val)
	{
		node* newNode = new node();
  
  //2. assign data element
  newNode->data = val;
  
  //3. assign null to the next of new node
  newNode->next = NULL; 
  
  //4. Check the list is empty or not,
  //   if empty make the new node as head 
  if(head == NULL) {
    head = newNode;
    newNode->next = head;
  } else {
    
    //5. Else, traverse to the last node
    node* temp = head;
    while(temp->next != head)
      temp = temp->next;
    
    //6. Adjust the links
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
	} 
}
    void attail(int val)
    {
    	node* newNode = new node();
  
  //2. assign data element
  newNode->data = val;
  
  //3. assign null to the next of new node
  newNode->next = NULL; 
  
  //4. Check the list is empty or not,
  //   if empty make the new node as head 
  if(head == NULL) {
    head = newNode;
    newNode->next = head;
  } else {
    
    //5. Else, traverse to the last node
    node* temp = head;
    while(temp->next != head)
      temp = temp->next;
    
    //6. Adjust the links
    temp->next = newNode;
    newNode->next = head;
  }   
	}
	void insertany(int pos,int ele)
		{
			node* newnode = new node(); 
            newnode->data = ele;
             newnode->next = NULL;

  //2. check if the position is > 0
           if(pos < 1) {
           cout<<"\nposition should be >= 1.";
            }
         else if (pos == 1) {
  
  //3. if the position is 1, make next of the
  //   new node as head and new node as head
          newnode->next = head;
          head = newnode;
         } 
       else {

   //4. Else, make a temp node and traverse to the 
   //   node previous to the position
        node* temp = head;
        for(int i = 1; i < pos-1; i++) {
          if(temp != NULL) {
        temp = temp->next;
       }
       
	   
	  
    }
 
    //5. If the previous node is not null, make 
    //   newNode next as temp next and temp next 
    //   as newNode.
    if(temp != NULL) {
      newnode->next = temp->next;
      temp->next = newnode;  
    } else {
      
      //6. When the previous node is null
      cout<<"\nThe previous node is null.";
    } 
  }
}
      void reverseList() {
  //1. If head is not null create three nodes
  //   prevNode - pointing to head,
  //   tempNode - pointing to head,
  //   curNode - pointing to next of head
  if(head != NULL) {
    node* prevNode = head;
    node* tempNode = head;
    node* curNode = head->next;
    
    //2. assign next of prevNode as itself to make the
    //   first node as last node of the reversed list
    prevNode->next = prevNode;
    
    while(curNode != head) {
      //3. While the curNode is not head adjust links 
      //   (unlink curNode and link it to the reversed list 
      //   from front and modify curNode and prevNode) 
      tempNode = curNode->next;
      curNode->next = prevNode;
      head->next = curNode;
      prevNode = curNode;
      curNode = tempNode;
    }

    //4. Make prevNode (last node) as head
    head = prevNode;
  }
} 
       void delatposition(int pos){
    node* curr;
    node* pre;
    curr=head;
    for(int i=1;i<pos;i++){
        pre=curr;
        curr=curr->next;
    }
    pre->next=curr->next;
    delete curr;
}
        void delf()
        {
        	//2. if the list contains more than one node,
      //   create two nodes - temp and firstNode, both
      //   pointing to head node
        	node*temp=head;
        	node*temp2=head;
        	//3. using temp node, traverse to the last node
        	while(temp->next!=head)
        	{
        		temp=temp->next;
			}
			//4. Make head as next of head,
      //   Make next of last node as head,
      //   delete the firstNode
			head = head->next;
            temp->next = head; 
            delete temp2;
		}
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
      
      //3. Change the next of the second 
      //   last node to head and delete the
      //   last node
      node* lastNode = temp->next;
      temp->next = head;
      delete lastNode;
    }
  }
		}
		//--------------------------------------------
//		// Copy constructor
//		cll(const cll& obj){
//			tail = NULL;
//			node *temp_node = obj.tail->next;	// to iterate through obj's list	// Diff
//			node *obj_first = temp_node;
//			node *last_node, *n;
//			node *my_first;
//			
//			do{
//				n = new node(temp_node->data, NULL);
//				
//				if (tail == NULL){		// Diff
//					my_first = n;
//				}
//				else{
//					last_node->next = n;
//				}
//				tail = n;
//				last_node = n;
//				temp_node = temp_node->next;
//			} while(temp_node != obj_first);
//			
//			last_node->next = my_first;	// Diff
//		}
//---------------------------------------------------
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
		
                	
				
};

// test the code  
int main() {
	cll c;
	
	cout<<"at head  :  ";
	c.athead(5);
	c.athead(4);
	c.athead(3);
	c.athead(2);
	c.athead(1);
	c.PrintList();
	cout<<"at tail : ";
	c.attail(6);
	c.attail(8);
	c.PrintList();
	cout<<"insert 9 at position 8 : ";
	c.insertany(8,9);
	c.PrintList();
	cout<<"reverse :  ";
	c.reverseList();
	c.PrintList();
	cout<<"delete 4th element : ";
	c.delatposition(4);
	c.PrintList();
	cout<<"delete at head : ";
	c.delf();
	c.PrintList();
	cout<<"delete at tail : ";
	c.delt();
	c.PrintList();
	cout<<"node count : ";
	cout<<c.countNodes()<<endl;
	
	
	
	cll c2(c);
	c2.PrintList();
	
  
  
}
