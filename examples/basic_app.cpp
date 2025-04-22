#include "ZeusGUI/platform/linux/X11Window.hpp"
#include <GL/gl.h>
#include <GL/glx.h>
#include <iostream>
#include <thread>
#include <chrono>

using namespace ZeusGUI;

int main() {
    X11Window window;
    window.create(800, 600, "ZeusGUI Example");
    window.show();

    std::cout << "Window running. Press Ctrl+C to exit.\n";

    while (true) {
        window.pollEvents();
        glClearColor(0.1f, 0.1f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glXSwapBuffers(window.getDisplay(), window.getWindow());
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    return 0;
}
