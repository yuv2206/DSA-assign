#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
};

class LinkedList{
private:
    Node*head=nullptr;
public:
    void insert(int data){
        Node*newNode=new Node;
        newNode->data=data;
        newNode->next=nullptr;
        if(head==nullptr){
            head=newNode;
            return;
        }
        Node*temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newNode;
    }

    void reverse(){
        Node*prev=nullptr;
        Node*current=head;
        Node*next_node=nullptr;

        while(current!=nullptr){
            next_node=current->next;
            current->next=prev;
            prev=current;
            current=next_node;
        }
        head=prev;
    }

    void display(){
        Node*temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    cout<<"Original Linked List:"<<endl;
    list.display();
    list.reverse();
    cout<<"Reversed Linked List:"<<endl;
    list.display();
    return 0;
}

