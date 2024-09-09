#include <iostream>
using namespace std;

// Function to find the least recently used page
int findLRU(int time[], int frameCount) {
    int minimum = time[0], pos = 0;
    for (int i = 1; i < frameCount; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

void LRUPageReplacement(int pages[], int pageCount, int frameCount) {
    int frame[10];  // Fixed-size array for frames
    int time[10];   // Array to store time for each page in frames (for LRU)
    int pageFaults = 0, counter = 0;

    // Initialize frame and time arrays
    for (int i = 0; i < frameCount; i++) {
        frame[i] = -1;
    }

    cout << "\nLRU Page Replacement Process:\n";
    cout << "-----------------------------------\n";
    cout << "Page Ref\tFrame State\t\tPage Fault\n";
    cout << "-----------------------------------\n";

    for (int i = 0; i < pageCount; i++) {
        bool pageFound = false;
        
        // Check if the current page is already in the frame
        for (int j = 0; j < frameCount; j++) {
            if (frame[j] == pages[i]) {
                pageFound = true;
                time[j] = ++counter; // Update the time for the accessed page
                break;
            }
        }

        if (!pageFound) {
            // If the page is not in the frame, find a spot to replace
            int pageToReplace = -1;

            // Find an empty frame or use LRU to replace
            for (int j = 0; j < frameCount; j++) {
                if (frame[j] == -1) {
                    pageToReplace = j; // Empty spot found
                    break;
                }
            }

            if (pageToReplace == -1) {
                // If no empty spot, replace the least recently used page
                pageToReplace = findLRU(time, frameCount);
            }

            // Replace the page in the frame
            frame[pageToReplace] = pages[i];
            time[pageToReplace] = ++counter;
            pageFaults++;

            // Display the frame state after the page replacement
            cout << pages[i] << "\t\t";
            for (int k = 0; k < frameCount; k++) {
                if (frame[k] == -1) {
                    cout << "E\t"; // Empty frame
                } else {
                    cout << frame[k] << "\t";
                }
            }
            cout << "\tYes\n";  // Page fault occurred
        } else {
            // If the page is already in the frame, no page fault
            cout << pages[i] << "\t\t";
            for (int k = 0; k < frameCount; k++) {
                if (frame[k] == -1) {
                    cout << "E\t";
                } else {
                    cout << frame[k] << "\t";
                }
            }
            cout << "\tNo\n";  // No page fault
        }
    }

    // Output the total number of page faults
    cout << "\nTotal Page Faults: " << pageFaults << endl;
}

int main() {
    int pageCount, frameCount;

    // Input the number of pages
    cout << "Enter the number of pages: ";
    cin >> pageCount;

    int pages[50];  // Fixed-size array for pages (max 50)

    // Input the page reference string
    cout << "Enter the page reference string:\n";
    for (int i = 0; i < pageCount; i++) {
        cin >> pages[i];
    }

    // Input the number of frames
    cout << "Enter the number of frames: ";
    cin >> frameCount;

    // Call the LRU Page Replacement function
    LRUPageReplacement(pages, pageCount, frameCount);

    return 0;
}