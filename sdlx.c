#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

const int WIDTH = 800;
const int HEIGHT = 600;

void main(int charc, char *args[])
{
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;
    SDL_Rect rect;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Could not initialise SDL. SDL Error: %s\n", SDL_GetError());
    }
    else
    {
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

        if (window == NULL)
        {
            printf("SDL could not create a window. SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            surface = SDL_GetWindowSurface(window);
            // SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
            SDL_FillRect(surface, NULL, 0xFF00FF00);
            SDL_UpdateWindowSurface(window);
            rect.x = 2;
            rect.y = 3;
            rect.w = 1;
            rect.h = 1;
            SDL_FillRect(surface, &rect, 0xFFFFFFFF);
            SDL_UpdateWindowSurface(window);

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
        }
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}