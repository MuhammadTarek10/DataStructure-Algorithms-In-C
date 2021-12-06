#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int arr[5] = {5, 2, 4, 1, 3};
    for(int i=0; i<5; i++){
        printf("%d\n", arr[i]);
    }

    for(int i=1; i<5; i++){
        int current = arr[i]; 
        int j = i-1; 

        while(j>=0 && arr[j]>current){ 
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = current;
    }

    printf("\n\n");
    for(int i=0; i<5; i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}