#pragma once

#include "ZeusGUI/core/IRenderer.hpp"
#include <memory> 

namespace ZeusGUI {

class BasicRenderer : public IRenderer {
public:
    BasicRenderer(int width, int height);

    void clear(float r, float g, float b, float a) override;
    void drawRect(int x, int y, int width, int height) override;
    void present() override;

private:
    int width_;
    int height_;
};

std::unique_ptr<IRenderer> createRenderer(int width, int height);

} // namespace ZeusGUI
