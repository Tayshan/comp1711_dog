#include <stdio.h>

'int main(){
    int num;
    printf("Give me a number\n");
    scanf("%d", &num);
    if (num == 0){
        printf("\nYour number is 0 ");
    }
    else if(num < 0){
        printf("\nYour number is negative ");
    }
    else{
        printf("\nYour number is positive");
    }
    return 0;
}'

