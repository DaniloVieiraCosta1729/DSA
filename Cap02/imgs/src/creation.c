#include "../header/Dimg.h"
#include <stdio.h>
#include <stdlib.h>

Context * initContext(int w, int h)
{
    Color * b = malloc(w * h * sizeof(Color));
    ISNULL(b);

    Context * c = malloc(sizeof(Context));
    ISNULL(c);

    c->w = w;
    c->h = h;
    c->buffer = b;

    return c;
}

void destroyContext(Context * c)
{
    free(c->buffer);
    free(c);
}

void paint(const char * nameFile, Context * c)
{
    FILE * f = fopen(nameFile, "wb");
    fprintf(f, "P6\n%d %d\n255\n", c->w, c->h);

    for(int i = 0; i < c->h; i++)
    {
        for(int j = 0; j < c->w; j++)
        {
            fputc(c->buffer[i * c->w + j].r, f);
            fputc(c->buffer[i * c->w + j].g, f);
            fputc(c->buffer[i * c->w + j].b, f);
        }
    }

    fclose(f);
    printf("File %s created!\n", nameFile);
} 

void clear(Context * c, const Color color)
{
    for(int i = 0; i < c->h; i++)
    {
        for(int j = 0; j < c->w; j++)
        {
            c->buffer[i * c->w + j].r = color.r;
            c->buffer[i * c->w + j].g = color.g;
            c->buffer[i * c->w + j].b = color.b;
        }
    }
}
