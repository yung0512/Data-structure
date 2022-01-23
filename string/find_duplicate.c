#include <stdio.h>

int find_duplicate(void){
  char A[]="finding";
  //use hash table
  int hash_table[26],i;
  //intialize hash_table value to be 0;
  for(i=0; i< 26;i++)
  {
    hash_table[i] = 0;
  }
  for(i=0;A[i]!='\0';i++)
  {
    hash_table[A[i]-97]+= 1;
  }
  //scan hash table to check if dubplicate character
  for(i=0; i< 26;i++)
  {
    if(hash_table[i]>1)
    {
      printf("%c ", i+97);//print character by its ascii code
      printf("%d times\n", hash_table[i]);
    }

  }
 return 0;
}