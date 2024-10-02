#include <stdlib.h>
#include <stdio.h>


struct n
{
    int data;
    struct n * left;
    struct n * right;
};

typedef struct n node;


node * add(node * tree, int x)
{
    if(tree == NULL)
    {
        node * root = (node*)malloc(sizeof(node));
        root -> left = NULL;
        root -> right = NULL;
        root -> data = x;
        return root;
    }
    
    
    if(tree -> data < x)
    {
        tree -> right = add(tree -> right, x);
        return tree;
    }
    tree -> left = add(tree -> left, x);
    return tree;
}

void toGatherUp(node * tree)
{
    if(tree == NULL)
        return;
    toGatherUp(tree -> right);
    printf("%d ", tree -> data);
    toGatherUp(tree -> left);
}

int find(node * tree, int aranan)
{
    if(tree == NULL)
        return -1;
    if(tree -> data == aranan)
        return 1;
    
    if(find(tree -> right, aranan) == 1)
        return 1;
    
    if(find(tree -> left, aranan) == 1)
        return 1;
    else
        return -1;

        
}

int max(node * tree)
{
    while(tree -> right != NULL)
        tree = tree -> right;
    
    return tree -> data;
}

int min(node * tree)
{
    while(tree -> left != NULL)
        tree = tree -> left;
    
    return tree -> data;
}

node * del (node * tree, int x)
{
    if(tree == NULL)
        return NULL;
    if(tree -> data == x)
    {
        if(tree -> left == NULL && tree -> right == NULL)
            return NULL;
        if(tree -> right != NULL)
        {
            tree -> data = min(tree -> right);
            tree -> right = del(tree -> right, min(tree -> right));
            return tree;
        }
        
        tree -> data = max(tree -> left);
        tree -> left = del(tree -> left, max(tree -> left));
        return tree;
        
    }
    if(tree -> data < x)
    {
        tree -> right = del(tree -> right, x);
        return tree;
    }
    tree -> left = del(tree -> left, x);
    return tree;
    
}

int main(int argc, const char * argv[]) {
    
    node * tree = NULL;
    tree = add(tree, 12);
    tree = add(tree, 200);
    tree = add(tree, 213);
    tree = add(tree, 190);
    tree = add(tree, 56);
    tree = add(tree, 27);
    tree = add(tree, 28);
    tree = add(tree, 24);
    tree = add(tree, 18);
    tree = add(tree, 26);
    
    printf("%d\n",find(tree, 12));
    
    printf("%d\n", max(tree));
    printf("%d\n", min(tree));

    tree = del(tree, 190);
    tree = del(tree, 27);

    toGatherUp(tree);
    
    
    
}
