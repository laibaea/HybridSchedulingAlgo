# HybridSchedulingAlgo
<h3><b>Abstract:</b>b></h3>
In this project, the scheduling algorithm defines how much CPU time must be allotted to which process and when.
This code implements a Hybrid Shortest Job First (SJF) - Round Robin (RR) scheduling algorithm for process execution. Both the RR and SJF components of the hybrid scheduling algorithm in our code are preemptive. According to SJF, if a process with a shorter burst time is found, the current process is preempted, and the new shortest job is selected to execute next. This preempts the current process before it completes its execution. 
According to Round Robins, each process is allowed to execute for a certain time slice (time quantum) before being preempted and allows the next process to execute. This preemption occurs even if the process has not completed its burst 
time.
This algorithm prioritizes processes based on their burst time, executing the process with the shortest burst time first. For longer processes, the Round Robin policy is applied with a specified time quantum. The code calculates the waiting time and turnaround time for each process and outputs the average waiting time and average turnaround time for all executed processes
