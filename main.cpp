#include "sketch.h"

void renderElephant () {
    int width = 600;
    int height = 800;
    Point2f ear [] {{85.f, 705.f}, {240.f, 695.f}, {235.f, 495.f}, {80.f, 505.f}};
    Point2f head [] {{150.f, 700.f}, {375.f, 700.f}, {375.f, 550.f}, {150.f, 550.f}};
    Point2f eye [] {{325.f, 675.f}, {350.f, 675.f}, {350.f, 600.f}, {325.f, 600.f}};
    Point2f iris [] {{325.f, 647.5f}, {335.f, 647.5f}, {335.f, 627.5f}, {325.f, 627.5f}};
    Point2f mouth [] {{300.f, 604.f}, {300.f, 565.f}, {325.f, 565.f}};
    Point2f cheek [] {{285.f, 620.f}, {285.f, 585.f}, {315.f, 585.f}, {315.f, 620.f}};
    Point2f eyebrow [] {{315.f, 660.f}, {315.f, 705.f}, {350.f, 705.f}, {339.f, 665.f}};
    Point2f trunkbot [] {{325.f, 570.f}, {380.f, 575.f}, {440.f, 540.f}, {455.f, 500.f}};
    Point2f trunktop [] {{350.f, 615.f}, {400.f, 605.f}, {465.f, 560.f}, {490.f, 500.f}};
    Point2f trunknose [] {{446.f, 523.f}, {491.f, 532.f}, {491.f, 500.f}, {446.f, 490.f}};
    Point2f tline1 [] {{403.f, 565.f}, {408.f, 585.f}, {433.f, 595.f}};
    Point2f tline2 [] {{415.f, 565.f}, {420.f, 580.f}, {441.f, 588.5f}};
    Point2f body [] {{200.f, 550.f}, {300.f, 550.f}, {380.f, 390.f}, {250.f, 300.f}, {120.f, 390.f}};
    Point2f arm [] {{196.f, 505.f}, {265.f, 505.f}, {300.f, 395.f}, {230.f, 370.f}, {160.f, 395.f}};
    Point2f rleg [] {{300.f, 425.f}, {440.f, 410.f}, {430.f, 310.f}, {290.f, 330.f}};

    Part parts [] {{ear, sizeof(ear) / sizeof(*ear), true},
                   {head, sizeof(head) / sizeof(*head), true},
                   {eye, sizeof(eye) / sizeof(*eye), true},
                   {iris, sizeof(iris) / sizeof(*iris), true},
                   {mouth, sizeof(mouth) / sizeof(*mouth), false},
                   {cheek, sizeof(cheek) / sizeof(*cheek), false},
                   {eyebrow, sizeof(eyebrow) / sizeof(*eyebrow), false},
                   {trunkbot, sizeof(trunkbot) / sizeof(*trunkbot), false},
                   {trunktop, sizeof(trunktop) / sizeof(*trunktop), false},
                   {trunknose, sizeof(trunknose) / sizeof(*trunknose), true},
                   {tline1, sizeof(tline1) / sizeof(*tline1), false},
                   {tline2, sizeof(tline2) / sizeof(*tline2), false},
                   {body, sizeof(body) / sizeof(*body), true},
                   {arm, sizeof(arm) / sizeof(*arm), true},
                   {rleg, sizeof(rleg) / sizeof(*rleg), true}};

    Sketch sketch {width, height};
    for (int i = 0; i < sizeof(parts) / sizeof(*parts); i++) {
        sketch.drawCurve(parts[i]);
    }
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
