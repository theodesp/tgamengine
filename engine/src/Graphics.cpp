#include "Engine/Graphics.h"

void Graphics::renderSomething(SDL_Renderer* renderer) {
    // Example: Draw a simple rectangle
    SDL_Rect rect = { 100, 100, 200, 150 };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red
    SDL_RenderFillRect(renderer, &rect);
}