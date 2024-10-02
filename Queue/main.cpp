#include <stdio.h>
#include <stdlib.h>


int * arr = NULL;
int que = 0;
int topOfQue = 0;
int size = 2;


int deque()
{
    if(que == topOfQue)
    {
        printf("\nQueue is empty ");
        return -1;
    }
    
    if ((que - topOfQue) <= size / 4)
    {
        int * arr2 = (int*)malloc(sizeof(int) * (size / 2));
        for (int i = 0; i < que - topOfQue; i++) {
            arr2[i] = arr[topOfQue + i];
        }
        que -= topOfQue;
        topOfQue = 0;
        free(arr);
        size /= 2;
        arr = arr2;
        
    }
    
    return arr[topOfQue++];
}

void toGatherUp()
{
    if (topOfQue == 0)
        return;
    
    for (int i = 0; i < size; i++)
        arr[i] = arr [i + topOfQue];
    
    que -= topOfQue;
    topOfQue = 0;
}

void enque(int a)
{
    if(arr == NULL)
    {
        arr = (int*)malloc(sizeof(int) * 2);
    }
    if (que >= size) {
        size *= 2;
        int * arr2 = (int*)malloc(sizeof(int) * size);
        for (int i = 0; i < size / 2; i++) {
            arr2[i] = arr[i];
        }
        free(arr);
        arr = arr2;
        
    }
    arr[que++] = a;
}




int main()
{
    for (int i = 0; i < 20; i++)
        enque(i * 10);
        
    printf("size: %d\nqueue: %d\ntopOfQue: %d\n\n",size,que,topOfQue);

    for (int i = 0; i < 13; i++)
        printf("%d ", deque());
    
    
    
    printf("\n\nsize: %d\nqueue: %d\ntopOfQue: %d\n",size,que,topOfQue);

    for (int i = 0; i < 20; i++)
        enque(i * 10);
    
    printf("\n");

    printf("size: %d\nqueue: %d\ntopOfQue: %d\n\n",size,que,topOfQue);

    for (int i = 0; i < 30; i++)
        printf("%d ", deque());
    
    printf("\n\nsize: %d\nqueue: %d\ntopOfQue: %d\n",size,que,topOfQue);

        
}
