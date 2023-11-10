#include<stdio.h>
#include<math.h>

#define PI 3.1415926535

double isSinTheta(double lambda, double order, double width)
{
    double sin_theta;
    sin_theta = ((lambda*1e-9)*(order)) / (width*1e-6);
    return sin_theta;
}
double isTheta(double sin_theta)
{
    double theta;
    theta = ((asin(sin_theta)*180) / PI);
    return theta;
}


int main() {
    double l, m, a1, a2, a3, t1, t2, t3;

    printf("Enter the value of wavelength (in nm): ");
    scanf("%lf", &l);
    if (l <= 380 || l >= 750) {
        printf("Out of the range. Please enter a valid number.\n");
        return 1;
    }

    printf("Enter the value of 'm' : ");
    scanf("%lf", &m);

    printf("Enter the values of 'a' for three cases (in micrometers):\n");
    scanf("%lf %lf %lf", &a1, &a2, &a3);

    double sin_t1, sin_t2, sin_t3;
    sin_t1 = isSinTheta(l, m, a1);
    sin_t2 = isSinTheta(l, m, a2);
    sin_t3 = isSinTheta(l, m, a3);

    t1 = isTheta(sin_t1);
    t2 = isTheta(sin_t2);
    t3 = isTheta(sin_t3);

    printf("For a1 = %.2lf, t1 = %lf degree\n", a1, t1);
    printf("For a2 = %.2lf, t2 = %lf degree\n", a2, t2);
    printf("For a3 = %.2lf, t3 = %lf degree\n\n", a3, t3);

    if (t1 > t2 && t1 > t3) {
        printf("Slit a1=%lf will bent the light more.\n",a1);
    } else if (t2 > t1 && t2 > t3) {
        printf("Slit a2=%lf will bent the light more.\n",a2);
    } else {
        printf("Slit a3=%lf will bent the light more.\n",a3);
    }

    return 0;
}
