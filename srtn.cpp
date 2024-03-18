#include<bits/stdc++.h>
using namespace std;
#define MAX 20

float average(int *matrix,int n){
	float avg = 0.0;
	for(int i=0;i<n;i++)
		avg += matrix[i];
	return avg/n;
}


void calc(int burst[], int arr[], int n){
	
	int rem_burst[MAX], WT[MAX], TAT[MAX], completion[MAX];
	int totaltime=0, smallest, count=0;
	
	
	for (int i=0; i<n; i++){
		rem_burst[i] = burst[i];
		totaltime += burst[i];
	}
	
	int temp_process_no[totaltime] = {0};			//all elements initialized to 0
	rem_burst[n]=999;
	
	for (int time=1; count!=n; time++){				//iterated until all processes are completed
		smallest=n;
		for (int i=0; i<n; i++){
			if (arr[i]<=time && rem_burst[i]<rem_burst[smallest] && rem_burst[i]>0){
				smallest = i;
			}
		}
		
		rem_burst[smallest]--;
		temp_process_no[time] = smallest;
		
		if (rem_burst[smallest] == 0){					//if rem_burst of process is 0 then count is incremented
			count++;									//loop is terminated when count becomes equal to n
			completion[smallest] = time+1;
			TAT[smallest] = completion[smallest] - arr[smallest];
			WT[smallest] = TAT[smallest] - burst[smallest];
		}
	}
	
	
	//gantt chart
	cout<<"Gantt chart:"<<endl<<endl;
	cout<<"|  ";
	for (int i=1; i<=totaltime; i++){
		cout<<"P"<<temp_process_no[i]+1<<"  |";
	}
	cout<<endl;
	for (int i=1; i<=totaltime; i++){
		cout<<i<<"    ";
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
	int n;
	cout<<"Enter number of processes: ";
	cin>>n;
	int burst[n],arr[n];
	for(int i=0;i<n;i++){
		cout<<"Process "<<i+1<<endl;
		cout<<"Enter Burst Time: ";
		cin>>burst[i];
		cout<<"Enter Arrival Time: ";
		cin>>arr[i];
	}
	cout<<endl;
	calc(burst, arr, n);
	return 0;
}
