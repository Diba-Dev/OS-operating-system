#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of elements: ";
    cin >> size;
    int sizeofFrame;
    cout << "Enter the frame size: ";
    cin >> sizeofFrame;
    int referenceA[size];
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> referenceA[i];
    }

    int frame[sizeofFrame];
    int pageOrder[sizeofFrame]; // To simulate the queue
    for (int i = 0; i < sizeofFrame; i++)
    {
        frame[i] = -1;
        pageOrder[i] = -1; // Initialize with -1 (empty)
    }

    int nextIndex = 0; // Points to the next frame to be replaced
    int pageFaults = 0;
    int finalArray[size][sizeofFrame];

    for (int i = 0; i < size; i++)
    {
        bool found = false;
        // Check if page is already in frame
        for (int j = 0; j < sizeofFrame; j++)
        {
            if (frame[j] == referenceA[i])
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            // Replace the oldest page in frame
            int oldPage = pageOrder[nextIndex];
            // Remove the old page from the frame
            for (int j = 0; j < sizeofFrame; j++)
            {
                if (frame[j] == oldPage)
                {
                    frame[j] = referenceA[i];
                    break;
                }
            }

            // Update the frame with the new page
            frame[nextIndex] = referenceA[i];
            pageOrder[nextIndex] = referenceA[i];
            nextIndex = (nextIndex + 1) % sizeofFrame; // Move to the next index in circular manner

            pageFaults++;
        }

        // Store the current frame state into finalArray
        for (int j = 0; j < sizeofFrame; j++)
        {
            finalArray[i][j] = frame[j];
        }
    }

    cout << "Value:  ";
    for (int i = 0; i < size; i++)
    {
        cout << referenceA[i] << "\t";
    }
    cout << endl;

    for (int j = 0; j < sizeofFrame; j++)
    {
        cout << "\t";
        for (int i = 0; i < size; i++)
        {
            if (finalArray[i][j] != -1)
            {
                cout << finalArray[i][j] << "\t";
            }
            else
            {
                cout << "-\t";
            }
        }
        cout << endl;
    }
    cout << "Total page faults: " << pageFaults << endl;
    return 0;
}
