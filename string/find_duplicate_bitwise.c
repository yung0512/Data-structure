#include <stdio.h>

int find_duplicate_bitwise(void)
{
  char A[] = "apple";
  long int H = 0; // to make sure we have at least 32bits so we declare H as a long integer
  int i, x = 0;
  for(i=0;A[i]!='\0';i++)
  {
    x = 1;
    x = x << (A[i] - 97);// 確認字元所對應到的bits 是否為1,如果是1就代表已經有此字元了
    if((x & H) > 0){
      printf("%c is duplicate", A[i]);
    }
    else {
      H = x | H;
    }
  }

}