#include <iostream>

using namespace std;

class Rectangle 
{
private:
  double a, b;
public:
  Rectangle(double a, double b) : a(a), b(b) {};
  Rectangle() : a(0), b(0) {};

  void PrintPr()
  {
    cout << "Прямоугольник имеет стороны " << a << " и " << b << endl;
  }

  friend double operator +(Rectangle A, Rectangle B)
  {
    return A.a*A.b + B.a*B.b;
  }

  friend Rectangle operator *(Rectangle A, double c)
  {
    return Rectangle(A.a*c, A.b*c);
  }
};

int main()
{
  setlocale(LC_ALL, "RU");
  Rectangle A(3, 4);
  Rectangle B(5, 6);

  double c = 3;

  A.PrintPr();

  (A * c).PrintPr();
  cout << A + B;

  return 0;
}
