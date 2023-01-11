#pragma once
#include "../Scene.hpp"
#include "../../UI/Text/Text.hpp"

class LevelScene : public Scene {
public:
    LevelScene(GraphicsEngine& _ge, AudioEngine& _ae);

    void update(float dt) override;
    void render() override;

private:
    Text yoText;
    Text dtText;
};