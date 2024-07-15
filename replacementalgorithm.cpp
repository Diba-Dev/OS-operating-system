#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Array declaration part:
    int size;
    cout << "Enter the size: ";
    cin >> size;
    int sizeofFrame;
    cout << "Enter the frame size: ";
    cin >> sizeofFrame;
    int referenceA[size], frame[sizeofFrame];
    cout << "Enter the values: ";
    for (int i = 0; i < size; i++)
    {
        cin >> referenceA[i];
    }

    // Initialize the frame array to -1 to indicate empty slots
    for (int i = 0; i < sizeofFrame; i++)
    {
        frame[i] = -1;
    }

    int finalArray[size][sizeofFrame];
    int count = 0; // Keeps track of the oldest frame slot
    int pageFaults = 0; // Counter for total page faults

    // The main calculation part:
    for (int i = 0; i < size; i++)
    {
        bool found = false;
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
            frame[count] = referenceA[i];
            count = (count + 1) % sizeofFrame;
            pageFaults++;
        }

        // Store the current frame state into finalArray
        for (int j = 0; j < sizeofFrame; j++)
        {
            finalArray[i][j] = frame[j];
        }
    }

    // Display the results
    for (int i = 0; i < size; i++)
    {
        cout << "For reference: " << referenceA[i] << " the frame is: ";
        for (int j = 0; j < sizeofFrame; j++)
        {
            if (finalArray[i][j] != -1)
            {
                cout << finalArray[i][j] << " ";
            }
            else
            {
                cout << "_ ";
            }
        }
        cout << endl;
    }

    cout << "Total page faults: " << pageFaults << endl;

    return 0;
}
