#include <stdio.h>

int main(){
    int temp;
    printf("Give me the temperature\n");
    scanf("%d", &temp);
    if (temp > -10 && temp < 40 ){
        printf("\nTemperature is within the valid range");
    }
    else{
        printf("The temperature is not within the vailid range");
    }

    return 0;
}