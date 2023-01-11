#include "ConstantText.hpp"

ConstantText::ConstantText(GraphicsEngine& _ge, AudioEngine& _ae, std::string _text, const UIInfo& _info)
    : UI(_ge, _ae, _info)
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

ConstantText::~ConstantText() {
    SDL_DestroyTexture(info.texture);
}

