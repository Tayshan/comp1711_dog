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
    FILE *file = fopen(filename, "r") ;
    return file;
}

LIST_DATA *listMaker (int numLines, FILE *file, LIST_DATA *data){
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

void dateFinder(LIST_DATA *data,int *startDate,int *endDate,int numOfRecs){
    int currStreak = 0;
    int streakOngoing = 0;
    int startStreak, endStreak, temp;
    int streakCheck = 1;
    int prevStreak = -1;
    for (int i = 0; i < numOfRecs; i++){
        if (data[i].steps > 500){
            if (streakCheck == 1){
                startStreak = i;
                streakCheck = 0;
            }
            currStreak++;
            streakOngoing = 1;
        }
        else{
            if (streakOngoing == 1)
            {          
                endStreak = i;
                temp = startStreak;
                streakCheck = 1;
                streakOngoing = 0;
                if (prevStreak < currStreak){
                    prevStreak = currStreak;
                    *startDate = temp;
                    *endDate = endStreak;
                }
                currStreak = 0;  
            }
        }
    }

}

int main() {

    char option;
    char fileName[10];
    int temp = 0;
    char tempDate[11] = "";
    char tempTime[6] = "";
    int totRecs;
    FILE *newFile;
    FILE *newFile2;
    FILE *newFile3;
    FILE *newFile4;
    FILE *newFile5;

    while ( option != 'Q' || option != 'q'){
        printf("Select Menu Option:\nA: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the data and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Exit\n\n");
        scanf(" %c", &option);

        if (option == 'A' || option == 'a')
        {
            printf("Enter the filename:\n");
            scanf("%s", fileName);
            newFile = openFile(fileName);
            if (newFile == NULL){
                perror("File not opened corrrectly");
                return 1;
            }
            totRecs = numRecords(newFile);
        }
        else if (option == 'B' || option == 'b')
        {
            printf("Total records: %d\n",totRecs);
        }
        else if (option == 'C' || option == 'c')
        {
            newFile2 = openFile(fileName);
            LIST_DATA dataList[totRecs];
            listMaker(totRecs,newFile2, dataList);
            for (int i = 1; i < totRecs; i++){
                if (dataList[i].steps < dataList[temp].steps){
                    temp = i;
                }
            }
            printf("Fewest steps: %s %s\n",dataList[temp].date,dataList[temp].time);
            fclose(newFile2);
        }
        else if (option == 'D' || option == 'd')
        {
            newFile3 = openFile(fileName);
            LIST_DATA dataList2[totRecs];
            listMaker(totRecs,newFile3, dataList2);
            for (int i = 1; i < totRecs; i++){
                if (dataList2[i].steps > dataList2[temp].steps){
                    temp = i;
                }
            }
            printf("Largest steps: %s %s\n",dataList2[temp].date,dataList2[temp].time);
            fclose(newFile3);
        }
        else if (option == 'E' || option == 'e')
        {
            char date [11];
            char time [6];
            char step [6];
            int meanRounded;
            float mean;
            newFile4 = openFile(fileName);
            float totSteps;
            char buffer[buffer_size];

            int index = 0;

            while (fgets(buffer, buffer_size, newFile4) != NULL){
                tokeniseRecord(buffer, ",", date,time,step);
                totSteps += atoi(step);
            }
            mean = totSteps/totRecs + 0.5;
            meanRounded = (int)(mean);
            printf("Mean step count: %d\n",meanRounded);
            fclose(newFile4);
        }
        else if (option == 'F' || option == 'f')
        {
            int start,end;
            newFile5 = openFile(fileName);
            LIST_DATA dataList3[totRecs];
            listMaker(totRecs,newFile5, dataList3);
            dateFinder(dataList3,&start,&end,totRecs);
            printf("Longest period start: %s %s\n",dataList3[start].date,dataList3[start].time);
            printf("Longest period end: %s %s\n",dataList3[end - 1].date,dataList3[end - 1].time);
            fclose(newFile5);
        }
        else if (option == 'Q' || option == 'q')
        {
            return 0;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
    return 0;
}