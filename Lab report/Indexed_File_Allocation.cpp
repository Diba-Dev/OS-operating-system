//TOPIC : Implementation of Indexed_File_Allocation 
 
#include<bits/stdc++.h>
using namespace std;

void initializeDisk(int disk[], int size) {
    for (int i = 0; i < size; i++) {
        disk[i] = -1; 
    }
}

void indexedFileAllocation(int disk[], int indexBlock[], int numBlocks, int fileSize, int startIndex) {
    if (startIndex + fileSize > numBlocks) {
        cout << "Error: Not enough space to allocate file.\n";
        return;
    }

    for (int i = 0; i < fileSize; i++) {
        indexBlock[i] = startIndex + i;
    }

    for (int i = 0; i < fileSize; i++) {
        disk[startIndex + i] = indexBlock[i];
    }

    cout << "File allocated successfully.\n";
}

void displayDiskAndIndex(int disk[], int indexBlock[], int numBlocks, int fileSize) {
    cout << "Disk state:\n";
    for (int i = 0; i < numBlocks; i++) {
        if (disk[i] == -1) {
            cout << "F\t"; 
        } else {
            cout << disk[i] << "\t";
        }
    }
    cout << "\n\nIndex Block:\n";
    for (int i = 0; i < fileSize; i++) {
        cout << indexBlock[i] << "\t";
    }
    cout << endl;
}

int main() {
    int numBlocks; // Total number of blocks in the disk
    cout << "Enter the total number of blocks in the disk: ";
    cin >> numBlocks;

    int disk[100];       // Disk array with a maximum of 100 blocks
    int indexBlock[100]; // Index block for file allocation

    // Initialize the disk array
    initializeDisk(disk, numBlocks);

    int fileSize; // Number of blocks required for the file
    int startIndex; // Starting index for the file allocation

    cout << "Enter the number of blocks required for the file: ";
    cin >> fileSize;

    cout << "Enter the starting index for file allocation: ";
    cin >> startIndex;

    // Ensure fileSize and startIndex are within valid ranges
    if (startIndex < 0 || startIndex >= numBlocks) {
        cout << "Error: Starting index is out of range.\n";
        return 1;
    }

    indexedFileAllocation(disk, indexBlock, numBlocks, fileSize, startIndex);
    displayDiskAndIndex(disk, indexBlock, numBlocks, fileSize);

    return 0;
}
