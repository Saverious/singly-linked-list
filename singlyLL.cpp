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

int main(){
    int choice;
    int age;
    do{
        cout<<"\n\n***SINGLY LINKED LIST DATA STRUCTURE***\n";
        cout<<"   1. Insert at the beginning\n   2. Insert at the end\n   0. Exit\n\n";
        cout<<"   Enter option : ";
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"   Enter age : ";
            cin>>age;
            insertFront(age);
            break;

            case 2:
            cout<<"\n   Enter age : ";
            cin>>age;
            insertEnd(age);
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