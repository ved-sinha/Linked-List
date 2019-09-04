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
    node* n=new node(data);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void insertAtMiddle(node* &head,int data,int pos){
    if(head==NULL||pos==0){
        insertAtHead(head,data);
    }
    if(pos>len(head)){
        insertAtEnd(head,data);
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
	insertAtHead(head,5);
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	//print(head);
	insertAtMiddle(head,4,4);
	//print(head);
	insertAtMiddle(head,6,6);
	//print(head);
	insertAtEnd(head,7);
	print(head);
	//deleteHead(head);
	//deleteTail(head);   
    //deleteMiddle(head,4);
    //print(head);
    bool res=searchR(head,9);
    if(res==true)
    cout<<"YES";
    else
    cout<<"NO";
	return 0;
}
