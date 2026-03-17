/** @file
 *  @brief Implementation of Merge Sort 
 * 
 *  Performance : O(n log(n))
 *  Worst case space complexity: O(n) 
 * 
 */


#include <stdio.h>
#include <stdlib.h>

/**
 * @param   array to sort
 * @param   left index
 * @param   mid index 
 * @param   right
 */
void merge(int arr[],int left,int mid,int right){
    int i,j,k;
    
    int LN = mid - left + 1;
    int RN = right - mid;

    //left and right arrays with their sizes
    int lA[LN];
    int rA[RN];
    
    for(int i=0;i<LN;i++)   lA[i] = arr[left + i];
    for(int j=0;j<RN;j++)   rA[j] = arr[mid + j + 1];  
    
    i = j = 0;  k = left;
     
    

    while(i<LN && j<RN){
        if(lA[i] <= rA[j]){
            arr[k] = lA[i];
            i++;
        }
        else{
            arr[k] = rA[j];
            j++;
        }
    k++;
    }
    //for surplass nums
    while(i<LN){
        arr[k++] = lA[i++]; 
    }
    while(j<RN){
        arr[k++] = rA[j++];
    }

    
    
    
}
/**
 * @brief Merge Sort function (uses recursion)
 * @param array to sort
 * @param left index 
 * @param right index
 */
void mergeSort(int arr[],int left,int right){
    if(left>=right) return;
    
    
    int mid = left + (right - left) / 2;
    
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    
    merge(arr,left,mid,right);
    
    
}









int main() {


    int arr[] = {15,33,21,59,13,12,24,43}; 
    for(int i=0;i<8;i++) printf("%d ",arr[i]);
    
    printf("\n\n\n");

    int n = sizeof(arr) / sizeof(arr[0]); 
    
    mergeSort(arr,0,n-1);
    for(int i=0;i<8;i++) printf("%d ",arr[i]);
    
        
    
    
    return 0;
}
