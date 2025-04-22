#pragma once
#include <memory>
#include <vector>
#include "ZeusGUI/core/IEventDispatcher.hpp"

namespace ZeusGUI {

/// Simple event dispatcher implementation
class EventDispatcher : public IEventDispatcher {
public:
    void registerWidget(std::shared_ptr<IWidget> widget) override;
    void dispatchEvent(int eventCode, int x, int y) override;

private:
    std::vector<std::shared_ptr<IWidget>> widgets_;
    class DummyRenderer : public IRenderer {
    public:
        void clear(float, float, float, float) override {}
        void drawRect(int, int, int, int) override {}
        void present() override {}
    } dummy_;
};

/// Factory for EventDispatcher
std::unique_ptr<IEventDispatcher> createEventDispatcher();

} // namespace ZeusGUI