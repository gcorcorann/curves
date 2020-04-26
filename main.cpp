#include <cassert>
#include <cmath>
#include <iostream>

#include "../raytracing/image.h"
#include "algorithms.h"

#include "sketch.h"

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
}

void drawLine(Point p0, Point p1, Image& img) {
    int numels;
    Point* pts = bresenhamLine(p0, p1, numels);
    for (int k = 0; k < numels; k++) {
        *img[pts[k].y * img.width + pts[k].x] = {1, 1, 1};
    }
}

void drawLines(Point2f pts [], int numels, Image& img) {
    Point p0, p1;
    for (int i = 0; i < numels - 1; i++) {
        p0 = {(int) round(pts[i].x), (int) round(pts[i].y)};
        p1 = {(int) round(pts[i + 1].x), (int) round(pts[i + 1].y)};
        drawLine(p0, p1, img);
    }
}

/*
 * Following function takes a list of sorted control points
 * to which a Chaikin curve is to be drawn.
 * Returns an array of new control points and modifies numels
 * to return number of new control points.
 */
Point2f* chaikinCurve(Point2f pts [], int& numels) {
    int num_pts = numels;
    numels = (numels - 1) * 2;
    Point2f* ctr_pts = new Point2f [numels];
    for (int i = 0; i < num_pts - 1; i++) {
        float vx, vy;
        vx = pts[i + 1].x - pts[i].x;
        vy = pts[i + 1].y - pts[i].y;
        ctr_pts[i * 2] = {pts[i].x + 0.25f * vx, pts[i].y + 0.25f * vy};
        ctr_pts[i * 2 + 1] = {pts[i].x + 0.75f * vx, pts[i].y + 0.75f * vy};
    }
    return ctr_pts;
}

void drawCurve(Point2f pts [], int numels, Image& img, int depth = 0) {
    if (depth >= 5) {
        drawLines(pts, numels, img);
        return;
    }
    Point2f* ctl_pts = chaikinCurve(pts, numels);
    drawCurve(ctl_pts, numels, img, ++depth);
}

void render (int width, int height) {
    Image img {width, height};
    int numels = 5;
    Point2f pts [numels] = {{10.f, 10.f}, {10.f, 50.f}, {50.f, 90.f},
                            {90.f, 50.f}, {90.f, 10.f}};
    drawCurve(pts, numels, img);
    Point2f lpts [] = {{10, 10}, {10, 90}, {90, 90}, {90, 10}, {10, 10}};
    drawLines(lpts, 5, img);
    img.write();
}

int main() {
    int width = 800;
    int height = 700;

    Point head [] {{250, 300}, {250, 500}, {550, 500}, {550, 300}, {250, 300}};
    int nhead = sizeof(head) / sizeof(*head);

    Point hat [] {{300, 500}, {400, 650}, {500, 500}, {300, 500}};
    int nhat = sizeof(hat) / sizeof(*hat);

    Point left_ear [] {{275, 500}, {225, 600}, {250, 600}, {300, 500}, {275, 500}};
    int nleft_ear = sizeof(left_ear) / sizeof(*left_ear);

    Point right_ear [] {{500, 500}, {550, 600}, {575, 600}, {525, 500}, {500, 500}};
    int nright_ear = sizeof(right_ear) / sizeof(*right_ear);

    Point left_eye [] {{325, 425}, {325, 475}, {375, 475}, {375, 425}, {325, 425}};
    int nleft_eye = sizeof(left_eye) / sizeof(*left_eye);

    Point right_eye [] {{425, 425}, {425, 475}, {475, 475}, {475, 425}, {425, 425}};
    int nright_eye = sizeof(right_eye) / sizeof(*right_eye);

    Point mouth [] {{350, 325}, {350, 375}, {450, 375}, {450, 325}, {350, 325}};
    int nmouth = sizeof(mouth) / sizeof(*mouth);

    Point body [] {{325, 175}, {325, 300}, {475, 300}, {475, 175}, {325, 175}};
    int nbody = sizeof(body) / sizeof(*body);

    Point hips [] {{325, 100}, {325, 175}, {475, 175}, {475, 100}, {325, 100}};
    int nhips = sizeof(hips) / sizeof(*hips);

    Point left_leg [] {{250, 50}, {250, 150}, {325, 150}, {325, 50}, {250, 50}};
    int nleft_leg = sizeof(left_leg) / sizeof(*left_leg);

    Point right_leg [] {{550, 50}, {550, 150}, {475, 150}, {475, 50}, {550, 50}};
    int nright_leg = sizeof(right_leg) / sizeof(*right_leg);

    Point left_arm [] {{325, 300}, {275, 300}, {175, 225}, {200, 200}, {325, 300}};
    int nleft_arm = sizeof(left_arm) / sizeof(*left_arm);

    Point right_arm [] {{475, 300}, {525, 300}, {625, 225}, {600, 200}, {475, 300}};
    int nright_arm = sizeof(right_arm) / sizeof(*right_arm);
 
    Sketch sketch {width, height};
    sketch.setBackgroundColour({0.f, 0.f, 0.f});
    sketch.setDrawColour({1.f, 0.f, 0.f});
    sketch.draw(head, nhead);
    sketch.draw(hat, nhat);
    sketch.draw(left_ear, nleft_ear);
    sketch.draw(right_ear, nright_ear);
    sketch.draw(left_eye, nleft_eye);
    sketch.draw(right_eye, nright_eye);
    sketch.draw(mouth, nmouth);
    sketch.draw(body, nbody);
    sketch.draw(hips, nhips);
    sketch.draw(left_leg, nleft_leg);
    sketch.draw(right_leg, nright_leg);
    sketch.draw(left_arm, nleft_arm);
    sketch.draw(right_arm, nright_arm);
    return 0;


    std::cout << "Running tests." << std::endl;
    run_tests();
    render(width, height);
    return 0;
}
