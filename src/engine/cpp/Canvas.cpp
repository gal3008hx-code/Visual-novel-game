// VisualNovel/src/engine/Canvas.cpp
#include "../hpp/Classes.hpp"
#include <cstdint>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstring>
#include <iostream>

AssetManager* ASSETMANAGER = nullptr;

void SetAssetManager(AssetManager* assetManager) {
    ASSETMANAGER = assetManager;
}

void canvas::Draw() {
    SDL_RenderClear(CANVAS_RENDERER);
    for (const sprite& item : ITEMS) {
        ASSETMANAGER->DrawTexture(item.Texture, item.px, item.py);
    }
    SDL_RenderPresent(CANVAS_RENDERER);
}

void canvas::AddSprite(const sprite* item, uint8_t index) {
    if (index > 5) {
        std::cerr << "Índice fuera de rango" << std::endl;
        return;
    }
    sprite* CS = &ITEMS[index];
    CS->px = item->px;
    CS->py = item->py;
    if (item->Texture == nullptr) {
        //Crear la textura en base al path del sprite
        SDL_Surface* surface = IMG_Load(item->path.c_str());
        if (!surface) {
            std::cerr << "Error al cargar la imagen: " << IMG_GetError() << std::endl;
            return;
        }
        CS->Texture = SDL_CreateTextureFromSurface(CANVAS_RENDERER, surface);    
    } else {
        CS->Texture = item->Texture;
    }
    //Si ya hay un sprite ocupado, lo reemplazará, no es un error, está pensado así para no tener que borrar el sprite antes de agregar uno nuevo
}

void canvas::SetScene(const sprite* items[5]) {
    for (uint8_t i = 0; i < 5; i++) {
        AddSprite(items[i], i);
    }
}