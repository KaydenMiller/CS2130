#pragma once
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

namespace CompStructs
{
	class Matrix
	{
		int **p, m, n;
	public:
		Matrix(int row, int col)
		{
			m = row;
			n = col;
			p = new int*[m];
			for (int i = 0; i < m; i++)
				p[i] = new int[n];
		}

		/*~Matrix()
		{
			for (int i = 0; i < m; i++)
				delete p[i];
			delete p;
		}*/

		void build(vector<vector<int>> values)
		{
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					p[i][j] = values[i][j];
				}
			}
		}

		void display()
		{
			cout << "The matrix is:";
			for (int i = 0; i < m; i++)
			{
				cout << endl;
				for (int j = 0; j < n; j++)
				{
					cout << p[i][j] << " ";
				}
			}
		}

		Matrix operator +(Matrix m2)
		{
			Matrix T(m, n);
			if (m == m2.m && n == m2.n)
			{
				for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < n; j++)
					{
						T.p[i][j] = p[i][j] + m2.p[i][j];
					}
				}
			}		
			else
			{
				throw std::exception("error");
			}
			return T;
		}

		Matrix operator= (Matrix eq)
		{
			m = eq.m;
			n = eq.n;
			p = eq.p;

			return *this;
		}

		friend Matrix operator * (Matrix, Matrix);
	};

	Matrix operator* (Matrix a, Matrix b)
	{
		Matrix B(1, 1);
		if (a.n == b.m)
		{
			Matrix T(a.m, b.n);
			for (int i = 0; i < a.m; i++)
			{
				for (int k = 0; k < b.n; k++)
				{
					T.p[i][k] = 0;
					for (int j = 0; j < a.n; j++)
					{
						T.p[i][k] += a.p[i][j] * b.p[j][k];
					}
				}
			}
			B = T;
			return B;
		}
		else
		{
			throw std::exception("error");
		}
	}
}

