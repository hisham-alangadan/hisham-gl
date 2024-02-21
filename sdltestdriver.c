#include <stdio.h>
#include <unistd.h>
#include "graphics.h"

#define WIDTH 800
#define HEIGHT 600

void ddaLine(void *window, int x1, int y1, int x2, int y2)
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
        // putPixel(pixels, (int)X, (int)Y, WIDTH, HEIGHT, 0xFFFFFFFF);
        putPixelWindow(window, (int)X, (int)Y, 0xFFFFFFFF);
        X += xinc;
        Y += yinc;
        printf("putpixel: %d %d\n", (int)X, (int)Y);
    }
}

void bresenhamsLine(void *window, int x1, int y1, int x2, int y2)
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
        // putPixel(pixels, x, y, WIDTH, HEIGHT, 0xFFFFFFFF);
        putPixelWindow(window, x, y, 0xFFFFFFFF);

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

void midPointCircle(void *window, int x_center, int y_center, int radius, __uint32_t color)
{
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    while (x <= y)
    {
        putPixelWindow(window, x + x_center, y + y_center, color);
        putPixelWindow(window, x + x_center, -y + y_center, color);
        putPixelWindow(window, -x + x_center, y + y_center, color);
        putPixelWindow(window, -x + x_center, -y + y_center, color);
        putPixelWindow(window, y + x_center, x + y_center, color);
        putPixelWindow(window, y + x_center, -x + y_center, color);
        putPixelWindow(window, -y + x_center, x + y_center, color);
        putPixelWindow(window, -y + x_center, -x + y_center, color);

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

void bresenhamsCircle(void *window, int x_center, int y_center, int radius, __uint32_t color)
{
    int d = 3 - (2 * radius);
    int x = 0;
    int y = radius;

    while (x < y)
    {
        putPixelWindow(window, x + x_center, y + y_center, color);
        putPixelWindow(window, x + x_center, -y + y_center, color);
        putPixelWindow(window, -x + x_center, y + y_center, color);
        putPixelWindow(window, -x + x_center, -y + y_center, color);
        putPixelWindow(window, y + x_center, x + y_center, color);
        putPixelWindow(window, y + x_center, -x + y_center, color);
        putPixelWindow(window, -y + x_center, x + y_center, color);
        putPixelWindow(window, -y + x_center, -x + y_center, color);

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

void main(int argc, char *argv[])
{
    void *window = initialiseWindow("Hello", WIDTH, HEIGHT);
    fillWindow(window, 0x00000000);

    // for (int i = 0; i < 600; i++)
    // {
    //     putPixelWindow(window, i, i, 0xFFFFFFFF);
    // }

    // ddaLine(window, 0, 0, 800, 600);
    // bresenhamsLine(window, 0, 0, 800, 600);
    // midPointCircle(window, 200, 200, 100, 0xFFFFFFFF);
    // bresenhamsCircle(window, 400, 200, 100, 0xFFFFFFFF);

    waitTillClose(window);
}