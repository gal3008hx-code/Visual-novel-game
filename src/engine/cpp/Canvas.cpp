// VisualNovel/src/engine/Canvas.cpp
#include "../hpp/Classes.hpp"
#include <cstdint>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstring>

AssetManager* AM = nullptr;

void SetAssetManager(AssetManager* assetManager) {
    AM = assetManager;
}

void canvas::Draw() {
    SDL_RenderClear(CANVAS_RENDERER);
    for (const sprite& item : ITEMS) {
        AM->DrawTexture(item.Texture, item.px, item.py);
    }
    SDL_RenderPresent(CANVAS_RENDERER);
}