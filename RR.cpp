//TOPIC: Implementation of Round robin Scheduling Algorithm 
#include <bits/stdc++.h>
using namespace std;

void calculateTAT(int N, int BT[], int BT2[], int TAT[], int QT)
{
    cout << "Processing started." << endl;
    int count = 0, i = 0;
    int remainingProcesses = N;
    
    while (remainingProcesses > 0)
    {
        if (BT2[i] > 0)
        {
            if (BT2[i] > QT)
            {
                count += QT;
                BT2[i] -= QT;
            }
            else
            {
                count += BT2[i];
                BT2[i] = 0;
                TAT[i] = count;
                remainingProcesses--;
            }
        }
        i = (i + 1) % N;
    }
    cout << "Processing done." << endl;
}

int main()
{
    int pNum;
    cout << "Number of processes: ";
    cin >> pNum;
    int BT[pNum], WT[pNum] = {0}, TAT[pNum] = {0}, QT, BT2[pNum];
    
    for (int i = 0; i < pNum; i++)
    {
        cout << "Burst Time of process P" << i + 1 << ": ";
        cin >> BT[i];
        BT2[i] = BT[i];
    }
    
    cout << "Put Quantum Time: ";
    cin >> QT;
    
    calculateTAT(pNum, BT, BT2, TAT, QT);
    
    double avgWT = 0, avgTAT = 0;
    
    for (int i = 0; i < pNum; i++)
    {
        WT[i] = TAT[i] - BT[i];
        avgTAT += TAT[i];
        avgWT += WT[i];
    }
    
    avgTAT /= pNum;
    avgWT /= pNum;
    
    cout << " P\t\tBT\t\tTAT\t\tWT\n";
    for (int i = 0; i < pNum; i++) {
        cout << " P" << i + 1 << "\t\t" << BT[i] << "\t\t" << TAT[i] << "\t\t " << WT[i] << endl;
    }
    
    cout << "The average Turn around time: " << avgTAT << endl;
    cout << "The average Waiting time: " << avgWT << endl;

    return 0;
}
