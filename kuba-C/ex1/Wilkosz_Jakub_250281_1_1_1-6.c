#include<stdio.h>
#include<math.h>

void spacing(){
    printf("\n\n--------------------------------------------\n\n");
}

void _1(){
    spacing();

    char myString[100];
    printf("Enter text to display: ");
    fgets(myString, 100, stdin);
    printf("Your text: %s",myString);

    printf("\n--------------------------------------------\n\n");
}

void _2(){
    float a=10.5,b=15.3,h=4.2;
    printf("This program calculates the area of a trapezoid of which one base is equal to %g,\nthe other base is equal to %g\nand the height is equal to %g\n",a,b,h);
    printf("The area is equal to %g", ((a+b)/2)*h);

    spacing();
}

void _3(){
    float a,b;
    a=5;
    b=3.7;
    printf("The arithmetic average of numbers %g and %g is equal to %g", a,b, (a+b)/2);

    spacing();
}

void _4(){
    float a,b;
    a=15;
    b=3.4;
    float exp1, exp2;
    exp1=(a+b)*(a-b);
    exp2=(a*a)-(b*b);
    printf("The expression (a+b)*(a-b) is equal to %g\n", exp1);
    printf("The expression a^2 - b^2 is equal to %g\n", exp2);

    if(exp1==exp2){
        printf("Both expressions are equal to eachoter");
    }
    else printf("The expressions are not equal to eachother");

    spacing();
}

void _5(){
    float a,b,c;

    a=3;
    b=4;
    c=sqrt(a*a + b*b);

    float angle1, angle2;

    angle1=(atan(a/b)*180)/M_PI;
    angle2=(atan(b/a)*180)/M_PI;

    printf("The legs of the triangle are equal to %g and %g. The hypotenuse is equal to %g\n", a,b,c);
    printf("The angles of the triangle (in degrees) are equal to 90, %g, %g",angle1, angle2);

    spacing();
}

void _6(){
    float x=7;
    float value;

    if(x>=-5 && x<=5){
        value=2*(x*x)+(3*x)-1;
        printf("The value of function 2x^2+3x-1 for x equal to %g is %g", x, value);

    }else{
        value=(x+5)*(x+5)-10;
        printf("The value of function (x+5)^2-10 for x equal to %g is %g", x, value);
    }

    spacing();
}

int main(){

    _1();
    _2();
    _3();
    _4();
    _5();
    _6();

return 0;
}
