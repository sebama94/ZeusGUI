#include "ZeusGUI/widgets/Button.hpp"
#include "ZeusGUI/core/IRenderer.hpp"

namespace ZeusGUI {

class ButtonImpl : public IWidget {
public:
    explicit ButtonImpl(std::string t) : text_(std::move(t)) {}
    void draw(IRenderer& r) override { r.drawRect(x_, y_, w_, h_); }
    void setPosition(int x, int y) override { x_ = x; y_ = y; }
    void setSize(int w, int h) override { w_ = w; h_ = h; }
    void setText(const std::string& t) override { text_ = t; }
private:
    int x_ = 0, y_ = 0, w_ = 100, h_ = 30;
    std::string text_;
};

std::shared_ptr<IWidget> createButton(const std::string& text) {
    return std::make_shared<ButtonImpl>(text);
}

} // namespace ZeusGUI