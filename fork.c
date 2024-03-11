#include<stdio.h>
#include<unistd.h>
void main(){
int pd,limit,i,num;
pd=fork(); //fork() is used to create a subprocess(works just like a thread)
if(pd==0){
wait(); //wait() is used to make the next process wait till the working process is completed
printf("child process\n");
printf("Process ID=%d\n",getpid());  //getpid() is used to get process ID
printf("Parent's ID=%d\n",getppid());  //getppid() is used to get parent's process ID
printf("Enter a limit:");
scanf("%d",&limit);
for(i=1;i<=limit;i++)
printf("%d\n",i);
}
else if(pd>0){
wait();
printf("Parent process\n");
printf("Parent's ID=%d\n",getppid());
printf("Enter a number:");
scanf("%d",&num);
if(num%2==0)
printf("The given number is even\n");
else
printf("The given number is odd\n");
}
else{
printf("fork failed\n");
}
}
