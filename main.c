#include <stdio.h>
#include <stdlib.h>
#include "insertion_sort.h"
extern int insertion_sort(int*,int);

int main ()
{
    int* arr=NULL;
    int number;
  //  int* new_arr= NULL;
    /*aloocate memory for 50 integers*/
    arr= (int*)malloc(SIZE*sizeof(int));
 //   int input=0;

    printf("enter 50 integer numbers\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("enter the %d number in the array", i); // delete it later, should not be printed
        scanf("%d", &number); //returns 0 if didn't work, 1 if worked
        *(arr+i)=number;
        // "You entered %c.", chr
       // printf("%d,",*(arr+i));
    }
  
    
    

    if(arr==NULL){
        printf("Insufficient Memory, Exiting... \n");
        return 0;
    }

    insertion_sort(arr,SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        if(i==SIZE-1){
            printf("%d",*(arr+i));
        }
        else{
            printf("%d,",*(arr+i));
        }
    }


free(arr);
return 0;
    }
