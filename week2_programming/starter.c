#include <stdio.h>

int sort(int *sortNums){
    int temp;
    for (int i = 0; i < 5; i++){
        for (int a = 0; a < 4; a++){
            if (sortNums[a] > sortNums[a + 1]){
                temp = sortNums[a + 1];
                sortNums[a + 1] = sortNums[a];
                sortNums[a] = temp;
            }
        }
    }
    return sortNums[4];

}

int main () {
    int nums[5];
    for ( int a = 0; a < 5; a++){
        printf("Enter a number pls\n");
        scanf("%d", &nums[a]);
    }
    
    printf("\n The biggest number is\n%d",sort(nums));
}