#include<stdio.h>

void breaker(){
    printf("\n\n=======================\n\n");
}

void Task1(){
    int n, x;
    printf("How many numbers you want to add: ");
    x = scanf("%d", &n);
    if(x != 1 || n<0) {
        printf("WRONG DATA");
        breaker();
        while((x=getchar()) != EOF && x!= '\n');
        return;
    }
    double sum=0, temp;
    while(n>0){
        x = scanf("%lf", &temp);
        if(x != 1){
            printf("WRONG DATA");
            breaker();
            while((x=getchar()) != EOF && x!= '\n');
            return;
        }
        sum += temp;
        n-=1;
    }
    printf("Sum is equal to: %g", sum);

    breaker();
}

void Tk2(){
    float e = 0.0001;
    float sum=0, temp=0;
    float n=1;
    sum=1.0/(n*(n+1.0));
    n+=1;

    while((sum-temp)>e){
        temp=sum;
        sum+=1.0/(n*(n+1.0));
        n+=1.0;
    }

    printf("Sum of %g elements id equal to: %g", n-1, sum);


    breaker();
}

void Tk4(){
    printf("3n^3 +20n > 3n^2 +370");
    printf("\nState a and b: ");
    int a, b, x;
    x = scanf("%d %d", &a, &b);
    if( x!= 2){
        printf("WRONG DATA");
        breaker();
        while((x=getchar()) != EOF && x!= '\n');
        return;
    }

    int lside, rside;
    printf("The formula is wrong for values: ");
    for(int i=a ; i<=b ; i++){
        lside = 3 * (i*i*i) + (20 * i);
        rside = (3 * i * i) + 370;
        if(lside <= rside) printf("%d, ", i);
    }

    breaker();
}

void Tk5(){
    printf("a)\n\t(1.02)^n > 1000 n^2 for n =  ");
    int n=1, rside = 1000;
    float lside = 1.02;
    while(1){
        if(lside > rside){
            printf("%d", n);
            break;
        }
        n+=1;
        lside *= 1.02;
        rside = 1000 * n * n;
    }

    printf("\nb)\n\t1+1/2+1/3+...+1/n > E");
    printf("\n\tState E: ");
    double E;
    int x = scanf("%lf", &E);
    if(x != 1 || E<0){
        printf("\tWRONG DATA");
        breaker();
        while((x=getchar()) != EOF && x!= '\n');
        return;
    }
    double sum = 0;
    int m=1;

    while(sum<E){
        sum+=(1.0/(float)m);
        m+=1;
    }
    printf("\tformula is true for n = %d", m);

    breaker();
}

void Tk6(){
    printf("give an array of numbers, finish with 0: ");
    double input, sum=0;
    int quan=0, q100=0, x;
    while(1){
        x = scanf("%lf", &input);
        if(x!= 1){
            printf("WRONG DATA");
            breaker();
            while((x=getchar()) != EOF && x!= '\n');
            return;
        }
        if(input == 0) break;
        if(input > 0 ){
            sum+=input;
            quan+=1;
        }
        if(input > -100 && input < 100 ) q100+=1;
    }
    double average = sum / quan;
    printf("Arithmetic average of positive numbers is: %g", average);
    printf("\nQuantity of numbers with absolute value lower than 100 is: %d", q100);

    breaker();
}

int main() {
    Task1();
    Tk2();
    Tk4();
    Tk5();
    Tk6();
}