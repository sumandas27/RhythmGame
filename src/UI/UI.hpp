#pragma once
#include "../IO/Graphics/GraphicsEngine.hpp"
#include "../IO/Audio/AudioEngine.hpp"

struct UIInfo {
public:
    UIInfo();
    UIInfo(SDL_Texture* _texture, const SDL_Rect& _src, const SDL_Rect& _dst, SDL_RendererFlip _flip, float _scale, bool _isCentered, const SDL_Color& _color, const SDL_Point& _rotCenter, double _angle);

    SDL_Texture* texture;
    SDL_Rect src;
    SDL_Rect dst;
    SDL_RendererFlip flip;
    float scale;
    bool isCentered;
    SDL_Color color;
    SDL_Point rotCenter;
    double angle;
};

class UI {
public:
    UI(GraphicsEngine& _ge, AudioEngine& _ae, const UIInfo& _info);

    static const SDL_Rect NULL_RECT;
    static const SDL_Color WHITE;
    static const SDL_Point NULL_POINT;

    UIInfo info;

    virtual void handle_input() = 0;
    virtual void update() = 0;
    void render();

protected:
    GraphicsEngine& ge;
    AudioEngine& ae;

private:
    bool is_null(const SDL_Rect& rect);
    bool is_null(const SDL_Point& point);
};