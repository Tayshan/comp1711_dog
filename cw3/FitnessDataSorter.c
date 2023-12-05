#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define buffer_size 100

typedef struct {
	char date[11];
	char time[6];
	int steps;
} LIST_DATA;

FILE* openFile(char filename[]){
    FILE *file = fopen(filename, "r") ;
    return file;
}

void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

LIST_DATA *listMaker (FILE *file, LIST_DATA *data){
    char date [12];
    char time [7];
    int step;

    char buffer[buffer_size];

    int index = 0;

    while (fgets(buffer, buffer_size, file) != NULL){
        tokeniseRecord(buffer, ",", date,time,step);
        strcpy(data[index].date,date);
        strcpy(data[index].time,time);
        data[index].steps = step;
        index++;
    }
}

int main() {
    char fileName[20];
    printf("Enter Filename:\n");
    scanf("%s",fileName);
    FILE *dataFile = openFile(fileName);
    if (dataFile == NULL){
        perror("File not opened corrrectly");
        return 1;
    }



    return 0;
}