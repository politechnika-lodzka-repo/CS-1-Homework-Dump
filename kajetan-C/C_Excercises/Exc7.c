#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<limits.h>

void breaker(){
    printf("\n=================\n");
}

void printarr(int tab[], int n){
    for(int i=0 ; i<n ; i++) printf("%d, ", tab[i]);
}

void swap(int *a, int *b){
    int t=*a;
    *a = *b;
    *b = t;

}

void bbSort(int t[], int n){
    for(int i=0 ; i<n ; i++){
        for(int j=i ; j<n ; j++) if(t[i] > t[j]) swap(&t[i], &t[j]);
    }
}

void iSort(int tab[], int n){
    int p;
    for(int i=1 ; i<n ; i++){
        p = i;
        while(tab[p]<tab[p-1] && p>0){
            swap(&tab[p], &tab[p-1]);
            p--;
        }
    }
}

void simpleSort(int tab[], int n){
    int t2[n];
    for(int i=0 ; i<n ; i++) t2[i] = tab[i];

    int s, p;
    for(int i=0 ; i<n ; i++){
        s = INT_MAX;
        for(int j=0 ; j<n ; j++) if(t2[j]<s){
                s = t2[j];
                p = j;
            }
        t2[p] = INT_MAX;
        tab[i] = s;
    }
}

void Tsk1(){
    int n=100;
    int tab[n];
    printf("Array of size 100:\n");
    for(int i=0 ; i<n ; i++) tab[i] = (rand()%1000)+1;
    printarr(tab, n);
    printf("\nSorted array:\n");
    bbSort(tab, n);
    printarr(tab, n);

    breaker();
}

void Tsk2(){
    int n, x;
    printf("How many numbers: ");
    x = scanf("%d", &n);
    while(x != 1 || n < 1){
        if(x != 1) while((x=getchar()) != EOF && x != '\n');
        printf("Wrong data!\nHow many numbers: ");
        x = scanf("%d", &n);
    }

    printf("enter the numbers: ");
    int p, tab[n];
    for(int i=0 ; i<n ; i++){
        x = scanf("%d", &p);
        while(x != 1){
            while((x=getchar()) != EOF && x!='\n');
            printf("not a number, try again: ");
            x = scanf("%d", &p);
        }
        tab[i] = p;
    }

    printf("Unsorted array:\n");
    printarr(tab, n);
    iSort(tab, n);
    printf("\nSorted Array:\n");
    printarr(tab, n);

    breaker();
}

void Tsk3(){
    char c;
    int n, x;
    printf("How many numbers: ");
    x = scanf("%d", &n);
    while(x != 1 || n < 1){
        if(x != 1) while((x=getchar()) != EOF && x != '\n');
        printf("Wrong data!\nHow many numbers: ");
        x = scanf("%d", &n);
    }
    while((x = getchar()) != EOF && x != '\n');

    printf("choose input method (k - keyboard ; r - random): ");
    //x = scanf("%c", &c);
    c = getchar();
    while(c  != 'k' & c != 'r'){
        //while((c = getchar()) != EOF && c != '\n');
        printf("wrong data!\nChoose method: ");
        scanf("%c", &c);
    }
    while((x = getchar()) != EOF && x != '\n');
    int tab[n];
    switch(c){
        case 'k':{
            printf("enter the numbers: ");
            int p;
            for(int i=0 ; i<n ; i++){
                x = scanf("%d", &p);
                while(x != 1){
                    while((x=getchar()) != EOF && x!='\n');
                    printf("not a number, try again: ");
                    x = scanf("%d", &p);
                }
                tab[i] = p;
            }
        } break;
        case 'r': for(int i=0 ; i<n ; i++) tab[i] = (rand()%1000)+1; break;
        default: printf("Something went REAAAALY wrong");
    }

    printf("Select sorting method (b - bubble sort ; i - insertion sort): ");
    scanf("%c", &c);
    while(c!= 'b' && c!= 'i'){
        while((c = getchar()) != EOF && c != '\n');
        printf("wrong data!\nChoose method: ");
        scanf("%c", &c);
    }
    while((x = getchar()) != EOF && x != '\n');

    printf("Unsorted Array:\n");
    printarr(tab, n);

    switch(c){
        case 'b': bbSort(tab, n); break;
        case 'i': iSort(tab, n); break;
        default: printf("Something is reaaaaly WRONG. AGAIN");
    }

    printf("\nSorted array:\n");
    printarr(tab, n);

    breaker();
}

void Tsk4(){
    printf("simple sort demonstration\nUnsorted radnomised array:\n");
    int n=10;
    int tab[n];
    for(int i=0 ; i<n ; i++) tab[i] = rand()%1000 + 1;
    printarr(tab, n);
    simpleSort(tab, n);
    printf("\n")
    printarr(tab, n);
}

int main(){
    srand(time(0));
    //Tsk1();
    //Tsk2();
    //Tsk3();
}