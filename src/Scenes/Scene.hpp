#pragma once
#include "../IO/Graphics/GraphicsEngine.hpp"

class Scene {
public:
    virtual void handle_input(SDL_Event& e) { }
    virtual void update(float dt) { }
    virtual void render() { }
};