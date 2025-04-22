#include "ZeusGUI/platform/linux/X11Window.hpp"
#include <iostream>
#include <GL/glx.h>
#include <X11/Xlib.h>

namespace ZeusGUI {

X11Window::X11Window() = default;

X11Window::~X11Window() {
    if (isOpen_) close();
}

void X11Window::create(int width, int height, std::string_view title) {
    display_ = XOpenDisplay(nullptr);
    width_ = width;
    height_ = height;
    if (!display_) {
        std::cerr << "[X11Window] Failed to open X display.\n";
        return;
    }

    int screen = DefaultScreen(display_);
    Window root = RootWindow(display_, screen);

    static int visualAttribs[] = {
        GLX_RGBA, GLX_DEPTH_SIZE, 24,
        GLX_DOUBLEBUFFER,
        None
    };

    XVisualInfo* vi = glXChooseVisual(display_, screen, visualAttribs);
    if (!vi) {
        std::cerr << "[X11Window] No appropriate visual found.\n";
        return;
    }

    Colormap cmap = XCreateColormap(display_, root, vi->visual, AllocNone);
    XSetWindowAttributes swa{};
    swa.colormap = cmap;
    swa.event_mask = ExposureMask | KeyPressMask | StructureNotifyMask;

    window_ = XCreateWindow(
        display_, root,
        0, 0, width, height,
        0, vi->depth,
        InputOutput, vi->visual,
        CWColormap | CWEventMask, &swa
    );

    if (!window_) {
        std::cerr << "[X11Window] Failed to create X window.\n";
        return;
    }

    XStoreName(display_, window_, std::string(title).c_str());

    glxContext_ = glXCreateContext(display_, vi, nullptr, GL_TRUE);
    glXMakeCurrent(display_, window_, glxContext_);
    XFree(vi);

    isOpen_ = true;
}

void X11Window::show() noexcept {
    if (display_ && window_) {
        XMapWindow(display_, window_);
        XFlush(display_);
    }
}

void X11Window::pollEvents() noexcept {
    while (XPending(display_)) {
        XEvent e;
        XNextEvent(display_, &e);
        // Handle input later...
    }
}

void X11Window::close() noexcept {
    if (!isOpen_) return;

    glXMakeCurrent(display_, None, nullptr);
    glXDestroyContext(display_, glxContext_);
    XDestroyWindow(display_, window_);
    XCloseDisplay(display_);

    isOpen_ = false;
}

void X11Window::swapBuffers() noexcept {
    glXSwapBuffers(display_, window_);
}

} // namespace ZeusGUI
