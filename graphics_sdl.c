#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define WINDOW_NAME "Hello"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main()
{
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;
    SDL_Rect *rect;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Could not initialise SDL. SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        printf("SDL could not create a window. SDL_Error: %s.\n", SDL_GetError());
        return -1;
    }

    surface = SDL_GetWindowSurface(window);

    // draw stuff

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