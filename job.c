#include <stdio.h>

// Structure to represent a job
struct Job {
    int profit;     // Profit of the job
    int deadline;   // Deadline of the job
};

// Function to swap two jobs
void swap(struct Job* a, struct Job* b) {
    struct Job temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort on jobs based on profit in descending order
void sortJobs(struct Job jobs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                swap(&jobs[j], &jobs[j + 1]);
            }
        }
    }
}

// Function to perform job scheduling and display the maximum profit and job sequence
void JS(struct Job jobs[], int n) {
    sortJobs(jobs, n);
    
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    
    int sequence[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        sequence[i] = -1;
    }
    
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        int deadline = jobs[i].deadline;
        
        while (deadline > 0 && sequence[deadline - 1] != -1) {
            deadline--;
        }
        
        if (deadline > 0) {
            sequence[deadline - 1] = i;
            totalProfit += jobs[i].profit;
        }
    }
    
    printf("Maximum Profit: %d\n", totalProfit);
    printf("Job Sequence with Deadlines: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (sequence[i] != -1) {
            printf("p%d (d%d) ", sequence[i] + 1, jobs[sequence[i]].deadline);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    
    struct Job jobs[n];
    
    printf("Enter the profit and deadline for each job:\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf("%d%d", &jobs[i].profit, &jobs[i].deadline);
    }
    
    JS(jobs, n);
    
    return 0;
}
