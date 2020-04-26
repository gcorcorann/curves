#pragma once
#include <cmath>

struct Point {
    int x;
    int y;
};

struct Point2f {
    float x;
    float y;
};

/*
 * Using equation of a line, find the new y coordinate for
 * every x position. Returns dynamically allocated array
 * for points along line.
 */
Point* calculate(Point p0, Point p1, int& numels) {
    int dx = p1.x - p0.x;
    numels = dx + 1;
    Point* points = new Point[numels];
    float m = (float) (p1.y - p0.y) / dx;
    for (int i = p0.x; i < p1.x + 1; i++) {
        points[i - p0.x] = {i, (int) round(m * (i - p0.x) + p0.y)};
    }
    return points;
}

/*
 * Swap x and y coordinates for array of points.
 */
void swapCoordinates(Point pts [], int numels) {
    for (int i = 0; i < numels; i++) {
        pts[i] = {pts[i].y, pts[i].x};
    }
}

/*
 * Reverse order of array of points.
 */
void reverseArray(Point pts [], int numels) {
    Point tmp;
    for (int i = 0; i < numels / 2; i++) {
        tmp = pts[i];
        pts[i] = {pts[numels - 1 - i].x, pts[numels - 1 - i].y};
        pts[numels - 1 - i] = {tmp.x, tmp.y};
    }
}

/*
 * Bresenham's line drawing algorithm. Draw line from
 * point p0 to p0 and return pointer to array of points
 * along the line. Numels reflects the number of points.
 */
Point* bresenhamLine(Point p0, Point p1, int& numels) {
    int dx = p1.x - p0.x;
    int dy = p1.y - p0.y;
    if (dx == 0 && dy == 0) {
        numels = 1;
        Point* pt =  new Point;
        pt->x = p0.x;
        pt->y = p0.y;
        return pt;
    }
    Point* pts = nullptr;
    if (abs(dy) > abs(dx)) {
        if (dy < 0) {
            pts = calculate({p1.y, p1.x}, {p0.y, p0.x}, numels);
            reverseArray(pts, numels);
        }
        else {
            pts = calculate({p0.y, p0.x}, {p1.y, p1.x}, numels);
        }
        swapCoordinates(pts, numels);
    }
    else {
        if (dx < 0) {
            pts = calculate({p1.x, p1.y}, {p0.x, p0.y}, numels);
            reverseArray(pts, numels);
        }
        else {
            pts = calculate({p0.x, p0.y}, {p1.x, p1.y}, numels);
        }
    }
    return pts;
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
