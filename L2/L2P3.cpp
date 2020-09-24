#include <bits/stdc++.h>

using namespace std;

int size;
int max_size=3;

typedef union Data{
	char c;
	int i;
	float f;
}	data;

typedef struct datanode{
	char type;
	data d;
	struct datanode* prev;
}	Stack;

bool Empty(Stack* top){
	if(top==NULL)	return true;
	return false;
}

bool Full(){
	if(size==max_size)	return true;
	return false;
}

Stack* Push(Stack* top){
	if(Full()){
		cout<<"Stack is full select another operation\n";
			cout<<"Enter Your Choice"<<endl;

	cout<<"I for Insert"<<endl;

	cout<<"D for Delete"<<endl;

	cout<<"E for Exit"<<endl;

	cout<<"P for Print"<<endl;
		return top;

	}
	cout<<"Enter I for Integer C for char and F for float\n";
	Stack t;
	cin>>t.type;
					//Enter the type of data element I for integer, C for char, F for float
	switch(t.type){
		case 'I':
		cout<<"Enter the Integer value \n";
		cin>>t.d.i;	
	cout<<"value inserted"<<endl;			//Enter an Integer value
		break;

		case 'F':
		cout<<"Enter the float value \n";
		cin>>t.d.f;
		cout<<"value inserted"<<endl;			//Enter an float value
		break;

		case 'C':
		cout<<"Enter the Char value \n";
		cin>>t.d.c;	
		cout<<"value inserted"<<endl;			//Enter an charecter
	
		break;

		default:cout<<"Provide valid input\n";
		break;
	}	 
	t.prev=top;
	Stack* temp;
	temp=(Stack*)calloc(1,sizeof(Stack));
	*temp=t;
	size++;
	cout<<"Enter Your Choice"<<endl;

	cout<<"I for Insert"<<endl;

	cout<<"D for Delete"<<endl;

	cout<<"E for Exit"<<endl;

	cout<<"P for Print"<<endl;
	return temp;
}

Stack* Pop(Stack* top){
	if(Empty(top)){
		cout<<"Stack is empty select other operation\n";
			cout<<"Enter Your Choice"<<endl;

	cout<<"I for Insert"<<endl;

	cout<<"D for Delete"<<endl;

	cout<<"E for Exit"<<endl;

	cout<<"P for Print"<<endl;
	}
	else{
		cout<<"The popped element is : ";
		switch(top->type){
			case'I':
			cout<<top->d.i;
			break;

			case 'F':
			cout<<top->d.f;
			break;

			case 'C':
			cout<<top->d.c;
			break;

			default: 
			break;
		}
		cout<<"\n";
		top=top->prev;
		size--;
	}
	return top;
}

void Print(Stack* top){
	cout<<"The Current status of stack is : \n";
	if(Empty(top)){
		cout<<"empty\n";
		cout<<"Enter Your Choice"<<endl;

	cout<<"I for Insert"<<endl;

	cout<<"D for Delete"<<endl;

	cout<<"E for Exit"<<endl;

	cout<<"P for Print"<<endl;
	
	}
	else{
		Stack* temp=top;
		while(temp!=NULL){
			switch(temp->type){
				case 'I':
				cout<<temp->d.i;
				break;

				case'F':
				cout<<temp->d.f;
				break;

				case 'C':
				cout<<temp->d.c;
				break;

				default:
				break;
			}
			temp=temp->prev;
			cout<<"\n";
		}
	}
}

int main(){
	
	cout<<"Enter Your Choice"<<endl;

	cout<<"I for Insert"<<endl;

	cout<<"D for Delete"<<endl;

	cout<<"E for Exit"<<endl;

	cout<<"P for Print"<<endl;
	char choice;
	cin>>choice;				//Enter choice I for insert, D for delete, P for print, E for exit
	size=0;
	Stack* top=NULL;
	while(choice!='E'){
		switch(choice){

			case'I':
			top=Push(top);
			break;

			case'D':
			top=Pop(top);
			break;

			case 'P':
			Print(top);
			break;

			default:cout<<"Provide a valid Intput";
			break;
		}
		cin>>choice;			//Enter choice I for insert, D for delete, P for print, E for exit
	}
	cout<<"The program is stopped\n";
}