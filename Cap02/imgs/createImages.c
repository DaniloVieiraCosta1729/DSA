#include <stdio.h>
#include <stdlib.h>
#include "sortAni.h"
#include "Dimg.h"

int main(int c, char * argv[])
{
    if(c < 2)
    {
        printf("Usage: %s <positive integer> <positive integer> ...\n", argv[0]);
        return -1;
    }

    int * list = malloc((c - 1) * sizeof(int));

    for(int i = 0; i < c - 1; i++)
    {
        list[i] = atoi(argv[i + 1]);
    }

    for (int i = 0; i < c - 1; i++)
    {
        printf("%d  ", list[i]);
    }

    printf("\n"); 

    sortAnimation(list, c - 1);

    free(list);

    return 0;
}
