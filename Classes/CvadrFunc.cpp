#include <iostream>
#include <cmath>

using namespace std;

class CvadrFunc
{
protected:
  double a, b, c;
public:
  CvadrFunc(double a, double b, double c): a(a), b(b), c(c){}
  CvadrFunc(): a(0), b(0), c(0){}

  void PrintFunc()
  {
    if (b < 0 && c < 0 && a != 0)
    {
      cout << "y = " << a << "x^2 " << b << "x " << c;
    }

    else if (b < 0 && c > 0 && a != 0)
    {
      cout << "y = " << a << "x^2 " << b << "x + " << c;
    }

    else if (b > 0 && c < 0 && a != 0)
    {
      cout << "y = " << a << "x^2 + " << b << "x " << c;
    }

    else if (b > 0 && c > 0 && a != 0)
    {
      cout << "y = " << a << "x^2 + " << b << "x +" << c;
    }

    else if (b > 0 && c == 0 && a != 0)
    {
      cout << "y = " << a << "x^2 + " << b << "x";
    }

    else if (b < 0 && c == 0 && a != 0)
    {
      cout << "y = " << a << "x^2 " << b << "x";
    }

    else if (b == 0 && c > 0 && a != 0)
    {
      cout << "y = " << a << "x^2 + " << c;
    }

    else if (b == 0 && c < 0 && a != 0)
    {
      cout << "y = " << a << "x^2 " << c;
    }
    else if (b < 0 && c < 0 && a == 0)
    {
      cout << "y = " << b << "x " << c;
    }

    else if (b < 0 && c > 0 && a == 0)
    {
      cout << "y = " << b << "x + " << c;
    }

    else if (b > 0 && c < 0 && a == 0)
    {
      cout << "y = " << b << "x " << c;
    }

    else if (b > 0 && c > 0 && a == 0)
    {
      cout << "y = " << b << "x +" << c;
    }

    else if (b > 0 && c == 0 && a == 0)
    {
      cout << "y = " << b << "x";
    }

    else if (b < 0 && c == 0 && a == 0)
    {
      cout << "y = " << b << "x";
    }

    else if (b == 0 && c > 0 && a == 0)
    {
      cout << "y = " << c;
    }

    else if (b == 0 && c < 0 && a == 0)
    {
      cout << "y = "<< c;
    }
  }
  void VivodPeresechSOs()
  {
    if (a == 0) 
    {
        if (b == 0) 
        {
            cout << "Получили прямую у = " << c;
            if (c != 0) cout << ". Пересечений с осью OX нет. Пересечение с OY: (0; " << c << ")";
            else cout << ". Прямая совпадает с осью OX.";
            cout << endl;
            return;
        }
        
        double x = -c / b;
        if (c == 0) cout << "Функция пересекается с осью OX и OY в точке: (0; 0)" << endl;
        else cout << "Функция пересекается с осью OY в точке: (0; " << c << ") и с осью OX в точке: (" << x << "; 0)" << endl;
        return;
    }

    double D = b * b - 4 * a * c;
    
    if (D < 0) 
    {
        if (c == 0) cout << "Пересечений с осью OX нет. Пересечение с OY: (0; 0)" << endl;
        else cout << "Пересечений с осью OX нет. Пересечение с OY: (0; " << c << ")" << endl;
    }
    else if (D == 0) 
    {
        double x = -b / (2 * a);
        if (c == 0) cout << "Функция пересекается с осью OX в точке: (" << x << "; 0)" << endl;
        else cout << "Функция пересекается с осью OY в точке: (0; " << c << ") и с осью OX в точке: (" << x << "; 0)" << endl;
    }
    else 
    {
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        if (c == 0) cout << "Функция пересекается с осью OX в точках: (" << x1 << "; 0) и (" << x2 << "; 0)" << endl;
        else cout << "Функция пересекается с осью OY в точке: (0; " << c << ") и с осью OX в точках: (" << x1 << "; 0) и (" << x2 << "; 0)" << endl;
    }
  }
};

int main()
{
  setlocale(LC_ALL, "RU");

  CvadrFunc A(0, 0, -7);
  A.VivodPeresechSOs();
  A.PrintFunc();

  return 0;
}
