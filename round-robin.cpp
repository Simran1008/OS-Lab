#include<bits/stdc++.h>
using namespace std;
#define MAX 20
#define queue_size 30

int q[30];
int front=-1, rear=-1;

void insert(int item){
	if (front == -1){
		front = 0;
	}
	rear = (rear+1)%queue_size;
	q[rear] = item;
}

int del(){
	int item = q[front];
	if (front == rear){
		front = -1;
		rear = -1;
	}
	else{
		front = (front+1)%queue_size;
	}
	return item;
}


float average(int *matrix,int n){
	float avg = 0.0;
	for(int i=0;i<n;i++)
		avg += matrix[i];
	return avg/n;
}


void calc(int burst[], int arr[], int n, int quantum){
	
	int completion[MAX], WT[MAX], TAT[MAX];
	int rem_burst[MAX], totaltime=0;
	int temp_process[MAX], arrived[n] = {0}, temp_time[MAX];
	int next=-1, tracker, k=0;
	
	for (int i=0; i<n; i++){
		rem_burst[i] = burst[i];
		totaltime += burst[i];
	}
	
	
	for (int time=0; time<totaltime; time++){
		
		for (int i=0; i<n; i++){
			if (arr[i]<=time && arrived[i]==0){
				insert(i);
				arrived[i] = 1;
			}
		}
		
		if (next == -1){
			next = del();
			cout<<next<<endl;
			temp_process[k] = next;
			tracker = 0;
		}
		
		if (tracker!=quantum && rem_burst[next]>0){
			rem_burst[next]--;
			tracker++;
			if (tracker!=quantum && rem_burst[next]>0){
				continue;
			}
		}
		
		temp_time[k++] = time;
		
		if (rem_burst[next] == 0){
			completion[next] = time+1;
			TAT[next] = completion[next] - arr[next];
			WT[next] = TAT[next] - burst[next];
			next = -1;
		}
		
		else{
			insert(next);
			next = -1;
		}
		
	}
	
	
	
	//----------------------------------------------------------------------------------------------------
	
	//gantt chart
	cout<<"Gantt chart:"<<endl<<endl;
	cout<<"|  ";
	for (int i=0; i<totaltime; i++){
		cout<<"P"<<temp_process[i]+1<<"  | ";
	}
	cout<<endl;
	for (int i=0; i<totaltime; i++){
		cout<<temp_time[i]<<"     ";
	}
	cout<<endl<<endl;
	
	
	//display colums
	cout<<endl;
	cout<<"P\tBT\tAT\tWT\tTAT"<<endl;
	for (int i=0; i<n; i++){
		cout<<"P"<<i+1<<"\t"<<burst[i]<<"\t"<<arr[i]<<"\t"<<WT[i]<<"\t"<<TAT[i];
		cout<<endl;
	}
	
	cout<<"AWT = "<<average(WT, n)<<endl;
	cout<<"ATAT = "<<average(TAT, n);
	
	
}

int main(){
	int n, quantum;
	cout<<"Enter number of processes: ";
	cin>>n;
	cout<<"Enter time quantum: ";
	cin>>quantum;
	int burst[n],arr[n];
	for(int i=0;i<n;i++){
		cout<<"Process "<<i+1<<endl;
		cout<<"Enter Burst Time: ";
		cin>>burst[i];
		cout<<"Enter Arrival Time: ";
		cin>>arr[i];
	}
	cout<<endl;
	calc(burst, arr, n, quantum);
	return 0;
}
