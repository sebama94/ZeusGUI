#include "ZeusGUI/core/EventDispatcher.hpp"

namespace ZeusGUI {

void EventDispatcher::registerWidget(std::shared_ptr<IWidget> w) {
    widgets_.push_back(std::move(w));
}

void EventDispatcher::dispatchEvent(int, int, int) {
    for (auto& w : widgets_) w->draw(dummy_);
}

} // namespace ZeusGUI