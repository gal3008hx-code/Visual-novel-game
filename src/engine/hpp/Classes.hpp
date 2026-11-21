// VisualNovel/src/engine/Classes.hpp
#pragma once
#include <cstdint>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class sprite {
    public:
        bool Occupied = false;

        int16_t px = 0;
        int16_t py = 0;
        std::string path = "";
        SDL_Texture* Texture = nullptr;
};

class canvas {
    public:
        SDL_Window* CANVAS_WINDOW;
        SDL_Renderer* CANVAS_RENDERER;

        sprite ITEMS[5] = {};

        void AddSprite(const sprite* item, uint8_t index); 
        void Draw();
        void SetScene(const sprite* item[5]);
};

class AssetManager {
    public:
        void DrawTexture(SDL_Texture* texture, int16_t px, int16_t py);
        void PlaySound(const char* path);
        void PlayMusic(const char* path);
};

