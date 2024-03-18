#include<bits/stdc++.h>
using namespace std;


void look(int requests[], int n, int head, int dir, int len){
	int totalseek=0, current=head, head_index;
	
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
		
		while (right < n){
			totalseek += abs(current - requests[right]);
			current = requests[right];
			cout<<"Seek "<<k<<": "<<requests[right]<<endl;
			right++;
			k++;
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
		
		while (left >= 0){
			totalseek += abs(current - requests[left]);
			current = requests[left];
			cout<<"Seek "<<k<<": "<<requests[left]<<endl;
			left--;
			k++;
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
	
	look(requests, n, head, dir, len);
	return 0;
	
}