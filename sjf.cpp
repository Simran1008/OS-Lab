#include<iostream>
#include<iomanip>
using namespace std;

float average(int *matrix,int n){
	float avg = 0.0;
	for(int i=0;i<n;i++)
		avg += matrix[i];
	return avg/n;
}


void calc(int burst[], int arr[],int n){
	
	//calculation
	int seq[20], k=0, current_time=0, totaltime=0, min;
	bool complete[20];
	
	for (int i=0; i<n; i++){
		totaltime += burst[i];
		complete[i] = false;
	}
	
	do {
		int min_time=999;
		for (int j=0; j<n; j++){
			if (burst[j]<min_time && complete[j]==false){
				if (arr[j]<=current_time){
					min_time=burst[j];
					min=j;
				}
			}
		}
		complete[min]=true;
		seq[k]=min;
		k++;
		current_time += burst[min];
	} while (totaltime>current_time);
	
	
	for (int i=0; i<n; i++){
		cout<<seq[i]+1<<" ";
	}
	
	
		
		
	//gantt chart
	int time=0;
	int WT[200], TAT[20];
	
	cout<<"Gantt chart:"<<endl<<endl;
	cout<<"|   ";
	for (int i=0; i<n; i++)
		cout<<"P"<<seq[i]+1<<"   |   ";
	cout<<endl;
	cout<<arr[seq[0]];
	for (int i=0; i<n; i++){
		WT[seq[i]] = time - arr[seq[i]];
		TAT[seq[i]] = burst[seq[i]] + WT[seq[i]];
		time += burst[seq[i]];
		
		cout<<"    "<<time<<"    ";
	}
	
	
	//display columns and average
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
	calc(burst,arr,n);
	return 0;
}
