#include <iostream>
#include <cmath>

using namespace std;

class Triangle
{
private:
  double a, b, c;
public:
  Triangle(double a, double b, double c) : a(a), b(b), c(c) {};
  Triangle() : a(0), b(0), c(0) {};

  void PrintTr()
  {
    cout << "Стороны треугольника: " << a << " " << b << " " << c << endl;
  }

  double Per()
  {
    return a + b + c;
  }

  double S()
  {
    return sqrt(Per() / 2 * (Per() / 2 - a)*(Per() / 2 - b)*(Per() / 2 - c));
  }

  bool SushLi()
  {
    if (a + b >= c && a + c >= b && b + c >= a)
    {
      return 1;
    }
    return 0;
  }

  bool Pr9Imoug()
  {
    if (a*a + b*b == c*c ||  a*a + c*c == b*b ||  b*b + c*c == a*a)
    {
      return 1;
    }
    return 0;
  }

  bool Ostroug()
  {
    if (a >= b && a >= c && a*a < b*b + c*c || b >= a && b >= c && b*b < a*a + c*c ||  c >= b && c >= a && c*c < b*b + a*a)
    {
      return 1;
    }
    return 0;
  }

  bool Tupoug()
  {
    if (a >= b && a >= c && a*a > b*b + c*c ||  b >= a && b >= c && b*b > a*a + c*c  ||  c >= b && c >= a && c*c > b*b + a*a)
    {
      return 1;
    }
    return 0;
  }

  bool Ravnobed()
  {
    if (a == b ||  a == c  || b == c)
    {
      return 1;
    }
    return 0;
  }

  bool Ravnost()
  {
    if (a == b && a == c)
    {
      return 1;
    }
    return 0;
  }

  friend Triangle operator *(Triangle A, Triangle B)
  {
    return Triangle(A.a + B.a, A.b + B.b, A.c + B.c);
  }

  friend Triangle operator ~(Triangle A)
  {
    return Triangle(A.Per() / 3, A.Per() / 3, A.Per() / 3);
  }

  friend Triangle operator --(Triangle &A)
  {
    if (A.a > A.b && A.a > A.c)
    {
      return Triangle(--A.a, A.b, A.c);
    }
    else if (A.b > A.a && A.b > A.c)
    {
      return Triangle(A.a, --A.b, A.c);
    }
    else if (A.c > A.b && A.c > A.a)
    {
      return Triangle(A.a, A.b, --A.c);
    }
    else if (A.a == A.b && A.a > A.c)
    {
      return Triangle(--A.a, --A.b, A.c);
    }
    else if (A.a > A.b && A.a == A.c)
    {
      return Triangle(--A.a, A.b, --A.c);
    }
    else if (A.b == A.c && A.b > A.a)
    {
      return Triangle(A.a, --A.b, --A.c);
    }
    else
    {
      return Triangle(--A.a, --A.b, --A.c);
    }
  }
  
  friend Triangle operator --(Triangle &A, int)
  {
    if (A.a > A.b && A.a > A.c)
    {
      return Triangle(A.a--, A.b, A.c);
    }
    else if (A.b > A.a && A.b > A.c)
    {
      return Triangle(A.a, A.b--, A.c);
    }
    else if (A.c > A.b && A.c > A.a)
    {
      return Triangle(A.a, A.b, A.c--);
    }
    else if (A.a == A.b && A.a > A.c)
    {
      return Triangle(A.a--, A.b--, A.c);
    }
    else if (A.a > A.b && A.a == A.c)
    {
      return Triangle(A.a--, A.b, A.c--);
    }
    else if (A.b == A.c && A.b > A.a)
    {
      return Triangle(A.a, A.b--, A.c--);
    }
    else
    {
      return Triangle(A.a--, A.b--, A.c--);
    }
  }

  friend double operator +(Triangle A, Triangle B)
  {
    return A.S() + B.S();
  }

  friend Triangle operator &(Triangle A, Triangle B)
  {
    if (A.Per() >= B.Per()) return A;
    else return B;
  }

  Triangle operator *(double d)
  {
    return Triangle(a*d, b*d, c*d);
  }

  friend bool operator <(Triangle A, Triangle B)
  {
    return (A.Per() < B.Per());
  }
  friend ostream& operator << (ostream& out, Triangle A)
  {
    return (out << A.a << " " << A.b << " " << A.c);
  }
  friend istream& operator >> (istream& str, Triangle& A)
  {
    return (str >> A.a >> A.b >> A.c);
  }
};

int main()
{
  setlocale(LC_ALL, "RU");

  Triangle A(3, 4, 5);
  Triangle B(10, 2, 3);

  (--A).PrintTr();

  (A&B).PrintTr();

  (A * 3).PrintTr();

  cout << (B < A) << endl;

  cout << A << endl;

  return 0;
}
