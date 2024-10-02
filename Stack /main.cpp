#include <stdio.h>
#include <stdlib.h>


struct s
{
    int size;
    int top;
    int *arr;
};

typedef s stack;


// smt like constructor
stack * declare()
{
    stack *s = (stack*)malloc(sizeof(stack));
    s->size = 2;
    s->top = 0;
    s->arr = NULL;
    
    return s;
}

int pop(stack *s)
{
    if (s->top <= 0 || s->arr == NULL) {
        printf("Empty");
        return -1;
    }
    if (s->top <= s->top / 4 )
    {
        int *arr2 = (int*)malloc(sizeof(int) * s->size / 2);
        for (int i = 0; i < s->size; i++) {
            arr2[i] = s->arr[i];
        }
        free(s->arr);
        s->arr = arr2;
        s->size /= 2;
    }
    
    return s->arr[--s->top];

}

void push(int a, stack *s)
{
    if (s->arr == NULL) {
        s->arr = (int*)malloc(sizeof(int) * 2);
    }
    
    if(s->top >= s->size - 1)
    {
        int *arr2 = (int*)malloc(sizeof(int) * s->size * 2);
        for (int i = 0; i < s->size; i++)
            arr2[i] = s->arr[i];
        
        free(s->arr);
        s->arr = arr2;
        s->size *= 2;
    }
    s->arr[s->top++] = a;
}

void print(stack *s)
{
    printf("Size: %d \n", s->size);
    for(int i = 0; i < s->top ;i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}


int main()
{
    
    stack * s1 = declare();
    stack * s2 = declare();
    
    for (int i = 0; i < 10; i++) {
        push(i*10, s1);
    }
    
    printf("S1: \n");
    print(s1);
    printf("\nS2: \n");
    print(s2);

    for (int i = 0; i < 10; i++) {
        push(pop(s1), s2);
    }
    printf("S1: \n");
    print(s1);
    printf("\nS2: \n");
    print(s2);

    
}
