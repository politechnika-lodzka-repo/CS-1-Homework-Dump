#include <stdio.h>
#include <math.h>
#include <string.h>
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

void assignString(char s[], char assigned[]){
    for(int i=0;i<100;i++){
        s[i]=assigned[i];
    }
}

int main(int argc, char** argv){
    int err = 0;

    printf("ex1:\nenter number of students and their names, surnames and adresses (adresses after newline):\n");
    int n;

    do{
        err=scanf("%d", &n);
    }while(isError(err,1));

    char students[3*n][100];

    for(int i=0;i<n;i++){
        char name[100], surname[100];
        char* adress;
        size_t foo=100;
        adress = (char *)malloc(foo * sizeof(char));

        do{
            err=scanf("%s%s", name, surname);
        }while(isError(err,2));
        
        fgets(adress, foo, stdin);

        assignString(students[3*i], name);
        assignString(students[3*i+1], surname);
        assignString(students[3*i+2], adress);
    }

    for(int i=0;i<n;i++){
        printf("name: %s\t surname: %s\t adress: %s\n", students[3*i], students[3*i+1], students[3*i+2]);
    }

    printf("ex2:\nenter dimmenstions of a 2d matrix:\n");

    int x,y;

    do{
        err=scanf("%d%d", &x, &y);
    }while(isError(err,2));
    
    int A[x][y];
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            scanf("%d", &A[i][j]);
        }
    }

    printf("ex2: matrix of the sum of the row elemets:\n");
    for(int i=0;i<x;i++){
        int sum=0;
        for(int j=0;j<y;j++){
            sum+=A[i][j];
        }
        printf("[%d]\n", sum);
    }

    printf("ex2: matrix of the sum of the collumn elemets:\n");
    for(int i=0;i<y;i++){
        int sum=0;
        for(int j=0;j<x;j++){
            sum+=A[j][i];
        }
        printf("[%d]", sum);
    }
    printf("\n");




    return 0;
}