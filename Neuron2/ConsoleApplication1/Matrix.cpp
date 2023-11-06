#include "Matrix.h"
#include <iostream>
#include <string>
#include <fstream>
void Matrix::Init(int row, int col) {
	this->row = row;
	this->col = col;
	int i, j;
	m = new double* [row];
	for (i = 0; i < row; i++) {
		m[i] = new double [col];
	}
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			m[i][j] = 0;
		}
	}
}
void Matrix::Rand() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			m[i][j] = 1/(rand()%100+i*30+j*66);
		}
	}
}
void Matrix::PrintM() {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			std::cout<<m[i][j]<<" ";
		}
		std::cout << "\n";
	}
	std::cout << "=============================\n";
}
//void Matrix::PrintMfw()
//{
//	std::ofstream fout;
//	fout.open("weights.txt");
//	for (int j = 0; j < row; j++) {
//		for (int k = 0; k < col; k++) {
//			fout << m[j][k] << " ";
//		}
//		fout << "\n";
//	}
//	//fout << "===============================\n";
//	fout.close();
//
//}
//void Matrix::ReadMfw()
//{
//	std::ifstream fin;
//	fin.open("weights.txt");
//	for (int j = 0; j < row; j++) {
//		for (int k = 0; k < col; k++) {
//			fin >> m[j][k];
//		}
//	}
//	fin.close();
//}
void Matrix::PrintAll(const Matrix& a){
	int i, j,ii,jj;
	ii = a.col;
	jj = a.row;
	std::cout << "ii " << ii << " jj " << jj << "\n";
	for (i = 0; i < ii; i++) {
		for (j = 0; j < jj; j++) {
			std::cout << a.m[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "=============================\n";
}
double** Matrix::Tm() {
	double** a;
	a = new double* [col];
	for (int i = 0; i < col; i++) {
		a[i] = new double[row];
	}
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			a[i][j] = m[j][i];
		}
	}
	return a;
}
void Matrix::Multi(const Matrix& a, double* b, int n, double* c) {
	/*if (a.col != n) {
		throw std::runtime_error("a.col!=n at Multi");
	}*/
	int i, j;
	double d = 0;
	for (i = 0; i < a.row; i++) {
		for (j = 0; j < a.col; j++) {
			d += a.m[i][j] * b[j];
		}
		c[i] = d;
		d = 0;
	}
}
void Matrix::Sum(double* a, double* b, int n,double d, double* c) {
	for (int i = 0; i < n; i++) {
		c[i] = a[i] + b[i]*d;
	}
}