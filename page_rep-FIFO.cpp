#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;


void display(queue<int> temp)
{
	while (!temp.empty()){
		cout<<temp.front()<<" ";
		temp.pop();
	}
	cout<<endl;
}


void fifo(int pages[], int n, int m)
{
	int faults=0, oldestPage;
	queue<int> pageQueue;
	unordered_set<int> pageSet;
	
	for (int i=0; i<n; i++){
		if (pageSet.size() < m){										//for first m inputs 
			if (pageSet.find(pages[i]) == pageSet.end()){						//if not found
				pageSet.insert(pages[i]);
				pageQueue.push(pages[i]);
				cout<<"Page added (page faults): "<<pages[i]<<endl;
				display(pageQueue);
				cout<<endl;
				faults++;
			}
			else {																//if found
				cout<<"Page already in memory: "<<pages[i]<<endl;
				display(pageQueue);
				cout<<endl;
			}
		}
		
		else{															//for remaining n-m inputs
			if (pageSet.find(pages[i]) == pageSet.end()){						//if not found
				oldestPage = pageQueue.front();
				pageQueue.pop();
				pageSet.erase(oldestPage);
				pageSet.insert(pages[i]);
				pageQueue.push(pages[i]);
				cout<<"Page added (page fault): "<<pages[i]<<endl;
				display(pageQueue);
				cout<<endl;
				faults++;
			}
			else {																//if found
				cout<<"Page already in memory: "<<pages[i]<<endl;
				display(pageQueue);
				cout<<endl;
			}
		}
	}
	
	cout<<endl<<"No of page faults: "<<faults;
}





int main()
{
	int n, m, pages[20];
	cout<<"Enter no of pages: ";
	cin>>n;
	cout<<"Enter no of frames: ";
	cin>>m;
	cout<<"Enter page string: ";
	for (int i=0; i<n; i++){
		cin>>pages[i];
	}
		
		
	fifo(pages, n, m);
	
	return 0;
}