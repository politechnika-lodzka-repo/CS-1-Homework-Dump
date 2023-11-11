#include<stdio.h>
#include<math.h>

void spacing(){
    printf("---------------------------------------\n\n");
}

void _3(){

    int num_of_measurements;

    printf("This program that calculates the variance o^2 and standard deviation sqrt(o^2(x)) for m independent measurements x1, x2, ..., xm (m<200)\n");
    printf("Type in m: ");

    int validity_check = scanf("%d",&num_of_measurements);
    if(validity_check==0 || num_of_measurements>=200){
        while((validity_check = getchar()) != EOF && validity_check != '\n');
        spacing();
        return;
    }

    float measurements[num_of_measurements];
    float measurement_value;

    for(int i=0; i<num_of_measurements; i++){
        
        validity_check=scanf("%f",&measurement_value);
        if(validity_check==0){
            while((validity_check = getchar()) != EOF && validity_check != '\n');
            printf("\nInvalid data\n");
            spacing();
            return;
        }

        measurements[i]=measurement_value;
    }

    float delta_x;
    for(int i=0; i<num_of_measurements; i++){
        delta_x+=measurements[i];
    }

    delta_x/=(float)num_of_measurements;

    float variance;
    for(int i=0; i<num_of_measurements; i++){
        variance+=(measurements[i]-delta_x)*(measurements[i]-delta_x);
    }

    variance/=((float)num_of_measurements-1);

    float sqrt_of_variance=sqrt(variance);

    printf("The value of variance is equal to: %g and the value of sqrt(variance) is equal to: %g\n", variance,sqrt_of_variance);

    spacing();
}

int main(){

    spacing();
    _3();

return 0;
}
