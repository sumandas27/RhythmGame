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
    textures[t_PiggyBank] = load_texture("assets/textures/piggyBank.png");

    fonts.fill(nullptr);
    fonts[f_Game] = load_font("assets/fonts/FFFFORWA.TTF");
}

void GraphicsEngine::close_media() {
    for (SDL_Texture* texture : textures)
        SDL_DestroyTexture(texture);

    for (TTF_Font* font : fonts)
        TTF_CloseFont(font);
}

SDL_Texture* GraphicsEngine::load_texture(const std::string& path) {
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == nullptr) {
        std::string imgErrMsg(IMG_GetError());
        throw std::invalid_argument("Cannot load surface from " + path + " - " + imgErrMsg);
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
        std::string sdlErrMsg(SDL_GetError());
        throw std::invalid_argument("Cannot create texture from " + path + " - " + sdlErrMsg);
    }

    SDL_FreeSurface(surface);
    return texture;
}

TTF_Font* GraphicsEngine::load_font(const std::string& path) {
    TTF_Font* font = TTF_OpenFont(path.c_str(), 72);
    if (font == nullptr) {
        std::string ttfErrMsg(TTF_GetError());
        throw std::ios_base::failure("Cannot create font from " + path + " - " + ttfErrMsg);
    }
    return font;
}

bool GraphicsEngine::is_null(const SDL_Rect& rect) {
    return rect.x == 0 && rect.y == 0 && rect.w == 0 && rect.h == 0;
}

bool GraphicsEngine::is_null(const SDL_Point& point) {
    return point.x == 0 && point.y == 0;
}