#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"
#define buffer_size 100

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} LIST_DATA;


int numRecords(FILE *file){
    char buffer[buffer_size];
    int numLines = 0;
    while (fgets(buffer, buffer_size, file)){
        numLines++;
    }
    return numLines;
}

FILE* openFile(char filename[]){
    FILE *file = fopen("FitnessData_2023.csv", "r") ;
    if (file == NULL){
        perror("File not opened corrrectly");
        exit;
    }
    return file;
}

LIST_DATA *listMaker (int numLines, FILE *file, LIST_DATA *data){
    printf("hello1");
    char date [11];
    char time [6];
    char step [6];

    char buffer[buffer_size];

    int index = 0;

    while (fgets(buffer, buffer_size, file) != NULL){
        printf("hello2");
        tokeniseRecord(buffer, ",", date,time,step);
        strcpy(data[index].date,date);
        strcpy(data[index].time,time);
        data[index].steps = atoi(step);
        index++;
        printf("%s %s %d /n",data[index].date, data[index].time, data[index].steps);
    }

}

int main() {

    char option;
    char fileName[10];
    int temp = 0;
    char tempDate[11] = "";
    char tempTime[6] = "";
    FILE *newFile;
    FILE *newFile2;

    while ( option != 'Q' || option != 'q'){
        printf("Select Menu Option:\nA: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the data and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Exit\n\n");
        scanf(" %c", &option);

        if (option == 'A' || option == 'a')
        {
            printf("Enter the filename:\n");
            scanf("%s", fileName);
            newFile = openFile(fileName);
        }
        else if (option == 'B' || option == 'b')
        {
            printf("Total records: %d\n", numRecords(newFile));
        }
        else if (option == 'C' || option == 'c')
        {
            char buffer[buffer_size];
            newFile2 = openFile(fileName);
            int a = numRecords(newFile);
            LIST_DATA dataList[a];
            printf("%s",fgets(buffer, buffer_size, newFile));
            listMaker(a,newFile, dataList);
            for (int i = 1; i < numRecords(newFile2); i++){
                if (dataList[i].steps < dataList[temp].steps){
                    temp = i;
                }
            }
            fclose(newFile2);
        }
        else if (option == 'D' || option == 'd')
        {
            //printf("Largest Steps: %s %s\n",dataList[temp].date,dataList[temp].time);//
        }
        else if (option == 'E' || option == 'e')
        {
        }
        else if (option == 'F' || option == 'f')
        {
        }
        else if (option == 'Q' || option == 'q')
        {
            exit;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
    return 0;
}