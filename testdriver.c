#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"

#define WIDTH 600
#define HEIGHT 800

void ddaLine(__uint32_t *pixels, int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xinc = dx / (float)steps;
    float yinc = dy / (float)steps;

    float X = x1;
    float Y = y1;

    printf("dx %d\ndy %d\n xinc %f\nyinc%f\nsteps %d\n", dx, dy, xinc, yinc, steps);

    for (int i = 0; i < steps; i++)
    {
        putPixel(pixels, (int)X, (int)Y, WIDTH, HEIGHT, 0xFFFFFFFF);
        X += xinc;
        Y += yinc;
        printf("putpixel: %d %d\n", (int)X, (int)Y);
    }
}

void bresenhamsLine(__uint32_t *pixels, int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int i1 = 2 * dy;
    int i2 = 2 * (dy - dx);
    int d = i1 - dx;

    int x, y, xend;

    if (dx < 0)
    {
        x = x2;
        y = y2;
        xend = x1;
    }
    else if (dx > 0)
    {
        x = x1;
        y = y1;
        xend = x2;
    }

    printf("dx %d dy %d i1 %d i2 %d d %d \n", dx, dy, i1, i2, d);

    printf("d\ti1\ti2\tx\ty\t\n");

    while (x <= xend)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", d, i1, i2, x, y);
        putPixel(pixels, x, y, WIDTH, HEIGHT, 0xFFFFFFFF);

        if (d < 0)
        {
            d += i1;
        }
        else if (d >= 0)
        {
            d += i2;
            y++;
        }
        x++;
    }
}

void midPointCircle(__uint32_t *canvas, int x_center, int y_center, int radius, __uint32_t color)
{
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    while (x <= y)
    {
        putPixel(canvas, x + x_center, y + y_center, WIDTH, HEIGHT, color);
        putPixel(canvas, x + x_center, -y + y_center, WIDTH, HEIGHT, color);
        putPixel(canvas, -x + x_center, y + y_center, WIDTH, HEIGHT, color);
        putPixel(canvas, -x + x_center, -y + y_center, WIDTH, HEIGHT, color);
        putPixel(canvas, y + x_center, x + y_center, WIDTH, HEIGHT, color);
        putPixel(canvas, y + x_center, -x + y_center, WIDTH, HEIGHT, color);
        putPixel(canvas, -y + x_center, x + y_center, WIDTH, HEIGHT, color);
        putPixel(canvas, -y + x_center, -x + y_center, WIDTH, HEIGHT, color);

        if (p < 0)
        {
            p = p + (2 * x) + 3;
        }
        else
        {
            p = p + (2 * (x - y)) + 5;
            y--;
        }
        x++;
    }
}

void bresenhamsCircle(__uint32_t *canvas, int x_center, int y_center, int radius, __uint32_t color)
{
    int d = 3 - (2 * radius);
    int x = 0;
    int y = radius;

    while (x < y)
    {
        putPixel(canvas, x + x_center, y + y_center, WIDTH, HEIGHT, color);
        putPixel(canvas, x + x_center, -y + y_center, WIDTH, HEIGHT, color);
        putPixel(canvas, -x + x_center, y + y_center, WIDTH, HEIGHT, color);
        putPixel(canvas, -x + x_center, -y + y_center, WIDTH, HEIGHT, color);
        putPixel(canvas, y + x_center, x + y_center, WIDTH, HEIGHT, color);
        putPixel(canvas, y + x_center, -x + y_center, WIDTH, HEIGHT, color);
        putPixel(canvas, -y + x_center, x + y_center, WIDTH, HEIGHT, color);
        putPixel(canvas, -y + x_center, -x + y_center, WIDTH, HEIGHT, color);

        if (d < 0)
        {
            d = d + (4 * x) + 6;
            x++;
        }
        else if (d >= 0)
        {
            d = d + (4 * (x - y)) + 10;
            y--;
            x++;
        }
    }
}

void main()
{
    int err;
    __uint32_t *canvas = createCanvas(WIDTH, HEIGHT);

    // for (size_t i = 0; i < HEIGHT * WIDTH; i++)
    // {
    //     canvas[i] = rand() % 4294967295;
    // }

    // fillCanvas(canvas, HEIGHT, WIDTH, 0xFFF00000);

    // ddaLine(canvas, 0, 0, WIDTH, HEIGHT);
    // bresenhamsLine(canvas, 1, 1, 8, 5);
    // midPointCircle(canvas, 200, 200, 100, 0xFFFFFFFF);
    // bresenhamsCircle(canvas, 400, 200, 100, 0xFFFFFFFF);

    // putPixel(canvas, 600, 800, WIDTH, HEIGHT, 0xFFFFFFFF);
    while (getchar() == '\n')
        ;

    err = savePPM(canvas, WIDTH, HEIGHT, "./hello.ppm");
    if (err != 0)
    {
        printf("Error in writing to the file.\n");
        return;
    }
}