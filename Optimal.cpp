//Topic: Page Optimal
#include <bits/stdc++.h>
using namespace std;
int DistanceCk(int index, int sizeofFrame, int size, int frame[], int referenceA[]){
    int Distance[sizeofFrame];
    for (int i = 0; i < sizeofFrame; i++)
    {
        Distance[i] = size;
    }
    for (int i = 0; i < sizeofFrame; i++)
    {
        for (int j = index; j < size; j++)
        {
            if (frame[i] == referenceA[j])
            {
                Distance[i] = j - index;
                break;
            }
        }
    }
    int maxDis = Distance[0];
    for (int i = 1; i < sizeofFrame; i++)
    {
        if(maxDis < Distance[i]){
            maxDis = Distance[i];
        }
    }
    for (int i = 0; i < sizeofFrame; i++)
    {
        if (Distance[i] == maxDis)
        {
            return i;
        }
    }
}

int main()
{
    int size;
    cout << "Enter the size of elements: ";
    cin >> size;
    int sizeofFrame;
    cout << "Enter the frame size: ";
    cin >> sizeofFrame;
    int referenceA[size], frame[sizeofFrame];
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> referenceA[i];
    }
    for (int i = 0; i < sizeofFrame; i++)
    {
        frame[i] = -1;
    }

    // 2D array to store all states to visualize:
    int finalArray[size][sizeofFrame];
    // counters:
    int pageFaults = 0;

    // fill the 2D array:


    for (int i = 0; i < size; i++)
    {
        int found = 0;
        for (int j = 0; j < sizeofFrame; j++)
        {
            if (frame[j] == referenceA[i])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            int index = DistanceCk(i, sizeofFrame, size, frame, referenceA);
            frame[index] = referenceA[i];
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