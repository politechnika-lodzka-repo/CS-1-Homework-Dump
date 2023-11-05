#include <stdio.h>
#include <math.h>

void clear(){
    while ( getchar() != '\n' );
}

int isError(int status, int expectedNOfArguments){
    clear();
    int res = status==EOF || status!=expectedNOfArguments;
    if(res)printf("warning, invalid data!\n");
    return res;
}

int isInvalidChoice(int choice){
    if(choice<1 || choice > 3){
        printf("invalid choice\n");
        return 1;
    }
    return 0;
}

int isPrime(int p){
    if(p<2)return 0;
    for(int i=2;i*i<=p;i++){
        if(p%i==0)return 0;
    }
    return 1;
}

void ex1(int a, int primePairs[]){
    int c=0;

    for(int i=a;c<20;i++){
        if(isPrime(i) && isPrime(i+2)){
            primePairs[2*c]=i;
            primePairs[2*c+1]=i+2;
            c++;
        }
    }
}

int goldbachs(int a){
    for(int i=2;i<=a-2;i++){
        if(isPrime(i) && isPrime(a-i)){
            return i;
        }
    }
    return 0;
}

void ex2(){
    for(int i=2;i<=40;i++){
        int isTrue=goldbachs(i);
        int p1,p2;
        if(isTrue){
            p1=isTrue;
            p2=i-p1;
            isTrue=1;
        }else {
            p1=0;
            p2=0;
        }
        printf("number: %d, true: %d, primes: %d,%d\n", i, isTrue, p1, p2);
    }
}

void ex3(){
    int err=0;
    int a,b;
    scanf("%d%d", &a, &b);
    printf("pick one:\n1. designate prime numbers\n2. designate twin primes\n3. verifies goldbach's conjecture\n");
    int choice;

    do{
        err=scanf("%d", &choice);
    }while(isError(err, 1) || isInvalidChoice(choice));

    if(choice<1 || choice > 3){
        printf("invalid choice\n");
        return;
    }

    switch(choice){
        case 1:
            printf("primes: \n");
            for(int i=a;i<=b;i++){
                if(isPrime(i)){
                    printf("%d, ", i);
                }
            }
            printf("\n");
        break;
        case 2:
            printf("prime pairs: \n");
            for(int i=a;i<=b;i++){
                if(isPrime(i) && isPrime(i+2)){
                    printf("(%d - %d), ", i, i+2);
                }
            }
            printf("\n");
        break;
        case 3:
            int isTrue=1;
            if(a%2)a++;
            if(b%2)b--;
            for(int i=a;i<=b;i+=2){
                if(!goldbachs(i)){
                    printf("this range doesnt satisfy golbachs conjecture [%d]\n", i);
                    return;
                }
            }
            printf("this range satisfies goldbachs conjecture\n");
        break;
    }
}

int main(int argc, char** argv){
    int err=0;


    printf("ex1:\nenter number\n");
    int a, primePairs[40];

    do{
        err=scanf("%d", &a);
    }while(isError(err, 1));

    if(a<1000){
        ex1(a, primePairs);
        for(int i=0;i<20;i++){
            printf("pair: %d - %d\n", primePairs[2*i], primePairs[2*i+1]);
        }
    }else {
        printf("invalid number\n");
    }

    printf("ex2:\n");

    ex2();

    printf("ex3:\n enter range (two numbers)\n");
    ex3();

}