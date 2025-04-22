// examples/full_example.cpp

#include "ZeusGUI/ZeusGUI.hpp"
#include <thread>
#include <chrono>
#include <iostream>

using namespace ZeusGUI;

int main() {
    // Create window and renderer
    auto window   = createWindow(800, 600, "ZeusGUI Manual Button Test");
    auto renderer = createRenderer(*window); // ✅ uses real size

    // Create a button manually
    auto button = createButton("Click Me!");
    button->setPosition(350, 275);
    button->setSize(100, 50);

    // Show the window
    window->show();
    std::cout << "[Example] Running... close the window to exit.\n";

    while (true) {
        window->pollEvents();

        renderer->clear(0.2f, 0.2f, 0.2f, 1.0f);  // dark gray background

        // 💡 Manually draw the button — no dispatcher involved
        button->draw(*renderer);

        renderer->present();
        window->swapBuffers();

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    return 0;
}
