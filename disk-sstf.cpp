#include<bits/stdc++.h>
using namespace std;


void sstf(int requests[], int n, int head)
{
	int totalseek=0, current=head, head_index;
	
	sort(requests, requests+n);
	
	//if head btwn 2 and 3 then head_index becomes 3
	for (int i=0; i<n; i++){
		if (requests[i] > head){
			head_index=i;
			break;
		}
	}
		
	int left=head_index-1, right=head_index;
	int k=1;
	
	while (left>=0 && right<n){
		if (abs(current - requests[left]) < abs(current - requests[right])){
			totalseek += abs(current - requests[left]);
			current = requests[left];
			cout<<"Seek "<<k<<": "<<requests[left]<<endl;
			left--;
		}
		else {
			totalseek += abs(current - requests[right]);
			current = requests[right];
			cout<<"Seek "<<k<<": "<<requests[right]<<endl;
			right++;
		}
		k++;
	}
	
	//if there are no more left seeks
	if (left == -1){
		while (right < n){
			totalseek += abs(current - requests[right]);
			current = requests[right];
			cout<<"Seek "<<k<<": "<<requests[right]<<endl;
			right++;
			k++;
		}
	}
	
	//if there are no more right seeks
	if (right == n){
		while (left >= 0){
			totalseek += abs(current - requests[left]);
			current = requests[left];
			cout<<"Seek "<<k<<": "<<requests[left]<<endl;
			left--;
			k++;
		}
	}
	
	
	cout<<endl<<"Total seek time: "<<totalseek;
	

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
	
	sstf(requests, n, head);
	return 0;
	
}