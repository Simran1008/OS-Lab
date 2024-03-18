#include<bits/stdc++.h>
using namespace std;


void cscan(int requests[], int n, int head, int dir, int len){
	int totalseek=0, current=head, head_index;
	int end=n-1, begin=0;				//to count backward while changing direction
	
	sort(requests, requests+n);
	
	for (int i=0; i<n; i++){
		if (requests[i] > head){
			head_index=i;
			break;
		}
	}
	
	int left=head_index-1, right=head_index;
	int k=1;
	
	//moves towards left
	if (dir == -1){
		while (left >= 0){
			totalseek += abs(current - requests[left]);
			current = requests[left];
			cout<<"Seek "<<k<<": "<<requests[left]<<endl;
			left--;
			k++;
		}
		
		totalseek += current;						//to include 0
		cout<<"Seek "<<k++<<": 0"<<endl;
		
		totalseek += len-1;							//to go from 0-199
		cout<<"Seek "<<k++<<": "<<len-1<<endl;
		
		current = len-1;
		while (end > right){									//backward iterate until you reach 'right'
			totalseek += abs(current - requests[end]);
			current = requests[end];
			cout<<"Seek "<<k++<<": "<<current<<endl;
			end--;
		}
	
	}
	
	
	//moves towards right
	if (dir == 1){
		while (right < n){
			totalseek += abs(current - requests[right]);
			current = requests[right];
			cout<<"Seek "<<k<<": "<<requests[right]<<endl;
			right++;
			k++;
		}
		
		totalseek += abs(current-len-1);				//to include 199
		cout<<"Seek "<<k++<<": "<<len-1<<endl;
		
		totalseek += len-1;								// to go from 199-0
		cout<<"Seek "<<k++<<": 0"<<endl;
		
		current=0;
		while (begin <= left){								//forward iterate until you reach 'left'
			totalseek += abs(current - requests[begin]);
			current = requests[begin];
			cout<<"Seek "<<k++<<": "<<current<<endl;
			begin++;
		}
											
	}
	
	cout<<endl<<totalseek;
	
}


int main()
{
	int n, requests[20], head, dir, len;
	cout<<"Enter no of requests: ";
	cin>>n;
	cout<<"Enter requests sequence: ";
	for (int i=0; i<n; i++){
		cin>>requests[i];
	}
	cout<<"Enter head position: ";
	cin>>head;
	
	cout<<"Enter length: ";
	cin>>len;
	
	cout<<"Enter direction in which you want to move (-1 for left, 1 for right): ";
	cin>>dir;
	
	cscan(requests, n, head, dir, len);
	return 0;
	
}