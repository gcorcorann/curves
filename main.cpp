#include <cassert>
#include <cmath>
#include <iostream>

#include "../raytracing/image.h"

struct Point {
    int x;
    int y;
};

Point* calculate(Point p0, Point p1, int& numels) {
    int dx = p1.x - p0.x;
    numels = dx + 1;
    Point* points = new Point[numels];
    float m = (float) (p1.y - p0.y) / dx;
    for (int i = p0.x; i < p1.x + 1; i++) {
        points[i - p0.x] = {i, (int) round((m * (float) (i - p0.x) + p0.y))};
    }
    return points;
}

Point* bresenhamLine(Point p0, Point p1, int& numels) {
    int dx = abs(p1.x - p0.x);
    int dy = abs(p1.y - p0.y);
    Point* pts = nullptr;
    Point pn0, pn1;

    if (dy > dx) {
        if (p0.y > p1.y) {
            pn0 = {p1.y, p1.x};
            pn1 = {p0.y, p0.x};
        }
        else {
            pn0 = {p0.y, p0.x};
            pn1 = {p1.y, p1.x};
        }
        pts = calculate(pn0, pn1, numels);
        for (int i = 0; i < numels; i++) {
            pts[i] = {pts[i].y, pts[i].x};
        }
        if (p0.y > p1.y) {
            Point tmp;
            for (int i = 0; i < numels / 2; i++) {
                tmp = pts[i];
                pts[i] = {pts[numels - 1 - i].x, pts[numels - 1 - i].y};
                pts[numels - 1 - i] = {tmp.x, tmp.y};
            }
        }
    }
    else {
        if (p0.x > p1.x) {
            pn0 = {p1.x, p1.y};
            pn1 = {p0.x, p0.y};
        }
        else {
            pn0 = {p0.x, p0.y};
            pn1 = {p1.x, p1.y};
        }
        pts = calculate(pn0, pn1, numels);
        if (p0.x > p1.x) {
            Point tmp;
            for (int i = 0; i < numels / 2; i++) {
                tmp = pts[i];
                pts[i] = {pts[numels - 1 - i].x, pts[numels - 1 - i].y};
                pts[numels - 1 - i] = {tmp.x, tmp.y};
            }
        }
    }
    return pts;
}

void printPoints(Point pts [], int numels) {
    for (int i = 0; i < numels; i++) {
        std::cout << "(" << pts[i].x << ", " << pts[i].y << ")" << std::endl;
    }
    std::cout << std::endl;
}

void test(Point p0, Point p1, Point r []) {
    int numels;
    Point* pts = bresenhamLine(p0, p1, numels);
    printPoints(pts, numels);
    for (int i = 0; i < numels; i++) {
        assert(pts[i].x == r[i].x);
        assert(pts[i].y == r[i].y);
    }
}

void run_tests() {
    Point p0 = {1, 1};
    Point p1 = {11, 5};
    Point r [] = {{1, 1}, {2, 1}, {3, 2}, {4, 2}, {5, 3}, {6, 3},
                  {7, 3}, {8, 4}, {9, 4}, {10, 5}, {11, 5}};
    test(p0, p1, r);

    p0 = {1, 1};
    p1 = {5, 11};
    Point r2 [] = {{1, 1}, {1, 2}, {2, 3}, {2, 4}, {3, 5}, {3, 6},
                   {3, 7}, {4, 8}, {4, 9}, {5, 10}, {5, 11}};
    test(p0, p1, r2);

    p0 = {1, 1};
    p1 = {1, 11};
    Point r3 [] = {{1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6},
                   {1, 7}, {1, 8}, {1, 9}, {1, 10}, {1, 11}};
    test(p0, p1, r3);

    p0 = {1, 1};
    p1 = {11, 1};
    Point r4 [] = {{1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1},
                   {7, 1}, {8, 1}, {9, 1}, {10, 1}, {11, 1}};
    test(p0, p1, r4);

    p0 = {11, 10};
    p1 = {1, 1};
    Point r5 [] = {{11, 10}, {10, 9}, {9, 8}, {8, 7}, {7, 6}, {6, 6},
                   {5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    test(p0, p1, r5);

    p0 = {10, 11};
    p1 = {1, 1};
    Point r6 [] = {{10, 11}, {9, 10}, {8, 9}, {7, 8}, {6, 7}, {6, 6},
                   {5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    test(p0, p1, r6);
}

void drawLine(Point p0, Point p1, Image& img) {
    int numels;
    Point* pts = bresenhamLine(p0, p1, numels);
    for (int k = 0; k < numels; k++) {
        *img[pts[k].y * img.width + pts[k].x] = {1, 1, 1};
    }
}

int main() {
    std::cout << "Running tests." << std::endl;
    run_tests();
    int width = 100;
    int height = 100;
    Image img {width, height};
    // TODO operator overlaoding for thie img[i, j]
    // TODO constructor all zeros
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            *img[j * width + i] = {0, 0, 0};
        }
    }
    drawLine({10, 10}, {10, 90}, img);
    drawLine({10, 90}, {90, 90}, img);
    drawLine({90, 90}, {90, 10}, img);
    drawLine({90, 10}, {10, 10}, img);
    drawLine({10, 10}, {90, 90}, img);
    drawLine({10, 90}, {90, 10}, img);
    img.write();
    return 0;
}
