#include<stdio.h>

struct memory{
int size;
int alloc;
}m[10];

struct process{
int p;
int psize;
int flag;
}p[10];

void main(){
int limit;
printf("Enter the no of process:");
scanf("%d",&limit);
printf("Enter the process and its size:");
for(int i=0;i<limit;i++){
scanf("%d",&p[i].p);
scanf("%d",&p[i].psize);
}
printf("Enter the Size of memory blocks:");
for(int i=0;i<limit;i++){
scanf("%d",&m[i].size);
}

for(int i=0;i<limit;i++){
 for(int j=0;j<limit;j++){
  if(p[i].psize<=m[i].size){
   if(m[i].alloc==1)
    continue;
   else{
    m[i].alloc=1;;
    p[i].flag=1;
    printf("Memory is allocated for process %d\n",i);
   }
  }
 }
}
for(int i=0;i<limit;i++){
 if(p[i].flag==0){
  printf("No space for the process %d to be allocated\n",i);
 }
}
}   
