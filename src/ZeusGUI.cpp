#include "ZeusGUI/ZeusGUI.hpp"
#ifdef __linux__
#include "ZeusGUI/platform/linux/X11Window.hpp"
#elif defined(_WIN32)
#include "platform/windows/Win32Window.hpp"
#elif defined(__APPLE__)
#include "platform/macos/CocoaWindow.hpp"
#endif
#include "ZeusGUI/core/BasicRenderer.hpp"
#include "ZeusGUI/core/EventDispatcher.hpp"

namespace ZeusGUI {

std::unique_ptr<IWindow> createWindow(int w, int h, std::string_view title) {
#ifdef __linux__
    auto win = std::make_unique<X11Window>();
#elif defined(_WIN32)
    auto win = std::make_unique<Win32Window>();
#elif defined(__APPLE__)
    auto win = std::make_unique<CocoaWindow>();
#endif
    win->create(w, h, title);
    return win;
}

std::unique_ptr<IRenderer> createRenderer(IWindow& window) {
    return std::make_unique<BasicRenderer>(window.getWidth(), window.getHeight());
}

std::unique_ptr<IEventDispatcher> createEventDispatcher() {
    return std::make_unique<EventDispatcher>();
}

void runEventLoop(IWindow& window, IRenderer& renderer, IEventDispatcher& dispatcher) {
    window.show();
    while (true) {
        window.pollEvents();
        renderer.clear(0.2f, 0.2f, 0.2f, 1.0f);
        dispatcher.dispatchEvent(0, 0, 0);
        renderer.present();
        window.swapBuffers();
    }
}

} // namespace ZeusGUI