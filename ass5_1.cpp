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
    void insertAtBeginning(int data){
        Node*newNode=new Node;
        newNode->data=data;
        newNode->next=head;
        head=newNode;
    }

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

    void insertAfter(int target,int data){
        Node*temp=head;
        while(temp!=nullptr&&temp->data!=target){
            temp=temp->next;
        }
        if(temp==nullptr){
            cout<<"Node with value "<<target<<" not found."<<endl;
            return;
        }
        Node*newNode=new Node;
        newNode->data=data;
        newNode->next=temp->next;
        temp->next=newNode;
    }

    void insertBefore(int target,int data){
        if(head==nullptr){
            cout<<"List is empty, cannot insert before."<<endl;
            return;
        }
        if(head->data==target){
            insertAtBeginning(data);
            return;
        }
        Node*temp=head;
        while(temp->next!=nullptr&&temp->next->data!=target){
            temp=temp->next;
        }
        if(temp->next==nullptr){
            cout<<"Node with value "<<target<<" not found."<<endl;
            return;
        }
        Node*newNode=new Node;
        newNode->data=data;
        newNode->next=temp->next;
        temp->next=newNode;
    }

    void deleteFromBeginning(){
        if(head==nullptr){
            cout<<"List is empty, nothing to delete."<<endl;
            return;
        }
        Node*temp=head;
        head=head->next;
        delete temp;
    }

    void deleteFromEnd(){
        if(head==nullptr){
            cout<<"List is empty, nothing to delete."<<endl;
            return;
        }
        if(head->next==nullptr){
            delete head;
            head=nullptr;
            return;
        }
        Node*temp=head;
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=nullptr;
    }

    void deleteNode(int data){
        if(head==nullptr){
            cout<<"List is empty, nothing to delete."<<endl;
            return;
        }
        if(head->data==data){
            deleteFromBeginning();
            return;
        }
        Node*temp=head;
        while(temp->next!=nullptr&&temp->next->data!=data){
            temp=temp->next;
        }
        if(temp->next==nullptr){
            cout<<"Node with value "<<data<<" not found."<<endl;
            return;
        }
        Node*toDelete=temp->next;
        temp->next=toDelete->next;
        delete toDelete;
    }

    void searchNode(int data){
        int position=1;
        Node*temp=head;
        while(temp!=nullptr&&temp->data!=data){
            temp=temp->next;
            position++;
        }
        if(temp==nullptr){
            cout<<"Node with value "<<data<<" not found."<<endl;
        }else{
            cout<<"Node with value "<<data<<" found at position "<<position<<"."<<endl;
        }
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
};

int main(){
    LinkedList list;
    int choice,value,target;
    do{
        cout<<"\nMenu:\n";
        cout<<"1. Insert at the beginning\n";
        cout<<"2. Insert at the end\n";
        cout<<"3. Insert after a specific node\n";
        cout<<"4. Insert before a specific node\n";
        cout<<"5. Delete from the beginning\n";
        cout<<"6. Delete from the end\n";
        cout<<"7. Delete a specific node\n";
        cout<<"8. Search for a node\n";
        cout<<"9. Display list\n";
        cout<<"10. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to insert: ";
                cin>>value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout<<"Enter value to insert: ";
                cin>>value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout<<"Enter target node value: ";
                cin>>target;
                cout<<"Enter value to insert: ";
                cin>>value;
                list.insertAfter(target,value);
                break;
            case 4:
                cout<<"Enter target node value: ";
                cin>>target;
                cout<<"Enter value to insert: ";
                cin>>value;
                list.insertBefore(target,value);
                break;
            case 5:
                list.deleteFromBeginning();
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                cout<<"Enter value of node to delete: ";
                cin>>value;
                list.deleteNode(value);
                break;
            case 8:
                cout<<"Enter value of node to search for: ";
                cin>>value;
                list.searchNode(value);
                break;
            case 9:
                list.display();
                break;
            case 10:
                cout<<"Exiting program.\n";
                break;
            default:
                cout<<"Invalid choice.\n";
        }
    }while(choice!=10);
    return 0;
}
