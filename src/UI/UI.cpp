#include "UI.hpp"

UIInfo::UIInfo(SDL_Texture* _texture, const SDL_Rect& _src, const SDL_Rect& _dst, SDL_RendererFlip _flip, float _scale, bool _isCentered, const SDL_Color& _color, const SDL_Point& _rotCenter, double _angle)
  : texture(_texture), src(_src), dst(_dst), flip(_flip), scale(_scale), isCentered(_isCentered), color(_color), rotCenter(_rotCenter), angle(_angle) { }

const SDL_Rect UI::NULL_RECT = { 0, 0, 0, 0 };
const SDL_Point UI::NULL_POINT = { 0, 0 };

UI::UI(GraphicsEngine& _ge, AudioEngine& _ae, const UIInfo& _info)
    : info(_info), ge(_ge), ae(_ae) { }

void UI::render() {
    SDL_SetTextureColorMod(info.texture, info.color.r, info.color.g, info.color.b);
    SDL_SetTextureAlphaMod(info.texture, info.color.a);

    SDL_Rect dst = info.dst;
    dst.w *= info.scale;
    dst.h *= info.scale;
    if (info.isCentered) {
        dst.x -= info.dst.w / 2;
        dst.y -= info.dst.h / 2;
    }

    const SDL_Rect* srcAddress = is_null(info.src) ? NULL : &info.src;
    const SDL_Rect* dstAddress = is_null(dst) ? NULL : &dst;
    const SDL_Point* rotCenAddress = is_null(info.rotCenter) ? NULL : &info.rotCenter;
    SDL_RenderCopyEx(ge.renderer, info.texture, srcAddress, dstAddress, info.angle, rotCenAddress, info.flip);

    static constexpr SDL_Color DEFAULT = { 255, 255, 255, 255 };
    SDL_SetTextureColorMod(info.texture, DEFAULT.r, DEFAULT.g, DEFAULT.b);
    SDL_SetTextureAlphaMod(info.texture, DEFAULT.a);
}

bool UI::is_null(const SDL_Rect& rect) {
    return rect.x == NULL_RECT.x &&
           rect.y == NULL_RECT.y &&
           rect.w == NULL_RECT.w &&
           rect.h == NULL_RECT.h;
}

bool UI::is_null(const SDL_Point& point) {
    return point.x == NULL_POINT.x &&
           point.y == NULL_POINT.y;
}