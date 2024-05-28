// TOPIC :Implementation of FCFS Scheduling Algorithm.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int processNum;
    cout << "Enter total number of processes: ";
    cin >> processNum;
    int burstTime[processNum], waitingTime[processNum], turnaroundTime[processNum];
    double averagewaitingTime = 0, averageTATime = 0;

    cout << endl<< "Enter Process Burst Time: " << endl;
    for (int i = 0; i < processNum; i++)
    {
        cout << "Enter P[" << i + 1 << "] : ";
        cin >> burstTime[i];
    }

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
    
    cout<<"Process\t Burst Time\t Waiting Time\t Turn aroundTime"<<endl;
    
    for (int i = 0; i < processNum; i++)
    {
        cout<<"P["<< i+1 <<"]\t\t"<< burstTime[i]<<"\t\t"<<waitingTime[i]<<"\t\t"<<turnaroundTime[i]<<endl;
    }
    cout<<endl<<"Average waiting time    : "<<averagewaitingTime<<endl;
    cout<<"Average turn around time: "<<averageTATime<<endl;


    return 0;
}