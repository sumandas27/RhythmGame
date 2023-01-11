#include <chrono>
#include "RhythmGame.hpp"
#include "UI/Text/ConstantText/ConstantText.hpp"

RhythmGame::RhythmGame() : ge(), ae() { }

void RhythmGame::game_loop() {
    SDL_Event e;

    using namespace std::chrono;
    high_resolution_clock::time_point currentTime = high_resolution_clock::now();

    ConstantText test(ge, ae, "yoski", UIInfo(nullptr, UI::NULL_RECT, { 100, 100, 0, 0 }, SDL_FLIP_NONE, 1.0, false, { 255, 255, 255, 255 }, UI::NULL_POINT, 0.0f));

    while (true) {
        while (SDL_PollEvent(&e))
            if (e.type == SDL_QUIT)
                return;

        high_resolution_clock::time_point newTime = high_resolution_clock::now();
        high_resolution_clock::duration frameTime = newTime - currentTime;
        float dt = duration_cast<milliseconds>(frameTime).count();
        currentTime = newTime;

        SDL_RenderClear(ge.renderer);
        test.render();
        SDL_RenderPresent(ge.renderer);
    }
}