#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
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
    
   int a = 10; b = 20, *pa, *pb;
   pa = &a;
   pb = &b;
   printf("Acessando o conteudo de *pa: %d\n", *pa);
   printf("Acessando o conteudo de *pb: %d\n", *pb);
   *pa = 500;
   printf("Valor atual de a: %d\n", a);
   b = *pa - b;
   printf("Acessando o conteudo de *pb: %d\n", *pb);
   printf("Endereco de b = %p e o valor do ponteiro: %p\n", &b, pb);
   */

    int pa = 10, *pb;
    pb = &pa;
    *pb = 20;
    printf("Valor de pa: %d\n", pa);
    printf("Valor de pb: %d\n", *pb);
}