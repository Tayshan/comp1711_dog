#include <stdio.h>

float volume(float radius){
    return radius * radius * radius * 3.14 * 4/3;
}

int main(){
    float r;
    printf("Please give the radius\n");
    scanf("%f",&r);
    float v = volume(r);
    printf("\nThe area of the circle is %f",v);
    return 0;
}