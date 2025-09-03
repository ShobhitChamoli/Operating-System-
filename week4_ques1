#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

struct process{
    int id;
    int arrival_time;
    int burst;
    int remaining_time;
    int starting_time;
    int completion_time;
    int turn_around;
    int waiting_time;
    int response_time;
    int priority;
    bool started;
};
typedef struct process process;
int main(){
    int n;
    printf("Enter number of Processes: ");
    scanf("%d",&n);
    process P[n];
    printf("Enter Arrival Time: ");
    for(int i=0;i<n;i++){
        scanf("%d",&P[i].arrival_time);
        P[i].id=i;
    }
    printf("Enter Burst Time: ");
    for(int i=0;i<n;i++){
        scanf("%d",&P[i].burst);
        P[i].remaining_time=P[i].burst;
        P[i].started=false;
    }
    printf("Enter Priority of Processes: ");
    for(int i=0;i<n;i++){
        scanf("%d",&P[i].priority);
    }
    int time=0,completed=0;
    int gantt[1000],idx=0;
    while(completed!=n){
        int min=-1,maxpriority=INT_MIN;
        for(int i=0;i<n;i++){
            if(P[i].arrival_time<=time && P[i].remaining_time>0){
                if(P[i].priority>maxpriority){
                    maxpriority=P[i].priority;
                    min=i;
                }
                else if(P[i].priority==maxpriority){
                    if(P[i].arrival_time<P[min].arrival_time){
                        min=i;
                    }
                    else if(P[i].arrival_time==P[min].arrival_time){
                        if(P[i].id<P[min].id){
                            min=i;
                        }
                    }
                }
            }
        }
        if(min==-1){
            time++;
        }
        else{
            if(!P[min].started){
                P[min].starting_time=time;
                P[min].response_time=P[min].starting_time-P[min].arrival_time;
                P[min].started=true;
            }
            gantt[idx++]=min;
            P[min].remaining_time--;
            time++;
            if(P[min].remaining_time==0){
                completed++;
                P[min].completion_time=time;
                P[min].turn_around=P[min].completion_time-P[min].arrival_time;
                P[min].waiting_time=P[min].turn_around-P[min].burst;
            }
        }
    }
    printf("\nGantt Chart...\n");
    for(int i=0;i<idx;i++){
        if(i==0||gantt[i]!=gantt[i-1]) printf("P%d ",gantt[i]);
    }
    printf("\n");
    printf("Process ID\tArrival\tBurst\tStart\tCompletion\tResponse\tTAT\tWaiting\n");
    for(int i=0;i<n;i++){
        printf("P%d\t\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t%d\n",P[i].id,P[i].arrival_time,P[i].burst,P[i].starting_time,P[i].completion_time,P[i].response_time,P[i].turn_around,P[i].waiting_time);
    }
    return 0;
}
