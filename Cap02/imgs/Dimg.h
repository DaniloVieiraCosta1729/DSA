#ifndef DIMG_H
#define DIMG_H

    #include <stdint.h>
    
    #define ISNULL(x) do {\
        if((x) == NULL)\
        {\
            perror("malloc");\
            return NULL;\
        }\
    } while(0)

    // types
    typedef struct {uint8_t r, g, b;} Color;

    typedef struct {
        int w, h;
        Color * buffer;
    } Context;

    typedef struct {int x, y;} Vec2;

    // functions for creation and destruction and other things
    Context * initContext(int w, int h);
    void destroyContext(Context * c);
    void paint(const char * nameFile, Context * c);

    // functions for drawing
    void drawRect(Context * c, const Vec2 start, const Vec2 size, const Color color);
    void drawCircle(Context * c, const Vec2 center, int radius, const Color color);
    void drawLine(Context * c, const Vec2 start, const Vec2 end, int thickness, const Color color);
    void clear(Context * c, const Color color);


#endif
