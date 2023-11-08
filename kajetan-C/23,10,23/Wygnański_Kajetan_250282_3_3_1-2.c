#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct Student{
    char name[15];
    char surname[15];
    char adress[30];
};

void breaker(){
    printf("\n==================\n");
}

void wrong_data(){
    printf("Wrong Data!");
    breaker();
}

void Tsk1(){
    int n, x;
    printf("state n: ");
    x = scanf("%d", &n);
    while ( x != 1 || n<1){
        if(x != 1) while((x=getchar()) != EOF && x!= '\n');
        printf("Wrong Data!\nstate n: ");
        x = scanf("%d", &n);
    }
    //struct Student students[n];
    char students[n][3][30];
    char *buf, temp[30], foo;
    size_t bufsize = 30, pom;
    for(int i=0 ; i<n ; i++){
        printf("student %d name: ", i+1);
        scanf("%s", students[i][0]);
        fflush(stdin);

        printf("student %d surname: ", i+1);
        scanf("%s", students[i][1]);
        while(getchar() != '\n') ;
        fflush(stdin);

        printf("student %d adress: ", i+1);
        fflush(stdin);
        fgets(students[i][2], 30, stdin);

    }
    printf("\n\tname\t|\tsurname\t|\tadress\n\t===============================\n");
    for(int i=0 ; i<n ; i++) printf("\t%s\t|\t%s\t|\t%s", students[i][0], students[i][1], students[i][2]);
}

void Tsk2(){
    int n, k, x;
    printf("state n and k: ");
    x = scanf("%d %d", &n, &k);
    if(x != 2 || n<1 || k<1){
        wrong_data();
        while((x=getchar()) != EOF && x!= '\n');
        return;
    }

    int tab[n][k], p;
    for(int i=0 ; i<n ; i++){
        for(int j = 0 ; j<k ; j++){
            x = scanf("%d", &p);
            if(x != 1){
                wrong_data();
                while((x=getchar()) != EOF && x!= '\n');
                return;
            }
            tab[i][j] = p;
        }
    }

    int sn[n], sk[k];

    for(int i=0 ; i<n ; i++){
        p = 0;
        for(int j=0 ; j<k ; j++) p+=tab[i][j];
        sn[i] = p;
    }

    for(int i=0 ; i<k ; i++){
        p = 0;
        for(int j=0 ; j<n ; j++) p+=tab[j][i];
        sk[i] = p;
    }
    printf("Sum of rows:\n");
    for(int i=0 ; i<n ; i++) printf("%d\n", sn[i]);

    printf("\nSum of columns:\n");
    for(int i=0 ; i<k ; i++) printf("%d, ", sk[i]);
}

int main(){
    Tsk1();
    Tsk2();
}

