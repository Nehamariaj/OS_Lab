#include<stdio.h>
void main(){
int limit,tot_wt=0,tot_tat=0,tq,total=0,flag=0;
printf("enter the no of process:");
scanf("%d",&limit);
printf("enter the time quantum:");
scanf("%d",&tq);
int process[limit],bt[limit],wt[limit],tat[limit],rt[limit];
printf("Enter the process and the corresponding burst time:\n");
for(int i=0;i<limit;i++){
scanf("%d",&process[i]);
scanf("%d",&bt[i]);
rt[i]=bt[i];
}
printf("Process Burst_Time\n");
for(int i=0;i<limit;i++){
printf("   %d",process[i]);
printf("        %d",bt[i]);
printf("\n");
}

while(flag!=limit){
for(int i=0;i<limit;i++)
{
if(rt[i]>tq){
total=total+tq;
rt[i]=rt[i]-tq;
}
else if(rt[i]==0)
continue;
else{
total=total+rt[i];
rt[i]=0;
tat[i]=total;
wt[i]=total-bt[i];
flag++;
}
}
}

printf("Process Burst_Time waiting_time Turn_around_time\n");
for(int i=0;i<limit;i++){
printf("   %d       %d         %d               %d\n",process[i],bt[i],wt[i],tat[i]);
tot_wt=tot_wt+wt[i];
tot_tat=tot_tat+tat[i];
}
printf("----------------------------\n");
printf("Total TAT=%d\n",tot_tat);
printf("Total WT=%d\n",tot_wt);
float avg_tat,avg_wt;
avg_tat=(float)tot_tat/limit;
avg_wt=(float)tot_wt/limit;
printf("average TAT=%f\n",avg_tat);
printf("average WT=%f\n",avg_wt);
}
