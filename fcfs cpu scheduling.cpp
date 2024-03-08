#include <stdio.h>

typedef struct {
    int pid;  
    int burst_time; 
} Process;

void fcfs(Process processes[], int n) {
    int waiting_time[n];
    int turnaround_time[n];
    int completion_time[n];
    for (int i = 0; i < n; i++) {
        waiting_time[i] = 0;
        turnaround_time[i] = 0;
        completion_time[i] = 0;
    }
    completion_time[0] = processes[0].burst_time;
    for (int i = 1; i < n; i++) {
        waiting_time[i] = completion_time[i - 1];
        completion_time[i] = completion_time[i - 1] + processes[i].burst_time;
        turnaround_time[i] = completion_time[i] - processes[i].burst_time;
    }

    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time,
               waiting_time[i], turnaround_time[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];
    printf("Enter process ID and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        scanf("%d %d", &processes[i].pid, &processes[i].burst_time);
    }

    fcfs(processes, n);

    return 0;
}