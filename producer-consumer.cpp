#include<iostream>
using namespace std;
#define MAX 20

int buffer_size, mutex=1, empty, full=0;
int in=0, out=0, counter=0;
int buffer[MAX];

void wait (int &S)
{
	if (S<=0){
		//cout<<"Cannot add/remove item"<<endl;
		return;
	}
	S--;
}

void signal (int &S)
{
	S++;
}

void produce()
{
	wait(empty);
	wait(mutex);
	
	if (counter == buffer_size){
		cout<<"Storage full"<<endl;
	}
	
	else {
		int next_produced;
		cout<<"Enter item to produce: ";
		cin>>next_produced;
		buffer[in] = next_produced;
		cout<<"Item added: "<<next_produced<<endl;
		in = (in+1)%buffer_size;
		counter++;
		signal(mutex);
		signal(full);
	}
}

void consume()
{
	wait(full);
	wait(mutex);
	
	if (counter == 0){
		cout<<"Storage empty"<<endl;
	}
	
	else {
		int next_consumed;
		next_consumed = buffer[out];
		cout<<"Item consumed: "<<next_consumed<<endl;
		out = (out+1)%buffer_size;
		counter--;
		signal(mutex);
		signal(empty);
	}
}



int main()
{
	cout<<"Enter size of buffer: ";
	cin>>buffer_size;
	empty = buffer_size;
	
	
	
	do {
		
		int ch;
		cout<<"\nSelection operation to be performed:\n1. Produce\n2. Consume\n3. Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		cout<<endl;
		
		switch(ch) {
			case 1:
				produce();
				break;
				
			case 2:
				consume();
				break;
				
			case 3:
				exit(1);
				
			deafult:
				cout<<"Enter valid choice";
				break;
		}
		
	} while(true);
	
	return 0;
	
}

