#include<stdio.h>
#include<math.h>

void Tsk2(){
    int m, y;
    printf("state m: ");
    y = scanf("%d", &m);
    if( y != 1 || m>=200) {
        printf("Wrong data!");
        while((y=getchar()) != EOF && y!= '\n');
        return;
    }
    int x[m], temp=0, sum=0;
    float avg_x;
    printf("state data: ");

    for(int i=0 ; i<m ; i+=1){
        y = scanf("%d", &temp);
        if( y != 1){
            printf("Wrong data!");
            while((y=getchar()) != EOF && y!= '\n');
            return;
        }
        x[i]=temp;
        sum+=temp;
    }

    avg_x = ((1.0)/(float)m) * sum;

    float ro, sum2, coof = (1.0 / (float)(m-1));
    for(int i=0 ; i<m ; i++) sum2 += pow(((float)x[i]-avg_x), 2.0);
    ro = coof * sum2;
    printf("variance is: %g\nStandard deviation is: %g", ro, sqrt(ro));

}

int main(){
    Tsk2();
}