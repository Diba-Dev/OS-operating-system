//TOPIC :  Implementation of Priority Scheduling Algorithm.
 
#include<bits/stdc++.h>
using namespace std;

struct Process {
    int pid; 
    int BT; 
    int priority; 
};


bool comparison(Process a, Process b) {
    return (a.priority > b.priority);
}


void findWaitingTime(Process proc[], int n, int wt[]) {
    
    wt[0] = 0;

    // calculating waiting time
    for (int i = 1; i < n; i++)
        wt[i] = proc[i - 1].bt + wt[i - 1];
}

// Function to calculate turn around time
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) {
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

// Function to calculate average time
void findavgTime(Process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    findWaitingTime(proc, n, wt);

    // Function to find turn around time for all processes
    findTurnAroundTime(proc, n, wt, tat);

    // Display processes along with all details
    cout << "\nProcesses\t"
         << " Burst time\t"
         << " Waiting time\t"
         << " Turn around time\t"
         << " Priority\n";

    // Calculate total waiting time and total turn
    // around time
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << proc[i].pid << "\t\t\t" << proc[i].bt
             << "\t\t" << wt[i] << "\t\t " << tat[i]
             << "\t\t" << proc[i].priority << endl;
    }

    cout << "\nAverage waiting time: "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time: "
         << (float)total_tat / (float)n;
}

void priorityScheduling(Process proc[], int n) {
    // Sort processes by priority
    sort(proc, proc + n, comparison);

    cout << "Order in which processes gets executed \n";
    for (int i = 0; i < n; i++)
        cout << proc[i].pid << " ";

    findavgTime(proc, n);
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process proc[n];
    cout << "Enter process ID, burst time, and priority for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ":\n";
        cout << "Process ID: ";
        cin >> proc[i].pid;
        cout << "Burst Time: ";
        cin >> proc[i].bt;
        cout << "Priority: ";
        cin >> proc[i].priority;
    }

    priorityScheduling(proc, n);
    return 0;
}
