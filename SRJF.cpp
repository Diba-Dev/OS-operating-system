//TOPIC: Implementation of SRJF scheduling algorithm
#include <bits/stdc++.h>
using namespace std;

int main() {
    int processNum;
    cout << "Enter total number of processes: ";
    cin >> processNum;

    vector<int> process(processNum), arrivalTime(processNum), burstTime(processNum), waitingTime(processNum), turnaroundTime(processNum), compTime(processNum);
    double aveTAT = 0, avgWT = 0;
    int total_TAT = 0, total_WT = 0;

    cout << "Enter Process Sequence: " << endl;
    for (int i = 0; i < processNum; i++) {
        cout << "Enter [" << i << "] : ";
        cin >> process[i];
    }

    cout << "Enter Process Arrival Time: " << endl;
    for (int i = 0; i < processNum; i++) {
        cout << "Enter P[" << process[i] << "] : ";
        cin >> arrivalTime[i];
    }

    cout << "Enter Process Burst Time: " << endl;
    for (int i = 0; i < processNum; i++) {
        cout << "Enter P[" << process[i] << "] : ";
        cin >> burstTime[i];
    }

    vector<pair<int, int>> processes; // Pair of arrival time and index
    for (int i = 0; i < processNum; i++) {
        processes.push_back({arrivalTime[i], i});
    }

    sort(processes.begin(), processes.end());

    int currentTime = 0;
    vector<bool> completed(processNum, false);
    int completedCount = 0;

    while (completedCount < processNum) {
        int shortestIdx = -1;
        int minBurst = INT_MAX;

        for (int i = 0; i < processNum; i++) {
            int idx = processes[i].second;
            if (!completed[idx] && arrivalTime[idx] <= currentTime && burstTime[idx] < minBurst) {
                minBurst = burstTime[idx];
                shortestIdx = idx;
            }
        }

        if (shortestIdx == -1) {
            currentTime++;
            continue;
        }

        currentTime += burstTime[shortestIdx];
        compTime[shortestIdx] = currentTime;
        turnaroundTime[shortestIdx] = compTime[shortestIdx] - arrivalTime[shortestIdx];
        waitingTime[shortestIdx] = turnaroundTime[shortestIdx] - burstTime[shortestIdx];

        total_TAT += turnaroundTime[shortestIdx];
        total_WT += waitingTime[shortestIdx];
        completed[shortestIdx] = true;
        completedCount++;
    }

    cout << "Process\t\tArrival Time\t\tBurst Time\t\tTurnaround Time\t\tWaiting Time" << endl;
    for (int i = 0; i < processNum; i++) {
        cout << "P[" << process[i] << "]\t\t" << arrivalTime[i] << "\t\t" << burstTime[i] << "\t\t" << turnaroundTime[i] << "\t\t" << waitingTime[i] << endl;
    }

    aveTAT = (double)total_TAT / processNum;
    avgWT = (double)total_WT / processNum;

    cout << "Average TAT : " << aveTAT << endl;
    cout << "Average WT : " << avgWT << endl;

    return 0;
}
