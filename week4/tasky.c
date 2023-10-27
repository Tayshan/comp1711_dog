#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double xcoord;
    double ycoord;
} point;

int main(){
    double totDist;
    point coords[10] = {};
    for (int i = 0; i < 10; i++){
        /*printf("Give the x coordinate of point number %d\n", i+1);
        scanf("%lf",&coords[i].xcoord);
        printf("Give the y coordinate of point number %d\n", i+1);
        scanf("%lf",&coords[i].ycoord);*/
        coords[i].xcoord = rand() % 10000  ;
        coords[i].ycoord = rand() % 10000 ;

    }

    for (int i = 0; i < 10; i++){
        printf("The coordinates of point number %d is (%.2f,%.2f)\n",i+1,coords[i].xcoord,coords[i].ycoord);
    }

    /*for (int i = 0; i < 10; i++){
        for (int i2 = i + 1; i2 < 10; i2++){
            totDist += unsigned(coords.xcoord[i] - coords.xcoord[i2]) + unsigned(coords.ycoord[i] - coords.ycoord[i2]);
        }
    }*/
    printf("The average Manhattan distance is %.3f", totDist/10);

    return 0;
}