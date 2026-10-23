#include <iostream>

using namespace std;

class Line 
{
private:
  double k, b;
public:
  Line(double k, double b) : k(k), b(b) {};
  Line() :k(0), b(0) {};

  void PrintLine()
  {
    if (k > 0 && b > 0)
    {
      cout << "y=" << k << "x+" << b;
    }
    else if (k > 0 && b < 0)
    {
      cout << "y=" << k << "x" << b;
    }
    else if (k < 0 && b > 0)
    {
      cout << "y=" << k << "x+"<< b;
    }
    else if (k < 0 && b < 0)
    {
      cout << "y=" << k << "x" << b;
    }
    else if (k == 0 && b != 0)
    {
      cout << "y="  << b;
    }
    else if (k != 0 && b == 0)
    {
      cout << "y=" << k << "x";
    }
    else
    {
      cout << "y=0";
    }
  }

  void CoordPerese4()
  {
    if (k == 0 && b == 0)
    {
      cout << "Прямая совпадает с осью OX, а с осью OY пересекается в точке (0;0)";
    }
    else if (k != 0 && b != 0)
    {
      cout << "Прямая переесекается с осью OX в точке (" << -b / k << "; 0) и с осью OY в точке (0;" << b << ")";
    }
    else if (k != 0 && b == 0)
    {
      cout << "Прямая переесекается с осью OX и OY в точке (0;0)";
    }
    else if (k == 0)
    {
      cout << "Прямая не переесекается с осью OX, а с оьсю OY в точке (0;" << b << ")";
    }
  }

};

int main()
{
  setlocale(LC_ALL, "RU");
  Line a(0, 2);
  a.PrintLine();
  a.CoordPerese4();

  return 0;
}
