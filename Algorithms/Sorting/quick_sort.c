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

int partition(int *arr, int low, int high){
    int pivot = arr[low];
    int left = low;
    for(int i=low+1; i<high; i++){
        if(arr[i]<pivot){
            swap(&arr[i], &arr[left]);
            left++;
        }
    }
    swap(&arr[low], &arr[left]);
    return left;
}


void quick_sort(int *arr, int low, int high){
    if(low>=high)
        return;

    int pivot_location = partition(arr, low, high);
    quick_sort(arr, low, pivot_location);
    quick_sort(arr, pivot_location+1, high);
}



int main(){
    int arr[5] = {3, 2, 5, 1, 4};

    print_arr(arr, 5);

    quick_sort(arr, 0, 5);
    printf("\n");

    print_arr(arr, 5);

    return 0;
}

