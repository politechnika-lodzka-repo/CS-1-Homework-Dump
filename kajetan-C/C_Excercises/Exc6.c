#include<math.h>
#include<stdio.h>
#include<stdbool.h>

int itpower(int n){
    int p=1;
    for(int i = 1 ; i<=n ; i++) p*=i;
    return p;
}

int repower(int n){
    if(n < 2) return 1;
    else return n * repower(n-1);
}

void Tsk1(){
    int n, x;
    printf("Calculating n!\nenter n: ");
    x = scanf("%d", &n);
    while(x != 1 || n < 1){
        if(x != 1) while((x = getchar()) != EOF && x != '\n');
        printf("Wrong data!\nEnter n: ");
        x = scanf("%d", &n);
    }

    char ch;
    printf("choose type (i = iterative, r - recursive): ");
    while((x = getchar()) != EOF && x != '\n');
    scanf("%c", &ch);
    while(!(ch == 'i' || ch == 'r')){
        while((x = getchar()) != EOF && x != '\n');
        printf("Wrong data!\nchoose type (i = iterative, r - recursive): ");
        scanf("%c", &ch);
    }

    switch (ch) {
        case 'i': printf("%d! = %d", n, itpower(n)); break;
        case 'r': printf("%d! = %d", n,repower(n)); break;
        default: printf("ERROR");
    }
}

int it2n(int n){
    if(n==0) return 1;
    int r = 1;
    for(int i=0 ; i<n ; i++) r *= 2;
    return r;
}

int re2n(int n){
    if(n == 0) return 1;
    else return (2 * re2n(n-1));
}

void Tsk2(){
    int x, n;
    bool pos = 1;
    printf("\nCalculating 2^n\nenter n: ");
    x = scanf("%d", &n);
    if(x != 1){
        while((x = getchar()) != EOF && x != '\n');
        printf("Wrong data!\nenter n: ");
        x = scanf("%d", &n);
    }

    if(n<0){
        n *= -1;
        pos = 0;
    }

    char ch;
    printf("choose type (i = iterative, r - recursive): ");
    while((x = getchar()) != EOF && x != '\n');
    scanf("%c", &ch);
    while(!(ch == 'i' || ch == 'r')){
        while((x = getchar()) != EOF && x != '\n');
        printf("Wrong data!\nchoose type (i = iterative, r - recursive): ");
        scanf("%c", &ch);
    }

    float pri;
    switch (ch) {
        case 'i': {
            if(pos){
                pri = (float)it2n(n);
                printf("2^%d = %g", n, pri);
            }
            else {
                pri = 1 / (float) (it2n(n));
                printf("2^-%d = %g", n, pri);
            }

        }break;
        case 'r': {
            if(pos){
                pri = (float)re2n(n);
                printf("2^%d = %g", n, pri);
            }
            else {
                pri = 1 / (float) (re2n(n));
                printf("2^-%d = %g", n, pri);
            }

        }break;
        default: printf("ERROR");
    }

}

int fib(int n){
    if(n == 1) return 2;
    if(n == 2) return 5;
    else return (fib(n-1)+fib(n-2));
}

void Tsk3(){
    int a, b, x;
    printf("\ngive range [ a : b ]: ");
    x = scanf("%d %d", &a, &b);
    while(x != 2){
        while((x = getchar()) != EOF && x != '\n');
        printf("Wrong Data!\ngive range: ");
        x = scanf("%d %d", &a, &b);
    }

    int n = 1, m;
    while(1){
        m = fib(n);
        if(m>b) break;
        if (m >= a) printf("%d, ", m);
        n++;
    }
    
}

void hanoitower(int n, char Arod, char Brod, char Srod){
    if(n==0) return;

    hanoitower(n-1, Arod, Srod, Brod);
    printf("Move disk %d from rod %c to rod %c\n", n, Arod, Brod);
    hanoitower(n-1, Srod, Brod, Arod);
}

void Tsk4(){
    int x, n;
    printf("\nCalculating Tower of hanoi\nenter number of discs: ");
    x = scanf("%d", &n);
    if(x != 1){
        while((x = getchar()) != EOF && x != '\n');
        printf("Wrong data!\nenter n: ");
        x = scanf("%d", &n);
    }

    hanoitower(n, 'A', 'B', 'S');

}

int main(){
    Tsk1();
    Tsk2();
    Tsk3();
    Tsk4();
}
