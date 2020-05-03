#pragma once

#include "algorithms.h"
#include "../raytracing/image.h"
#include "../raytracing/vector.h"

struct Part {
    Point2f* pts;
    int npts;
    bool closed = false;
};

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
    void erase(Point botleft, Point topright) {
        for (int j = botleft.y; j < topright.y; ++j) {
            for (int i = botleft.x; i < topright.x; ++i) {
                *img[j * m_width + i] = m_bg;
            }
        }
    }
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
    void drawCurve(Part part) {
        // if curve is enclosed, add the first and second point to the end of array
        if (part.closed) {
            Point2f pts [part.npts + 2];
            for (int i = 0; i < part.npts; i++) {
                pts[i] = {part.pts[i].x, part.pts[i].y};
            }
            pts[part.npts] = {pts[0].x, pts[0].y};
            pts[part.npts + 1] = {pts[1].x, pts[1].y};
            _drawCurve(pts, part.npts + 2);
        }
        else {
            _drawCurve(part.pts, part.npts);
        }
    }
    void grow(int i, int j, Vector colour) {
        Vector p = *img[j * m_width + i];
        if (p.x == m_fg.x && p.y == m_fg.y && p.z == m_fg.z) {
            return;
        }
        if (p.x == colour.x && p.y == colour.y && p.z == colour.z) {
            return;
        }
        *img[j * m_width + i] = colour;
        grow(i + 1, j, colour);
        grow(i - 1, j, colour);
        grow(i, j + 1, colour);
        grow(i, j - 1, colour);
    }
    void colourPart(Part part, Vector colour) {
        Point2f inside {0.f, 0.f};
        for (int i = 0; i < part.npts; ++i) {
            inside.x += part.pts[i].x;
            inside.y += part.pts[i].y;
        }
        inside.x /= part.npts;
        inside.y /= part.npts;
        inside.x = round(inside.x);
        inside.y = round(inside.y);
        std::cout << inside.x << ", " << inside.y << std::endl;
        grow(inside.x, inside.y, colour);
        std::cout << "done" << std::endl;
    }
    void colourObject(Point p, Vector colour) {
        int i = m_width / 2;
        int j = m_height / 2;
        grow(p.x, p.y, colour);
    }
};
