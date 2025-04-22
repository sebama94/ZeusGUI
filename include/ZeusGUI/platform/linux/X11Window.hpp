#pragma once
#include "ZeusGUI/core/IWindow.hpp"
#include <X11/Xlib.h>
#include <GL/glx.h>
#include <string_view>

namespace ZeusGUI {

class X11Window : public IWindow {
public:
    X11Window();
    ~X11Window() override;

    void create(int width, int height, std::string_view title) override;
    void show() noexcept override;
    void pollEvents() noexcept override;
    void close() noexcept override;
    void swapBuffers() noexcept override;
    int getWidth() const noexcept override { return width_; }
    int getHeight() const noexcept override { return height_; }


private:
    Display*    display_    = nullptr;
    ::Window    window_     = 0;
    GLXContext  glxContext_ = nullptr;
    bool        isOpen_     = false;
    int width_ = 0;
    int height_ = 0;

};

} // namespace ZeusGUI
