#include<stdio.h> 
#include <fcntl.h> 
#include<stdio.h>
int main() 
{ 
char arr[30];
int size=read(0,arr,sizeof(arr));
int bytes =write(1,arr,size);
printf("number of bytes %d",bytes);
return 0; 
} 
