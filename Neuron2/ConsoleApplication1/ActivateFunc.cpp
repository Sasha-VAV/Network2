#include "ActivateFunc.h"
#include <iostream>
void ActivateFunc::set() {
	int a=2;
	if (a == 0) {
		std::cout << "Choose activation function\nOptions:\n1-Sigmoid\n2-Modified RELu\n3-Th\nPress and send number: ";
		std::cin >> a;
	}
	switch (a)
	{
	case 1:
		actF = Sigm;
		break;
	case 2:
		actF = ModRELu;
		break;
	case 3:
		actF = th;
		break;
	default:
		throw std::runtime_error("We don't have such function");
		break;
	}
}
void ActivateFunc::F(double* a, int n) {
	int i;
	switch (actF) {
	case actFunc::Sigm:
		for (i = 0; i < n; i++)
			a[i] = 1 / (1 + exp(-a[i]));
		break;
	case actFunc::ModRELu:
		for (i = 0; i < n; i++) {
			if (a[i] < 0)
				a[i] *= 0.01;
			else if (a[i] > 1)
				a[i] = 1. + 0.01 * (a[i] - 1.);
			else
				a[i] = a[i];
		}
		break;
	case actFunc::th:
		for (i = 0; i < n; i++) {
			if (a[i] < 0)
				a[i] = 0.01 * (exp(a[i]) - exp(-a[i])) / (exp(a[i]) + exp(-a[i]));
			else
				a[i] = (exp(a[i]) - exp(-a[i])) / (exp(a[i]) + exp(-a[i]));
		}
		break;
	default:
		throw std::runtime_error("Error in activationFunction\n");
		break;
	}
}
double ActivateFunc::f(double a)
{
	switch (actF) {
	case actFunc::Sigm:
			return 1 / (1 + exp(-a));
		break;
	case actFunc::ModRELu:
			if (a < 0)
				a *= 0.01;
			else if (a > 1)
				a = 1. + 0.01 * (a - 1.);
			else
				a = a;
			return a;
		break;
	case actFunc::th:
			if (a < 0)
				a = 0.01 * (exp(a) - exp(-a)) / (exp(a) + exp(-a));
			else
				a = (exp(a) - exp(-a)) / (exp(a) + exp(-a));
			return a;
		break;
	default:
		throw std::runtime_error("Error in activationFunction\n");
		break;
	}
}
double ActivateFunc::dF(double a) {
	int i;
	switch (actF)
	{
	case actFunc::Sigm:
		a = a * (1 - a);
		break;
	case actFunc::ModRELu:
		if (a < 0 or a>1)
			a = 0.01;
		else
			a = 1;
		break;
	case actFunc::th:
		if (a < 0)
			a = 0.01 * (1 - a * a);
		else
			a = 1 - a * a;
		break;
	default:
		throw std::runtime_error("Error in dF'\n");
		break;
	}
	return a;
}
void ActivateFunc::dFM(double* a, int n) {
	int i;
	switch (actF)
	{
	case actFunc::Sigm:
		for (int i=0;i<n;i++)
			a[i] = a[i] * (1 - a[i]);
		break;
	case actFunc::ModRELu:
		for (int i = 0; i < n; i++)
		if (a[i] < 0 or a[i]>1)
			a[i] = 0.01;
		else
			a[i] = 1;
		break;
	case actFunc::th:
		for (int i = 0; i < n; i++)
		if (a[i] < 0)
			a[i] = 0.01 * (1 - a[i] * a[i]);
		else
			a[i] = 1 - a[i] * a[i];
		break;
	default:
		throw std::runtime_error("Error in dF'\n");
		break;
	}
}