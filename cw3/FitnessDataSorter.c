#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"
#define buffer_size 100

typedef struct {
	char date[11];
	char time[6];
	int steps;
} LIST_DATA;

FILE* readFile(char filename[]){
    FILE *file = fopen(filename, "r");
    return file;
}

FILE* writeFile(char filename[]){
    FILE *file = fopen(strcat(filename,".tsv"), "w") ;
    return file;
}


int formatCheck(LIST_DATA *data, int numLines){
    int passCheck = 1;
    for (int i = 0; i < numLines; i++){
        if(strchr(data[i].date,'-') == NULL ||strchr(data[i].time,'-') != NULL ){
            passCheck = 0;
        }
        if(strchr(data[i].time,':') == NULL ||strchr(data[i].date,':') != NULL ){
            passCheck = 0;
        }
        if(data[i].steps == 0){
            passCheck = 0;
        }
    }
    return passCheck;
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
            if( data[i - 1].steps < data[i].steps)
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

void writeToFile(LIST_DATA *data, int numRecs, FILE *newFile){
    for (int index = 0; index < numRecs; index++){
            fprintf(newFile,"%s\t%s\t%d\n",data[index].date,data[index].time,data[index].steps);
    }
}

int main() {
    char fileName[20];
    printf("Enter Filename:\n");
    scanf("%s",fileName);

    FILE *countFile = readFile(fileName);
    if (countFile == NULL){
        perror("Error: invalid file");
        return 1;
    }
    int numOfRecs = numRecords(countFile);
    fclose(countFile);
    FILE *dataFile = readFile(fileName);
    LIST_DATA dataList[numOfRecs];

    listMaker(dataFile, dataList);
    fclose(dataFile);

    if (formatCheck(dataList, numOfRecs) == 0){
        perror("Error: invalid file");
        return 1;
    }

    sortList(dataList, numOfRecs);
    FILE *sortedFile = writeFile(fileName);
    writeToFile(dataList,numOfRecs,sortedFile);
    fclose(sortedFile);


    return 0;
}