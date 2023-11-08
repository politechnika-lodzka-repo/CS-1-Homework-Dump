#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int x;

void breaker(){
    printf("\n=================\n\n");
}

void Tsk1() {
    float A, B, C, ß;
    printf("State A, B, C, ß: ");
    x = scanf("%f %f %f %f", &A, &B, &C, &ß);
    while( x != 4 || A <= 0 || B <= 0 || C <= 0 || ß<0) {
        printf("One of the paramiters was wrong, state them again: ");
        while((x=getchar()) != EOF && x!= '\n');
        x = scanf("%f %f %f, %f", &A, &B, &C, &ß);
    }
    float fx, dx, E;
    printf("state x0: ");
    x = scanf("%f", &fx);
    while( x != 1){
        while((x=getchar()) != EOF && x!= '\n');
        printf("Wrong Data! Try again\nstate x0: ");
        x = scanf("%f", &fx);
    }

    printf("State delta x: ");
    x = scanf("%f", &dx);
    while( x != 1 || dx<0){
        while((x=getchar()) != EOF && x!= '\n');
        printf("Wrong Data! Try again\nstate delta x: ");
        x = scanf("%f", &dx);
    }

    printf("state threshold: ");
    x = scanf("%f", &E);
    while(x != 1){
        while((x=getchar()) != EOF && x!= '\n');
        printf("Wrong Data! Try again\nstate threshold: ");
        x = scanf("%f", &E);
    }

    float W;
    char ch;
    printf("\tx\t|\tf(x)\n");
    do {
        W = (A * exp(x - ß)) / (B * fx * fx + C);
        printf("\t%g\t|\t%g\n", fx, W);
        fx -= dx;
    } while(W>E);
    //No idea how to do key presses
    breaker();
}

float W(int n){
    float fx=n;
    if(n%2==0) return x * 0.5 + (fx*fx);
    return (fx-5)*fx;
}

void print_results(int tab[], int a, int b){
    int n = b-a+1;
    printf("\tx\t|\tW(x)\n");
    for(int i=0 ; i<n ; i++) printf("\t%d\t|\t%d\n", i+a, tab[i]);
}

void Tsk2(){
    int a, b;
    printf("Calculating function values between a nad b\nstate a and b: ");
    x = scanf("%d %d", &a, &b);
    while( x != 2 || a<0 || b<0){
        while((x=getchar()) != EOF && x!= '\n');
        printf("one of the parimiters was wrong, try again\nstate a and b: ");
        x = scanf("%d %d", &a, &b);
    }
    int tab[(b-a)+1];
    for(int i=0 ; i<=b-a ; i++) tab[i] = W(i+a);

    print_results(tab, a, b);

    breaker();
}

bool isprime(int n){
    if(x<2) return 0;
    for(int i=2 ; i*i<=n ; i++) if(n%i == 0) return 0;
    return 1;
}

void Tsk3(){
    int a, b;
    printf("Calculating prime numbers, and numbers devisible by 23, in thwe range <a, b>\n");
    printf("state a and b: ");
    x = scanf("%d %d", &a, &b);
    while( x != 2 || a<0 || b<0){
        while((x=getchar()) != EOF && x!= '\n');
        printf("one of the parimiters was wrong, try again\nstate a and b: ");
        x = scanf("%d %d", &a, &b);
    }

    int n=b;
    int tab[n], p=2, i=0;
    while(i<n){
        if(isprime(p) || p%23 == 0){
            tab[i] = p;
            i++;
        }
        p++;
    }

    for(int i=0 ; i<=b ; i++){
        if(tab[i]<a) continue;
        if(tab[i]>b) break;
        printf("%d ", tab[i]);
    }

}

int main(){
    Tsk1();
    Tsk2();
    Tsk3();
}
