#include "Engine/Engine.h"
#include "Engine/Components.h"
#include <iostream>

Engine::Engine() {}

Engine::~Engine() {
    clean();
}

bool Engine::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("TGameEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        return false;
    }

    isRunning = true;
    return true;
}

void Engine::run() {
    std::cout << "Engine initialized!" << std::endl;

    entt::registry registry;
    entt::entity entity = registry.create();

    // Attach a component to the entity
    registry.emplace<Position>(entity, 10.0f, 20.0f);

    // Retrieve and print the component data
    auto& pos = registry.get<Position>(entity);
    std::cout << "Entity Position: (" << pos.x << ", " << pos.y << ")" << std::endl;
}

void Engine::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}

void Engine::update() {
    // Game logic update goes here
}

void Engine::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // Blue color
    SDL_RenderClear(renderer);

    // Add rendering code here (if using Graphics class)
    // Example:
    // Graphics::renderSomething(renderer);

    SDL_RenderPresent(renderer);
}

void Engine::clean() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}