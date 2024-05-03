#include<stdio.h>
#include<stdlib.h>
void main(){
    int p_no,r_no,count=0,k=0;
    printf("Enter the no of process and resources:");
    scanf("%d%d",&p_no,&r_no);
    int available[r_no],allocation[p_no][r_no],max[p_no][r_no],visited[p_no],need[p_no][r_no],safeseq[p_no];
    printf("Enter the available resources:");
    for(int i=0;i<r_no;i++){
        scanf("%d",&available[i]);
    }
    for(int i=0;i<p_no;i++){
        visited[i]=0;
        printf("Enter the no of instance allocated to P[%d]:",i);
        for(int j=0;j<r_no;j++){
            scanf("%d",&allocation[i][j]);
        }
        printf("Enter the maximum demand of P[%d]:",i);
        for(int j=0;j<r_no;j++){
            scanf("%d",&max[i][j]);
        }
        for(int j=0;j<r_no;j++){
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    printf("PROCESS|ALLOCATION| MAXIMUM |AVAILABLE|   NEED   |\n");
    printf("-------|----------|---------|---------|----------|\n");
    for(int i=0;i<p_no;i++){
    printf(" P[%d]  |",i);
    for(int j=0;j<r_no;j++){
    printf(" %d ",allocation[i][j]);
    }
    printf("|");
    for(int j=0;j<r_no;j++){
    printf(" %d ",max[i][j]);
    }
    printf("|");
     for(int j=0;j<r_no;j++){
    printf(" %d ",available[j]);
    }
    printf("|");
     for(int j=0;j<r_no;j++){
    printf(" %d ",need[i][j]);
    }
    printf("|");
    printf("\n");
    }
    while(count<p_no){
        int flag=0;
        for(int i=0;i<p_no;i++){
            int executed=0;
            for(int j=0;j<r_no;j++){
                if(need[i][j]<=available[j]){
                    executed++;
                }
            }
            if(executed==r_no && visited[i]==0){
                for(int j=0;j<r_no;j++)
                    available[j]+=allocation[i][j];
                flag=1;
                visited[i]=1;
                safeseq[k++]=i;
                count++;
            }
            }
        if(flag==0){
        printf("No safe state\n");
          exit(0);
        }
    }
         printf("Safe sequence:<");
         for(int i=0;i<p_no;i++){
           printf("P%d ",safeseq[i]);
        }
         printf(">");
        printf("\nSafe state exist\n");
     }
