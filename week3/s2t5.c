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

/*char stringCat(char st[100], int strLength1, char st2[100], int strLength2){
    char newString[] = st[];
    int index2 = 0;
    newString[strLength1] = " ";
    for (int i = strLength1 + 1; i < (strLength1 + strLength2); i++){
        newString[i] = st2[index2];
        index2 ++;
    }
    return newString[100];
}*/


int main(){
    char st[100];
    char st2[100];
    printf("please enter a phrase\n");
    scanf("%s", st);
    printf("please enter another phrase\n");
    scanf("%s", st2);
    int strLength1 = length(st);
    int strLength2 = length(st2);
    //char catString[100] = stringCat(st[100],strLength1,st2[100],strLength2);
    char newString[100];
    for (int i = 0; i < strLength1; i++)
    {
        newString[i] = st[i];
    }
    newString[strLength1 + 1] = ' ';
    int i2;
    i2 = 0;
    for (int i3 = strLength1 + 2; i3 < (strLength1 + strLength2 + 1); i3++){
        newString[i3] = st2[i2];
        printf("%s",newString);
        i2 ++;
    }
    printf("Your new string is %s",newString);
}