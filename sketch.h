#pragma once

#include <iostream>

#include "algorithms.h"
#include "../raytracing/image.h"
#include "../raytracing/vector.h"

class Sketch {
private:
    int m_width;
    int m_height;
    Vector m_bg = {0.f, 0.f, 0.f};
    Vector m_fg = {1.f, 1.f, 1.f};
    Image img {m_width, m_height};
public:
    Sketch(int width, int height) : m_width(width), m_height(height) { }
    void setBackgroundColour(Vector colour) {
        m_bg = colour;
        for (int j = 0; j < m_height; j++) {
            for (int i = 0; i < m_width; i++) {
                *img[j * m_width + i] = m_bg;
            }
        }
    }
    void setDrawColour(Vector colour) {
        m_fg = colour;
    }
    /*
     * Every call to draw writes image to disk.
     */
    void draw(Point pts [], int numels) {
        drawPiecewise(pts, numels, img);
        img.write();
    }
    void drawLine(Point p0, Point p1, Image& img) {
        int numels;
        Point* pts = bresenhamLine(p0, p1, numels);
        for (int i = 0; i < numels; i++) {
            *img[pts[i].y * m_width + pts[i].x] = m_fg;
        }
        delete [] pts;
    }
    void drawPiecewise(Point pts [], int numels, Image& img) {
        for (int i = 0; i < numels - 1; i++) {
            drawLine(pts[i], pts[i + 1], img);
        }
    }
};
