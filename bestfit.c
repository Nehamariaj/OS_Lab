#include<stdio.h>
void main(){
    int p_limit,m_limit;
    struct memory{
        int m_size;
        int allocation;
    }m[10];
    struct process{
        int p_size;
        int flag;
    }p[10];
    printf("Enter the no of process:");
    scanf("%d",&p_limit);
    printf("Enter the size of each process:");
    for(int i=0;i<p_limit;i++){
      scanf("%d",&p[i].p_size);
      p[i].flag=0;
    }
    printf("Enter the no of memory blocks:");
    scanf("%d",&m_limit);
    printf("Enter the size of each memory block:");
    for(int i=0;i<m_limit;i++){
      scanf("%d",&m[i].m_size);
      m[i].allocation=0;
    }
    printf("After allocation:\n");
    printf("Process_Size Memory_Block_Size\n");
    for(int i=0;i<p_limit;i++){
        int best_index=-1;
        for(int j=0;j<m_limit;j++){
            if(m[j].m_size>=p[i].p_size && m[j].allocation==0){
                if(best_index==-1)
                  best_index=j;
                else if(m[best_index].m_size>m[j].m_size)
                  best_index=j;
            }
        }
        if(best_index!=-1){
            m[best_index].allocation=1;
            p[i].flag=1;
            printf("      %d               %d\n",p[i].p_size,m[best_index].m_size);
        }
    }
    for(int i=0;i<p_limit;i++){
        if(p[i].flag==0)
          printf("No space in memory blocks for allocation of process size of %d\n",p[i].p_size);
    }
}
