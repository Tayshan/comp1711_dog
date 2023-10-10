#include <stdio.h>

int main() {
    char name [8];
    char revName[8] = "       ";
    printf("Gimme yo name\n");
    scanf("%s", name);
    printf("\n%s",name);
    for (int i = 0; i < 8; i++){
            revName[i] = name[7 - i];
            printf("\n%c", name[7 -i]);
            printf("\n%c", revName[i]);
    }
    //revName[8] = '\0';
    printf("\nHello , %s", revName);
    return 0;
}