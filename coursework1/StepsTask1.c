#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
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



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
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
    
    // Free the duplicated string
    free(inputCopy);

}

int main() {
    char filename [] = "FitnessData_2023.csv" ;
    FILE *file = fopen(filename, "r") ;
    if (file == NULL){
        perror("");
        return 1;
    }
    
    int buffer_size = 100;
    char buffer[buffer_size];
    int numLines = 0;
    char date [11];
    char time [6];
    char step [6];

    while (fgets(buffer, buffer_size, file)){
        numLines++;
    }

    printf("Number of records in file: %d\n",numLines);

    fclose(file);

    FILE *file2 = fopen(filename, "r") ;
    if (file2 == NULL){
        perror("");
        return 1;
    }

    char buffer2[buffer_size];

    FITNESS_DATA data [numLines];
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