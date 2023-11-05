#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <termios.h>

const float e=2.71828;

char getch(void)
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    //printf("%c\n", buf);
    return buf;
 }

float func1(float A, float B, float C, float x){
    float up=A*pow(e, -B*x);
    float down=B*x*x+C;
    if(down!=0)return up/down;
    return 0.0f;
}

float W(int n){
    if(n%2==0){
        return 1/2*n+n*n;
    }else{
        return (n-5)*n;
    }
}

void printResult(int n, float W){
    printf("n value: %d \t W(n) value: %f\n", n, W);
}

int isPrime(int n){
    if(n==1)return 0;
    for(int i = 2; i*i<=n ;i++){
        if(n%i==0)return 0;
    }
    return 1;
}

void clear(){
    while ( getchar() != '\n' );
}

int isError(int status, int expectedNOfArguments){
    clear();
    int res = status==EOF || status!=expectedNOfArguments;
    if(res)printf("warning, invalid data!\n");
    return res;
}

int main(void){
    int err=0;
    
    float A,B,C;

    printf("1. Provide parameters A,B and C:\n");
    do{
        err=scanf("%f%f%f", &A,&B,&C);
    }while(isError(err, 3));

    float dx, E;
    if(A>0 && B>0 && C>0){
        printf("enter dx: \n");
        do{
            err=scanf("%f", &dx);
        }while(isError(err, 1));

        printf("enter epsilon: \n");
        do{
            err=scanf("%f", &E);
        }while(isError(err, 1));

    }else {
        printf("parameters should not be non positive, aborting\n");
    }

    for(float x=0;func1(A,B,C,x)>=E; x+=dx){
        printf("value of x: %f \t value of f(x): %f\n", x, func1(A,B,C,x));
        getch();
    }
    
    int a,b;
    printf("2. enter range boundaries a and b:");

    do{
        err=scanf("%d%d", &a,&b);
    }while(isError(err, 2));
    
    for(int i=a;i<=b;i++){
        printResult(i, W(i));
    }

    int p;
    printf("3. enter a number to check wether it is prime: \n");

    do{
        err=scanf("%d", &p);
    }while(isError(err, 1));
    
    if(isPrime(p)){
        printf("%d is prime\n", p);
    }else{
        printf("%d is not prime\n", p);
    }

    printf("2. enter range boundaries a and b:");
    
    do{
        err=scanf("%d%d", &a,&b);
    }while(isError(err, 2));

    int arr[b];
    for(int i=a;i<=b;i++){
        if(i%23==0 || isPrime(i))arr[i]=i;
        else arr[i]=0;
    }

    for(int i=a; i<=b; i++){
        if(arr[i]!=0)printf("%d, ", arr[i]);
    }
    printf("\n");

    return 0;
}

