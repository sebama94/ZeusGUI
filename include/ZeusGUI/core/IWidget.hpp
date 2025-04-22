#pragma once
#include <string>
#include "IRenderer.hpp"

namespace ZeusGUI {

/// Abstract interface for GUI widgets
class IWidget {
public:
    virtual void draw(IRenderer& renderer) = 0;
    virtual void setPosition(int x, int y) = 0;
    virtual void setSize(int width, int height) = 0;
    virtual void setText(const std::string& text) = 0;
    virtual ~IWidget() = default;
};

} // namespace ZeusGUI