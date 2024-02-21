# hisham-gl

Made my own graphics library coz I can't get graphics.h to work properly on my system.

Tested on Arch Linux (6.7.3), but should work on any Linux machine.

## Dependancies

libc and SDL2(optional; for rendering directly into a window)

## Documentation

If SDL isin't your cup of tea, then you can output your artwork as a ppm file.

- **Check testdriver.c and sdltestdriver.c for implementation instructions**
- **testdriver.c outs an image file** <br>
- **sdltestdriver.c outputs directly into a window (needs SDL2)** <br>
- **_Please compile files that require SDL with the -lSDL2 flag_**

## Functions

##### - For rendering into a window (SDL needed)

void *initialiseWindow(char *WINDOW_NAME, int WINDOW_WIDTH, int WINDOW_HEIGHT)

int fillWindow(void \*window, uint32_t color)

int putPixelWindow(SDL_Window \*window, int x, int y, \_\_uint32_t color)

void waitTillClose(SDL_Window \*window)

##### - For rendering into an image file

void \*createCanvas(int height, int width)

void fillCanvas(**uint32_t \*canvas, size_t height, size_t width, **uint32_t color)

int putPixel(**uint32_t \*canvas, int x, int y, size_t WIDTH, size_t HEIGHT, **uint32_t color)

void drawx(**uint32_t \*canvas, int x_coordinate, size_t WIDTH, size_t HEIGHT, **uint32_t color)

int savePPM(\_\_uint32_t *canvas, size_t width, size_t height, char *filepath)
