#include <stdlib.h>
#include <stdio.h>

/*Percorrer a lista, depois trocar com o maior número*/


/*echo "# EstruturaDeDados" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/hPedroSantos/EstruturaDeDados.git
git push -u origin main*/
    
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