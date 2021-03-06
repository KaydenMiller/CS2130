#include "stdafx.h"
#include "matrix.h"

using std::cout;
using std::endl;
using CS2130::Matrix;

void DisplayMatrix(Matrix<bool> mat)
{
	for (int x = 0; x < mat.get_cols(); x++)
	{
		for (int y = 0; y < mat.get_rows(); y++)
		{
			cout << (mat(x, y) ? "T " : "F ");
		}
		cout << endl;
	}
}

int main(int argc, char **argv)
{
	cout << "Matrix 1: " << endl;
	Matrix<bool> boolMat1(3, 3, true);
	DisplayMatrix(boolMat1);
	cout << "Matrix 1 Type: ";
	boolMat1.DisplayOutputTypes();

	cout << "Matrix 2: " << endl;
	Matrix<bool> boolMat2(3, 3, false);
	DisplayMatrix(boolMat2);
	cout << "Matrix 2 Type: ";
	boolMat2.DisplayOutputTypes();

	cout << "Matrix 3: " << endl;
	Matrix<bool> boolMat3(3, 3, true);
	boolMat3.SetIndexValue(0, 0, false);
	boolMat3.SetIndexValue(1, 1, false);
	boolMat3.SetIndexValue(2, 2, false);
	DisplayMatrix(boolMat3);
	cout << "Matrix 3 Type: ";
	boolMat3.DisplayOutputTypes();

	cout << "Matrix 4: " << endl;
	Matrix<bool> boolMat4(3, 3, true);
	boolMat4.SetIndexValue(1, 0, false);
	boolMat4.SetIndexValue(2, 0, false);
	boolMat4.SetIndexValue(2, 1, false);
	DisplayMatrix(boolMat4);
	cout << "Matrix 4 Type: ";
	boolMat4.DisplayOutputTypes();

	cout << "Matrix 5: " << endl;
	Matrix<bool> boolMat5(3, 3, false);
	boolMat5.SetIndexValue(1, 0, true);
	boolMat5.SetIndexValue(2, 0, true);
	boolMat5.SetIndexValue(2, 1, true);
	DisplayMatrix(boolMat5);
	cout << "Matrix 5 Type: ";
	boolMat5.DisplayOutputTypes();

	cout << "Matrix 6: " << endl;
	Matrix<bool> boolMat6(3, 3, true);
	boolMat6.SetIndexValue(0, 0, false);
	boolMat6.SetIndexValue(1, 0, false);
	boolMat6.SetIndexValue(2, 0, true);
	boolMat6.SetIndexValue(2, 1, true);
	DisplayMatrix(boolMat6);
	cout << "Matrix 6 Type: ";
	boolMat6.DisplayOutputTypes();

	system("PAUSE");
	return 0;
}