#include <stdio.h>

int isPrime(int num){
    int checker = num - 1;
    while (checker != 1){
        if (num % checker == 0)
        {
            return 0;
        }
        checker --;
    }
    return 1;
}

int main(){
    printf("Gimme a number\n");
    int num;
    scanf("%d",&num);
    printf("\nThe result from the function is ...... %d ", isPrime(num));

}