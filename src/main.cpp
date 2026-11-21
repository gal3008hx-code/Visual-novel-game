// VisualNovel/src/main.cpp
#include <SDL2/SDL.h>
#include <iostream>
#include "src/engine/hpp/Initializer.hpp"
#include "engine/hpp/Classes.hpp"


canvas* MC = nullptr;
AssetManager AM;

int main() {

    // 1. Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Error al iniciar SDL: " << SDL_GetError() << std::endl;
        return 1;
    }
    MC = InitializeEngine(AM);

    return 0;
}   