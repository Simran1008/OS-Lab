#include<iostream>
using namespace std;

#define MAX_PAGES 100
#define MAX_REFERENCES 1000

// Function to check if a page is present in memory
int isPagePresent(int page, int *memory, int numFrames) {
    for (int i = 0; i < numFrames; i++) {
        if (memory[i] == page) {
            return 1; // Page is present in memory
        }
    }
    return 0; // Page is not present in memory
}

// Function to find the index of the page that will not be used for the longest period
int findOptimalPage(int *pages, int *memory, int numFrames, int currentPosition, int numReferences) {
    int index = -1, farthest = currentPosition;

    for (int i = 0; i < numFrames; i++) {
        int j;
        for (j = currentPosition; j < numReferences; j++) {
            if (memory[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }

        // If the page is not referenced in the future, return its index
        if (j == numReferences) {
            return i;
        }
    }

    return (index == -1) ? 0 : index;
}

// Optimal Page Replacement Algorithm
void optimalPageReplacement(int *pages, int numReferences, int numFrames) {
    int memory[MAX_PAGES];
    int pageFaults = 0;

    for (int i = 0; i < numFrames; i++) {
        memory[i] = -1; // Initialize memory frames to -1 (indicating empty)
    }

    for (int i = 0; i < numReferences; i++) {
        if (!isPagePresent(pages[i], memory, numFrames)) {
            int pageToReplace = findOptimalPage(pages, memory, numFrames, i + 1, numReferences);
            memory[pageToReplace] = pages[i];
            pageFaults++;
        }

        cout<<"Page "<<pages[i]<<" -> Memory: ";
        for (int j = 0; j < numFrames; j++) {
            cout<<memory[j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Total Page Faults: "<<pageFaults<<endl;
}

int main() {
    int pages[MAX_REFERENCES];
    int numFrames, numReferences;


    cout<<"Enter number of frames: ";
    cin>>numFrames;

    cout<<"Enter number of pages: ";
    cin>>numReferences;
    

    cout<<"Enter sequence of pages: ";
    for (int i=0; i<numReferences; i++)
        cin>>pages[i];

    optimalPageReplacement(pages, numReferences, numFrames);

    return 0;
}
