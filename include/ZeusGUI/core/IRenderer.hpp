#pragma once

namespace ZeusGUI {

/// Abstract interface for a rendering backend
class IRenderer {
public:
    virtual void clear(float r, float g, float b, float a) = 0;
    virtual void drawRect(int x, int y, int width, int height) = 0;
    virtual void present() = 0;
    virtual ~IRenderer() = default;
};

} // namespace ZeusGUI