#include <stdio.h>

typedef struct Process {
    int PID, AT, BT, CT, TAT, WT;
} Process;

int main() {
    int n;
    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].PID = i + 1;
        printf("Enter Arrival Time and Burst Time for PID %d: ", p[i].PID);
        scanf("%d %d", &p[i].AT, &p[i].BT);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].AT > p[j].AT) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    int ct = 0;
    for (int i = 0; i < n; i++) {
        if (ct < p[i].AT)
            ct = p[i].AT;
        
        p[i].CT = ct + p[i].BT;
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;

        ct = p[i].CT;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", 
            p[i].PID, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
    }

    return 0;
}
