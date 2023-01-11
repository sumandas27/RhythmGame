#include "Text.hpp"

Text::Text(GraphicsEngine& _ge, AudioEngine& _ae, const std::string& _text, const UIInfo& _info) 
    : UI(_ge, _ae, _info), text(_text), oldText(_text)
{
    SDL_Surface* strSurface = TTF_RenderText_Blended(ge.fonts[f_Game], _text.c_str(), info.color);
    if (strSurface == nullptr) {
        std::string sdlErrMsg(SDL_GetError());
        throw std::ios_base::failure("Unable to load string surface for \"" + _text + "\" - " + sdlErrMsg);
    }

    info.texture = SDL_CreateTextureFromSurface(ge.renderer, strSurface);
    if (info.texture == nullptr) {
        std::string sdlErrMsg(SDL_GetError());
        throw std::ios_base::failure("Unable to create string texture for \"" + _text + "\" - " + sdlErrMsg);
    }

    info.dst.w = strSurface->w;
    info.dst.h = strSurface->h;
}

Text::~Text() {
    SDL_DestroyTexture(info.texture);
}

void Text::update() {
    if (text == oldText)
        return;

    oldText = text;
    SDL_DestroyTexture(info.texture);

    SDL_Surface* strSurface = TTF_RenderText_Blended(ge.fonts[f_Game], text.c_str(), info.color);
    if (strSurface == nullptr) {
        std::string sdlErrMsg(SDL_GetError());
        throw std::ios_base::failure("Unable to load string surface for \"" + text + "\" - " + sdlErrMsg);
    }

    info.texture = SDL_CreateTextureFromSurface(ge.renderer, strSurface);
    if (info.texture == nullptr) {
        std::string sdlErrMsg(SDL_GetError());
        throw std::ios_base::failure("Unable to create string texture for \"" + text + "\" - " + sdlErrMsg);
    }

    info.dst.w = strSurface->w;
    info.dst.h = strSurface->h;
}