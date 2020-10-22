#include <stdio.h>
#include <math.h>

/// funkcja zwraca 0 gdy nie znajdzie miejsca zerowego, 1 gdy znajdzie
///
/// *f   - wskaźnik do funkcji
/// a, b - poczatek i koniec przedziału
/// m_z  - miejsce zerowe
/// eps  - dokładność
int zero(double (*f)(double), double a, double b, double* m_z, double eps);

double f(double x){
    return -(x*x)+(3.0)*x+11.0;
}

int main() {
    double a, b, mz, eps;

    a = -1; b = 1; eps = 1e-3;
    int z = zero(sin, a, b, &mz, eps);
    if (z == 0){
        printf("Nie znaleziono miejsca zerowego\n");
    } else {
        printf("dla funkcji sin(x) mz = %.2f w przedziale <%.2f,%.2f>\n", mz, a, b);
    }


    a = 0; b = 8;
    z = zero(f, a, b, &mz, eps);
    if (z == 0){
        printf("Nie znaleziono miejsca zerowego\n");
    } else {
        printf("dla funkcji f(x) mz = %.2f w przedziale <%.2f,%.2f>\n", mz, a, b);
    }


    a = -1; b = 1;
    z = zero(f, a, b, &mz, eps);
    if (z == 0){
        printf("Nie znaleziono miejsca zerowego\n");
    } else {
        printf("dla funkcji f(x) mz = %.2f w przedziale <%.2f,%.2f>\n", mz, a, b);
    }

    return 0;
}

int zero(double (*f)(double), double a, double b, double* m_z, double eps){
    double fa = f(a);
    double fb = f(b);
    double eps0 = 1e-6;

    if(fa * fb > 0) {
        return 0;
    } else {
        while(fabs(a - b) > eps) {
            *m_z = (a + b) / 2;
            double f0 = f(*m_z);
            if(fabs(f0) < eps0) {
                break;
            }
            if(fa * f0 < 0) {
                b = *m_z;
            } else {
                a = *m_z;
                fa = f0;
            }
        }
    }

    return 1;
}