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

/*filename -> the name of the file that is being read
file/file2 -> the contents of the file being read
buffer_size -> how much of a line the program should read
buffer -> the contents of each line in the program
buffer2 -> the contents of each line that will be read in the program
numlines -> the number of lines in the program
date -> value for the date after being read
time -> exact value of the time after being read
steps -> the value of the steps after being read and separated from the other values
data -> a record of all the dates, times and steps
index -> the index of the value in the data array
 */
int numRecords(FILE *file){
    char buffer[buffer_size];
    int numLines = 0;
    while (fgets(buffer, buffer_size, file)){
        numLines++;
    }
    return numLines;
}

FILE* openFile(char filename[]){
    FILE *file = fopen(filename, "r") ;
    if (file == NULL){
        perror("File not opened corrrectly");
        exit;
    }
    return file;
}

LIST_DATA * listMaker (int numLines, FILE *file){
    char date [11];
    char time [6];
    char step [6];

    char buffer2[buffer_size];

    LIST_DATA data [numLines];
    int index = 0;

    while (fgets(buffer2, buffer_size, file)){
        tokeniseRecord(buffer2, ",", date,time,step);
        strcpy(data[index].date,date);
        strcpy(data[index].time,time);
        data[index].steps = atoi(step);
        index++;
    }

    return data;
}

int main() {

    char option;
    char fileName[10];
    LIST_DATA *dataList;
    int temp = 0;
    char tempDate[11] = "";
    char tempTime[6] = "";
    FILE *newFile;

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
            dataList = listMaker(numRecords(newFile), newFile);
            for (int i = 0; i < numRecords(newFile); i++){
                if (dataList[i].steps < dataList[temp].steps){
                    temp = i;
                }
            }
            printf("Fewest Steps: %s %s\n",dataList[temp].date,dataList[temp].time);
        }
        else if (option == 'D' || option == 'd')
        {
            dataList = listMaker(numRecords(newFile), newFile);
            for (int i = 0; i < numRecords(newFile); i++){
                if (dataList[i].steps > dataList[temp].steps){
                    temp = i;
                }
            }
            printf("Largest Steps: %s %s\n",dataList[temp].date,dataList[temp].time);
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

    FILE *file = openFile(fileName);
    int numLines = numRecords(file);

    char date [11];
    char time [6];
    char step [6];

    printf("Number of records in file: %d\n",numLines);

    fclose(file);

    FILE *file2 = openFile(fileName);

    char buffer2[buffer_size];

    LIST_DATA data [numLines];
    int index = 0;

    while (fgets(buffer2, buffer_size, file2)){
        tokeniseRecord(buffer2, ",", date,time,step);
        strcpy(data[index].date,date);
        strcpy(data[index].time,time);
        data[index].steps = atoi(step);
        index++;
    }

    for (int i = 0; i<3; i++){
        printf("%s/%s/%d\n",data[i].date,data[i].time,data[i].steps);
    }

    fclose(file2);
    return 0;
}