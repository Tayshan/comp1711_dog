#include <stdio.h>
#include <stdlib.h>

FILE *open_file(char filename[], char mode[]){
    FILE *file = fopen(filename, mode);
    if (file == NULL){
        perror("");
        exit(1);
    }
    return file;

}
int main () {   
    FILE* file = open_file("squares.dat","r");
    int buffer_size = 100;
    char buffer [buffer_size];
    int totalNum = 0;
    int count = 0;
    while ( fgets(buffer, buffer_size, file)){
        printf("%d\n",atoi(fgets(buffer, buffer_size, file)));
        totalNum += atoi(fgets(buffer, buffer_size, file));
        count++;
    }
    printf("%d\n%d\n",totalNum,count);
    float average = totalNum/count;
    printf("The average of all numbers is %f\n",average);


    fclose(file);
    return 0;
}