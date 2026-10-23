#include <iostream>
#include <cmath>

using namespace std;

class Point
{
  double x, y;

public:

  Point(double x, double y) : x(x), y(y) {}

  Point() : x(0), y(0) {}

  void print()
  {
    cout << x << ' ' << y;
  }

  double rastOO()
  {
    return sqrt(x*x + y * y);
  }

  double pervec(double a, double b)
  {
    x += a;
    y += b;
    return rastOO();
  }

  double rastto4(double x1, double y1)
  {
    return sqrt((x1 - x)*(x1 - x) + (y1 - y)*(y1 - y));
  }

  void simmOO(Point n)
  {
    n.x *= -1;
    n.y *= -1;
  }

  void simmOa(Point n)
  {
    n.y *= -1;
  }

  void simmOb(Point n)
  {
    n.x *= -1;
  }

  int chetv()
  {
    if (x > 0 && y > 0) return 1;
    else if (x < 0 && y > 0) return 2;
    else if (x < 0 && y < 0) return 3;
    else return 4;
  }

  friend Point operator +(Point A, Point B)
  {
    return Point(A.x + B.x, A.y + B.y);
  }

  Point operator ++()
  {
    return Point(++x, ++y);
  }

  Point operator ++(int)
  {
    return Point(x++, y++);
  }

  Point operator -()
  {
    return Point(-x, -y);
  }

  friend Point operator *(Point A, Point B)
  {
    return Point((B.x - A.x) / 2, (B.y - A.y) / 2);
  }

  friend double operator &(Point A, Point B)
  {
    return sqrt((B.x - A.x)*(B.x - A.x) - (B.y - A.y)*(B.y - A.y));
  }

  friend Point operator *(Point A, int c)
  {
    return Point(A.x*c, A.y*c);
  }

  friend ostream& operator << (ostream& out, Point A)
  {
    return (out << A.x << " " << A.y);
  }

  friend istream& operator >> (istream& str, Point& A)
  {
    return (str >> A.x >> A.y);
  }
};

int main()
{
  Point A;
  cin >> A;
  cout << A;

  return 0;
}
