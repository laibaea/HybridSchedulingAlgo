#include <iostream>

using namespace std;

// Process structure
struct Process {
    int processId;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;

    // Default constructor
    Process()
        : processId(0), arrivalTime(0), burstTime(0),
          remainingTime(0), completionTime(0), turnaroundTime(0), waitingTime(0) {}

    // Constructor
    Process(int id, int arrival, int burst)
        : processId(id), arrivalTime(arrival), burstTime(burst),
          remainingTime(burst), completionTime(0), turnaroundTime(0), waitingTime(0) {}
};

// Selection sort for SJF scheduling
void selectionSort(Process* processes, int numProcesses) {
    for (int i = 0; i < numProcesses - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numProcesses; j++) {
            if (processes[j].burstTime < processes[minIndex].burstTime) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(processes[i], processes[minIndex]);
        }
    }
}

// Hybrid SJF-RR Scheduling Algorithm
void hybridScheduling(Process* processes, int numProcesses, int timeQuantum) {
    int currentTime = 0;
    int numExecutions = 0;
    int totalWaitingTime = 0;

    selectionSort(processes, numProcesses);

    int completedProcesses = 0;
    int currentIndex = 0;

    while (completedProcesses < numProcesses) {
        for (int i = 0; i < numProcesses; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0) {
                currentIndex = i;
                break;
            }
        }

        int executionTime = min(timeQuantum, processes[currentIndex].remainingTime);
        processes[currentIndex].remainingTime -= executionTime;
        currentTime += executionTime;

        if (processes[currentIndex].remainingTime == 0) {
            processes[currentIndex].completionTime = currentTime;
            processes[currentIndex].turnaroundTime = processes[currentIndex].completionTime - processes[currentIndex].arrivalTime;
            numExecutions++;
            totalWaitingTime += processes[currentIndex].waitingTime;
            completedProcesses++;
        }
		
        cout << "Process " << processes[currentIndex].processId << ": Executed " << executionTime << " time.";
        if (processes[currentIndex].remainingTime > 0)
            cout << " Remaining burst time: " << processes[currentIndex].remainingTime << endl;
        else
            cout << " Execution complete." << endl;

        int shortestJobIndex = -1;
        for (int i = 0; i < numProcesses; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0) {
                if (shortestJobIndex == -1 || processes[i].remainingTime < processes[shortestJobIndex].remainingTime)
                    shortestJobIndex = i;
            }
        }

        if (shortestJobIndex != -1 && shortestJobIndex != currentIndex) {
            currentIndex = shortestJobIndex;
            processes[currentIndex].waitingTime = currentTime - processes[currentIndex].arrivalTime;
        }
    }

    double averageWaitingTime = static_cast<double>(totalWaitingTime) / numProcesses;
    double averageTurnaroundTime = 0.0;

    for (int i = 0; i < numProcesses; i++) {
        averageTurnaroundTime += processes[i].turnaroundTime;
    }
    averageTurnaroundTime /= numProcesses;

    cout << "\nAverage Waiting Time: " << averageWaitingTime << endl;
    cout << "Average Turnaround Time: " << averageTurnaroundTime << endl;
}

int main() {
    int numProcesses;
    int timeQuantum;

    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    cout << "Enter the time quantum: ";
    cin >> timeQuantum;

    Process* processes = new Process[numProcesses];

    for (int i = 0; i < numProcesses; i++) {
        int arrivalTime, burstTime;
        cout << "\nProcess " << i + 1 << ":" << endl;
        cout << "Enter arrival time: ";
        cin >> arrivalTime;
        cout << "Enter burst time: ";
        cin >> burstTime;

        processes[i] = Process(i + 1, arrivalTime, burstTime);
    }
	cout << "\nProcess Execution Order:" << endl;
    cout << "-------------------------" << endl;
    hybridScheduling(processes, numProcesses, timeQuantum);

    delete[] processes;

    return 0;
}

