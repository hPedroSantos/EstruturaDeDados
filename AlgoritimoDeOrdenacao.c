#include <stdlib.h>
#include <stdio.h>
    
void bubbleSort(int arr[], int n){

    int i, j, temp;

    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void){

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Lista original:\n");
    /*Lista original*/
    for(int i = 0; i < n; i++){
        printf("%i, ", arr[i]);
    }

    printf("\n");

    /*Lista ornada*/
    bubbleSort(arr, n);
    printf("Lista Ordenada:\n");
    for(int i = 0; i < n; i++){
        printf("%i, ", arr[i]);
    }
    printf("\n");

    return 0;

}
