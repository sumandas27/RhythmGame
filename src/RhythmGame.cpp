#include <chrono>
#include "RhythmGame.hpp"
#include "UI/Text/Text.hpp"

RhythmGame::RhythmGame() : ge(), ae() { }

void RhythmGame::game_loop() {
    std::unique_ptr<Scene> scene = std::make_unique<LevelScene>(ge, ae);

    SDL_Event e;
    using namespace std::chrono;
    high_resolution_clock::time_point currentTime = high_resolution_clock::now();

    while (true) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                return;

            scene->handle_input(e);
        }

        high_resolution_clock::time_point newTime = high_resolution_clock::now();
        high_resolution_clock::duration frameTime = newTime - currentTime;
        float dt = duration_cast<milliseconds>(frameTime).count();
        scene->update(dt);
        currentTime = newTime;

        SDL_RenderClear(ge.renderer);
        scene->render();
        SDL_RenderPresent(ge.renderer);
    }
}