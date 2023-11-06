#pragma once
#include "ActivateFunc.h"
#include "Matrix.h"
#include <fstream>
using namespace std;
struct NW {
	int L;
	int* size;
};
class Network//Боже, дай мне сил
{
public:
	int L;
	int* size;
	ActivateFunc actF;
	Matrix* weights;
	double** bios;
	double** neurons, ** errors;
	double* bv;
public:
	void Init(NW nw);
	void Fill(NW nw);
	void SaveWeights();
	void ReadWeights();
	void Forward(NW nw);
	void BackPropogation(NW nw, double* a);
	void UpdateWeights(NW nw, int k, double* a);
	void Activate(NW nw);
};
