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

    node *iter = r;
    printf("%d ", iter -> x);
    iter = iter -> next;
    
    while(iter != r)
    {
        printf("%d ", iter -> x);
        iter = iter -> next;
    }
}

void add(node * r, int x)
{
    node* iter = r;
    while(iter -> next != r)
        iter = iter -> next;
    
    iter -> next = (node *) malloc(sizeof(node));
    iter -> next -> x = x;
    iter -> next -> next = r;
}

node * addSeq(node * r, int x)
{
    if (r == NULL) { // if empty
        r = (node *)malloc(sizeof(node));
        r -> next = r;
        r -> x = x;
        return r;
    }
    
    if(r -> x > x) // if lower than first element
    {
        // root change
        node * temp = (node *)malloc(sizeof(node));
        temp -> x = x;
        temp -> next = r;
        node * iter = r;
        while(iter -> next != r)
            iter = iter -> next;
        iter -> next = temp;
        return temp;
    }
    
    node * iter = r;
    while(iter -> next != r && (iter -> next -> x) < x)
    {
        iter = iter -> next;
    }
    
    
    node * temp = (node *)malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> x = x;
    
    return r;
  
}

node * del(node * root, int x)
{
    node * temp;
    node * iter = root;
    
    if(root -> x == x)
    {
        while(iter -> next != root)
            iter = iter -> next;
        iter -> next = root -> next;
        free(root);
        return iter -> next;
    }
    
    while(iter -> next != root && iter -> next -> x != x)
    {
        iter = iter -> next;
    }
    
    if(iter -> next == root)
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

