#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Polynomial
{
private:
  int n;
  vector<double> a;

public:
  Polynomial(int n, vector<double> a) : n(n), a(a) {};
  Polynomial() : n(0), a() {};

  void PrintPolynomial()
  {
    int k = n;
    bool isFirst = true;

    for (int i = 0; i < n + 1; i++)
    {
      if (a[i] == 0) { k--; continue; }

      if (!isFirst && a[i] > 0) cout << "+";

      if (k > 0) 
      {
        cout << a[i] << "*x";
        if (k > 1) cout << "^" << k;
      }
      else 
      {
        cout << a[i];
      }
      
      isFirst = false;
      k--;
    }
    
    if (isFirst) cout << "0";
    cout << endl;
  }

  double CalculatePolynomial(double x)
  {
    double sum = 0;
    int k = n;
    for (int i = 0; i < n + 1; i++)
    {
      sum += (a[i] * pow(x, k));
      k--;
    }
    return sum;
  }
};

int main()
{
  Polynomial A(4, { 4, 5, 2, 3, 9 });

  A.PrintPolynomial();

  cout << A.CalculatePolynomial(2);

  return 0;
}
