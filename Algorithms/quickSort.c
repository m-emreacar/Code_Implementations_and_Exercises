#include <stdio.h>
#include <stdlib.h>

/**
 * @brief swap function
 * @param variable a pointer to swap with b
 * @param variable b pointer to swap with a
 */

void swap(int* a, int* b){
 int temp = *a;
 *a = *b;
 *b = temp;

}

/**
 * @brief partition function (compare arr elements with pivot (arr[high] in my funct).)
 * @param wanted array
 * @param left sub-array index
 * @param index of the last element a.k.a pivot
 * 
 */


int partition(int arr[], int low,int high){

int i = low - 1;
int pivot = arr[high];

for(int j=low;j<high;j++){
    if(arr[j]<pivot){
        i++;
        swap(&arr[i],&arr[j]);

    }

}

//lastly re-place pivot 
swap(&arr[i+1],&arr[high]);

//returns pivot position (i+1)
return i+1;


}

/**
 * @brief recursive quicksort funct
 * @param left array / sub-array index
 * @param right array / sub-array last index
 */

void quicksort(int arr[],int low,int high){

    if(low>=high) return;

    int pi = partition(arr,low,high);

    //divide and conquer left and right sub-array respectively.
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);


}