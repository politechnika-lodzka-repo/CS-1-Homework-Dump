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

void selectionSort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
 
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }

        if (min != i)
            swap(&arr[min], &arr[i]);
    }
}

int partition(int arr[],int low,int high)
{
  int pivot=arr[high];
  int i=(low-1);
   
  for(int j=low;j<=high;j++)
  {
    if(arr[j]<pivot)
    {
      i++;
      swap(&arr[i],&arr[j]);
    }
  }
  swap(&arr[i+1],&arr[high]);
  return (i+1);
}
            
void quickSort(int arr[],int low,int high)
{
  if(low<high)
  {
    int pi=partition(arr,low,high);

    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}
            

void displayArr(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("[%d]: %d\n", i, arr[i]);
    }
}

int main(void){
    int err = 0;

    printf("3.\n");
    printf("would you like to provide n numbers or get n random items?\n");
    printf("for n own numbers please enter 1, number of numbers and the n numbers:\n");
    printf("for random numbers please enter 2 and number of numbers:\n");
    int choice, n;

    do{
        err=scanf("%d%d", &choice, &n);
    }while(isError(err,2));

    int arr[n];
    if(choice==1){
        for(int i=0;i<n;i++){

            do{
                err=scanf("%d", &arr[i]);
            }while(isError(err,1));
        }
    }else{
        for(int i=0;i<n;i++){
            generateRandomInt();
        }
    }

    displayArr(arr, n);
    printf("now choose the method of sorting: \n1 - bubble sort\n2 - insertion sort\n3 - simple sort\n4 - quick sort\n");

    do{
        err=scanf("%d", &choice);
    }while(isError(err,1));

    if(choice==1){
        bubbleSort(arr, n);
    }
    if(choice==2){
        insertionSort(arr, n);
    }
    if(choice==3){
        insertionSort(arr, n);
    }
    if(choice==4){
        quickSort(arr, 0, n-1);
    }

    displayArr(arr, n);

    return 0;
}