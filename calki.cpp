#include <iostream>
#include <cmath>
using namespace std;

double funkcja(double x)
{
   return (exp((pow(x, 2) * -1) / 2)) / (sqrt(2 * (2 * acos(0.0))));
}


int main()
{
    double a = -3, b = 3, h, n = 2, suma = 0.0, tym, dokladnosc = 0.00001, suma_t = 0;

    cout << "Metoda trapezow:\n";

    do {
        tym = suma;
        suma = 0.0;
        h = (b - a) / n;
        for (int i = 1; i < n; i++)
        {
            suma += funkcja(a + (i * h));
        }
        suma = (suma + (funkcja(a) + funkcja(b)) / 2.0) * h;
        n *= 2;
    } while (abs(suma - tym) > dokladnosc);


   cout << "Wartosc calki: " << suma;
   cout << "\nIlosc przedzialow: " << n / 2 << endl;

    cout << "\nMetoda Simpsona: \n";
    n = 2, suma = 0, tym = 0;
    do
    {
        tym = suma;
        suma = 0.0;
        suma_t = 0.0;
        h = (b - a) / n;
        for (int i = 1; i <= n; i++)
        {
            suma_t = suma_t + funkcja((a + i * h) - h / 2.0);
            if (i < n)
                suma += funkcja(a + i * h);
        }
        suma = (h / 6.0) * (funkcja(a) + funkcja(b) + 2.0 * suma + 4.0 * suma_t);
        n *= 2;
    } while (abs(suma - tym) > dokladnosc);
    cout << "Wartosc calki: " << suma;
    cout << "\nIlosc przedzialow: " << n / 2<<endl;
    cout << "\nMetoda Milne'a: ";
    double x1, x2, x3, x4, x0;
    n = 4;
    h = (b - a) / 4.0;
    x0 = a+h*0;
    x1 = a + h * 1;
    x2 = a + h * 2;
    x3 = a + h * 3;
    x4 = a + h * 4;
    suma = (b-a)*((funkcja(x0)*7./90.)+(funkcja(x1)*32./90.)+(funkcja(x2)*12./90.)+(funkcja(x3)*32./90.)+(funkcja(x4)*7./90.));
    cout << "\nWartosc calki: " << suma;
    cout << "\nIlosc przedzialow: " << n << endl;

    return 0;
}
