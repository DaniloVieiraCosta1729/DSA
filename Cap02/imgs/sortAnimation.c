#include <stdio.h>
#include "Dimg.h"

void swap(int * x, int * y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void makeListImage(int * list, int length, const char * name, const Vec2 size)
{
    if(length > 99)
    {
        printf("I cannot display the sorting of more than 99 elements.");
        return;
    }
    int max = list[0];
    for(int i = 0; i < length; i++)
    {
        if(list[i] > max)
        {
            max = list[i];
        }
    }

    Context * ctx = initContext(size.x, size.y);
    if (ctx == NULL)
    {
        return;
    }
    
    Vec2 recPos, recSize;
    Color recColor;
    recColor.g = 1;
    Color bg = {255, 255, 255};

    clear(ctx, bg);

    if(max == 0)
    {
        printf("Congrats, you gotta a non treated case.\n");
            return;
    }

    int scaleY = (int)((float)size.y * 0.9f / ((float)max));
    int offsetX = (int)((float)size.x * 0.9f / ((float)length));
    recSize.x = offsetX - (int)((float)offsetX * 0.3);
    int startX = (int)((float)size.x * 0.05f);

    for(int i = 0; i < length; i++)
    {
        recSize.y = scaleY * list[i];

        recPos.x = startX + i * offsetX;
        recPos.y = ctx->h - recSize.y;

        uint8_t r = (uint8_t)((int)(((float)list[i]/(float)max) * 255) % 255) + 1;
        uint8_t b = (uint8_t)((int)((1 - ((float)list[i]/(float)max)) * 255) % 255) + 1;
        recColor.r = r;
        recColor.b = b;

        drawRect(ctx, recPos, recSize, recColor);
    }

    paint(name, ctx);
    destroyContext(ctx);
}

void sortAnimation(int * list, int length)
{
    char name[32] = {0};
    name[0] = 's'; name[1] = 't'; name[2] = 'e'; name[3] = 'p'; name[4] = '0'; name[5] = '0'; name[6] = '.'; name[7] = 'p'; name[8] = 'p'; name[9] = 'm';
    int imgNum = 0;
    Vec2 s = {1000, 800};
    name[4] = '0' + imgNum / 10;
    name[5] = '0' + imgNum % 10;
    makeListImage(list, length, name, s);
    imgNum++;

    int j;

    for(int i = 0; i < length - 1; i++)
    {
        j = i + 1;
        while((j > 0) && (list[j] < list[j - 1]))
        {
            swap(&list[j], &list[j - 1]);
            j--;

            name[4] = '0' + imgNum / 10;
            name[5] = '0' + imgNum % 10;
            makeListImage(list, length, name, s);
            imgNum++;
        }
    }

    for (int i = 0; i < length; i++)
    {
        printf("%d  ", list[i]);
    }

    printf("\n");    
}


