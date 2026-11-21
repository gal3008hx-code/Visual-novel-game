// VisualNovel/src/engine/Classes.hpp
#pragma once
#include <cstdint>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class sprite {
    public:
        int16_t px = 0;
        int16_t py = 0;

        SDL_Texture* Texture = nullptr;
};

class canvas {
    public:
        SDL_Window* CANVAS_WINDOW;
        SDL_Renderer* CANVAS_RENDERER;

        sprite ITEMS[4] = {};

        void Draw();
        void RemoveSprite(uint16_t index);
};

class AssetManager {
    public:
        void DrawTexture(SDL_Texture* texture, int16_t px, int16_t py);
        void PlaySound(const char* path);
        void PlayMusic(const char* path);
};

