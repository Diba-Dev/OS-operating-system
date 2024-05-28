// TOPIC : SJF (non preemptive)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int processNum;
    cout << "Enter total number of processes: ";
    cin >> processNum;
    int process[processNum], burstTime[processNum], waitingTime[processNum], turnaroundTime[processNum];

    cout << endl
         << "Enter Process : " << endl;
    for (int i = 0; i < processNum; i++)
    {
        cout << "Enter P[" << i << "] : ";
        cin >> process[i];
    }

    cout << endl
         << "Enter Process Burst Time: " << endl;
    for (int i = 0; i < processNum; i++)
    {
        cout << "Enter Burst time of process P[" << i + 1 << "] : ";
        cin >> burstTime[i];
    }

    for (int i = 0; i < processNum; i++)
    {
        for (int j = 0; j < processNum; j++)
        {
            if (burstTime[j] > burstTime[j + 1])
            {
                int temp = burstTime[j];
                burstTime[j] = burstTime[j + 1];
                burstTime[j + 1] = temp;

                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
            }
        }
    }
    double averagewaitingTime = 0, averageTATime = 0;
    waitingTime[0] = 0;
    for (int i = 1; i < processNum; i++)
    {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
        averagewaitingTime += waitingTime[i];
    }

    for (int i = 0; i < processNum; i++)
    {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
        averageTATime += turnaroundTime[i];
    }

    averagewaitingTime /= processNum;
    averageTATime /= processNum;

    cout << "Process\t\t Burst Time\t Waiting Time\t Turn aroundTime" << endl;

    for (int i = 0; i < processNum; i++)
    {
        cout << "Process - " << process[i] << "\t\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << endl;
    }
    cout << endl
         << "Average waiting time    : " << averagewaitingTime << endl;
    cout << "Average turn around time: " << averageTATime << endl;

    return 0;
}