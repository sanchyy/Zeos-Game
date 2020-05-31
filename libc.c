/*
 * libc.c 
 */

#include <libc.h>

#include <types.h>

int errno;

void itoa(int a, char *b)
{
  int i, i1;
  char c;
  
  if (a==0) { b[0]='0'; b[1]=0; return ;}
  
  i=0;
  while (a>0)
  {
    b[i]=(a%10)+'0';
    a=a/10;
    i++;
  }
  
  for (i1=0; i1<i/2; i1++)
  {
    c=b[i1];
    b[i1]=b[i-i1-1];
    b[i-i1-1]=c;
  }
  b[i]=0;
}

int strlen(char *a)
{
  int i;
  
  i=0;
  
  while (a[i]!=0) i++;
  
  return i;
}

void perror()
{
char buffer[256];
itoa(errno, buffer);

	switch(errno){
		 case 11: 
		  write(1, "EAGAIN: Try again", 17);

		  case 12:
		  write(1, "ENOMEM: Out of Memory",21); 

		  case 13:
		  write(1, "EACCESS: Permission denied", 26); 

		  case 14:
		  write(1, "EFAULT: Bad address", 19); 

		  case 105: 
		  write(1, "ENOBUF: No buffer space available", 25);
		  
		  default: write(1, buffer, strlen(buffer));
	}  
}
