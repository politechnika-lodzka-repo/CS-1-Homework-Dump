#include<stdio.h>
#include<math.h>

const double EULER = 2.71828182845904523536;

void spacing(){
    printf("----------------------------------------------------------------------------------------------------\n");
}

void clear_stream(){
    int x;
    while((x = getchar()) != EOF && x != '\n');
}

float f(float x, float A, float B, float C, float beta){
    return (A*pow(EULER,-beta*x))/(B*x*x + C);
}

int w(int n){
    if(n%2==0){
        return n/2 +n*n;
    } else{
        return (n-5)*n;
    }
}

int is_prime(int num){
    if(num==1) return 0;
    if(num==2) return 0;
    for(int i=2; i*i<=num; i++){
        if(num % i == 0) return 0;
    }
    return 1;
}

void _1(){
    float A, B, C, beta, initial_x;
    float delta_x, epsilon;
    int validity_check;

    spacing();
    printf("This program tabulates the function f(x) whith the step delta x. It finishes tabulating when the value of the function decreases below threshold epsilon\n");
    printf("Type in A, B, C, beta that are the positive parameters of the function, the step delta x, the threshold epsilon and the initial x value: \n");

    validity_check = scanf("%f %f %f %f %f %f %f", &A, &B, &C, &beta, &delta_x, &epsilon, &initial_x);
    while(validity_check <6 || A<=0 || B<=0 || C<=0 || beta<=0){
        printf("\nInvalid input, provide input again:\n");
        clear_stream();
        validity_check = scanf("%f %f %f %f %f %f %f", &A, &B, &C, &beta, &delta_x, &epsilon, &initial_x);
    }
    
    printf("The values of function are:\n");
    clear_stream();

    printf("\nPress ENTER to get the next page\n");
    for(float x=initial_x; f(x,A,B,C,beta)>=epsilon;){
        char input = getchar();

        if(input==10){
            printf("for x = %g \t f(x) = %g\n",x,f(x,A,B,C,beta));
            printf("\nPress ENTER to get the next page\n");
            x+=delta_x;
        }
    }

    spacing();
}

void _2(){
    int a, b;
    int validity_check;

    spacing();
    printf("This program puts the values of fuction w(n) into an array with values of n being natural numbers in range <a,b>\n");
    printf("Type in the natural values of a and b:\n");

    validity_check = scanf("%d %d", &a, &b);
    while(validity_check<2 || a<=0 || b<=0 || b<a){
        printf("\nInvalid input, provide input again\n");
        clear_stream();
        validity_check = scanf("%d %d", &a, &b);
    }

    int arr[b-a+1];
    for(int n=a, i=0; n<=b; n++, i++){
        arr[i]=w(n);
    }

    for(int i=0; i<b-a+1; i++){
        printf("for n=%d \t w(n)=%d\n", i+a, arr[i]);
    }

    spacing();
}

void _3(){
    int a, b;
    int validity_check;

    spacing();
    printf("This program calculates the prime numbers and numbers divisible by 23 from range <a,b> and prints them\n");
    printf("Type in positive intigers a and b:\n");

    validity_check=scanf("%d %d", &a, &b);
    while(validity_check<2 || a<=0 || b<=0 || b<a){
        printf("\nInvalid input, provide input again\n");
        clear_stream();
        validity_check=scanf("%d %d", &a, &b);
    }

    printf("The numbers are: \n");

    for(int i=a; i<=b; i++){
        if(is_prime(i) || i%23==0) printf("%d\n", i);
    }    

    spacing();
}

 int main(){
    
    _1();
    _2();
    _3();

    return 0;
 }
