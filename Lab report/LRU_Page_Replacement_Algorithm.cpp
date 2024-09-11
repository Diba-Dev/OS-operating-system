//TOPIC : LRU Page replacement algorithm. 
 
#include<bits/stdc++.h>
using namespace std;

int findLRUPage(int frame[], int lastUsed[], int frameCount) {
    int lruIndex = 0;
    for (int i = 1; i < frameCount; i++) {
        if (lastUsed[i] < lastUsed[lruIndex]) {
            lruIndex = i;
        }
    }
    return lruIndex;
}

void lruPageReplacement(int pages[], int pageCount, int frameCount) {
    int frame[10];         
    int lastUsed[10];       
    int time = 0;           
    int pageFaults = 0;     

    for (int i = 0; i < frameCount; i++) {
        frame[i] = -1;       
        lastUsed[i] = -1;    
    }

    cout << "\nLRU Page Replacement Process:\n";
    cout << "-----------------------------------\n";
    cout << "Page Ref\tFrame State\t\tPage Fault\n";
    cout << "-----------------------------------\n";

    for (int i = 0; i < pageCount; i++) {
        bool pageFound = false;

        for (int j = 0; j < frameCount; j++) {
            if (frame[j] == pages[i]) {
                pageFound = true;
                lastUsed[j] = time;  // Update the time of last use for this page
                break;
            }
        }

        bool pageFaultOccurred = false; 
        if (!pageFound) {
            // Page fault occurs, we need to replace a page
            int pageToReplace = -1;

            // Check for an empty frame first
            for (int j = 0; j < frameCount; j++) {
                if (frame[j] == -1) {
                    pageToReplace = j;
                    break;
                }
            }

            // If no empty frame, find the LRU page
            if (pageToReplace == -1) {
                pageToReplace = findLRUPage(frame, lastUsed, frameCount);
            }

            // Replace the page
            frame[pageToReplace] = pages[i];
            lastUsed[pageToReplace] = time;  // Update the time of use
            pageFaults++;
            pageFaultOccurred = true;
        }

        // Print the current frame state and whether a page fault occurred
        cout << pages[i] << "\t\t";
        for (int k = 0; k < frameCount; k++) {
            if (frame[k] == -1) {
                cout << "E\t";  // Empty slot
            } else {
                cout << frame[k] << "\t";
            }
        }
        cout << (pageFaultOccurred ? "\tYes" : "\tNo") << endl;

        time++;  // Increment time after each page request
    }

    cout << "\nTotal Page Faults: " << pageFaults << endl;
}

int main() {
    int pageCount, frameCount;

    cout << "Enter the number of pages: ";
    cin >> pageCount;

    int pages[50];  // Fixed-size array for page references
    
    cout << "Enter the page reference string:\n";
    for (int i = 0; i < pageCount; i++) {
        cin >> pages[i];
    }

    cout << "Enter the number of frames: ";
    cin >> frameCount;

    lruPageReplacement(pages, pageCount, frameCount);

    return 0;
}
