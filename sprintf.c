/*sprintf example*/
#include<stdio.h>

int main()
{
  char buffer [50];
  int n, a=5, b=3;
  sprintf("okok: %c ", buffer);
  n= sprintf(buffer, "\n%d plus %d is %d", a,b, a+b);
  printf("[%s] is a string %d chars long\n", buffer,n);
  return 0;
}  
