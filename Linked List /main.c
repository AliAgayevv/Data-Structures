#include <stdio.h>
#include <stdlib.h>

struct n
{
    int x;
    struct n* next;
};
typedef struct n node;

void print(node * r)
{
    printf("Node list: ");

    while(r != NULL)
    {
        printf("%d ", r -> x);
        r = r -> next;
    }
}

void add(node * r, int x)
{
    while(r -> next != NULL)
        r = r -> next;
    
    r -> next = (node *) malloc(sizeof(node));
    r -> next -> x = x;
    r -> next -> next = NULL;
}

// To add sequential
node * addSeq(node * r, int x)
{
    if (r == NULL) { // if empty
        r = (node *)malloc(sizeof(node));
        r -> next = NULL;
        r -> x = x;
        return r;
    }
    if(r -> x > x) // if lower than first element
    {
        // root change.
        node * temp = (node *)malloc(sizeof(node));
        temp -> x = x;
        temp -> next = r;
        return temp;
    }
    
    node * iter = r;
    while(iter -> next != NULL && (iter -> next -> x) < x)
    {
        iter = iter -> next;
    }
    
    
    node * temp = (node *)malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> x = x;
    
    return r;
  
}
//delete
node * del(node * root, int x)
{
    node * temp;
    node * iter = root;
    
    if(root -> x == x)
    {
        temp = root;
        root = root -> next;
        free(temp);
        
        return root;
    }
    
    while(iter -> next != NULL && iter -> next -> x != x)
    {
        iter = iter -> next;
    }
    
    if(iter -> next == NULL)
    {
        printf("Number cant find");
        return root;
    }

    temp = iter -> next;
    iter -> next = iter -> next -> next;
    free(temp);
    
    return root;
}


int main(void)
{
    node * root;
    root = NULL;
    root = addSeq(root, 400);
    root = addSeq(root, 40);
    root = addSeq(root, 4);
    root = addSeq(root, 450);
    root = addSeq(root, 50);
    root = addSeq(root, 420);
    
    
    print(root);
    printf("\n\n");
    
    root = del(root, 50);
    root = del(root, 400);
    root = del(root, 4);
    
    print(root);
    printf("\n\n");

    
}

