#include<stdio.h>
void main(){
int limit,tot_wt=0,tot_tat=0,temp,temp2,temp3;
printf("enter the no of process:");
scanf("%d",&limit);
int process[limit],bt[limit],wt[limit],tat[limit],priority[limit];
printf("Enter the process and the corresponding burst time and priority:\n");
for(int i=0;i<limit;i++){
scanf("%d",&process[i]);
scanf("%d",&bt[i]);
scanf("%d",&priority[i]);
}
printf("Process Burst_Time Priority\n");
for(int i=0;i<limit;i++){
printf("   %d",process[i]);
printf("        %d",bt[i]);
printf("         %d",priority[i]);
printf("\n");
}
for(int i=0;i<limit;i++){
for(int j=i+1;j<limit;j++){
if(priority[i]>priority[j]){
temp3=priority[i];
priority[i]=priority[j];
priority[j]=temp3;
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
temp2=process[i];
process[i]=process[j];
process[j]=temp2;
}
}
}
printf("After Sorting by priority:\nProcess Burst_Time Priority\n");
for(int i=0;i<limit;i++){
printf("   %d",process[i]);
printf("        %d",bt[i]);
printf("         %d",priority[i]);
printf("\n");
}
wt[0]=0;
tat[0]=bt[0];
printf("Process Burst_Time Priority waiting_time Turn_around_time\n");
printf("   %d       %d         %d        0               %d\n",process[0],bt[0],priority[0],bt[0]);
tot_tat=tot_tat+bt[0];
for(int i=1;i<limit;i++){
wt[i]=wt[i-1]+bt[i-1];
tat[i]=tat[i-1]+bt[i];
printf("   %d       %d         %d        %d               %d\n",process[i],bt[i],priority[i],wt[i],tat[i]);
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
