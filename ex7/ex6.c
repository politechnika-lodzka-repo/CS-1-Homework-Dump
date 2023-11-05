#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void clear(){
    while ( getchar() != '\n' );
}

int isError(int status, int expectedNOfArguments){
    clear();
    int res = status==EOF || status!=expectedNOfArguments;
    if(res)printf("warning, invalid data!\n");
    return res;
}


void swapStr(char *str1, char *str2) {     
    char foo[100];
    strcpy(foo, str1);
    strcpy(str1, str2);
    strcpy(str2, foo);
} 

int less(char* a, char* b){
    int l=strlen(a) > strlen(b) ? strlen(b) : strlen(a);
    for(int i=0;i<l;i++){
        if(a[i]<b[i])return 1;
        else if(a[i]>b[i])return 0;
        else if(a[i]==b[i])continue;
    }
    if(strlen(a) < strlen(b)) return 1;
    return 0;
}

void bubbleAlphaSort(char arr[][100], int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(less(arr[j],arr[j-1]))swapStr(arr[j], arr[j-1]);
        }
    }
}

void printArr(char arr[][100], int n){
    printf("sorted arr:\n");
    for(int i=0;i<n;i++){
        printf("%s\n", arr[i]);
    }
}

int main(void){
    int err=0;

    printf("enter number of students:\n");
    int n;

    do{
        err=scanf("%d", &n);
    }while(isError(err, 1));

    printf("now enter n student names:\n");
    char arr[n][100];
    for(int i=0;i<n;i++){
        do{
            err=scanf("%s", arr[i]);
        }while(isError(err, 1));
    }

    bubbleAlphaSort(arr, n);
    printArr(arr, n);
    

    return 0;
}