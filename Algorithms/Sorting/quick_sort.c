#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_arr(int *arr, int arrSize){
    for(int i=0; i<arrSize; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void swap(int *num1, int *num2){
    *num1 = *num1+*num2;
    *num2 = *num1-*num2;
    *num1 = *num1-*num2;
}

int get_pivot(int *arr, int low, int high){
    int mid = (low+high)/2;
    if(arr[low]>arr[mid])
        swap(&arr[low], &arr[mid]);
    if(arr[low]>arr[high-1])
        swap(&arr[low], &arr[high]);
    if(arr[mid]>arr[high-1])
        swap(&arr[mid], &arr[high]);
    return arr[mid];
}

int partition(int *arr, int low, int high){
    int pivot = arr[low];
    int i = low, j = high;
    while(i<j){
        while(arr[i]<=pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<j)
            swap(&arr[i], &arr[j]);
    }
    if(low!=j)
        swap(&arr[low], &arr[j]);
    return j;
}


void quick_sort(int *arr, int low, int high){
    if(low>=high)
        return;

    int pivot_location = partition(arr, low, high);
    quick_sort(arr, low, pivot_location);
    quick_sort(arr, pivot_location+1, high);
}



int main(){
    int arr[] = {8, 7, 9, 10, 15, 13, 5, 1, 6, 2, 3};
    

    print_arr(arr, 11);

    quick_sort(arr, 0, 11);
    printf("\n");

    print_arr(arr, 11);

    return 0;
}

