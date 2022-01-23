#include <stdio.h>

int palindrome(void) {
  char A[] = "donf";
  char B[100];
  int i;
  //reverse string A
  for(i=0;A[i]!='\0';i++)
  {
  }
  i = i - 1;
  int j;
  for(j=0;j<=i;j++)
  {
    B[j] = A[i-j];
  }
  //compare string
  int is_palindrome = 1;
  for(i=0,j=0;A[i]!='\0'&&B[j]!='\0';i++,j++)
  {
    if(A[i]!=B[j])
    {
      is_palindrome = 0;
      break;
    }
  }
  printf("%d", is_palindrome);
  return 0;
}