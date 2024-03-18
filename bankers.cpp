#include<iostream>
using namespace std;
#define MAX 10

int allocation[MAX][MAX];
int maximum[MAX][MAX];
int need[MAX][MAX];
int available[MAX];
int request[MAX];
int n, m;
int flag;
int safe[MAX];


void display(int matrix[MAX][MAX]){
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cout<<matrix[i][j]<<"  ";
			if (j==m-1)
				cout<<endl;
		}
	}
	cout<<endl;
}


//--------------------------------------------------------------------------

void safety()
{
	int k=0, work[MAX], num=0;
	bool finish[MAX];
	
	for (int i=0; i<n; i++){
		safe[i] = -1;
		finish[i] = false;
	}
	
	for (int i=0; i<m; i++){
		work[i] = available[i];
	}
	
	
	do {
		for (int i=0; i<n; i++){
			if (finish[i] ==  false){
				int j;
				for (j=0; j<m; j++){
					if (need[i][j] > work[j]){
						break;
					}
				}
				
				if (j==m){						//checked that need for all resources is less than available
					finish[i]=true;
					safe[k++]=i;
					for (int t=0; t<m; t++){
						work[t] += allocation[i][t];
					}
				}
			}
			
		}
		
		flag=0;
		for (int i=0; i<n; i++){
			if (finish[i] == false){
				flag=1;						//if any process is not finished then loop will continue
				break;
			}
		}
		
		if (flag==0){			//all processes are finished
			break;
		}
		
		num++;
	
	} while(num<n);
	
	if (flag == 0){
		cout<<"safe sequence exists: ";
		for (int i=0; i<n; i++){
			cout<<"P"<<safe[i]<<"  ";
		}
	}
	
	else {
		cout<<"no safe sequence";
	}

}


//-------------------------------------------------------------------------------

bool check_request(int p)
{
	for (int i=0; i<m; i++){
		if (request[i]>need[p][i] || request[i]>available[i]){			//check if request is less than need and available
			cout<<"Invalid request. Denied";
			return false;
		}
	}
	
	for (int i=0; i<m; i++){				//allocate resources by changing the matrices
		available[i] -= request[i];
		need[p][i] -= request[i];
		allocation[p][i] += request[i];
	}
	
	safety();						//run safety algo
	
	if (flag == 1){		
		cout<<"Request cannot be granted";			//if not granted change matrices to original state
		for (int i=0; i<m; i++){
			available[i] += request[i];
			need[p][i] += request[i];
			allocation[p][i] -= request[i];
		}
		return false;
	}
	
	else {
		cout<<"Request granted";
		return true;
	}
}



//-----------------------------------------------------------------------------


int main()
{
	cout<<"Enter no of processes: ";
	cin>>n;
	cout<<"Enter no of resources: ";
	cin>>m;
	
	cout<<"Enter Allocation matrix:\n";
	for (int i=0; i<n; i++){
		cout<<"P"<<i<<": ";
		for (int j=0; j<m; j++){
			cin>>allocation[i][j];
		}
	}
	cout<<endl;
	
	cout<<"Enter Max matrix:\n";
	for (int i=0; i<n; i++){
		cout<<"P"<<i<<": ";
		for (int j=0; j<m; j++){
			cin>>maximum[i][j];
		}
	}
	cout<<endl;
	
	cout<<"Enter available vector:\n";
	for (int i=0; i<m; i++){
		cin>>available[i];
	}
	
	//compute need matrix
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			need[i][j] = maximum[i][j] - allocation[i][j];
		}
	}
	
	cout<<"Allocation Matrix:\n";
	display(allocation);
	cout<<"Max Matrix:\n";
	display(maximum);
	cout<<"Need Matrix:\n";
	display(need);
	
	
	//check for safe sequence
	safety();
	
	
	//ask for request
	cout<<endl<<endl;
	int p;
	cout<<"Enter process no for request: ";
	cin>>p;
	cout<<"Enter request: ";
	for (int i=0; i<m; i++){
		cin>>request[i];
	}
	
	if (check_request(p)){
		cout<<endl<<"yes";
	}
	else {
		cout<<endl<<"no";
	}
	
	
	return 0;
	
	
}