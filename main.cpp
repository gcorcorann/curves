#include "sketch.h"

void renderElephant () {
    int width = 600;
    int height = 800;
    Point2f ear [] = {{75.f, 700.f}, {250.f, 700.f}, {250.f, 500.f},
                      {75.f, 500.f}};
    int near = sizeof(ear) / sizeof(*ear);
    Point2f head [] = {{150.f, 700.f}, {375.f, 700.f}, {375.f, 550.f},
                       {150.f, 550.f}};
    int nhead = sizeof(head) / sizeof(*head);
    Sketch sketch {width, height};
    sketch.drawCurve(ear, near, true);
    sketch.drawCurve(head, nhead, true);
    sketch.write();
}

void renderRobot() {
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
    Point* parts [] {head, hat, left_ear, right_ear, left_eye, right_eye, mouth,
                     body, hips, left_leg, right_leg, left_arm, right_arm};
    int npts [] {nhead, nhat, nleft_ear, nright_ear, nleft_eye, nright_eye, nmouth,
                 nbody, nhips, nleft_leg, nright_leg, nleft_arm, nright_arm};
    for (int i = 0; i < sizeof(npts) / sizeof(*npts); i++) {
        sketch.draw(parts[i], npts[i]);
    }
    sketch.write();
}

int main() {
    // uncomment to render robot or elephant
    // renderRobot();
    renderElephant();
    return 0;
}
