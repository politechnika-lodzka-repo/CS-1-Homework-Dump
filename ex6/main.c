#include <stdio.h>

void clear(){
    while ( getchar() != '\n' );
}

int isError(int status, int expectedNOfArguments){
    clear();
    int res = status==EOF || status!=expectedNOfArguments;
    if(res)printf("warning, invalid data!\n");
    return res;
}


int iterativeMethod1(int n){
    int res=n;
    while(--n){
        res*=n;
    }
    return res;
}

int recursiveMethod1(int n){
    if(n==0)return 1;
    return n*recursiveMethod1(n-1);
}

void ex1(){
    int err=0;
    printf("enter number n! and method (1-iterative, 2-recursive)\n");
    int n,m;

    do{
        err=scanf("%d%d", &n, &m);
    }while(isError(err, 2));
    
    if(m==1){
        printf("%d factorial: %d\n", n, iterativeMethod1(n));
    }if(m==2){
        printf("%d factorial: %d\n", n, recursiveMethod1(n));
    }
}

int iterativeMethod2(int n){
    int res=1;
    while(n--){
        res*=2;
    }

    return res;
}

int recursiveMethod2(int n){
    if(n==0)return 1;
    return 2*recursiveMethod2(n-1);
}

void ex2(){
    int err=0;

    printf("enter number 2^n and method (1-iterative, 2-recursive)\n");
    int n,m;
    
    do{
        err=scanf("%d%d", &n, &m);
    }while(isError(err, 2));

    if(m==1){
        printf("2^%d: %d\n", n, iterativeMethod2(n));
    }if(m==2){
        printf("2^%d: %d\n", n, recursiveMethod2(n));
    }
}

void ex3(){
    int err=0;

    printf("enter range [a;b]:\n");
    int a,b;

    do{
        err=scanf("%d%d", &a, &b);
    }while(isError(err, 2));
    
    int n1=1, n2=1;
    if(n1>=a && n1<=b){
        printf("%d, ", n1);
    }
    if(n2>=a && n2<=b){
        printf("%d, ", n2);
    }

    while(n2<=b){
        int n3=n1+n2;
        if(n3>=a && n3<=b){
            printf("%d, ", n3);
        }
        n1=n2;
        n2=n3;
    }
    printf("\n");
}

int isInGoodOrder(int *r, int l){
    for(int i=0;i<l-1;i++){
        if(r[i]-1!=r[i+1]){
            return 0;
        }
        if(r[i]==0 || r[i+1]==0){
            return 0;
        }
    }
    return 1;
}

void printRods(int* r1, int* r2, int* r3, int n){
    for(int i=0;i<20;i++)printf("=");
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\n", r1[i], r2[i], r3[i]);
    }

    for(int i=0;i<20;i++)printf("=");
    printf("\n");
}

void moveR1ToR2(int r1[], int r2[], int n, int* c1, int* c2){
    while(*c1){
        r2[*c2]=r1[*c1];
        r1[*c1]=0;
        (*c1)--;
        (*c2)++;
    }
}

void moveLastOfR1ToR3(int r1[], int r3[], int n, int* c1, int* c3){
    r3[*c3]=r1[0];
    r1[0]=0;
    (*c1)--;
    (*c3)++;
}

void moveR2ToR1(int r2[], int r1[], int n, int* c2, int* c1){
    while(*c2){
        r1[*c1]=r2[*c2];
        r2[*c2]=0;
        (*c2)--;
        (*c1)++;
    }
}

void ex4(){
    int err=0;

    printf("enter number of disks: \n");
    int n;
    
    do{
        err=scanf("%d", &n);
    }while(isError(err,1));

    int r1[n], r2[n], r3[n];
    for(int i=0;i<=n;i++){
        r1[i]=n-i;
        r2[i]=0;
        r3[i]=0;
    }

    int c1=n, c2=0, c3=0;

    while(!isInGoodOrder(r3, n)){
        printRods(r1,r2,r3,n);
        moveR1ToR2(r1, r2, n, &c1, &c2);
        printRods(r1,r2,r3,n);
        moveLastOfR1ToR3(r1,r3, n, &c1, &c3);
        printRods(r1,r2,r3,n);
        moveR2ToR1(r2, r1, n, &c2, &c1);
        printRods(r1,r2,r3,n);
    }
}

int main(int argc, char** argv){
    ex1();
    ex2();
    ex3();
    ex4();

    return 0;
}