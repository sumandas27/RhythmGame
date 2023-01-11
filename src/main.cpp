#include "RhythmGame.hpp"

int main(int argc, char* argv[]) {
    try {
        RhythmGame game = RhythmGame();
        game.game_loop();
    }
    catch (const std::exception& e) {
        std::cerr << "[ERROR] " << e.what();
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "[FATAL] Unexcepted exception caught. Good luck debugging this.";
        return EXIT_FAILURE;
    }

    std::cout << "S∑M∑N";
    return EXIT_SUCCESS;
}