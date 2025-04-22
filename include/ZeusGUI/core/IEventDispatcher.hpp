#pragma once
#include <memory>
#include <vector>
#include "IWidget.hpp"

namespace ZeusGUI {

/// Abstract interface for event dispatching
class IEventDispatcher {
public:
    virtual void registerWidget(std::shared_ptr<IWidget> widget) = 0;
    virtual void dispatchEvent(int eventCode, int x, int y) = 0;
    virtual ~IEventDispatcher() = default;
};

} // namespace ZeusGUI