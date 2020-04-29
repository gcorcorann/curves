#include "sketch.h"

void renderElephant () {
    int width = 600;
    int height = 600;
    Point2f ear [] {{85.f, 505.f}, {240.f, 495.f}, {235.f, 295.f}, {80.f, 305.f}};
    Point2f head [] {{170.f, 500.f}, {355.f, 500.f}, {355.f, 350.f}, {170.f, 350.f}};
    Point2f eye [] {{305.f, 475.f}, {330.f, 475.f}, {330.f, 400.f}, {305.f, 400.f}};
    Point2f iris [] {{305.f, 447.5f}, {315.f, 447.5f}, {315.f, 427.5f}, {305.f, 427.5f}};
    Point2f mouth [] {{280.f, 404.f}, {280.f, 365.f}, {305.f, 365.f}};
    Point2f cheek [] {{265.f, 420.f}, {265.f, 385.f}, {295.f, 385.f}, {295.f, 420.f}};
    Point2f eyebrow [] {{285.f, 440.f}, {285.f, 515.f}, {330.f, 505.f}, {319.f, 469.f}};
    Point2f trunkbot [] {{315.f, 370.f}, {360.f, 375.f}, {420.f, 340.f}, {435.f, 300.f}};
    Point2f trunktop [] {{330.f, 415.f}, {380.f, 405.f}, {445.f, 360.f}, {470.f, 300.f}};
    Point2f trunknose [] {{426.f, 323.f}, {471.f, 332.f}, {471.f, 300.f}, {426.f, 290.f}};
    Point2f tline1 [] {{383.f, 365.f}, {388.f, 385.f}, {413.f, 395.f}};
    Point2f tline2 [] {{395.f, 365.f}, {400.f, 380.f}, {421.f, 388.5f}};
    Point2f body [] {{200.f, 350.f}, {300.f, 350.f}, {380.f, 190.f}, {250.f, 100.f}, {120.f, 190.f}};
    Point2f arm [] {{196.f, 305.f}, {265.f, 305.f}, {300.f, 195.f}, {230.f, 170.f}, {160.f, 195.f}};
    Point2f rleg [] {{300.f, 225.f}, {440.f, 210.f}, {430.f, 110.f}, {290.f, 130.f}};
    Point2f lleg [] {{320.f, 232.f}, {387.f, 257.f}, {455.f, 217.f}, {417.f, 130.f}};
    Point2f hair1 [] {{265.f, 472.f}, {250.f, 530.f}, {270.f, 550.f}, {290.f, 550.f}};
    Point2f hair2 [] {{270.f, 482.f}, {265.f, 520.f}, {280.f, 535.f}, {290.f, 535.f}};

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
                   {rleg, sizeof(rleg) / sizeof(*rleg), true},
                   {lleg, sizeof(lleg) / sizeof(*lleg), false},
                   {hair1, sizeof(hair1) / sizeof(*hair1), false},
                   {hair2, sizeof(hair2) / sizeof(*hair2), false}};

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
