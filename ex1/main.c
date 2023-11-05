#include <stdio.h>
#include <math.h>

double f(double x){
    if(x >= -5 && x <= 5){
        return 2*x*x + 3*x -1;
    }
    return (x+5)*(x+5)-1;
}

double radToDegrees(double r){
    return 180*r/3.14;
}

int main(int argc, char** argv){
    int err=0;

    char input[100];
    size_t maxInputLength=100;


    printf("Enter the text from the keyboard: %s\n", "Sample text");
    fgets(input, maxInputLength, stdin);

    printf("An area of a rectangle 10x20 is: %d\n", 10*20);

    printf("Enter two numbers to get an arithmetic avarage: \n");

    float inputA, inputB;
    scanf("%f%f", &inputA, &inputB);

    printf("An avarage of: %f and %f is: %f\n", inputA, inputB, (inputA + inputB)/2);

    printf("Verification of an equation (a+b)(a-b)=a2-b2: \n");
    printf("a: 10, b: 20 -> %d = %d\n", (10+20)*(10-20), 10*10-20*20);

    printf("Enter two lengths of a right angled trinangle: \n");
    float a,b;
    scanf("%f%f", &a, &b);
    float h = sqrt(a*a+b*b);
    printf("The hypotenuse is: %f\n", h);
    printf("The angles of the triangle are: %f\', %f\', %f\'\n", 90.0, radToDegrees(asin(a/h)), radToDegrees(asin(b/h)));

    float x;
    printf("Enter the value of x to evaluate f(x)\n");
    scanf("%f", &x);
    printf("f(%f) = %f\n", x, f(x));

    return 0;
}