#pragma once

#include <SDL2/SDL.h>

class Engine {
public:
    Engine();
    ~Engine();

    bool init();
    void run();

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool isRunning = false;

    void handleEvents();
    void update();
    void render();
    void clean();
};