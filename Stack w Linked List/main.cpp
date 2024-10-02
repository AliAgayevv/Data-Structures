#include <stdio.h>
#include <stdlib.h>

// Stack Last in First Out
// |__c__|                                  |__d__|
// |__b__|  pop() -> delete c           ==> |__c__|
// |__a__|  push(x) -> add x to top     ==> |__b__|
//                                          |__a__|


typedef struct n node;

struct n
{
    node * next;
    int data;
};

int pop(node * root)
{
    if (root == NULL) {
        printf("Linked list is empty, cant pop element!");
        return -1;
    }
    
    if(root -> next == NULL)
    {
        int rvalue = root -> data;
        free(root);
        return rvalue;
    }
    
    node *iter = root;
    
    while(iter -> next -> next != NULL) {
        iter = iter -> next;
    }
    
    node * temp = iter -> next;
    int rvalue = temp -> data;
    iter -> next = NULL;
    free(temp);
    
    return rvalue;
}

node * push(node * root, int x)
{
    if (root == NULL) {
        root = (node*)malloc(sizeof(node));
        root -> data = x;
        root -> next = NULL;
        return root;
    }
    
    node *iter = root;
    
    while (iter -> next != NULL) {
        iter = iter -> next;
    }
    
    node * temp = (node*)malloc(sizeof(node));
    temp -> data = x;
    temp -> next = NULL;
    iter -> next = temp;
    
    return root;
}

void printLinkedList(node * root)
{
    if (root == NULL) {
        printf("Linked list is empty.\n");
    }
    
    while (root != NULL) {
        printf("%d ", root->data);
        root = root -> next;

    }
    printf("\n");
}

int main()
{
    node * s = NULL;
    s = push(s, 1);
    s = push(s, 2);
    s = push(s, 3);
    s = push(s, 4);

    printf("popped-> %d\n", pop(s));
    printLinkedList(s);
}
