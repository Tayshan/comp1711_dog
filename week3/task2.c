#include <stdio.h>

int main(){
    int num;
    printf("Give me a number\n");
    scanf("%d", &num);
    if ((num % 4 == 0) && (num % 5 == 0)){
        printf("\nYour number is divisible by 4 and 5 ");
    }
    return 0;
}