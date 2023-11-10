#include <stdio.h>
#include <string.h>

void spacing(){
    printf("----------------------------------------\n");
}

void clear_stream(){
    int x;
    while((x = getchar()) != EOF && x != '\n');
}

void _1(){
    int validity_chceck;

    spacing();
    printf("This program displays the names, surnames and adresses of n students(n<10)\n");
    printf("Type in n<10: ");
    int n;

    validity_chceck=scanf("%d",&n);
    while(validity_chceck==0 || n>=10 || n<0){
        printf("\nInvalid input\n\n");
        clear_stream();
        spacing();

        printf("Type in n<10 again: ");
        validity_chceck=scanf("%d",&n);
        spacing();
    }

    char names_surnames_adresses[n][3][32];

    spacing();


    printf("Type in %d names, surnames and adresses:\n",n);

    clear_stream();

    for(int i=0; i<n; i++){

        printf("Data of person No: %d: \n", i+1);

        validity_chceck=scanf("%s",names_surnames_adresses[i][0]);
        while(validity_chceck==0){
            printf("\nInvalid input\n\n");
            clear_stream();

            printf("Enter the name again: ");
            validity_chceck=scanf("%s",names_surnames_adresses[i][0]);
            spacing();
        }

        validity_chceck=scanf("%s",names_surnames_adresses[i][1]);
        while(validity_chceck==0){
            printf("\nInvalid input\n\n");
            clear_stream();

            printf("Enter the surname again: ");
            validity_chceck=scanf("%s",names_surnames_adresses[i][1]);
            spacing();
        }

        validity_chceck=scanf("%s",names_surnames_adresses[i][2]);
        while(validity_chceck==0){
            printf("\nInvalid input\n\n");
            clear_stream();

            printf("Enter the adress again: ");
            validity_chceck=scanf("%s",names_surnames_adresses[i][2]);
            spacing();
        }


    }

    printf("\nName:\tSurname:\tAdress:\n");
    spacing();

    for(int i=0; i<n; i++){
        names_surnames_adresses[i][0][strcspn(names_surnames_adresses[i][0],"\n")]='\0';
        names_surnames_adresses[i][1][strcspn(names_surnames_adresses[i][1],"\n")]='\0';
        names_surnames_adresses[i][2][strcspn(names_surnames_adresses[i][2],"\n")]='\0';
        printf("%s\t%s\t\t%s\n",names_surnames_adresses[i][0],names_surnames_adresses[i][1],names_surnames_adresses[i][2]);
    }
}

void _2(){
    int validity_chceck;

    spacing();
    printf("This program puts the elements of an A matrix of dimension n to k (n,k<20) into an array\n");
    printf("It then Calculates and displays matrix of the sum of the row elements and Calculates and displays matrix of the sum of the column elements\n\n");
    printf("Type in n<20 and k<20: \n");

    int n, k;

    validity_chceck=scanf("%d %d", &n, &k);
    spacing();

    while(validity_chceck==0 || n>=20 || k>=20){
        printf("\nInvalid input\n\n");
        clear_stream();
        spacing();

        printf("Type in n<20 and k<20 again: \n");
        validity_chceck=scanf("%d %d", &n, &k);
        spacing();
    }

    float matrix[n][k];

    printf("Type in values of the %d by %d matrix: \n\n", n, k);

    for(int i=0; i<n; i++){
        printf("\tNow typing in row %d of %d: \n", i+1, n);
        for(int j=0; j<k; j++){
            printf("Now typing in value %d of %d: \n", j+1, k);
            validity_chceck=scanf("%f",&matrix[i][j]);
            while(validity_chceck==0){
                spacing();
                printf("\nInvalid input\n");
                clear_stream();
                spacing();

                printf("Type the value again: \n");
                validity_chceck=scanf("%f",&matrix[i][j]);
            }
        }
    }

    spacing();

    printf("\nYour matrix looks like: \n\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            printf("%g\t",matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    spacing();

    float sum_of_rows[n];
    float sum_of_columns[k];

    for(int i=0; i<n; i++){
        float row_sum=0;
        for(int j=0; j<k; j++){
            row_sum+=matrix[i][j];
        }
        sum_of_rows[i]=row_sum;
    }

    for(int j=0; j<k; j++){
        float column_sum=0;
        for(int i=0; i<n; i++){
            column_sum+=matrix[i][j];
        }
        sum_of_columns[j]=column_sum;
    }

    printf("\nMatrix of sum of row elements: \n\n");
    for(int i=0; i<n; i++){
        printf("%g   ", sum_of_rows[i]);
    }

    printf("\n\nMatrix of sum of column elements: \n\n");
    for(int i=0; i<k; i++){
        printf("%g   ", sum_of_columns[i]);
    }

    printf("\n\n");
    spacing();
}

int main(){

    _1();
    _2();

return 0;
}
