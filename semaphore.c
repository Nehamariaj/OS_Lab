#include<stdio.h>
int mutex=1,full=0,empty=3;
int produce();
int consume();
int wait(int s);
int signal(int s);

void main(){
int choice;
while(choice!=3){
printf("------->Choose an option:\n1.Produce 2.Consume 3.Exit\nChoice:");
scanf("%d",&choice);

switch(choice){
case 1:{
if(mutex==1 && empty!=0){
produce();
printf("***Data is produced***\n");
}
else
printf("***Buffer space is full***\n");
break;
}
case 2:{
if(mutex==1 && full!=0){
consume();
printf("***Data is consumed***\n");
}
else
printf("****There is no data in the buffer***\n");
break;
}
case 3:{
printf("***EXITED!!***\n");
break;
}
}
}
}

int wait(int s){
s--;
return s;
}

int signal(int s){
s++;
return s;
}

int produce(){
mutex=wait(mutex);
full=signal(full);
empty=wait(empty);
mutex=signal(mutex);
}

int consume(){
mutex=wait(mutex);
empty=signal(empty);
full=wait(full);
mutex=signal(mutex);
}
