#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void clear(){
    while ( getchar() != '\n' );
}

int isError(int status, int expectedNOfArguments){
    clear();
    int res = status==EOF || status!=expectedNOfArguments;
    if(res)printf("warning, invalid data!\n");
    return res;
}


int generateRandomInt(){
    return rand()%1000+1;
}

void swap(int* a, int* b){
    int foo=*a;
    *a=*b;
    *b=foo;
}

void bubbleSort(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(arr[j]<arr[j-1])swap(&arr[j], &arr[j-1]);
        }
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void displayArr100(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("[%d]: %d\n", i, arr[i]);
    }
}

int main(void){
    int err=0;

    printf("1: \n");
    srand(time(NULL));
    int arr[100];
    for(int i=0;i<100;i++){
        arr[i]=generateRandomInt();
    }

    bubbleSort(arr, 100);
    displayArr100(arr, 100);
    printf("2: \n");
    int n;
    printf("enter number of numbers: \n");

    do{
        err=scanf("%d", &n);
    }while(isError(err, 1));

    int arr2[n];
    printf("enter n numbers: \n");
    for(int i=0;i<n;i++){

        do{
            err=scanf("%d", &arr2[i]);
        }while(isError(err,1));
    }

    insertionSort(arr2, n);
    displayArr100(arr2, n);

    return 0;
}