#include "Stack.h"
#include <string.h>
#include <stdio.h>
// Questao do Estacionamento de EDCarlos
int main()
{
    Stack* stack1 = stack_create();
    Stack* stack2 = stack_create();
    char o;
    int n;
    do {
        scanf(" %c %d", &o, &n);
        if (o == 'i') {
            if (!Stack_push(stack1, n)) {
                printf("Overflow!\n");
            }
        } else if (o == 'r'){
            
            int temp;
            while (Stack_pop(stack1, &temp)){
                if (temp == n) break;
                printf("%d, ", temp);
                Stack_push(stack2, temp);
            }

            if (temp == n) {
                printf("%d \n", temp);
                int temp2;
                while (Stack_pop(stack2, &temp2)) {
                    Stack_push(stack1, temp2);
                }
            } else {
                printf("Underflow!\n");
            }
            
        }
    } while (!(o == '0' && n == 0));
}