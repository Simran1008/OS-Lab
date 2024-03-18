#include<iostream>
#include<cstdlib>
using namespace std;


void fcfs(int requests[], int n, int head){
	int totalseek=0, current=head, seek;
	
	//adding seek time in sequential order
	for (int i=0; i<n; i++){
		cout<<"Seek "<<i+1<<": "<<requests[i];
		cout<<endl;
		seek = abs(current-requests[i]);
		totalseek += seek;
		current = requests[i];
	}
	
	cout<<endl<<endl<<"Total seek time: "<<totalseek;
	
}


int main()
{
	int n, requests[20], head;
	cout<<"Enter no of requests: ";
	cin>>n;
	cout<<"Enter requests sequence: ";
	for (int i=0; i<n; i++){
		cin>>requests[i];
	}
	cout<<"Enter head position: ";
	cin>>head;
	
	fcfs(requests, n, head);
	return 0;
	
}