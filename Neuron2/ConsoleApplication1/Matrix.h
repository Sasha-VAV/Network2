#pragma once
#include <cstdlib>
#include <string>
#include <fstream>
class Matrix
{
public:
	double** m;
	int row, col;
public:
	void Init(int row, int col);
	void Rand();
	void PrintM();
	static void PrintAll(const Matrix& a);
	double** Tm();
	static void Multi(const Matrix& a,double* b,int n, double* c);
	static void Sum(double* a, double* b, int n,double d, double* c);
};

