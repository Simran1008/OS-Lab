#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;


void display(list<int> temp)
{
	while (!temp.empty()){
		cout<<temp.front()<<"  ";
		temp.pop_front();
	}
	cout<<endl;
}

void lru (int pages[], int n, int m)
{
	int faults=0;
	list<int> pageList;
	unordered_map<int, list<int>::iterator> pageMap;
	
	for (int i=0; i<n; i++){
		
		if (pageMap.find(pages[i]) == pageMap.end()){				//if page not found
			if (pageMap.size() == m){										//if size of list is full
				int leastRecentlyUsed = pageList.back();
				pageList.pop_back();
				pageMap.erase(leastRecentlyUsed);
			}
			faults++;														//increment faults
			cout<<"Page added: "<<pages[i]<<endl;
			
		}
		
		else {														//if page found
			cout<<"Page already in memory: "<<pages[i]<<endl;
			pageList.erase(pageMap[pages[i]]);
		}
		
		pageList.push_front(pages[i]);								//push page to front of list
		pageMap[pages[i]] = pageList.begin();						//map the added page to front of list
	}
	
	cout<<endl<<faults;
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
		
		
	lru(pages, n, m);
	
	return 0;
}