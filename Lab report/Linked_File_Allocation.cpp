#include <iostream>
using namespace std;

struct Block {
    int data;
    int next;
};

int main() {
    const int TOTAL_BLOCKS = 100;   // Total blocks on disk
    Block disk[TOTAL_BLOCKS];       // Disk with blocks
    bool allocated[TOTAL_BLOCKS] = {false}; // Allocation status of blocks

    int fileCount, startBlock, numBlocks;

    // Initialize the disk's next pointers to -1 (indicating the end of the file)
    for (int i = 0; i < TOTAL_BLOCKS; i++) {
        disk[i].next = -1;
    }

    cout << "Enter the number of files to allocate: ";
    cin >> fileCount;

    for (int i = 0; i < fileCount; i++) {
        cout << "\nEnter the starting block of file " << i + 1 << ": ";
        cin >> startBlock;

        // Check if the starting block is free
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