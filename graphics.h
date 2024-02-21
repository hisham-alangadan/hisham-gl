#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

// Initialises a window with specified name, width and height.
// Returns to a pointer to the window.
void *initialiseWindow(char *WINDOW_NAME, int WINDOW_WIDTH, int WINDOW_HEIGHT)
{
    SDL_Window *window;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Could not initialise SDL. SDL_Error: %s\n", SDL_GetError());
        return NULL;
    }

    window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        printf("SDL could not create a window. SDL_Error: %s.\n", SDL_GetError());
        return NULL;
    }

    SDL_Window *ret = malloc(sizeof(window));
    ret = window;
    return (void *)ret;
}

// Fills the window with the specified color.
int fillWindow(void *window, uint32_t color)
{
    SDL_FillRect(SDL_GetWindowSurface(window), NULL, color);
    SDL_UpdateWindowSurface(window);
}

// Puts a pixel on the window.
int putPixelWindow(SDL_Window *window, int x, int y, __uint32_t color)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = 1;
    rect.h = 1;

    SDL_FillRect(SDL_GetWindowSurface(window), &rect, color);
    SDL_UpdateWindowSurface(window);
}

// Polls the SDL window and if it detects a quit signal, it destroys the window and quits SDL instance.
void waitTillClose(SDL_Window *window)
{
    SDL_Event e;
    bool quit = false;
    while (quit == false)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = true;
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}

#endif // _GRAPHICS_H_