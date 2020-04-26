#include <iostream>
#include <cassert>

#include "algorithms.h"

void printPoints(Point pts [], int numels) {
    for (int i = 0; i < numels; i++) {
        std::cout << "(" << pts[i].x << ", " << pts[i].y << ")" << std::endl;
    }
    std::cout << std::endl;
}

void test(Point p0, Point p1, Point r [], bool print = false) {
    int numels;
    Point* pts = bresenhamLine(p0, p1, numels);
    if (print) {
        printPoints(pts, numels);
    }
    for (int i = 0; i < numels; i++) {
        assert(pts[i].x == r[i].x);
        assert(pts[i].y == r[i].y);
    }
}

void run_tests() {
    std::cout << "Running tests..." << std::endl;
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
    p0 = {2, 1};
    p1 = {2, 1};
    Point r7 [] = {{2, 1}};
    test(p0, p1, r7);
    std::cout << "Tests passed!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}
