#include <iostream>
using namespace std;

int findOptimalPage(int frame[], int sizeofFrame, int referenceA[], int size, int currentIndex) {
    int farthest = -1;
    int pageToReplace = -1;

    for (int i = 0; i < sizeofFrame; i++) {
        bool found = false;
        for (int j = currentIndex + 1; j < size; j++) {
            if (frame[i] == referenceA[j]) {
                if (j > farthest) {
                    farthest = j;
                    pageToReplace = i;
                }
                found = true;
                break;
            }
        }
        if (!found) {
            return i; // If the page is not found in future references, replace it.
        }
    }
    return pageToReplace;
}

int main() {
    int size;
    cout << "Enter the number of pages: ";
    cin >> size;
    int sizeofFrame;
    cout << "Enter the frame size: ";
    cin >> sizeofFrame;
    int referenceA[size];
    int frame[sizeofFrame];
    cout << "Enter the page reference sequence: ";
    for (int i = 0; i < size; i++) {
        cin >> referenceA[i];
    }
    for (int i = 0; i < sizeofFrame; i++) {
        frame[i] = -1;
    }

    int finalArray[size][sizeofFrame];
    int pageFaults = 0;

    for (int i = 0; i < size; i++) {
        bool found = false;
        for (int j = 0; j < sizeofFrame; j++) {
            if (frame[j] == referenceA[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            int replaceIndex = findOptimalPage(frame, sizeofFrame, referenceA, size, i);
            frame[replaceIndex] = referenceA[i];
            pageFaults++;
        }

        // Store the current frame state into finalArray
        for (int j = 0; j < sizeofFrame; j++) {
            finalArray[i][j] = frame[j];
        }
    }

    cout << "Page Reference Sequence: ";
    for (int i = 0; i < size; i++) {
        cout << referenceA[i] << "\t";
    }
    cout << endl;

    cout << "Frames State:\n";
    for (int j = 0; j < sizeofFrame; j++) {
        cout << "\t";
        for (int i = 0; i < size; i++) {
            if (finalArray[i][j] != -1) {
                cout << finalArray[i][j] << "\t";
            } else {
                cout << "-\t";
            }
        }
        cout << endl;
    }

    cout << "Total page faults: " << pageFaults << endl;
    return 0;
}
