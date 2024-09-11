//TOPIC : Implementation of Linked_File_Allocation
 
#include<bits/stdc++.h>
using namespace std;

struct Block {
    int data;
    int next;
};

int main() {
    const int TOTAL_BLOCKS = 100;   
    Block disk[TOTAL_BLOCKS];       
    bool allocated[TOTAL_BLOCKS] = {false}; 

    int fileCount, startBlock, numBlocks;

    for (int i = 0; i < TOTAL_BLOCKS; i++) {
        disk[i].next = -1;
    }

    cout << "Enter the number of files to allocate: ";
    cin >> fileCount;

    for (int i = 0; i < fileCount; i++) {
        cout << "\nEnter the starting block of file " << i + 1 << ": ";
        cin >> startBlock;

        if (allocated[startBlock]) {
            cout << "Block " << startBlock << " is already allocated. Try again.\n";
            i--;
            continue;
        }

        cout << "Enter the number of blocks for file " << i + 1 << ": ";
        cin >> numBlocks;

        int currentBlock = startBlock;
        allocated[currentBlock] = true;  // Allocate starting block
        numBlocks--;  // One block is allocated, decrement count

        while (numBlocks > 0) {
            int nextBlock;
            cout << "Enter the next block after " << currentBlock << ": ";
            cin >> nextBlock;

            // Check if the next block is free
            if (allocated[nextBlock]) {
                cout << "Block " << nextBlock << " is already allocated. Try again.\n";
                continue;
            }

            // Allocate the next block
            disk[currentBlock].next = nextBlock;  // Link the current block to the next
            currentBlock = nextBlock;             // Move to the next block
            allocated[currentBlock] = true;       // Mark the block as allocated
            numBlocks--;                          // Decrement the number of blocks to allocate
        }

        cout << "File " << i + 1 << " allocated successfully!\n";
    }

    // Display the allocation details
    cout << "\nFile Allocation Details:\n";
    for (int i = 0; i < TOTAL_BLOCKS; i++) {
        if (allocated[i]) {
            cout << "Block " << i << " -> Next: ";
            if (disk[i].next == -1)
                cout << "End\n";
            else
                cout << disk[i].next << endl;
        }
    }

    return 0;
}