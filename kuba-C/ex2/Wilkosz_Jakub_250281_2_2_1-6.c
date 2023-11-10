#include<stdio.h>
#include<math.h>

void spacing(){
    printf("---------------------------------------\n\n");
}

void _1(){
    float sum=0;
    int n;

    printf("This program calculates the sum of n arbitrary real numbers\n");
    printf("Type in n: ");

    int validity_chceck=scanf("%d", &n);
    if(validity_chceck==0 || n<=0){
        printf("\nInvalid input, program terminated\n\n");
        while((validity_chceck = getchar()) != EOF && validity_chceck != '\n');
        spacing();
        return;
    }

    printf("Type in %d real numbers: ", n);

    float num;

    for(int i=0;i<n; i++){

        validity_chceck=scanf("%f", &num);
            if(validity_chceck==0){
                printf("\nInvalid input, program terminated\n\n");
                while((validity_chceck = getchar()) != EOF && validity_chceck != '\n');
                spacing();
            return;
        }
        else sum+=num;
    }

    printf("The sum is equal to: %f \n\n", sum);

    spacing();
}

void _2(){
    const float e=0.0001;
    float sum=0;
    float elem=0.5;
    int n=1;

    printf("This program calculates the sum of infinite series 1/(n*(n+1)) with an accuracy of %g\n", e);

    while(elem>e){
        elem=1.0/(n*(n+1));
        sum+=elem;
        n++;
    }

    printf("This sum is equal to %.4f\n\n", sum);

    spacing();
}

void _4(){
    int a=5,b=20;
    int sum1=0, sum2=0;

    printf("This program chcecks if all natural numbers in range <a, b> satisfy the inequality n^3 + 20n < 3n^2 +370 and prints out numbers that do not satisfy this inequality\n");
    printf("Type in a and b: ");

    int validity_chceck=scanf("%d%d", &a, &b);
    if(validity_chceck<2 || a<0 || b<0 || (a-b)>0){
        printf("\nInvalid input, program terminated\n\n");
        while((validity_chceck = getchar()) != EOF && validity_chceck != '\n');
        spacing();
        return;
    }

    for(int i=a; i<=b; i++){
        sum1=i*i*i+20*i;
        sum2=i*i*3+370;

        if(sum1>=sum2) printf("The inequality is not satisfied with the number %d\n",i); 
    }

    printf("\n");
    spacing();
}

void _5(){
    int natural=1;
    float formula_1=1.02;
    float formula_2=1000.0;

    printf("This program calculates the smallest natural number n that satisfies the inequality (1.02)^n > 1000*n^2\n");

    while(formula_1<formula_2){
        formula_1*=1.02;
        formula_2=1000.0*((float)natural*(float)natural);

        natural++;
    }

    if(formula_1<formula_2) printf("dupa\n");

    printf("Smallest natural is %d\n\n", natural);
    printf("This program also calculates the smallest natural number n that satisfies the inequality 1 + 1/2 + 1/3 + ... + 1/n > E where E is any positive number\n");

    int n=1;
    float E;
    float sum1=0.0;

    printf("Type in the value E: ");

    int validity_chceck=scanf("%f", &E);
    if(validity_chceck==0 || E<0){
        printf("\nInvalid input, program terminated\n\n");
        while((validity_chceck = getchar()) != EOF && validity_chceck != '\n');
        spacing();
        return;
    }

    while(sum1<=E){
        sum1+=(float)1/(float)n;
        n++;
    }

    printf("Smallest natural is %d\n\n", n);
    spacing();
}

void _6(){
    float num;
    float arthm_averege=0;
    int quantity=0, quantity_of_absolutes=0;
    int validity_chceck;

    printf("Enter the series of any real numbers. If number 0 is entered the program terminates\n");

    while(num!=0){
        validity_chceck=scanf("%f", &num);
        if(validity_chceck==0){
            printf("\nInvalid input\n\n");
            while((validity_chceck = getchar()) != EOF && validity_chceck != '\n');
            spacing();
            return;
        }

        if(fabs(num)<100 && num!=0){
            quantity_of_absolutes++;
        }

        if(num>0 && num!=0){
            arthm_averege+=num;
            quantity++;
        }

    }

    arthm_averege/=(quantity);

    printf("The arithmetic averege of the positive numbers of this series is equal to %g and the quantity of numbers that have their absolute value < 100 is equal to %d \n\n", arthm_averege, quantity_of_absolutes);

    spacing();
}

int main(){

    spacing();
    _1();
    _2();
    _4();
    _5();
    _6();

return 0;
}
