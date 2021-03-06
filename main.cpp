#include "sketch.h"

void renderElephant () {
    int width = 600;
    int height = 600;
    Point2f ear [] {{85.f, 505.f}, {240.f, 495.f}, {235.f, 295.f}, {80.f, 305.f},
                    {85.f, 505.f}, {240.f, 495.f}};
    Point2f head [] {{170.f, 495.f}, {355.f, 495.f}, {355.f, 345.f}, {170.f, 345.f}};
    Point2f eye [] {{305.f, 470.f}, {330.f, 470.f}, {330.f, 395.f}, {305.f, 395.f}};
    Point2f iris [] {{310.f, 444.5f}, {320.f, 444.5f}, {320.f, 424.5f}, {310.f, 424.5f}};
    Point2f biris [] {{305.f, 455.f}, {325.f, 455.f}, {325.f, 410.f}, {305.f, 410.f}};
    Point2f mouth [] {{280.f, 399.f}, {280.f, 360.f}, {305.f, 360.f}};
    Point2f cheek [] {{265.f, 415.f}, {265.f, 380.f}, {295.f, 380.f}, {295.f, 415.f}};
    Point2f eyebrow [] {{285.f, 435.f}, {285.f, 510.f}, {330.f, 500.f}, {319.f, 464.f}};
    Point2f trunkbot [] {{315.f, 365.f}, {360.f, 370.f}, {420.f, 335.f}, {435.f, 295.f}};
    Point2f trunktop [] {{330.f, 410.f}, {380.f, 400.f}, {445.f, 355.f}, {470.f, 295.f}};
    Point2f trunknose [] {{426.f, 318.f}, {471.f, 327.f}, {471.f, 295.f}, {426.f, 285.f}};
    Point2f tline1 [] {{383.f, 360.f}, {388.f, 380.f}, {413.f, 390.f}};
    Point2f tline2 [] {{395.f, 360.f}, {400.f, 375.f}, {421.f, 383.5f}};
    Point2f body [] {{200.f, 350.f}, {300.f, 350.f}, {380.f, 190.f}, {250.f, 100.f},
                     {120.f, 190.f}};
    Point2f arm [] {{196.f, 305.f}, {265.f, 305.f}, {300.f, 195.f}, {230.f, 170.f},
                    {160.f, 195.f}};
    Point2f rleg [] {{300.f, 225.f}, {440.f, 210.f}, {430.f, 110.f}, {290.f, 130.f}};
    Point2f lleg [] {{320.f, 232.f}, {387.f, 257.f}, {455.f, 217.f}, {417.f, 130.f}};
    Point2f hair1 [] {{265.f, 468.f}, {250.f, 525.f}, {270.f, 545.f}, {290.f, 545.f}};
    Point2f hair2 [] {{270.f, 477.f}, {265.f, 515.f}, {280.f, 530.f}, {290.f, 530.f}};
    Point2f h1 [] {{188.f, 180.f}, {188.f, 197.f}, {214.f, 197.f}, {214.f, 162.f}};
    Point2f h2 [] {{214.f, 160.f}, {214.f, 202.f}, {246.f, 202.f}, {246.f, 160.f}};
    Point2f h3 [] {{246.f, 160.f}, {246.f, 197.f}, {274.f, 197.f}, {274.f, 177.f}};
    Point2f tail [] {{125.f, 183.f}, {172.f, 173.f}, {172.f, 148.f}, {125.f, 158.f}};
    Point2f t1 [] {{100.f, 165.f}, {110.f, 195.f}, {127.f, 190.f}, {127.f, 160.f}};
    Point2f t2 [] {{115.f, 160.f}, {90.f, 160.f}, {90.f, 180.f}, {120.f, 180.f}};
    Point2f t3 [] {{104.f, 175.f}, {104.f, 145.f}, {125.f, 145.f}, {127.f, 183.f}};
    Point2f f1 [] {{418.f, 120.f}, {380.f, 120.f}, {390.f, 200.f}, {434.f, 212.f}};
    Point2f f2 [] {{415.f, 205.f}, {410.f, 210.f}, {420.f, 240.f}, {430.f, 230.f}};
    Point2f rl1 [] {{403.f, 185.5f}, {380.f, 190.f}, {385.f, 215.f}, {410.f, 210.f}};
    Point2f rl2 [] {{400.f, 162.f}, {369.f, 167.f}, {377.f, 191.f}, {403.f, 185.f}};
    Point2f ll1 [] {{425.f, 223}, {400.f, 228.f}, {405.f, 245.f}, {430.f, 235.f}};
    Point2f ll2 [] {{428.f, 205}, {395.f, 210.f}, {400.f, 230.f}, {430.f, 220.f}};
    Part parts [] {{ear, sizeof(ear) / sizeof(*ear), false},
                   {head, sizeof(head) / sizeof(*head), true},
                   {eye, sizeof(eye) / sizeof(*eye), true},
                   {iris, sizeof(iris) / sizeof(*iris), true},
                   {biris, sizeof(biris) / sizeof(*biris), true},
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
                   {hair2, sizeof(hair2) / sizeof(*hair2), false},
                   {h1, sizeof(h1) / sizeof(*h1), false},
                   {h2, sizeof(h2) / sizeof(*h2), false},
                   {h3, sizeof(h3) / sizeof(*h3), false},
                   {tail, sizeof(tail) / sizeof(*tail), true},
                   {t1, sizeof(t1) / sizeof(*t1), false},
                   {t2, sizeof(t2) / sizeof(*t2), false},
                   {t3, sizeof(t3) / sizeof(*t3), false},
                   {f1, sizeof(f1) / sizeof(*f1), false},
                   {f2, sizeof(f2) / sizeof(*f2), false},
                   {rl1, sizeof(rl1) / sizeof(*rl1), false},
                   {rl2, sizeof(rl2) / sizeof(*rl2), false},
                   {ll1, sizeof(ll1) / sizeof(*ll1), false},
                   {ll2, sizeof(ll2) / sizeof(*ll2), false}};
    Sketch sketch {width, height};
    sketch.setBackgroundColour({1.f, 1.f, 1.f});
    sketch.setDrawColour({0.f, 0.f, 0.f});
    for (int i = 0; i < sizeof(parts) / sizeof(*parts); ++i) {
        sketch.drawCurve(parts[i]);
        // sketch.colourPart(parts[i], {1.f, 128.f/255.f, 149.f/255.f});
    }
    sketch.erase({155, 157}, {173, 177});
    sketch.erase({431, 309}, {457, 327});
    sketch.erase({334, 369}, {356, 405});
    sketch.erase({221, 445}, {235, 480});
    sketch.erase({232, 345}, {274, 351});
    sketch.erase({215, 293}, {245, 309});
    sketch.erase({288, 168}, {324, 204});
    sketch.erase({351, 220}, {361, 233});
    sketch.erase({168, 348}, {206, 485});
    sketch.erase({177, 302}, {184, 321});
    sketch.erase({184, 309}, {201, 333});
    sketch.erase({200, 329}, {222, 360});
    sketch.erase({222, 334}, {225, 352});
    sketch.erase({225, 345}, {229, 351});
    sketch.erase({229, 347}, {231, 349});
    sketch.erase({355, 219}, {357, 221});
    sketch.erase({310, 140}, {357, 204});
    sketch.erase({351, 204}, {357, 218});
    sketch.erase({288, 481}, {324, 495});
    sketch.colourObject({width / 2, height / 2}, {1.f, 128.f/255.f, 149.f/255.f});
    sketch.colourObject({427, 210}, {1.f, 128.f/255.f, 149.f/255.f});
    sketch.colourObject({413, 166}, {1.f, 128.f/255.f, 149.f/255.f});
    sketch.colourObject({110, 170}, {0.f, 0.f, 0.f});
    sketch.colourObject({230, 185}, {0.9f, 0.75f, 0.f});
    sketch.colourObject({204, 190}, {0.9f, 0.75f, 0.f});
    sketch.colourObject({260, 186}, {0.9f, 0.75f, 0.f});
    sketch.colourObject({384, 177}, {0.9f, 0.75f, 0.f});
    sketch.colourObject({392, 202}, {0.9f, 0.75f, 0.f});
    sketch.colourObject({408, 217}, {0.9f, 0.75f, 0.f});
    sketch.colourObject({413, 234}, {0.9f, 0.75f, 0.f});
    sketch.colourObject({317, 420}, {0.f, 0.f, 0.f});
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
