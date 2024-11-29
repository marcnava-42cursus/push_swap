#include "push_swap.h"
#include "../libs/libft/headers/libft.h"
#include <stdio.h>

void print_stack(t_ps_node *stack)
{
    while (stack)
    {
        printf("%d ", stack->number);
        stack = stack->next;
    }
    printf("\n");
}

int main(void)
{
    t_ps_node *stack_a = NULL;
    t_ps_node *stack_b = NULL;

    // Poner algunos números en la pila A para probar
    // Los valores son solo ejemplos. Puedes agregarlos de cualquier forma.
    push(&stack_a, 5);
    push(&stack_a, 4);
    push(&stack_a, 3);
    push(&stack_a, 2);
    push(&stack_a, 1);

    // Imprimir estado de las pilas antes de las operaciones
    printf("Pila A antes de las operaciones: ");
    print_stack(stack_a);
    printf("Pila B antes de las operaciones: ");
    print_stack(stack_b);

    // Realizar algunas operaciones
    pb(&stack_a, &stack_b);  // Mueve 1 de A a B
    pb(&stack_a, &stack_b);  // Mueve 2 de A a B
    pa(&stack_a, &stack_b);  // Mueve 2 de B a A
    pa(&stack_a, &stack_b);  // Mueve 1 de B a A

    // Imprimir estado de las pilas después de las operaciones
    printf("Pila A después de las operaciones: ");
    print_stack(stack_a);
    printf("Pila B después de las operaciones: ");
    print_stack(stack_b);

    // Liberar la memoria de las pilas
    while (stack_a)
        pop(&stack_a);
    while (stack_b)
        pop(&stack_b);

    return 0;
}
