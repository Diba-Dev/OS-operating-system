#include <iostream>
using namespace std;

const int MAX_PROCESSES = 10;
const int MAX_RESOURCES = 10;

void calculateNeed(int need[][MAX_RESOURCES], int max[][MAX_RESOURCES], int allocation[][MAX_RESOURCES], int processCount, int resourceCount) {
    for (int i = 0; i < processCount; i++) {
        for (int j = 0; j < resourceCount; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

bool isSafe(int processes[], int available[], int max[][MAX_RESOURCES], int allocation[][MAX_RESOURCES], int processCount, int resourceCount) {
    int need[MAX_PROCESSES][MAX_RESOURCES];
    calculateNeed(need, max, allocation, processCount, resourceCount);

    bool finished[MAX_PROCESSES] = {0};
    int safeSequence[MAX_PROCESSES];
    int work[MAX_RESOURCES];

    for (int i = 0; i < resourceCount; i++) {
        work[i] = available[i];
    }

    int count = 0;
    while (count < processCount) {
        bool found = false;
        for (int p = 0; p < processCount; p++) {
            if (!finished[p]) {
                bool possible = true;
                for (int r = 0; r < resourceCount; r++) {
                    if (need[p][r] > work[r]) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    for (int r = 0; r < resourceCount; r++) {
                        work[r] += allocation[p][r];
                    }
                    safeSequence[count++] = p;
                    finished[p] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "System is not in a safe state.\n";
            return false;
        }
    }

    cout << "System is in a safe state.\nSafe sequence is: ";
    for (int i = 0; i < processCount; i++) {
        cout << "P" << safeSequence[i] << " ";
    }
    cout << endl;
    return true;
}

bool requestResources(int processID, int request[], int available[], int max[][MAX_RESOURCES], int allocation[][MAX_RESOURCES], int processCount, int resourceCount) {
    int need[MAX_PROCESSES][MAX_RESOURCES];
    calculateNeed(need, max, allocation, processCount, resourceCount);

    // Check if request exceeds the need
    for (int r = 0; r < resourceCount; r++) {
        if (request[r] > need[processID][r]) {
            cout << "Error: Request exceeds the need.\n";
            return false;
        }
    }

    // Check if request exceeds available resources
    for (int r = 0; r < resourceCount; r++) {
        if (request[r] > available[r]) {
            cout << "Resources not available.\n";
            return false;
        }
    }

    // Pretend to allocate resources
    for (int r = 0; r < resourceCount; r++) {
        available[r] -= request[r];
        allocation[processID][r] += request[r];3
        need[processID][r] -= request[r];
    }

    // Check if the system is still in a safe state
    if (isSafe(new int[processCount], available, max, allocation, processCount, resourceCount)) {
        return true;
    } else {
        // Rollback the allocation if not safe
        for (int r = 0; r < resourceCount; r++) {
            available[r] += request[r];
            allocation[processID][r] -= request[r];
            need[processID][r] += request[r];
        }
        cout << "Request cannot be granted as it leads to an unsafe state.\n";
        return false;
    }
}

int main() {
    int processCount, resourceCount;

    cout << "Enter number of processes: ";
    cin >> processCount;

    cout << "Enter number of resources: ";
    cin >> resourceCount;

    int processes[MAX_PROCESSES];
    int available[MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int allocation[MAX_PROCESSES][MAX_RESOURCES];

    // Input resources and matrices
    cout << "Enter the available resources: \n";
    for (int i = 0; i < resourceCount; i++) {
        cin >> available[i];
    }

    cout << "Enter the max matrix: \n";
    for (int i = 0; i < processCount; i++) {
        for (int j = 0; j < resourceCount; j++) {
            cin >> max[i][j];
        }
    }

    cout << "Enter the allocation matrix: \n";
    for (int i = 0; i < processCount; i++) {
        for (int j = 0; j < resourceCount; j++) {
            cin >> allocation[i][j];
        }
    }

    isSafe(processes, available, max, allocation, processCount, resourceCount);

    int processID;
    int request[MAX_RESOURCES];

    cout << "Enter process number making the request: ";
    cin >> processID;

    cout << "Enter resource request: \n";
    for (int i = 0; i < resourceCount; i++) {
        cin >> request[i];
    }

    if (requestResources(processID, request, available, max, allocation, processCount, resourceCount)) {
        cout << "Request granted.\n";
    }

    return 0;
}
