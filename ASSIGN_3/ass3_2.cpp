#include<iostream>
using namespace std;

int n,top1,top2;
char stack1[100],stack2[100];
void push(char arr[],int* top){
    if(*top==n-1){
        cout<<"Stack is full."<<endl;
        return;
    }
    *top=*top+1;
    cin>>arr[*top];
}

void push(char arr[],int* top,char cp){
    if(*top==n-1){
        cout<<"Stack is full."<<endl;
        return;
    }
    *top=*top+1;
    cout<<cp<<" pushed in."<<endl;
    arr[*top]=cp;
}

void pop(char arr[],int* top){
    if(*top==-1){
        cout<<"Stack is empty."<<endl;
        return;
    }
    cout<<arr[*top]<<" poped out."<<endl;
    *top=*top-1;
}
    
void display(char arr[],int *top){
    if(*top==-1){
        cout<<"Stack is empty."<<endl;
        return;
    }
    cout<<arr<<endl;
    
}

int main(){
    top1=-1;
    top2=-1; 
    cout<<"Enter stack: ";
    cin.getline(stack1, 100); 
    cout<<"You entered: "<<stack1<<endl;
    for(n=0;stack1[n]!='\0';n++){top1++;}
    for(;top1>-1;){
        push(stack2,&top2,stack1[top1]);
        pop(stack1,&top1);
    }
    display(stack2,&top2);
    return 0;
}
