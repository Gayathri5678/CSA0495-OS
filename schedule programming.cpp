#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;  
    int burst_time; 
    int arrival_time; 
} Process;

void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}
void sort_processes(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time ||
                (processes[j].arrival_time == processes[j + 1].arrival_time &&
                 processes[j].burst_time > processes[j + 1].burst_time)) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void sjf(Process processes[], int n) {
    int completed = 0, current_time = 0;
    bool found = false; 

    while (completed < n) {
        found = false;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].burst_time > 0) {
                if (!found || processes[i].burst_time < processes[found_index].burst_time) {
                    found = true;
                    found_index = i;
                }
            }
        }

        if (found) {
            printf("Process %d running at time %d\n", processes[found_index].pid, current_time);
            processes[found_index].burst_time--;
            current_time++;
            if (processes[found_index].burst_time == 0) {
                completed++;
            }
        } else {
            current_time++;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Error: Maximum number of processes exceeded.\n");
        return 1;
    }

    Process processes[n];
    printf("Enter process ID, arrival time, and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        scanf("%d %d %d", &processes[i].pid, &processes[i].arrival_time, &processes[i].burst_time);
    }

    printf("\nShortest Job First Scheduling:\n");

    sort_processes(processes, n); 

    return 0;
}