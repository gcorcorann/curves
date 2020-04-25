#include <cassert>
#include <cmath>
#include <iostream>

struct Point {
    int x;
    int y;
};

Point* bresenhamLine(Point p0, Point p1, int& numels) {
    int dx = p1.x - p0.x;
    numels = dx + 1;
    Point* points = new Point[numels];
    float m = (float) (p1.y - p0.y) / dx;
    for (int i = p0.x; i < p1.x + 1; i++) {
        points[i - p0.x] = {i, (int) round((m * (float) (i - p0.x) + p0.y))};
    }
    return points;
}

void test() {
    Point p0 = {1, 1};
    Point p1 = {11, 5};
    Point r [] = {{1, 1}, {2, 1}, {3, 2}, {4, 2}, {5, 3}, {6, 3}, {7, 3}, {8, 4}, {9, 4}, {10, 5}, {11, 5}};
    int numels;
    Point* pts = bresenhamLine(p0, p1, numels);
    for (int i = 0; i < numels; i++) {
        assert(pts->x  == r[i].x);
        assert(pts->y == r[i].y);
        pts++;
    }
}

int main() {
    test();
    return 0;
}
