#include "ZeusGUI/core/BasicRenderer.hpp"
#include <GL/gl.h>
#include <GL/glu.h>
#include <memory>
#include <iostream>

namespace ZeusGUI {

BasicRenderer::BasicRenderer(int width, int height)
    : width_(width), height_(height) {}

void BasicRenderer::clear(float r, float g, float b, float a) {
    glViewport(0, 0, width_, height_);
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void BasicRenderer::drawRect(int x, int y, int width, int height) {
    glBegin(GL_QUADS);
    glVertex2f((float)x, (float)y);
    glVertex2f((float)(x + width), (float)y);
    glVertex2f((float)(x + width), (float)(y + height));
    glVertex2f((float)x, (float)(y + height));
    glEnd();
}

void BasicRenderer::present() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width_, height_, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glFlush();
}

std::unique_ptr<IRenderer> createRenderer(int width, int height) {
    return std::make_unique<BasicRenderer>(width, height);
}

} // namespace ZeusGUI
