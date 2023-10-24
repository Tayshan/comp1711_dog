#include <stdio.h>

int length(char string[100]){
    int numChar = 0;
    int index = 0;
    char checker = string[0];
    while (checker != '\0'){
        numChar ++;
        index ++;
        checker = string[index];
    }

    return numChar;
}

int main(){
    char st[100];
    printf("please enter a phrase\n");
    scanf("%s", st);
    int strLength;
    strLength = length(st);
    printf("\n your string has %d characters", strLength);
}