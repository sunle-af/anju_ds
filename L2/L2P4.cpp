#include <bits/stdc++.h>

using namespace std;

int size;
int max_size=20;

typedef union Data{
	int i;
	float f;
	char c;
} data;

typedef struct datanode{
	char type;
	data d;
	struct datanode* next;
} Queue;

bool Overflow(){
	if(size==max_size)	return true;
	return false;
}

bool Underflow(Queue* front, Queue* rear){
	if(front==NULL&&rear==NULL)	return true;
	return false;
}

void Insert(Queue*& front, Queue*& rear){
	if(Overflow()){
		cout<<"Queue is full select another operation\n";
		return;
	}
	size++;
	Queue t;
	cin>>t.type;				//Enter I for integer, F for Float, C for char
	switch(t.type){
		case 'I':
		cin>>t.d.i;				//Enter an integer value
		break;

		case 'F':
		cin>>t.d.f;				//Enter a float value
		break;

		case 'C':
		cin>>t.d.c;				//Enter a char value
		break;

		default:
		break;
	}
	t.next=front;

	Queue* temp;
	temp=(Queue*)calloc(1,sizeof(Queue));
	*temp=t;

	if(front==NULL&&rear==NULL){
		front=temp;
		front->next=temp;
		rear=temp;
	}
	else{
		rear->next=temp;
		rear=temp;
	}	
}

void Delete(Queue*& front, Queue*& rear){
	if(Underflow(front,rear)){
		cout<<"Queue is empty select another operation\n";
		return;
	}
	cout<<"The deleted element is : ";
	switch(front->type){
		case 'I':
		cout<<front->d.i;
		break;

		case'F':
		cout<<front->d.f;
		break;

		case 'C':
		cout<<front->d.c;
		break;

		default:
		break;
	}
	size--;
	cout<<endl;
	if(front==rear){
		front=rear=NULL;
	}
	else{
		rear->next=front->next;
		front=front->next;
	}
}

void Print(Queue* front, Queue* rear){
	Queue* temp=front;
	if(Underflow(front,rear)){
		cout<<"The current status of queue is : empty\n";
		return;
	}
	cout<<"The current status of queue is : ";
	while(temp!=rear){
		switch(temp->type){
			case 'I':
			cout<<temp->d.i<<endl;
			break;

			case'F':
			cout<<temp->d.f<<endl;
			break;

			case 'C':
			cout<<temp->d.c<<endl;
			break;

			default:
			break;
		}
		temp=temp->next;
	}
	switch(temp->type){
		case 'I':
		cout<<temp->d.i<<endl;
		break;

		case'F':
		cout<<temp->d.f<<endl;
		break;

		case 'C':
		cout<<temp->d.c<<endl;
		break;

		default:
		break;
	}
}

int main(){
	char choice;
	Queue* front=NULL;
	Queue* rear=NULL;
	size=0;

	cin>>choice;				//Enter your choice I for insert, D for delete, P for print, E for exit
	while(choice!='E'){
		switch(choice){
			case 'I':
			Insert(front,rear);
			break;

			case 'D':
			Delete(front,rear);
			break;

			case 'P':
			Print(front,rear);
			break;

			default:
			break;
		}
		cin>>choice;			//Enter your choice I for insert, D for delete, P for print, E for exit
	}
	cout<<"Program is stopped.";
	return 0;
}