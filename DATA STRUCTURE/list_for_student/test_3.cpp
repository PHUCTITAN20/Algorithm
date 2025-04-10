// C program to illustrate fgets()
#include <stdio.h>
#include <string.h>
#define MAX 15
 
int main()
{
    // defining buffer
    char buf[MAX];
 
    // using fgets to take input from stdin
    fgets(buf, MAX, stdin);//lenh fget() da doc luon dau xuong dong
    if (buf[strlen(buf)-1]=='\n')
	   buf[strlen(buf)-1]='\t';    
    printf("string is: %s", buf);
    printf("Het rui!");
 
    return 0;
}
