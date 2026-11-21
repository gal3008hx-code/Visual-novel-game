// VisualNovel/src/main.cpp
#include <SDL2/SDL.h>
#include <iostream>
#include "src/engine/hpp/Initializer.hpp"
#include "engine/hpp/Classes.hpp"


canvas* MC = nullptr;
AssetManager* AM;

//Función de depuración para ir probando cosas aleatorias, cambia constantemente, no tiene un propósito específico
void DebugFunction() {
    MC->AddSprite(new sprite{true, 0, 0, "assets/Debug/DebugBackground.png", nullptr}, 0);
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Error al iniciar SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    MC = InitializeEngine(AM);
    
    bool running = true;
    SDL_Event event;

    DebugFunction();

    while (running) {

        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_QUIT) {
                running = false;
            }

        }

        MC->Draw();
    }

    return 0;
}   