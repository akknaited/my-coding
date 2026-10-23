#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
  int n, m;
  vector<vector<double>> a;
public:
  Matrix(int n, int m, vector<vector<double>> a) : n(n), m(m), a(a) {};
  Matrix() : n(0), m(0), a() {};

  void PrintMatrix()
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cout << a[i][j] << " ";
      }
      cout << endl;
    }
  }

  Matrix Sum(Matrix B)
  {
    if (n != B.n || m != B.m)
    {
      return Matrix(0, 0, {}); 
    }

    vector<vector<double>> res(n, vector<double>(m, 0));

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        res[i][j] = a[i][j] + B.a[i][j]; 
      }
    }
    
    return Matrix(n, m, res);
  }

  Matrix Umn(double c)
  {
    vector<vector<double>> res(n, vector<double>(m, 0));

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        res[i][j] = a[i][j] * c;
      }
    }
    
    return Matrix(n, m, res);
  }
};

int main()
{
  setlocale(LC_ALL, "RU");
  
  Matrix A(3, 3, { {1, 2, 3}, {3, 4, 5}, {6, 7, 8} });
  Matrix B(3, 3, { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} });
  
  A.PrintMatrix();
  
  Matrix C = A.Sum(B);
  C.PrintMatrix();
  
  Matrix D = A.Umn(2);
  D.PrintMatrix();
  
  return 0;
}
