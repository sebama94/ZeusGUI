#pragma once

#include "core/core.hpp"
#include "widgets/Button.hpp"

namespace ZeusGUI {

    /// Create a platform-specific window
    std::unique_ptr<IWindow> createWindow(int width, int height, std::string_view title);

    /// Create a renderer matching the window's dimensions
    std::unique_ptr<IRenderer> createRenderer(IWindow& window);

    /// Create the event dispatcher (manages widgets and their drawing)
    std::unique_ptr<IEventDispatcher> createEventDispatcher();

    /// Run the main loop (optional utility)
    void runEventLoop(IWindow& window, IRenderer& renderer, IEventDispatcher& dispatcher);

}
