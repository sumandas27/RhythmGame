#pragma once
#include "../UI.hpp"

class Text : public UI {
public:
    Text(GraphicsEngine& _ge, AudioEngine& _ae, const std::string& _text, const UIInfo& _info = UIInfo());
    ~Text();

    std::string text;

    void handle_input() override { }
    void update() override;

private:
    std::string oldText;
};