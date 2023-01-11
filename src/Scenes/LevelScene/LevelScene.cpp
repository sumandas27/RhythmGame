#include "LevelScene.hpp"

LevelScene::LevelScene(GraphicsEngine& _ge, AudioEngine& _ae)
    : yoText(_ge, _ae, "yo"), dtText(_ge, _ae, "0.00sec")
{
    yoText.info.dst.x = GraphicsEngine::SCREEN_W / 2;
    yoText.info.dst.y = GraphicsEngine::SCREEN_H / 3;
    yoText.info.isCentered = true;

    dtText.info.dst.x = GraphicsEngine::SCREEN_W / 2;
    dtText.info.dst.y = 2 * GraphicsEngine::SCREEN_H / 3;
    dtText.info.isCentered = true;
}

void LevelScene::update(float dt) {
    float second = dt / 1000;
    dtText.text = std::to_string(second).substr(0, 5) + "sec";
    dtText.update();
    yoText.update();
}

void LevelScene::render() {
    dtText.render();
    yoText.render();
}