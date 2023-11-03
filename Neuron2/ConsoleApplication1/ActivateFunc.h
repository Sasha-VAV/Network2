#pragma once
enum actFunc {Sigm, ModRELu, th}	;
class ActivateFunc
{
	actFunc actF;
public:
	void set();
	void F(double* a, int n);
	double dF(double a);
	void dFM(double* a, int n);
};

