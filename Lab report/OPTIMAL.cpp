#include <iostream>
using namespace std;

// Function to find the optimal page to replace
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
        // If the page is not found in the future, we should replace this page
        if (!found) {
            return i;
        }
    }
    // If all pages in frames are found in the future, return the one found farthest
    return pageToReplace == -1 ? 0 : pageToReplace;
}

void optimalPageReplacement(int pages[], int pageCount, int frameCount) {
    int *frame = new int[frameCount];
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

        // Check if the current page is already in the frames
        for (int j = 0; j < frameCount; j++) {
            if (frame[j] == pages[i]) {
                pageFound = true;
                break;
            }
        }

        bool pageFaultOccurred = false;
        if (!pageFound) {
            // If page is not found, we need to replace a page
            int pageToReplace = -1;
            for (int j = 0; j < frameCount; j++) {
                if (frame[j] == -1) { // If there's an empty frame
                    pageToReplace = j;
                    break;
                }
            }
            if (pageToReplace == -1) { // No empty frame, use optimal replacement
                pageToReplace = findOptimalPage(pages, frame, pageCount, frameCount, i + 1);
            }
            frame[pageToReplace] = pages[i];
            pageFaults++;
            pageFaultOccurred = true;
        }

        // Display current frame state
        cout << pages[i] << "\t\t";
        for (int k = 0; k < frameCount; k++) {
            if (frame[k] == -1) {
                cout << "E\t"; // 'E' for empty frame slot
            } else {
                cout << frame[k] << "\t";
            }
        }
        cout << (pageFaultOccurred ? "\tYes" : "\tNo") << endl;
    }
    
    cout << "\nTotal Page Faults: " << pageFaults << endl;

    delete[] frame;
}

int main() {
    int pageCount, frameCount;

    // Input number of pages
    cout << "Enter the number of pages: ";
    cin >> pageCount;

    int *pages = new int[pageCount];
    
    // Input page reference string
    cout << "Enter the page reference string:\n";
    for (int i = 0; i < pageCount; i++) {
        cin >> pages[i];
    }

    // Input number of frames
    cout << "Enter the number of frames: ";
    cin >> frameCount;

    // Call the Optimal Page Replacement function
    optimalPageReplacement(pages, pageCount, frameCount);

    delete[] pages;
    return 0;
}
