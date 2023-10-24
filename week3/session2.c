#include <stdio.h>

float area(float radius){
    return radius * radius * 3.14;
}

int main(){
    float r;
    printf("Please give the radius\n");
    scanf("%f",&r);
    float a = area(r);
    printf("\nThe area of the circle is %f",a);
    return 0;
}