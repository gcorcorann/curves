#include <cassert>
#include <cmath>
#include <iostream>

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
    int dx = p1.x - p0.x;
    int dy = p1.y - p0.y;
    Point* pts = nullptr;
    if (dy > dx) {
        Point pn0 = {p0.y, p0.x};
        Point pn1 = {p1.y, p1.x};
        pts = calculate(pn0, pn1, numels);
        for (int i = 0; i < numels; i++) {
            pts[i] = {pts[i].y, pts[i].x};
        }
    }
    else {
        pts = calculate(p0, p1, numels);
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

int main() {
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
    return 0;
}
