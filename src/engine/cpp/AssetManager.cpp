// VisualNovel/src/engine/AssetManager.cpp
#include <cstdint>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../hpp/Classes.hpp"

canvas* MainCanvas = nullptr;

void SetMainCanvas(canvas* canvas) {
    MainCanvas = canvas;
}

void AssetManager::DrawTexture(SDL_Texture* texture, int16_t px, int16_t py) {
    SDL_Rect destRect = { px, py, 0, 0 };
    SDL_QueryTexture(texture, nullptr, nullptr, &destRect.w, &destRect.h);
    SDL_RenderCopy(MainCanvas->CANVAS_RENDERER, texture, nullptr, &destRect);
}

void AssetManager::PlaySound(const char* path) {
    // Implementación para reproducir un sonido
}

void AssetManager::PlayMusic(const char* path) {
    // Implementación para reproducir música
}