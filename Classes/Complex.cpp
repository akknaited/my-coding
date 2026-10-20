#include <iostream>

using namespace std;

class Comp {
  double a, b;
public:
  Comp(double a, double b) :a(a), b(b) {}
  Comp() :a(0), b(0) {}
  void print()
  {
    if (b > 0 && a != 0)
    {
      cout << a << "+" << b << "i" << endl;
    }
    else if (b > 0 && a == 0)
    {
      cout << b << "i" << endl;
    }
    else if (b < 0 && a!=0)
    {
      cout << a << b << "i" << endl;
    }
    else if (b < 0 && a == 0)
    {
      cout << b << "i" << endl;
    }
    else
    {
      cout << a << endl;
    }
  }
  void sum(Comp A) {
    a += A.a;
    b += A.b;
  }
  void proizvedenie(Comp A) {
    double c = A.a * a - b * A.b;
    double d = A.a * b + A.b * a;
    a = c;
    b = d;
  }
};

int main()
{
  Comp y(1, 4);
  Comp x(3, 6);
  Comp z(0, 1);
  
  z.print();

  y.print();
  y.sum(x);
  y.print();
  y.proizvedenie(z);
  y.print();

  return 0;
}
