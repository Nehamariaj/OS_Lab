#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
void main()
{
 char filename[10],data[20];
int id;
printf("Enter a filename:");
scanf("%s",&filename);
printf("enter a id:");
scanf("%d",&id);
key_t key= ftok(filename,id);//unique key value for a filename is created
printf("%d\n",key);

int shm_id=shmget(key,1024,0644|IPC_CREAT);
if(shm_id==-1){
printf("Shared memory is not created\n");
}
else{
printf("Shared memory is created\n");
printf("Shared memory ID=%d\n",shm_id);
void * a=shmat(shm_id,(void*)0,0);
if (a==-1){
printf("Shared memory is not attached");
}
else{
printf("Shared memory is attached\n");
printf("a=%d\n",(int)a);
printf("enter a value to be written:");
scanf("%s",&data);
strcpy(a,data);
printf("Data written is %s\n",(char*)a);
int x=shmdt(a);
if(x==-1){
printf("Shared memory is not dettached");
}
else{
printf("Shared memory is dettached\n");
}
int y=shmctl(shm_id,IPC_RMID,NULL);
if(y==-1)
printf("Shared memory is not deleted");
else
printf("Shared memory is deleted");
}
}
  }                                                                                        
