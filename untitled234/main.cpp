#include <iostream>
#include <vector>
#include <math.h>
#include<iomanip>
using namespace std;
float K, L;

void Variant() {
    cout << "Введите вариант" << endl;
    int v;
    cin >> v;
    if (v > 16)
        v = v - 16;
    switch (v)
    {
        case 1: {
            K = round(3.2 * 10) / 10;
            L = round(1.6 * 10) / 10;
            break;
        }
        case 2: {
            K = round(3.4 * 10) / 10;
            L = round(1.8 * 10) / 10;
            break;
        }
        case 3: {
            K = round(3.6 * 10) / 10;
            L = round(2.0 * 10) / 10;
            break;
        }
        case 4: {
            K = round(3.8 * 10) / 10;
            L = round(2.2 * 10) / 10;
            break;
        }
        case 5: {
            K = round(4.0 * 10) / 10;
            L = round(2.4 * 10) / 10;
            break;
        }
        case 6: {
            K = round(2.2 * 10) / 10;
            L = round(1.2 * 10) / 10;
            break;
        }
        case 7: {
            K = round(2.4 * 10) / 10;
            L = round(1.4 * 10) / 10;
            break;
        }
        case 8: {
            K = round(2.6 * 10) / 10;
            L = round(1.6 * 10) / 10;
            break;
        }
        case 9: {
            K = round(2.8 * 10) / 10;
            L = round(1.8 * 10) / 10;
            break;
        }
        case 10: {
            K = round(3.0 * 10) / 10;
            L = round(2.2 * 10) / 10;
            break;
        }
        case 11: {
            K = round(1.2 * 10) / 10;
            L = round(0.8 * 10) / 10;
            break;
        }
        case 12: {
            K = round(1.4 * 10) / 10;
            L = round(1.0 * 10) / 10;
            break;
        }
        case 13: {
            K = round(1.6 * 10) / 10;
            L = round(1.2 * 10) / 10;
            break;
        }
        case 14: {
            K = round(1.8 * 10) / 10;
            L = round(1.4 * 10) / 10;
            break;
        }
        case 15: {
            K = round(4.2 * 10) / 10;
            L = round(3.2 * 10) / 10;
            break;
        }
        case 16: {
            K = round(4.4 * 10) / 10;
            L = round(3.4 * 10) / 10;
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    Variant();
    float a = 0, h = 0.5;
    vector <float> x;
    vector <float> y;
    x.resize(64);
    y.resize(64);
    a = round(((K - 1) / 2) * 10) / 10;
    cout << "Метод Эйлера" << endl;
    x[0] = 0;
    y[0] = L;
    cout << "x(0) = " << x[0] << endl << "y(0) = " << y[0] << endl;
    for (int i = 0; i < 4; i++) {
        y[i + 1] = round((y[i] + h * (x[i] * x[i] + a * y[i])) * 1000000) / 1000000;
        x[i + 1] = round((x[i] + 0.5) * 10) / 10;
        cout << "x(" << i + 1 << ") = x[" << i << "] + h = " << x[i + 1] << endl;
        cout << "y(" << i + 1 << ") = y[" << i << "] + h * f(x[" << i << "], y[" << i << "]) = " << y[i + 1] << endl;
    }
    x.clear();
    y.clear();
    x.resize(64);
    y.resize(64);
    cout << endl << "Метод трапеций" << endl;
    x[0] = 0;
    y[0] = L;
    cout << "x(0) = " << x[0] << endl << "y(0) = " << y[0] << endl;
    for (int i = 0; i < 4; i++) {
        x[i + 1] = round((x[i] + 0.5) * 10) / 10;
        y[i + 1] = round((y[i] + h / 2 * ((x[i] * x[i] + a * y[i]) + (x[i + 1] * x[i + 1] + a * (y[i] + h * (x[i] * x[i] + a * y[i]))))) * 1000000) / 1000000;
        cout << "x(" << i + 1 << ") = x[" << i << "] + h = " << x[i + 1] << endl;
        cout << "y(" << i + 1 << ") = y[" << i << "] + h / 2 * (f(x[" << i << "], y[" << i << "]) + f(x[" << i + 1 << "], y[" << i << "] + h * f(x[" << i  << "], y[" << i << "])) = " << y[i + 1] << endl;
    }
    x.clear();
    y.clear();
    x.resize(64);
    y.resize(64);
    cout << endl << "Метод Рунге-Кутты" << endl;
    x[0] = 0;
    y[0] = L;
    vector <float> k;
    k.resize(64);
    cout << "x(0) = " << x[0] << endl << "y(0) = " << y[0] << endl;
    for (int i = 0; i < 4; i++) {
        x[i + 1] = round((x[i] + 0.5) * 10) / 10;
        k[1] = round((x[i] * x[i] + a * y[i]) * 1000000) / 1000000;
        k[2] = round(((x[i] + h / 2) * (x[i] + h / 2) + a * (y[i] + h * k[1] / 2)) * 1000000) / 1000000;
        k[3] = round(((x[i] + h / 2) * (x[i] + h / 2) + a * (y[i] + h * k[2] / 2)) * 1000000) / 1000000;
        k[4] = round(((x[i] + h) * (x[i] + h) + a * (y[i] + h * k[3])) * 1000000) / 1000000;
        y[i + 1] = round((y[i] + h / 6 * (k[1] + 2 * k[2] + 2 * k[3] + k[4])) * 1000000) / 1000000;
        cout << "x(" << i + 1 << ") = x[" << i << "] + h = " << x[i + 1] << endl;
        cout << "K1[" << i << "] = f(x[" << i << "], y[" << i << "]) = " << k[1] << endl;
        cout << "K2[" << i << "] = f(x[" << i << "] + h / 2, y[" << i << "] + h * K1[" << i << "] / 2) = " << k[2] << endl;
        cout << "K3[" << i << "] = f(x[" << i << "] + h / 2, y[" << i << "] + h * K2[" << i << "] / 2) = " << k[3] << endl;
        cout << "K4[" << i << "] = f(x[" << i << "] + h, y[" << i << "] + h * K3[" << i << "]) = " << k[4] << endl;
        cout << "y(" << i + 1 << ") = y[" << i << "] + h / 6 * (K1[" << i << "] + 2 * K2[" << i << "] + 2 * K3[" << i << "] + K4[" << i << "]) = " << y[i + 1] << endl;
    }
}