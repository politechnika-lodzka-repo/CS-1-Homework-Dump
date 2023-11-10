#include<stdio.h>
#include<math.h>

void breaker(){
    printf("\n\n===========================\n\n");
}

void Excercise1(){
    char str[100];
    printf("Enter your text: ");
    fgets(str, 100, stdin);
    fflush(stdin);
    printf("your Text %s", str);

    breaker();
}

void Exc2(){
    printf("Choose a figure (1 - Triangle, 2 - Rectangle, 3 - Square, 4 - Circle): ");
    int n;
    scanf("%d", &n);
    float a, b, c;
    switch(n){

        case 1:{
            printf("State base and height values: ");
            scanf("%f %f", &a, &b);
            c = a * b;
            c*=0.5;
            printf("%g", c);
        } break;

        case 2:{
            printf("State height and length values: ");
            scanf("%f %f", &a, &b);
            c=a*b;
            printf("%g", c);
        }break;

        case 3:{
            printf("State the length of the sides: ");
            scanf("%f", &a);
            c=a*a;
            printf("%g", c);
        }break;

        case 4:{
            printf("State the radius: ");
            scanf("%f", &a);
            c = a*a*3.14;
            printf("%g", c);
        } break;

        default: printf("wrong number");

    }
    breaker();
}

void Exc3(){
    float a, b;
    printf("Give two nubers you want to average: ");
    scanf("%f %f", &a, &b);
    float c=(a+b)/2.0;
    printf("%g", c);
    breaker();
}

void Exc4(){
    printf("VERYFYING THE IDENTITY (a+b)(a-b)=a^2-b^2\nState a nd b: ");
    float a, b;
    scanf("%f %f", &a, &b);
    float s1, s2;
    s1=(a+b)*(a-b);
    s2=(a*a)-(b*b);
    //printf("(a+b)(a-b) = (%f", a, "+ %f", b, ")( %f", a, " - %f", b, ")");
    printf("(a+b)(a-b) = (%g + %g)(%g - %g) = ", a, b, a, b);
    printf("%g * %g = ", a+b, a-b);
    printf("%g", s1);

    printf("\na^2 - b^2 = %g^2 - %g^2 = %g - %g = %g", a, b, a*a, b*b, s2);

    if(s1==s2) printf("\nThe numbers are equal, the expression is true");

    breaker();
}

void Exc5(){
    printf("Provide the values of legs of a right triangle a, b, c (where c is the hypotenuse): ");
    double a, b, c;
    scanf("%lf%lf", &a, &b);
    c=sqrt ((a*a)+(b*b));
    printf("The hypotenuse length is: %g\n", c);
    double alph, bet;
    alph=atan(a/b) * 180.0 / M_PI;
    bet=atan(b/a) * 180.0 / M_PI;
    printf("Angle between a and c: %g\nAngle between b and c: %g", bet, alph);

    breaker();
}

void Exc6() {
    float x;
    printf("give x value for the function f(x): ");
    scanf("%f", &x);
    //printf("|||%f|||\n", x);
    float y;
    if(x>=(-5) && x<=5) y = (2*(x*x) + (3*x) -1);
    else y =  ((x+5)*(x+5)-10);
    printf("%g", y);

    breaker();
}

int main(){
    Excercise1();
    Exc2();
    Exc3();
    Exc4();
    Exc5();
    Exc6();
    return 0;
}
