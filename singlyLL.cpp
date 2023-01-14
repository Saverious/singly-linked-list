#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    int age;
    struct node* next;
};

struct node* head=NULL;

bool isEmpty(){
    if(head==NULL){
        return true;
    }else{
        return false;
    }
}

void insertFront(int val){
    struct node* ptr=NULL;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        cout<<"\n\nFailed to allocate memory!";
    }else{
        if(isEmpty()){
            ptr->age=val;
            ptr->next=NULL;
            head=ptr;
            cout<<"\n   First node inserted";
            cout<<"\n   Head is "<<head;
            cout<<"\n   Age : "<<head->age;
            cout<<"\n   Node's next address : "<<head->next;
        }else{
            ptr->age=val;
            ptr->next=head;
            head=ptr;
            cout<<"\n   Node inserted at the beginning";
            cout<<"\n   Head is "<<head;
            cout<<"\n   Age : "<<head->age;
            cout<<"\n   Node's next address : "<<head->next;
        }
    }
}

void insertEnd(int val){
    struct node* ptr=NULL;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        cout<<"\n   Failed to allocate memory!";
    }else{
        if(isEmpty()){
            insertFront(val);
        }else{
            struct node* temp;
            temp=head;
            
            while(temp->next != NULL){
                temp=temp->next;
            }
            ptr->age=val;
            ptr->next=NULL;
            temp->next=ptr; // store address of new node in the *next* of previously last node
            cout<<"\n   Node inserted at the end";
            cout<<"\n   Head is "<<head;
            cout<<"\n   Age : "<<ptr->age;
            cout<<"\n   Next address : "<<ptr->next;
        }
    }
}

void insertAfter(int value, int index){
    if(!isEmpty()){
        int init;
        struct node* temp=NULL;
        temp=head;
        for(init=0;init<index;init++){
            temp=temp->next;
        }
        if(temp->next==NULL){
            cout<<"\n   The index given belongs to the last node. Inserting at the end...";
            insertEnd(value);
        }else{
            struct node* ptr=NULL;
            ptr=(struct node*)malloc(sizeof(struct node));
            if(ptr==NULL){
                cout<<"\n   Failed to allocate memory";
            }else{
                ptr->age=value;
                ptr->next=temp->next;
                cout<<"\n   Next of previous node before insertion-### : "<<temp->next;
                temp->next=ptr;
                cout<<"\n   Next of previous node after insertion-&&& : "<<temp->next;
                cout<<"\n   Node inserted after node number "<<index;
                cout<<"\n   Address of previous node : "<<temp;
                cout<<"\n   Next of inserted node-### : "<<ptr->next;
                cout<<"\n   Address of inserted node-&&& : "<<ptr;
            }
        }
    }else{
        cout<<"\n   The list is empty. Proceeding to insert the first node...";
        insertFront(value);
    }
}

int main(){
    int choice;
    int age;
    int index;
    do{
        cout<<"\n\n***SINGLY LINKED LIST DATA STRUCTURE***\n";
        cout<<"   1. Insert at the beginning\n   2. Insert at the end\n   3. Insert after a specified node\n   0. Exit\n\n";
        cout<<"   Enter option : ";
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"   Enter age : ";
            cin>>age;
            insertFront(age);
            break;

            case 2:
            cout<<"   Enter age : ";
            cin>>age;
            insertEnd(age);
            break;

            case 3:
            cout<<"   Enter age : ";
            cin>>age;
            cout<<"   Enter node index to insert after : ";
            cin>>index;
            insertAfter(age,index);
            break;

            case 0:
            return 0;
            break;

            default:
            cout<<"\n   Invalid choice!";
            break;
        }
    }while(choice != 0);
}