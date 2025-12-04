#include<iostream>
#include<string>
using namespace std;
int main(){
	string n;
	int r=0;
	int l=0;
	
	cout<<"Enter expression: ";
	getline(cin,n);
	for(int i=0;i<n.length();i++){
		if(n[i]=='('){
			r++;
		}
		if(n[i]==')'){
			l++;
		}
			
	}
	if(r==l){
		cout<<"All parenthesis are closed!";
	}
	else{
		cout<<"All parenthesis aren't closed!";
	}
}
