/************************
* Автор: Долинин Никита.*
* Название: Вариант 5   *
************************/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <locale>
using namespace std;
 
int main() {
  setlocale(LC_ALL, "Russian");

  double tR = 500.0;
  double tB = 15.0;
  double nu_cm2_s = 0.15;
  double nu = nu_cm2_s * 0.0001;
  double g = 9.81;

  cout << fixed << setprecision(1);
  cout << "m    Gr          Nu" << endl;

  double d = 0.1;
  while (d <= 0.3) {
    double deltaT = tR - tB;
    double Gr = g * pow(d, 3.0) * deltaT / (nu * nu * (tB + 273.0));

    double Nu;
    if (Gr < 1000000000) {
      Nu = 0.76 * pow(Gr, 0.22);
    } else {
      Nu = 0.15 * pow(Gr, 0.35);
    }

    cout << d << "  " << Gr << "  " << Nu << endl;

    if (d == 0.1) d = 0.2;
    else if (d == 0.2) d = 0.25;
    else if (d == 0.25) d = 0.275;
    else if (d == 0.275) d = 0.3;
    else d += 1;
  }
  return 0;
}
