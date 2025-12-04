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

    int findMiddle(){
        if(head==nullptr){
            return -1;
        }
        Node*slow=head;
        Node*fast=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
    }
};

int main(){
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    cout<<"Middle element is: "<<list.findMiddle()<<endl;
    return 0;
}
