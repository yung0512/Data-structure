#include "array_adt.h"
#include <stdlib.h>

int BinarySearch(struct Array arr,int key)
{
    int low = 0, high = arr.length - 1, mid;
    while(low <= high )
    {
        printf("low is: %d\n", low);
        printf("high is: %d\n", high);
        mid = (low + high)/2; //因為mid 是 int 若不能整除則直接去掉小數點
        printf("mid is: %d\n", mid);
        if(arr.A[mid] == key){
            return mid;
        }else if(key < arr.A[mid])
        {
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    struct Array arr={{1,2,3,4,5},10,5};
    printf("%d\n",BinarySearch(arr, 5));
    Display(arr);
}