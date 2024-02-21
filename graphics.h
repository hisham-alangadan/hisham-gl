#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <stdio.h>
#include <stdlib.h>

// Returns an allocated memory space for image in memory.
// Returns a __uint32_t pointer.
void *createCanvas(int height, int width)
{
    return (__uint32_t *)malloc(height * width * sizeof(__uint32_t));
}

// Fills the whole canvas with a specific color.
void fillCanvas(__uint32_t *canvas, size_t height, size_t width, __uint32_t color)
{
    for (size_t i = 0; i < height * width; i++)
    {
        canvas[i] = color;
    }
}

// Modifies a single pixel by filling it with the specified color.
// Returns 0 if successful.
int putPixel(__uint32_t *canvas, int x, int y, size_t WIDTH, size_t HEIGHT, __uint32_t color)
{
    if (y > HEIGHT || x > WIDTH)
    {
        printf("Check putPixel arguments.\n");
        return -1;
    }
    canvas[(y * WIDTH) + x] = color;
    // printf("PutPixel: %d %d\n", x, y);
    return 0;
}

// Draws a line parallel to the y axis at the specified x coordinate.
void drawx(__uint32_t *canvas, int x_coordinate, size_t WIDTH, size_t HEIGHT, __uint32_t color)
{
    if (x_coordinate > WIDTH)
    {
        printf("Check drawx arguments.\n");
        return;
    }
    for (int i = 0; i < HEIGHT; i++)
    {
        putPixel(canvas, x_coordinate, i, WIDTH, HEIGHT, color);
    }
}

// Saves the image in memory to a ppm file.
// Returns 0 if successful.
int savePPM(__uint32_t *canvas, size_t width, size_t height, char *filepath)
{
    FILE *f = fopen(filepath, "wb");
    if (f == NULL)
        return -1;

    fprintf(f, "P6\n%zu %zu\n255\n", width, height);
    if (ferror(f))
    {
        fclose(f);
        return -1;
    }

    for (size_t i = 0; i < width * height; i++)
    {
        // 0xAARRGGBB
        __uint32_t pixel = canvas[i];
        __uint8_t bytes[3] = {
            (pixel >> 0) & 0xFF,
            (pixel >> 8) & 0xFF,
            (pixel >> 16) & 0xFF};

        fwrite(bytes, sizeof(bytes), 1, f);
    }

    return 0;
}

#endif // _GRAPHICS_H_