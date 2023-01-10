#include "GraphicsEngine.hpp"

const int GraphicsEngine::INIT_SCREEN_W = 800;
const int GraphicsEngine::INIT_SCREEN_H = 450;

GraphicsEngine::GraphicsEngine() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::string sdlErrMsg(SDL_GetError());
        throw std::ios_base::failure("Unable to initialize SDL - " + sdlErrMsg);
    }

    if (TTF_Init() == -1) {
        std::string ttfErrMsg(TTF_GetError());
        throw std::ios_base::failure("Unable to initialize TTF - " + ttfErrMsg);
    }

    window = SDL_CreateWindow("Rhythm Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, INIT_SCREEN_W, INIT_SCREEN_H, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::string sdlErrMsg(SDL_GetError());
        throw std::ios_base::failure("Unable to create SDL Window - " + sdlErrMsg);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::string sdlErrMsg(SDL_GetError());
        throw std::ios_base::failure("Unable to create SDL Renderer - " + sdlErrMsg);
    }

    load_media();
}

GraphicsEngine::~GraphicsEngine() {
    close_media();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

void GraphicsEngine::load_media() {
    textures.fill(nullptr);
    

    fonts.fill(nullptr);
}

void GraphicsEngine::close_media() {
    for (SDL_Texture* texture : textures)
        SDL_DestroyTexture(texture);

    for (TTF_Font* font : fonts)
        TTF_CloseFont(font);
}