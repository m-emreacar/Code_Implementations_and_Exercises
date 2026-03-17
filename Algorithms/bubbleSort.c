

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Bubble Sorting
 * Worst  performance: O(n^2)
 * Best  performance: O(n)
 * Space complexity: O(1) 
 */



//swap funct
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}






void bubbleSort(int *arr,int size){

for(int i=0;i<size-1;i++){
    for(int j=0;j<size-1-i;j++){
        if(arr[j]>arr[j+1]){
            swap(&arr[j+1],&arr[j]);
        }
    }

}


}


void printArray(int* arr,int size){

    for(int i=0;i<size;i++) printf("%d ",arr[i]);

    printf("\n\n");
}







int main(){

    
int arr[] = {12,33,21,15,16,11,26};

int n = sizeof(arr) / sizeof(arr[0]);


printArray(arr,n);
bubbleSort(arr,n);
printArray(arr,n);



    return 0;
}