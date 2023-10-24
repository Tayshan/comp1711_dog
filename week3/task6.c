#include <stdio.h>

int main(){
    int cancel = 0;
    while (cancel != -1)
    {
        printf("\nPlease enter a number  ");
        scanf("%d",&cancel);
        if (cancel == -1){}
        else if (cancel > -1 && cancel < 101){
            printf("\nYour number is within the valid range");
        }
        else{
            printf("\nPlease enter a valid number");
        }
    }
}