#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(){
    int arr[5] = {4, 5, 2, 1, 3};
    for(int i=0; i<5; i++){
        printf("%d\n", arr[i]);
    }
    for(int i=0; i<4; i++){
        int posMin = i;
        for(int j=i+1; j<5; j++){
            if(arr[j]<arr[posMin]){
                posMin = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[posMin];
        arr[posMin] = temp;
    }
    printf("\n\n");
    for(int i=0; i<5; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}