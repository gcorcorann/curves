#pragma once

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
    void _drawCurve(Point2f pts [], int numels, int depth = 0) {
        if (depth >= 5) {
            Point ipts [numels];  // convert points to integers for drawing
            for (int i = 0; i < numels; i++) {
                ipts[i] = {(int) round(pts[i].x), (int) round(pts[i].y)};
            }
            drawPiecewise(ipts, numels);
            return;
        }
        Point2f* ctl_pts = chaikinCurve(pts, numels);
        _drawCurve(ctl_pts, numels, ++depth);
    }
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
    void write() {
        img.write();
    }
    void setDrawColour(Vector colour) {
        m_fg = colour;
    }
    /*
     * Every call to draw writes image to disk.
     */
    void draw(Point pts [], int numels) {
        drawPiecewise(pts, numels);
    }
    void drawLine(Point p0, Point p1) {
        int numels;
        Point* pts = bresenhamLine(p0, p1, numels);
        for (int i = 0; i < numels; i++) {
            *img[pts[i].y * m_width + pts[i].x] = m_fg;
        }
        delete [] pts;
    }
    void drawPiecewise(Point pts [], int numels) {
        for (int i = 0; i < numels - 1; i++) {
            drawLine(pts[i], pts[i + 1]);
        }
    }
    void drawCurve(Point2f pts[], int numels, bool enclosed) {
        int numpts = numels;
        if (enclosed) {
            numpts += 2;
        }
        Point2f npts [numpts];
        for (int i = 0; i < numels; i++) {
            npts[i] = {pts[i].x, pts[i].y};
        }
        if (enclosed) {
            npts[numels] = {pts[0].x, pts[0].y};
            npts[numels + 1] = {pts[1].x, pts[1].y};
        }
        _drawCurve(npts, numpts);
    }
};
