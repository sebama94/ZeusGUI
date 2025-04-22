#pragma once
#include <memory>
#include <string>
#include "../core/IWidget.hpp"

namespace ZeusGUI {

/// Factory for a basic button
std::shared_ptr<IWidget> createButton(const std::string& text = "Button");

} // namespace ZeusGUI