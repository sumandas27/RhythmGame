#pragma once
#include <memory>
#include "IO/Graphics/GraphicsEngine.hpp"
#include "IO/Audio/AudioEngine.hpp"
#include "Scenes/LevelScene/LevelScene.hpp"

class RhythmGame {
public:
    RhythmGame();

    void game_loop();

private:
    GraphicsEngine ge;
    AudioEngine ae;
};