#include<stdio.h>
int main()
{
	int process[20];
    int arrival_time[20],burst_time[20],waiting_time[20],turn_around_time[20],priority[20];
	int i,j,n;
	int total=0;
	int position,temp;
	int avg_wt,avg_tat;
	
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
    
    printf("\nEnter the processes names: \n ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&process[i]);
	}
    printf("\nEnter  Arrival time ");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Arrival time:");
        scanf("%d",&arrival_time[i]);
    }
    printf("\nEnter Burst Time  ");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&burst_time[i]);
    }
    printf("\nEnter Priority\n  ");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Priority:");
        scanf("%d",&priority[i]);
    }
    
 
    //sorting  arrival time,burst time, priority and process number in ascending order
    for(i=0;i<n;i++)
    {
        position=i;
        for(j=i+1;j<n;j++)
        {
            if(process[j]<process[position])
                position=j;
        }
        
        temp=arrival_time[i];
        arrival_time[i]=arrival_time[position];
        arrival_time[position]=temp;
 
        temp=process[i];
        process[i]=process[position];
        process[position]=temp;
 
        temp=burst_time[i];
        burst_time[i]=burst_time[position];
        burst_time[position]=temp;
 
        temp=priority[i];
        priority[i]=priority[position];
        priority[position]=temp;
    }
 
    waiting_time[0]=0;	//waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]=waiting_time[i]+burst_time[j];
 
        total=total+waiting_time[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
 
    printf("\nProcess\t  Arrival time\t  Burst Time\t Priority\t Waiting Time\t  Turnaround Time");
    for(i=0;i<n;i++)
    {
        turn_around_time[i]=burst_time[i]+waiting_time[i];     //calculate turnaround time
        total=total+turn_around_time[i];
        printf("\nP[%d]\t\t  %d\t\t  %d\t\t  %d\t\t   %d\t\t %d ",process[i],arrival_time[i],burst_time[i],priority[i],waiting_time[i],turn_around_time[i]);
    }
 
    avg_tat=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
 
	return 0;
}
