#pragma once
#include <iostream>
#include <exception>
#include <string>
#include <array>
#include <algorithm>
#include <SDL.h>
#include <SDL_ttf.h>

class GraphicsEngine {
public:
    GraphicsEngine();
    ~GraphicsEngine();

    SDL_Window* window;
    SDL_Renderer* renderer;

private:
    static const int INIT_SCREEN_W;
    static const int INIT_SCREEN_H;

    static constexpr size_t MAX_TEXTURES = 127;
    std::array<SDL_Texture*, MAX_TEXTURES> textures;
    static constexpr size_t MAX_FONTS = 15;
    std::array<TTF_Font*, MAX_FONTS> fonts;

    void load_media();
    void close_media();
};

enum Texture : size_t {
    t_PiggyBank = 0
};

enum Font : size_t {
    f_Game = 0
};