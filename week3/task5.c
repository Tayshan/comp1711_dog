#include <stdio.h>

int main(){
    int input;
    printf("Menu Options\nStarters(1):\nMains(2):\nDesserts(3):\nRefreshments(4)\nBill(5)\n");
    scanf("%d", &input);
    switch (input)
    {
        case 1: printf("Here are the starters");
        break;
        case 2: printf("Here are the mains");
        break;
        case 3: printf("Here are the desserts");
        break;
        case 4: printf("Here are the refreshments");
        break;
        case 5: printf("Here's the bill");
        break;
        default: printf("You didnt select a valid option");
    }



    return 0;
}