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
    void insertAtEnd(int data){
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

    void display(){
        if(head==nullptr){
            cout<<"List is empty."<<endl;
            return;
        }
        Node*temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    int countAndDelete(int key){
        Node*dummy=new Node;
        dummy->next=head;
        Node*current=head;
        Node*prev=dummy;
        int count=0;
        
        while(current!=nullptr){
            if(current->data==key){
                count++;
                prev->next=current->next;
                Node*temp=current;
                current=current->next;
                delete temp;
            }else{
                prev=current;
                current=current->next;
            }
        }
        head=dummy->next;
        delete dummy;
        return count;
    }
};

int main(){
    LinkedList list;
    int choice;
    int key;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtEnd(1);
    do{
        cout<<"\nMenu:\n";
        cout<<"1. Count and delete a key\n";
        cout<<"2. Display list\n";
        cout<<"3. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter key to count and delete: ";
                cin>>key;
                cout<<"Count: "<<list.countAndDelete(key)<<"\n";
                break;
            case 2:
                list.display();
                break;
            case 3:
                cout<<"Exiting program.\n";
                break;
            default:
                cout<<"Invalid choice. Please try again.\n";
        }
    }while(choice!=3);
    return 0;
}

