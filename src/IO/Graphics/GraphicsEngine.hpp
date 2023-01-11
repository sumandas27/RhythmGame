#pragma once
#include <iostream>
#include <exception>
#include <string>
#include <array>
#include <algorithm>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class GraphicsEngine {
public:
    GraphicsEngine();
    ~GraphicsEngine();

    static const int SCREEN_W;
    static const int SCREEN_H;

    SDL_Window* window;
    SDL_Renderer* renderer;

    static constexpr size_t MAX_TEXTURES = 127;
    std::array<SDL_Texture*, MAX_TEXTURES> textures;

    static constexpr size_t MAX_FONTS = 15;
    std::array<TTF_Font*, MAX_FONTS> fonts;

private:
    void load_media();
    void close_media();

    SDL_Texture* load_texture(const std::string& path);
    TTF_Font* load_font(const std::string& path);

    bool is_null(const SDL_Rect& rect);
    bool is_null(const SDL_Point& point);
};

enum Texture : size_t {
    t_PiggyBank = 0
};

enum Font : size_t {
    f_Game = 0
};