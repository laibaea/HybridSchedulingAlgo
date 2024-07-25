# HybridSchedulingAlgo
<h3><b>Abstract:</b></h3>
In this project, the scheduling algorithm defines how much CPU time must be allotted to which process and when.
This code implements a Hybrid Shortest Job First (SJF) - Round Robin (RR) scheduling algorithm for process execution. Both the RR and SJF components of the hybrid scheduling algorithm in our code are preemptive. According to SJF, if a process with a shorter burst time is found, the current process is preempted, and the new shortest job is selected to execute next. This preempts the current process before it completes its execution. 
According to Round Robins, each process is allowed to execute for a certain time slice (time quantum) before being preempted and allows the next process to execute. This preemption occurs even if the process has not completed its burst 
time.

<h3><b>Introduction:</b></h3>
The Hybrid SJF-RR scheduling algorithm aims to minimize the waiting time and maximize the throughput of processes. It accomplishes this by prioritizing processes with shorter burst times. Additionally, for longer processes that exceed a certain time quantum, the algorithm applies the Round Robin policy to ensure fair execution among all processes. 
By combining the strengths of SJF and RR policies, the Hybrid SJF-RR scheduling algorithm optimizes process execution, reduces waiting time, and ensures fairness among processes. 
This algorithm is widely used in modern operating systems to enhance system performance and provide a balance between response time and throughput.
