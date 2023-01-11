#pragma once
#include "../../UI.hpp"

class ConstantText : public UI {
public:
    ConstantText(GraphicsEngine& _ge, AudioEngine& _ae, std::string _text, const UIInfo& _info);
    ~ConstantText();

    void handle_input() override { }
    void update() override { }
};