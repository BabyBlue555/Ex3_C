#include <stdio.h>
#include <math.h>
#include "insertion_sort.h"

void shift_element(int*, int); // declaration on helping function
int insertion_sort(int* arr , int len);


// watch this https://www.youtube.com/watch?v=Tz7vBodZqo8

// make sure you do it without arrays, and only with pointers!!!!!!!!!!!
// take the example and convert it to pointers
void shift_element(int* arr, int i){
    int key= *(arr+i);
    int j=i-1;
    while(j>=0 && *(arr+j)>key){
        *(arr+j+1)=*(arr+j);
        j=j-1;

    }
    *(arr+j+1)=key;

   // free(arr);  can't free the array here,
   // since it's a pointer, it is the same array

}



int insertion_sort(int* arr , int len)
{
    for(int i=1; i< SIZE; i++)
    {
        shift_element(arr,i);

    }



}