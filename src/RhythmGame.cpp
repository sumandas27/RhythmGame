#include <chrono>
#include "RhythmGame.hpp"

RhythmGame::RhythmGame() : ge(), ae() { }

void RhythmGame::game_loop() {
    SDL_Event e;

    using namespace std::chrono;
    high_resolution_clock::time_point currentTime = high_resolution_clock::now();

    while (true) {
        while (SDL_PollEvent(&e))
            if (e.type == SDL_QUIT) {
                std::cout << "yo\n";
                return;
            }

        high_resolution_clock::time_point newTime = high_resolution_clock::now();
        high_resolution_clock::duration frameTime = newTime - currentTime;
        float dt = duration_cast<milliseconds>(frameTime).count();
        currentTime = newTime;
        //currentScene.update(dt);
        //std::cout << dt << " ms\n";

        SDL_RenderClear(ge.renderer);
        //currentScene.render();
        SDL_RenderPresent(ge.renderer);
    }
}