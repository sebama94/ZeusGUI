// include/ZeusGUI/core/core.hpp
#pragma once

#include <memory>
#include <string_view>
#include "IWindow.hpp"
#include "IRenderer.hpp"
#include "IEventDispatcher.hpp"

namespace ZeusGUI {

std::unique_ptr<IWindow> createWindow(int width, int height, std::string_view title);
std::unique_ptr<IRenderer> createRenderer();
std::unique_ptr<IEventDispatcher> createEventDispatcher();
void runEventLoop(IWindow& window, IRenderer& renderer, IEventDispatcher& dispatcher);

} // namespace ZeusGUI
