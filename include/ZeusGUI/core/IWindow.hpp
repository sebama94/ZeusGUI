#pragma once
#include <string_view>

namespace ZeusGUI {

class IWindow {
    public:
        virtual ~IWindow() = default;
    
        virtual void create(int width, int height, std::string_view title) = 0;
        virtual void show() noexcept = 0;
        virtual void pollEvents() noexcept = 0;
        virtual void close() noexcept = 0;
        virtual void swapBuffers() noexcept = 0;
        virtual int getWidth() const noexcept = 0;
        virtual int getHeight() const noexcept = 0;
    };
        

} // namespace ZeusGUI