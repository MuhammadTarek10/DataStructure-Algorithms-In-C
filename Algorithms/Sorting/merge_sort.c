#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void merge(int *arr, int beg, int end){
    int mid = (beg+end)/2;
    int temp[end-beg+1];
    int i = beg, j = mid+1, k = 0;

    while(i<=mid && j<=end){
        if(arr[i]<arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i<=mid)
        temp[k++] = arr[i++];
    while(j<=end)
        temp[k++] = arr[j++];

    for(int p=0; p<k; p++){
        arr[beg+p] = temp[p];
    }
}

void merge_sort(int *arr, int beg, int end){
    if(beg==end)
        return;

    int mid = (beg+end)/2;
    merge_sort(arr, beg, mid);
    merge_sort(arr, mid+1, end);
    merge(arr, beg, end);
}


int main(){
    int arr[5] = {5, 2, 4, 1, 3};
    for(int i=0; i<5; i++){
        printf("%d\n", arr[i]);
    }

    merge_sort(arr, 0, 4);
    printf("\n");

    for(int i=0; i<5; i++){
        printf("%d\n", arr[i]);
    }
}