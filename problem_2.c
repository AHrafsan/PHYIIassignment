#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
    double mg = 3.0, lg = 530e-9, tg = 65.0, mr = 2.0, lr = 700e-9, d, tr;
                                      //mg=order of green, lg= wavelength of green, tg= theta of green,
                                      //mg=order of red, lr= wavelength of red, tr= theta of red,
                                      //d= distance
    tg = tg * PI / 180.0;
    d = (mg * lg) / sin(tg);
    tr = asin((mr * lr) / d);
    tr = tr * 180.0 / PI;
    printf("The second-order bright spot for red light will be at %.2f degrees.\n", tr);

    return 0;
}
