#include<iostream>
using namespace std;
#define MAX 20

int pages[MAX], frames[MAX];
int n, m;
int flag1, flag2;
int faults = 0;


int optimal (int n, int m, int current){
	
	int flag, k=0, temp[MAX];
	
	for (int j=0; j<m; j++){							//for checking next occurence of a page in page sequence
		flag = 0;
		for (int i=current+1; i<n; i++){
			if (frames[j] == pages[i]){							//next immediate occurence is found
				temp[k++] = i;									//occurence index assigned to temp
				flag = 1;
				break;											//since next occurence is found, terminate loop for that page 
			}											
		}
		
		if (flag == 0){										//if that page has no next occurence in sequence then return the current frame index
			return j;
		}
	}
	
	
	int max = temp[0], pos;								//if all pages in the frames have next occurences, find the farthest (maximum index) to replace
	for (int j=0; j<m; j++){
		if (temp[j] > max){
			max = temp[j];
			pos = j;
		}
	}
	
	return pos;
	
}



int main()
{
	cout<<"Enter no of pages: ";
	cin>>n;
	cout<<"Enter number of frames: ";
	cin>>m;
	cout<<"Enter page sequence: ";
	for (int i=0; i<n; i++){
		cin>>pages[i];
	}
	
	for (int i=0; i<m; i++){			//initialize all frames to -1
		frames[i] = -1;
	}
	
	for (int i=0; i<n; i++){			//iterate over all pages
		
		flag1 = 0;
		flag2 = 0;
		
		for (int j=0; j<m; j++){							//to check if page in memory
			if (frames[j] == pages[i]){
				cout<<"Page already in memory"<<endl;
				flag1 = 1;
				flag2 = 1;
				break;
			}
		}
		
		if (flag1 == 0){									//page is not in memory => checking for empty frame
			for (int j=0; j<m; j++){
				if (frames[j] == -1){
					frames[j] = pages[i];
					faults++;
					cout<<"Page added"<<endl;
					flag2 = 1;
					break;
				}
			}
		}
		
		if (flag2 == 0){									//page not in mempry && no empty frame => finding frame to replace
			int pos = optimal(n, m, i);
			frames[pos] = pages[i];
			cout<<"Page added"<<endl;
			faults++;
		}
		
		for (int j=0; j<m; j++){
			cout<<frames[j]<<" ";
		}
		
		cout<<endl<<endl;
		
	}
	
	cout<<endl<<faults;
	
	return 0;
}