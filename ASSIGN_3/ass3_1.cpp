#include<iostream>
using namespace std;

int n=5,top;
int stack[5];
void push(){
    if(top==n-1){
        cout<<"Stack is full."<<endl;
        return;
    }
    top++;
    cout<<"Enter element: ";
    cin>>stack[top];
}

void pop(){
    if(top==-1){
        cout<<"Stack is empty."<<endl;
        return;
    }
    cout<<stack[top]<<" poped out."<<endl;
    top--;
}
    
void display(){
    if(top==-1){
        cout<<"Stack is empty."<<endl;
        return;
    }
    for(int i=0;i<=top;i++){
        cout<<stack[i]<<endl;
    }
}

int main(){
    top=-1; 
    cout<<"Enter stack: "<<endl;
    for(int i=0;i<5;i++){
        cin>>stack[i];
        top++;
    }
    int c;
    for(int i=1;i!=0;){
    cout<<"choose: \n1 Push\n2 Pop\n3 Display\n";
    cin>>c;
    switch(c){
    case 1:
    push();
    break;
    case 2:
    pop();
    break;
    case 3:
    display();
    break;
    default:
    cout<<"invalid input"<<endl;
    break;
    }
    cout<<endl;
    cout<<"to exit press 0 else 1 : ";
    cin>>i;
    cout<<endl;
    }
    return 0;
}
