#pragma once
#include "IO/Graphics/GraphicsEngine.hpp"
#include "IO/Audio/AudioEngine.hpp"

class RhythmGame {
public:
    RhythmGame();

    void game_loop();

private:
    GraphicsEngine ge;
    AudioEngine ae;
};