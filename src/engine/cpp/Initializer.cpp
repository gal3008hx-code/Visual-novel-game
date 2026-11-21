#include "../hpp/Classes.hpp"
#include "../hpp/Initializer.hpp"
#include "../hpp/Dependences.hpp"

#include <iostream>
#include <SDL2/SDL.h>

void SetDependences(canvas* c, AssetManager* am) {
    SetMainCanvas(c);
    SetAssetManager(am);
}

canvas* InitializeEngine(AssetManager AM) {
    SDL_Window* window = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 384, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!window) {
        std::cerr << SDL_GetError() << '\n';
        return nullptr;
    }
    if (!renderer) {
        std::cerr << SDL_GetError() << '\n';
        SDL_DestroyWindow(window);
        return nullptr;
    }

    canvas* mainCanvas = new canvas{window, renderer};
    SetDependences(mainCanvas, AM);

    return mainCanvas;
}