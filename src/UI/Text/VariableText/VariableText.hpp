#pragma once
#include "../../UI.hpp"

class VariableText : public UI {
public:
    VariableText(GraphicsEngine& _ge, AudioEngine& _ae, const std::string& _text, const UIInfo& _info);
    ~VariableText();

    std::string text;

    void handle_input() override { }
    void update() override;
};