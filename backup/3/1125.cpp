#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#define pi 3.1415926535898
using namespace std;

int main(int argc, char* argv[]) {
    int n, m;
    int s1, s2, s3;

    double sina, cosa, tana;
    double sinb, cosb, tanb;
    double sinc, cosc, tanc;
    double mina, maxa, mida, sumx;

    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &s1, &s2, &s3);

    mina = 0;
    maxa = pi / 2;
    while (true) {
        mida = (mina + maxa) / 2;

        sina = sin(mida);
        cosa = cos(mida);
        tana = sina / cosa;

        sinb = sina * s2 / s1;
        cosb = sqrt(1 - sinb * sinb);
        tanb = sinb / cosb;

        sinc = sinb * s3 / s2;
        cosc = sqrt(1 - sinc * sinc);
        tanc = sinc / cosc;

        sumx = m * (tana + tanb + tanc);
        if (abs(sumx - n) <= 0.000001) {
            printf("%.10f\n", m / cosa / s1 + m / cosb / s2 + m / cosc / s3);
            break;
        }
        if (sumx < n)
            mina = mida;
        else
            maxa = mida;
    }

    return 0;
}
