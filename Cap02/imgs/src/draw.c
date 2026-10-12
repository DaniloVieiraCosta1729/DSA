#include "../header/Dimg.h"

void drawRect(Context * c, const Vec2 start, const Vec2 size, const Color color)
{
    int w = c->w;
    int h = c->h;
    Color * b = c->buffer;

    int sizeX = start.x + size.x;
    int sizeY = start.y + size.y;

    if((start.x > w) || (start.y > h))
    {
        return;
    }

    int index;

    for(int i = start.x; i < sizeX; i++)
    {
        for(int j = start.y; j < sizeY; j++)
        {
            if((i > w) || (i < 0) || (j > h) || (j < 0))
            {
                continue;
            }
            
            index = j * w + i;

            b[index].r = color.r;
            b[index].g = color.g;
            b[index].b = color.b;
        }
    }
}

void drawCircle(Context * c, const Vec2 center, int radius, const Color color)
{
    int w = c->w;
    int h = c->h;
    Color * b = c->buffer;

    int startX = center.x - radius;
    int endX = center.x + radius;
    int startY = center.y - radius;
    int endY = center.y + radius;

    if((startX > w) || (startY > h))
    {
        return;
    }

    int index;

    for(int i = startY; i < endY; i++)
    {
        for(int j = startX; j < endX; j++)
        {
            if((i > h) || (i < 0) || (j > w) || (j < 0))
            {
                continue;
            }

            if(((i - center.x) * (i - center.x) + (j - center.y) * (j - center.y)) > (radius * radius))
            {
                continue;
            }
            
            index = i * w + j;

            b[index].r = color.r;
            b[index].g = color.g;
            b[index].b = color.b;

            // i just thought in a less expensive way to do this, using startY and endY with radius*cos(angle)
        }
    }
}

