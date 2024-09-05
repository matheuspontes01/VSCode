#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *p1, *p2;
    p1 = (float*)malloc(sizeof(float));
    *p1 = 10;
    p2 = p1;
    printf("*p1: %f, *p2: %f\n", *p1, *p2);
    p1 = (float*)malloc(sizeof(float));
    puts("Digite um valor para float: ");
    scanf("%f", p1);
    printf("*p1: %f; *p2: %f\n", *p1, *p2);
    
    //desperdiçando memoria aqui
    p2 = (float*)malloc(sizeof(float));
    *p2 = 20;
    return 0;
}