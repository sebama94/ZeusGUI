#ifndef ZEUSGUI_PLATFORM_WINDOWS_WIN32WINDOW_HPP
#define ZEUSGUI_PLATFORM_WINDOWS_WIN32WINDOW_HPP

#include "../../core/IWindow.hpp"
#include <string_view>
#include <Windows.h>

namespace ZeusGUI {

    class Win32Window : public IWindow {
    public:
        Win32Window();
        ~Win32Window() override;
        void create(int w, int h, std::string_view title) override;
        void show() noexcept override;
        void pollEvents() noexcept override;
        void close() noexcept override;
    private:
        HWND    hwnd_   = nullptr;
        HINSTANCE hInst_= nullptr;
        bool    open_   = false;
    };

} // namespace ZeusGUI

#endif // ZEUSGUI_PLATFORM_WINDOWS_WIN32WINDOW_HPP
