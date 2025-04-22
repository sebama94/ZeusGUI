#ifndef ZEUSGUI_PLATFORM_MACOS_COCOAWINDOW_HPP
#define ZEUSGUI_PLATFORM_MACOS_COCOAWINDOW_HPP

#include "../../core/IWindow.hpp"
#include <string_view>

@class NSWindow;
@class NSOpenGLContext;

namespace ZeusGUI {

    class CocoaWindow : public IWindow {
    public:
        CocoaWindow();
        ~CocoaWindow() override;
        void create(int w, int h, std::string_view title) override;
        void show() noexcept override;
        void pollEvents() noexcept override;
        void close() noexcept override;
    private:
        NSWindow*       nsWindow_ = nil;
        NSOpenGLContext* glContext_ = nil;
        bool            open_ = false;
    };

} // namespace ZeusGUI

#endif // ZEUSGUI_PLATFORM_MACOS_COCOAWINDOW_HPP
