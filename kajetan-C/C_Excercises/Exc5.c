#include<stdio.h>
#include<stdbool.h>

void breaker(){
    printf("\n\n============================\n\n");
}

bool IsPrime(int n){
    if(n<2) return 0;
    for(int i=2 ; i*i<=n ; i++) if(n%i == 0) return 0;
    return 1;
}

void Tsk1(){
    int arr[20][2], a, x;
    printf("state a (0 < a < 1000): ");
    x = scanf("%d", &a);
    while(x != 1 || a>=1000 || a<1){
        printf("wrong data!\nstate a: ");
        if(x != 1) while((x=getchar()) != EOF && x!='\n');
        x = scanf("%d", &a);
    }

    int i=0;
    a+=1;
    while(i<20){
        if(IsPrime(a) && IsPrime(a+2)){
            arr[i][0] = a;
            arr[i][1] = a+2;
            i+=1;
        }
        a+=1;
    }

    for(int i=0 ; i<20 ; i++) printf("%d. %d %d\n", i+1, arr[i][0], arr[i][1]);
    breaker();
}

void Tsk2(int x1, int x2){
    int p;
    int a, b;
    for(int i=x1 ; i<=x2 ; i+=2){
        a = i;
        b = 0;
        do{
            a -= 1;
            b += 1;
        }while(!(IsPrime(a) && IsPrime(b)));
        printf("%d = %d + %d\n", i, a, b);
    }
    breaker();
}

void Tsk3(){
    int x1, x2, p, x;
    printf("choose range [x1, x2]: ");
    x = scanf("%d %d", &x1, &x2);
    while(x != 2){
        while((x=getchar()) != EOF && x!='\n');
        printf("Wrong data!\nchoose range[x1, x2]: ");
        x = scanf("%d %d", &x1, &x2);
    }

    printf("1 - all primes in range \n2 - all twin primes in range\n3 - veryfi golbach conjecture in range\n choose operation: ");
    x = scanf("%d", &p);
    while(x != 1 || p<1 || p>3){
        if(x != 1)while((x=getchar()) != EOF && x!='\n');
        printf("Wrong data!\nchoose operation: ");
        x = scanf("%d", &p);
    }
    while(x1<2) x1+=1;
    switch(p){
        case 1:{
            printf("primes in range:\n");
            for(int i=x1 ; i<=x2 ; i++) if(IsPrime(i)) printf("%d, ", i);
        }break;
        case 2:{
            printf("twin primes in range:\n");
            for(int i=x1 ; i<=x2-2 ; i++) if(IsPrime(i) && IsPrime(i+2)) printf("{%d, %d}, ", i, i+2);
        }break;
        case 3:{
            printf("Golbach's conjecture in range:\n");
            while(x1<3) x1+=1;
            for(int i=x1 ; i<=x2 ; i++){
                if(i%2 == 1) continue;
                int a=i, b=0;
                do{
                    a-=1;
                    b+=1;
                }while(!(IsPrime(a) && IsPrime(b)));
                printf("%d = %d + %d\n", i, a, b);
            }break;
            default: printf("wrong data");
        }
    }
}

int main(){
    Tsk1();
    Tsk2(4, 42);
    Tsk3();
}
