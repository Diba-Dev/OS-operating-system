//Topic: Optimal Page replacement algorithm
#include <bits/stdc++.h>
using namespace std;

int findOptimalPage(int pages[], int frame[], int pageCount, int frameCount, int index) {
    int farthest = index;
    int pageToReplace = -1;
    
    for (int i = 0; i < frameCount; i++) {
        bool found = false;
        for (int j = index; j < pageCount; j++) {
            if (frame[i] == pages[j]) {
                found = true;
                if (j > farthest) {
                    farthest = j;
                    pageToReplace = i;
                }
                break;
            }
        }
        if (!found) {
            return i;
        }
    }
    return pageToReplace == -1 ? 0 : pageToReplace;
}

void optimalPageReplacement(int pages[], int pageCount, int frameCount) {
    int frame[10];  // Fixed-size array for frames
    for (int i = 0; i < frameCount; i++) {
        frame[i] = -1; // Initialize frames with -1 indicating empty
    }

    int pageFaults = 0;
    cout << "\nOptimal Page Replacement Process:\n";
    cout << "-----------------------------------\n";
    cout << "Page Ref\tFrame State\t\tPage Fault\n";
    cout << "-----------------------------------\n";

    for (int i = 0; i < pageCount; i++) {
        bool pageFound = false;

        for (int j = 0; j < frameCount; j++) {
            if (frame[j] == pages[i]) {
                pageFound = true;
                break;
            }
        }

        bool pageFaultOccurred = false;
        if (!pageFound) {
            int pageToReplace = -1;
            for (int j = 0; j < frameCount; j++) {
                if (frame[j] == -1) {
                    pageToReplace = j;
                    break;
                }
            }
            if (pageToReplace == -1) {
                pageToReplace = findOptimalPage(pages, frame, pageCount, frameCount, i + 1);
            }
            frame[pageToReplace] = pages[i];
            pageFaults++;
            pageFaultOccurred = true;
        }

        cout << pages[i] << "\t\t";
        for (int k = 0; k < frameCount; k++) {
            if (frame[k] == -1) {
                cout << "E\t";
            } else {
                cout << frame[k] << "\t";
            }
        }
        cout << (pageFaultOccurred ? "\tYes" : "\tNo") << endl;
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

    optimalPageReplacement(pages, pageCount, frameCount);

    return 0;
}