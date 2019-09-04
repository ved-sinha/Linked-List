#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        
    //Constructor
    node(int d){
        data=d;
        next=NULL;
    }
};


//Insertion operations

void insertAtHead(node*&head, int data){
    node* n=new node(data);
    n->next=head;
    head=n;
}

int len(node* &head){
    int l=1;
    node* temp=head;
    while(temp != NULL){
        temp=temp->next;
        l++;
    }
    return l;
}

void insertAtEnd(node* &head,int data){
    if(head==NULL){
        insertAtHead(head,data);
        return;
    }
    node* n=new node(data);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    return;
}

void insertAtMiddle(node* &head,int data,int pos){
    if(head==NULL||pos==0){
        insertAtHead(head,data);
        return;
    }
    if(pos>len(head)){
        insertAtEnd(head,data);
        return;
    }
    int count=1;
    node *n=new node(data);
    node *temp=head;
    while(count!=pos-1){
        temp=temp->next;
        count++;
    }
    n->next=temp->next;
    temp->next=n;
    return;
}


//Deletion operation

void deleteHead(node* &head){
    node* temp=head;
    head=head->next;
    delete temp;
    return;
}

void deleteTail(node* &head){
    node* prev=NULL;
    node* temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    return;
}

void deleteMiddle(node* &head,int pos){
    int count=1;
    node *prev=NULL;
    node* temp=head;
    while(count!=pos){
        prev=temp;
        temp=temp->next;
        count++;
    }
    prev->next=temp->next;
    delete temp;
}

//Searching recursively and iteratively

bool searchR(node*&head,int key){
    node* temp=head;
    if(temp==NULL)
    return false;
    
    if(temp->data==key) {
        return true;
    }
    
    else return searchR(temp->next,key);
}

void buildList(node*&head){
    int data;
    cin>>data;
    while(data != -1){
        insertAtEnd(head,data);
        cin>>data;
    }
}

//reverse the linked List iteratively and recursively

void reverse(node* &head){
    
    node* prev=NULL;
    node* curr=head;
    node* n;
    
    while(curr!=NULL){
        //make n point to next node
        n=curr->next;
        //make the next of current node point to its previous node
        curr->next=prev;
        //updating conditions
        prev=curr;
        curr=n;
    }
    head=prev;
    return;
}


node* reverseRec(node*head){
   
    if(head->next==NULL||head==NULL){
        return head;
    }
    
    //going to the last 2nd call i.e just a call before head hits dead end
    
    node* smallHead=reverseRec(head->next);
    node* c=head;
    c->next->next=c;
    c->next=NULL;
    return smallHead;
}



void print(node* head){
    node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main() {
	node* head=NULL;
	//buildList(head);
	buildList(head);
	print(head);
	head=reverseRec(head);
	print(head);
	return 0;
}
