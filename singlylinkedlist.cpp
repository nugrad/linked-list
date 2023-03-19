#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
};
class sll{
	public:
		node* head;
		void display()
		{
			node* ptr=head;
			while(ptr!=NULL)
			{
				cout<<"\t"<<ptr->data;
				ptr=ptr->next;
			}
			cout<<"\n";
		}
		void athead(int val){
			node* newnode=new node();
			newnode->data=val;
			newnode->next=head;
			head=newnode;
		}
		void attail(int val)
		{
			node* newnode=new node();
			newnode->data=val;
			newnode->next=NULL;
			//4. Check the Linked List is empty or not,
        //   if empty make the new node as head
			if(head==NULL)
			{
				head=newnode;
			}
			//5. Else, traverse to the last node
			else{
				node* ptr=head;
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
				 //6. Change the next of last node to new node
				ptr->next=newnode;
			}
			 
		}
		void delf()// delete at front
		{
			node* temp;
			temp=head;
			head=head->next;
			delete temp;
		}
		void delt() // delete at tail
		{
			if(head==NULL)
			{
				cout<<"node with value does not exist;";
			}
			else{
				node* temp=head;
				//2. Else, traverse to the second last 
               //   element of the list
               while(temp->next->next!=NULL)
               {
               	temp=temp->next;
			   }
			   //3. Change the next of the second 
              //   last node to null and delete the
            //   last node
            node* last=temp->next;
            temp->next=NULL;
            delete last;
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
       bool search(int v)
       {
       	node* temp=head;
       	while(temp!=NULL)
       	{
       		if(temp->data=v)
       		{
       			return true;
			   }
			   else{
			   	temp=temp->next;
			   }
			   return false;
		   }
	   }
	   void reverse()
	   {
	   	node* current = head;
        node *prev = NULL, *next = NULL;
 
        while (current != NULL) 
	   {
		
        	
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
	   }
	   void sort()
	   {
	   	node*curr=head;
	   	node*index=NULL;
	   	int temp;
	   	if(head==NULL)
	   	{
	   		return;
	}
	else{
		while(curr!=NULL)// arr[i]
		{
			index=curr->next;//arr[i+1]
			while(index!=NULL)
			{
				if(curr->data>index->data)
				{
					temp=curr->data;
					curr->data=index->data;
					index->data=temp;
				}
				index=index->next;
			}
			curr=curr->next;
		}
	}
	   }
	   void dup()
	{
		int data;
		int count =0;
		node *ptr,*ptr1;
		ptr=head;
		ptr1=head;
		while(ptr!=NULL)
		{
			count=0;
			data=ptr->data;
			while(ptr1!=NULL)
			{
				if(data==ptr1->data)
				{
					count++;
					
				}
				if(count>1)
				{
					cout<<endl<<"Number of "<<ptr1->data<<" are ="<<count;
				}
				ptr1=ptr1->next;
			}
			
			ptr=ptr->next;
		}
		
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
//-----------------------
		
		
};
int main()
{
	sll s;
	cout<<"at head : :";
	s.athead(4);

	s.athead(3);
	s.athead(9);
	s.athead(1);
	s.display();
	cout<<"at tail : :";
	s.attail(5);
	s.display();
	cout<<"insert 2 at position 3 : :";
	s.insertany(3,2);
	s.display();
	cout<<"duplicate : :";
	s.dup();
	s.display();
	cout<<"sorted :  : ";
	s.sort();
	s.display();
	cout<<"reverse : :";
	s.reverse();
	s.display();
	cout<<"delete at head : :";
	s.delf();
	s.display();
	cout<<"delete at tail : :";
	s.delt();
	s.display();
	cout<<"delete at position 4";
	s.delatposition(4);
	s.display();
	cout<<"search 4 : :";
	cout<<s.search(4)<<endl;
	cout<<"node count : ";
	cout<<s.countNodes();
	
	
}
