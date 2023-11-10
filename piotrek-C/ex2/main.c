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

float ex1(float nums[], int n) {
    float res = 0.0;

    for(size_t i=0;i<n;i++){
        res+=nums[i];
    }
    return res;
}

float ex2(){
    float res=0.0, e;
    int n=1;
    do{
        e=1.0/(n*n+n);
        res+=e;
        n++;
    }while(e>=0.0001);

    return res;
}

float ex3(float nums[], int n){
    float avg=ex1(nums, n);
    float res=0.0;
    for(int i=1;i<=n;i++){
        res+=(nums[i-1]-avg)*(nums[i-1]-avg);
    }
    res*=1.0/(n-1);

    return res;
}

int ex4(int a, int b){
    if(a>b || a<0 || b<0)return -1;
    for(int i=a;i<=b;i++){
        if(i*i*i+20*i >= 3*i*i + 370) return i;
    } 

    return 0;
}

int ex5(){
    int res=1;
    float foo=1.02;
    float pow=1.02;
    while(pow <= 1000*res*res){
        pow*=foo;
        res++;
    }

    return res;
}

int main(int argc, char** argv){
    int err = 0;

    printf("ex1: enter number of numbers:\n");
    int n, m;
    do{
        err=scanf("%d", &n);
    }while(isError(err,1));

    m=n;
    float nums[n];

    printf("ex1: enter numbers (after newlines)\n");

    while(n--){
        float foo;
        do{
            err=scanf("%f", &foo);
        }while(isError(err,1));

        nums[n]=foo;
    }

    printf("ef1: sum of numbers is: %f\n", ex1(nums, m));
    (50);

    printf("ex2: %f\n", ex2());
    (50);

    printf("ex3: enter number of numbers:\n");
    
    do{
        err=scanf("%d", &n);
    }while(isError(err,1));

    m=n;

    float nums3[n];
    while(n--){
        float foo;
        
        do{
            err=scanf("%f", &foo);
        }while(isError(err,1));

        nums3[n]=foo;
    }

    printf("ex3: variance: %f\nex3: deviance: %f\n", ex3(nums3, m), sqrt(ex3(nums3, m)));
    (50);

    printf("ex4: enter two numbers to form a range [a,b]: \n");
    int a,b;
    do{
        err=scanf("%d%d", &a,&b);
    }while(isError(err,2));

    char str[100];
    int res=ex4(a,b);
    sprintf(str, "%d", res);

    printf("ex4: do all the numbers satisfy the formula: %s\n", (res==0 ? "true" : str));
    (50);

    printf("ex5: %d\n", ex5());
    (50);

    printf("ex6: enter number series terminate by zero: \n");

    float e5=-1;
    
    int cOfPositive=0;
    int cOfModUnder100=0;
    float sumOfPositive=0;

    while(e5!=0){
        do{
            err=scanf("%f", &e5);
        }while(isError(err,1));

        if(e5 > 0 ){
            cOfPositive++;
            sumOfPositive+=e5;
        }
        if(e5 < 100 && e5 > -100){
            cOfModUnder100++;
        }
    }

    printf("ex5: avarage of positive numbers: %f\nex5: number of numbers with abs under 100: %d\n", sumOfPositive/cOfPositive, cOfModUnder100);
    (50);


    return 0;
}