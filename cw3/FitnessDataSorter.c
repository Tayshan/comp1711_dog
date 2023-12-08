#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define buffer_size 100

typedef struct {
	char date[11];
	char time[6];
	int steps;
} LIST_DATA;

FILE* readFile(char filename[]){

    FILE *file = fopen(filename, "r") ;
    return file;
}

FILE* writeFile(char filename[]){
    FILE *file = fopen(strcat(filename,".tsv"), "w") ;
    return file;
}

void tokeniseRecord(const char *input, const char *delimiter,char *date, char *time, char *steps) {
    char *inputCopy = strdup(input);
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    free(inputCopy);
}

int formatCheck(LIST_DATA * data){
    return 1;
} 


int numRecords(FILE *file){
    char buffer[buffer_size];
    int numLines = 0;
    while (fgets(buffer, buffer_size, file)){
        numLines++;
    }
    return numLines;
}

LIST_DATA *listMaker (FILE *file, LIST_DATA *data){
    char date [12];
    char time [7];
    char step [7];

    char buffer[buffer_size];

    int index = 0;

    while (fgets(buffer, buffer_size, file) != NULL){
        tokeniseRecord(buffer, ",", date,time,step);
        strcpy(data[index].date,date);
        strcpy(data[index].time,time);
        data[index].steps = atoi(step);
        index++;
    }
}

void sortList(LIST_DATA *data, int numRecs){

    int sorted = 0;
    int tempSteps;
    char tempTime[7];
    char tempDate[12];
    while (sorted == 0)
    {
        sorted = 1;
        for (int i = 1; i < numRecs; i++){
            if( data[i - 1].steps > data[i].steps)
            {
                tempSteps = data[i - 1].steps;
                strcpy(tempDate,data[i - 1].date);
                strcpy(tempTime,data[i - 1].time);

                data[i - 1].steps = data[i].steps;
                strcpy(data[i - 1].date,data[i].date);
                strcpy(data[i - 1].time,data[i].time);

                data[i].steps = tempSteps;
                strcpy(data[i].date,tempDate);
                strcpy(data[i].time,tempTime);

                sorted = 0;
            }
        }
    }

}

void writeToFile(LIST_DATA *data){
    
}

int main() {
    char fileName[20];
    printf("Enter Filename:\n");
    scanf("%s",fileName);

    FILE *dataFile = readFile(fileName);
    int numOfRecs = numRecords(dataFile);
    LIST_DATA dataList[numOfRecs];
    fclose(dataFile);

    if (dataFile == NULL){
        perror("File not opened corrrectly");
        return 1;
    }

    listMaker(dataFile, dataList);
    sortList( dataList, numOfRecs);

    FILE *sortedFile = writeFile(fileName);



    return 0;
}