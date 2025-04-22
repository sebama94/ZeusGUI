# ⚡ ZeusGUI — Cross-Platform C++23 GUI Framework

**ZeusGUI** is a lightweight, modern, and modular GUI framework written in C++23.  
It provides a simple and extensible architecture for building cross-platform graphical applications using OpenGL, X11, and modern C++ paradigms.

> ✨ Linux support is available now. Windows/macOS coming soon!

---

## 📦 Features

- 🧱 **Modular Design** — `IWindow`, `IRenderer`, `IWidget` interfaces
- 🔁 **Pluggable Architecture** — drop in your own window system or renderer
- 🖼️ **OpenGL 2D Renderer** — pixel-based rendering with orthographic projection
- 🧩 **Widget System** — easy to create custom UI elements (buttons, etc.)
- 🧠 **Event Dispatcher** — register and route user-defined widgets
- 🔥 **Modern C++23** — `std::unique_ptr`, `std::string_view`, concepts-ready

---

## 🚀 Getting Started

### 🔧 Prerequisites

Ensure you have the following installed:

- Linux (Ubuntu/Debian tested)
- CMake ≥ 3.22
- A C++23-compatible compiler (e.g. `g++-13` or `clang++-18`)
- OpenGL and X11 development headers:

```bash
sudo apt update
sudo apt install build-essential cmake libx11-dev libgl1-mesa-dev libglx-dev
```

---

### 📁 Clone and Build

```bash
git clone https://github.com/your-username/ZeusGUI.git
cd ZeusGUI
mkdir build && cd build
cmake ..
cmake --build .
```

---

## ✍️ Example Usage

Check `examples/full_example.cpp` for a live demo:

```cpp
#include "ZeusGUI/ZeusGUI.hpp"
#include <thread>
using namespace ZeusGUI;

int main() {
    auto window = createWindow(800, 600, "ZeusGUI Example");
    auto renderer = createRenderer(*window);
    auto button = createButton("Click Me!");
    button->setPosition(300, 200);
    button->setSize(200, 60);

    window->show();
    while (true) {
        window->pollEvents();
        renderer->clear(0.1f, 0.1f, 0.1f, 1.0f);
        button->draw(*renderer);
        renderer->present();
        window->swapBuffers();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}
```

Build and run:

```bash
./examples/FullExample
```

---

## 🗂️ Project Structure

```
ZeusGUI/
├── include/ZeusGUI/
│   ├── ZeusGUI.hpp                # Public API entry point
│   ├── core/                      # Abstract interfaces and factories
│   └── widgets/                   # Built-in widget definitions
├── src/                           # Implementation of interfaces
│   ├── core/BasicRenderer.cpp
│   ├── platform/linux/X11Window.cpp
│   └── widgets/Button.cpp
├── examples/                      # Example applications
│   └── full_example.cpp
├── CMakeLists.txt
```

---

## 🔌 Extending ZeusGUI

### Create a custom widget

1. Derive from `IWidget`
2. Implement `draw(renderer)`, `setPosition`, `setSize`
3. Register with `IEventDispatcher` or draw manually

### Add new platform support

Implement `IWindow` and register it in `createWindow()` factory.

---

## 🧪 Unit Testing (coming soon)

We recommend integrating with **Catch2** or **GoogleTest**.  
Modular design allows headless testing of logic and widgets.

---

## 🤝 Contributing

Pull requests are welcome! Please:

1. Fork the repo and create your feature branch
2. Write clean, modular C++23 code with comments
3. Test and ensure builds with `cmake .. && cmake --build .`
4. Submit a PR with a clear description

---

## 📄 License

**MIT License** — free to use, modify, and distribute.

---

## 🧠 Authors

- **sebama94** — Lead developer and architect  
- **ChatGPT** — Technical assistant and code support 💡

---

## 💬 Questions? Feedback?

Feel free to [open an issue](https://github.com/sebama94/ZeusGUI/issues) or email me directly.

---

🎉 Happy coding with **ZeusGUI**!