#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include "stdafx.h"
#include <vector>

using namespace std;

namespace CS2130
{
	template <typename T> class Matrix
	{
	private:
		std::vector<std::vector<T>> mat;
		unsigned rows;
		unsigned cols;

		void DetermineMatrixType();

		bool CheckReflexive();
		bool CheckIrreflexive();
		bool CheckSymmetric();
		bool CheckAntiSymmetric();
		bool CheckAsymmetric();

	public:
		Matrix(unsigned _rows, unsigned _cols, const T& _initial);
		Matrix(const Matrix<T>& rhs);
		virtual ~Matrix();

		// Operator overloading, for "standard" mathematical matrix operations                                                                                                                                                          
		Matrix<T>& operator=(const Matrix<T>& rhs);

		// Matrix mathematical operations                                                                                                                                                                                               
		Matrix<T> operator+(const Matrix<T>& rhs);
		Matrix<T>& operator+=(const Matrix<T>& rhs);
		Matrix<T> operator-(const Matrix<T>& rhs);
		Matrix<T>& operator-=(const Matrix<T>& rhs);
		Matrix<T> operator*(const Matrix<T>& rhs);
		Matrix<T>& operator*=(const Matrix<T>& rhs);
		Matrix<T> transpose();

		// Matrix/scalar operations                                                                                                                                                                                                     
		Matrix<T> operator+(const T& rhs);
		Matrix<T> operator-(const T& rhs);
		Matrix<T> operator*(const T& rhs);
		Matrix<T> operator/(const T& rhs);

		// Matrix/vector operations                                                                                                                                                                                                     
		std::vector<T> operator*(const std::vector<T>& rhs);
		std::vector<T> diag_vec();

		// Access the individual elements                                                                                                                                                                                               
		T& operator()(const unsigned& row, const unsigned& col);
		const T& operator()(const unsigned& row, const unsigned& col) const;

		// Access the row and column sizes                                                                                                                                                                                              
		unsigned get_rows() const;
		unsigned get_cols() const;

		// Return the core Matrix
		vector<vector<T>>& GetMatrixAs2DVector();

		// Set index value
		void SetIndexValue(int x, int y, const T& value);

		// Output Matrix Types
		void DisplayOutputTypes();

		// Determine the type of the matrix (reflexive, irreflexive, symmetric, asymmetric, anti-symmetric, none)
		enum MatrixType
		{
			Reflexive, Irreflexive, Symmetric, Asymmetric, AntiSymmetric, None
		};
		std::vector<MatrixType> TypeOfMatrix;
	};

	/*
	----------------------FUNCTION DECLARATIONS-------------------------
	THIS IS REQUIRED TO BE IN THE SAME FILES FOR TEMPLATES BECAUSE LOGIC
	----------------------FUNCTION DECLARATIONS-------------------------
	*/

	template<typename T>
	void Matrix<T>::SetIndexValue(int x, int y, const T& value)
	{
		this->mat[x][y] = value;
	}

	template<typename T>
	void Matrix<T>::DisplayOutputTypes()
	{
		DetermineMatrixType();

		for (int i = 0; i < TypeOfMatrix.size(); i++)
		{
			MatrixType type = TypeOfMatrix[i];

			switch (type)
			{
			case MatrixType::Reflexive:
				cout << "Reflexive ";
				break;
			case MatrixType::Irreflexive:
				cout << "Irreflexive ";
				break;
			case MatrixType::Symmetric:
				cout << "Symmetric ";
				break;
			case MatrixType::AntiSymmetric:
				cout << "Anti-Symmetric ";
				break;
			case MatrixType::Asymmetric:
				cout << "Asymmetric ";
				break;
			case MatrixType::None:
				cout << "None";
				break;
			default:
				cout << "ERROR IN CASE STATEMENT!";
				break;
			}
		}

		cout << endl;
	}

	template<typename T>
	void Matrix<T>::DetermineMatrixType()
	{
		// Reflexive or Irreflexive (Not both)
		if (CheckReflexive())
			TypeOfMatrix.push_back(MatrixType::Reflexive);
		else if (CheckIrreflexive())
			TypeOfMatrix.push_back(MatrixType::Irreflexive);

		// Check Symmetric/Anti/Asymmetric
		if (CheckSymmetric())
			TypeOfMatrix.push_back(MatrixType::Symmetric);

		if (CheckAntiSymmetric())
			TypeOfMatrix.push_back(MatrixType::AntiSymmetric);

		if (CheckAsymmetric())
			TypeOfMatrix.push_back(MatrixType::Asymmetric);

		if (TypeOfMatrix.size() == 0)
			// No valid types set to none
			TypeOfMatrix.push_back(MatrixType::None);
	}

	// Determine if the matrix is reflexive ie. 1's on the diagonal
	template<typename T>
	bool Matrix<T>::CheckReflexive()
	{
		std::vector<bool> diag = this->diag_vec();

		for (unsigned int i = 0; i < diag.size(); i++)
		{
			if (!diag[i])
				return false;
		}

		return true;
	}

	// Determine if the matrix is irreflexive ie. 0's on the diagonal
	template<typename T>
	bool Matrix<T>::CheckIrreflexive()
	{
		std::vector<bool> diag = this->diag_vec();

		for (unsigned int i = 0; i < diag.size(); i++)
		{
			if (diag[i])
				return false;
		}

		return true;
	}

	template<typename T>
	bool Matrix<T>::CheckSymmetric()
	{
		Matrix<bool> matOrig = *this;

		for (int x = 0; x < this->get_cols(); x++)
			for (int y = 0; y < this->get_rows(); y++)
				if (x != y)
					if (!(matOrig(x, y) && matOrig(y, x)))
						return false;
		return true;
	}

	// THIS FUNCTION WAS FREAKING STUIPD IT TOOK ME A FREAKING WEEK 
	// TO MAKE IT WORK ALL BECAUSE OF A STUIPID MATH ERROR!
	template<typename T>
	bool Matrix<T>::CheckAntiSymmetric()
	{
		Matrix<bool> matOrig = *this;
		bool IsValidFlag = true;

		for (int x = 0; x < this->get_cols(); x++)
			for (int y = 0; y < this->get_rows(); y++)
				if (x != y)
					if (!(matOrig(x, y) || matOrig(y, x))
						|| (matOrig(x, y) && matOrig(y, x)))
						return false;
		return true;
	}

	// Determine if the matrix is Asymmetric ie. antisymmetric und Irreflexive
	template<typename T>
	bool Matrix<T>::CheckAsymmetric()
	{
		if (CheckAntiSymmetric() && CheckIrreflexive())
			return true;
		else
			return false;
	}

	template<typename T>
	vector<vector<T>>& Matrix<T>::GetMatrixAs2DVector()
	{
		return &mat;
	}

	template<typename T>
	Matrix<T>::Matrix(unsigned _rows, unsigned _cols, const T& _initial)
	{
		mat.resize(_rows);
		for (unsigned i = 0; i < mat.size(); i++)
		{
			mat[i].resize(_cols, _initial);
		}
		rows = _rows;
		cols = _cols;
	}

	// Copy Constructor                                                                                                                                                           
	template<typename T>
	Matrix<T>::Matrix(const Matrix<T>& rhs)
	{
		mat = rhs.mat;
		rows = rhs.get_rows();
		cols = rhs.get_cols();
	}

	// Destructor                                                                                                                                                       
	template<typename T>
	Matrix<T>::~Matrix() {}

	template<typename T>
	Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs)
	{
		if (&rhs == this)
			return *this;

		unsigned new_rows = rhs.get_rows();
		unsigned new_cols = rhs.get_cols();

		mat.resize(new_rows);
		for (unsigned i = 0; i < mat.size(); i++)
		{
			mat[i].resize(new_cols);
		}

		for (unsigned i = 0; i < new_rows; i++)
		{
			for (unsigned j = 0; j < new_cols; j++)
			{
				mat[i][j] = rhs(i, j);
			}
		}
		rows = new_rows;
		cols = new_cols;

		return *this;
	}

	template<typename T>
	Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs)
	{
		Matrix result(rows, cols, 0.0);

		for (unsigned i = 0; i < rows; i++)
		{
			for (unsigned j = 0; j < cols; j++)
			{
				result(i, j) = this->mat[i][j] + rhs(i, j);
			}
		}

		return result;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs)
	{
		unsigned rows = rhs.get_rows();
		unsigned cols = rhs.get_cols();

		for (unsigned i = 0; i < rows; i++)
		{
			for (unsigned j = 0; j < cols; j++)
			{
				this->mat[i][j] += rhs(i, j);
			}
		}

		return *this;
	}

	template<typename T>
	Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs)
	{
		unsigned rows = rhs.get_rows();
		unsigned cols = rhs.get_cols();
		Matrix result(rows, cols, 0.0);

		for (unsigned i = 0; i < rows; i++)
		{
			for (unsigned j = 0; j < cols; j++)
			{
				result(i, j) = this->mat[i][j] - rhs(i, j);
			}
		}

		return result;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& rhs)
	{
		unsigned rows = rhs.get_rows();
		unsigned cols = rhs.get_cols();

		for (unsigned i = 0; i < rows; i++)
		{
			for (unsigned j = 0; j < cols; j++)
			{
				this->mat[i][j] -= rhs(i, j);
			}
		}

		return *this;
	}

	template<typename T>
	Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs)
	{
		unsigned rows = rhs.get_rows();
		unsigned cols = rhs.get_cols();
		Matrix result(rows, cols, 0.0);

		for (unsigned i = 0; i < rows; i++)
		{
			for (unsigned j = 0; j < cols; j++)
			{
				for (unsigned k = 0; k < rows; k++)
				{
					result(i, j) += this->mat[i][k] * rhs(k, j);
				}
			}
		}

		return result;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& rhs)
	{
		Matrix result = (*this) * rhs;
		(*this) = result;
		return *this;
	}

	// Calculate a transpose of this matrix                                                                                                                                       
	template<typename T>
	Matrix<T> Matrix<T>::transpose()
	{
		Matrix result(rows, cols, 0.0);

		for (unsigned i = 0; i < rows; i++)
		{
			for (unsigned j = 0; j < cols; j++)
			{
				result(i, j) = this->mat[j][i];
			}
		}

		return result;
	}

	// Matrix/scalar addition                                                                                                                                                     
	template<typename T>
	Matrix<T> Matrix<T>::operator+(const T& rhs)
	{
		Matrix result(rows, cols, 0.0);

		for (unsigned i = 0; i < rows; i++)
		{
			for (unsigned j = 0; j < cols; j++)
			{
				result(i, j) = this->mat[i][j] + rhs;
			}
		}

		return result;
	}

	// Matrix/scalar subtraction                                                                                                                                                  
	template<typename T>
	Matrix<T> Matrix<T>::operator-(const T& rhs)
	{
		Matrix result(rows, cols, 0.0);

		for (unsigned i = 0; i < rows; i++)
		{
			for (unsigned j = 0; j < cols; j++)
			{
				result(i, j) = this->mat[i][j] - rhs;
			}
		}

		return result;
	}

	// Matrix/scalar multiplication                                                                                                                                               
	template<typename T>
	Matrix<T> Matrix<T>::operator*(const T& rhs)
	{
		Matrix result(rows, cols, 0.0);

		for (unsigned i = 0; i < rows; i++)
		{
			for (unsigned j = 0; j < cols; j++)
			{
				result(i, j) = this->mat[i][j] * rhs;
			}
		}

		return result;
	}

	// Matrix/scalar division                                                                                                                                                     
	template<typename T>
	Matrix<T> Matrix<T>::operator/(const T& rhs)
	{
		Matrix result(rows, cols, 0.0);

		for (unsigned i = 0; i < rows; i++)
		{
			for (unsigned j = 0; j < cols; j++)
			{
				result(i, j) = this->mat[i][j] / rhs;
			}
		}

		return result;
	}

	// Multiply a matrix with a vector                                                                                                                                            
	template<typename T>
	std::vector<T> Matrix<T>::operator*(const std::vector<T>& rhs)
	{
		std::vector<T> result(rhs.size(), 0.0);

		for (unsigned i = 0; i < rows; i++)
		{
			for (unsigned j = 0; j < cols; j++)
			{
				result[i] = this->mat[i][j] * rhs[j];
			}
		}

		return result;
	}

	// Obtain a vector of the diagonal elements                                                                                                                                   
	template<typename T>
	std::vector<T> Matrix<T>::diag_vec()
	{
		std::vector<T> result(rows, 0.0);

		for (unsigned i = 0; i < rows; i++)
		{
			result[i] = this->mat[i][i];
		}

		return result;
	}

	// Access the individual elements                                                                                                                                             
	template<typename T>
	T& Matrix<T>::operator()(const unsigned& row, const unsigned& col)
	{
		bool boolvar = this->mat[row][col];
		return boolvar;
	}

	// Access the individual elements as a (const)                                                                                                                                     
	template<typename T>
	const T& Matrix<T>::operator()(const unsigned& row, const unsigned& col) const
	{
		return this->mat[row][col];
	}

	// Get the number of rows of the matrix                                                                                                                                       
	template<typename T>
	unsigned Matrix<T>::get_rows() const
	{
		return this->rows;
	}

	// Get the number of columns of the matrix                                                                                                                                    
	template<typename T>
	unsigned Matrix<T>::get_cols() const
	{
		return this->cols;
	}
}
#endif