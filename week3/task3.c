#include <stdio.h>

int main(){
    int grade;
    printf("Give me your grade\n");
    scanf("%d", &grade);
    if (grade < 50){
        printf("\nYou failed tut tut ");
    }
    else if (grade >= 50 && grade < 70){
        printf("\nCONGRATS ... you passed");
    }
    else if (grade > 69){
        printf("Ayyyyy your smart you got a distinction!!!");
    }
    return 0;
}