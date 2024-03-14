#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
char *args[]={"./neha",NULL}; //"./ex" is used to store the compiled file instead of ./a.out
execvp(args[0],args);  //prints the content in new.c file
printf("End");
}
