#include "Network.h"
#include <fstream>

void Network::Init(NW nw) {
	actF.set();
	srand(time(NULL));
	L = nw.L;
	size = new int[L];
	for (int i = 0; i < L; i++) {
		size[i] = nw.size[i];
	}
	weights = new Matrix[L - 1];
	bios = new double* [L - 1];
	for (int i = 0; i < L - 1; i++) {//заполнение массива весов и смещений рандомными числами
		weights[i].Init(size[i + 1], size[i]);
		bios[i] = new double[size[i + 1]];
		weights[i].Rand();
		for (int j = 0; j < size[i + 1]; j++) {
			bios[i][j] = ((rand() % 10)) * 0.05 / (size[i] + 66);
		}
	}
	neurons = new double* [L];
	errors = new double* [L];
	for (int i = 0; i < L; i++) {
		neurons[i] = new double[size[i]];
		errors[i] = new double[size[i]];
	}
	bv = new double[L - 1];
	for (int i = 0; i < L - 1; i++) {
		bv[i] = 1;
	}
}

void Network::Fill(NW nw) {
	
}

void Network::SaveWeights()
{
	for (int i = 0; i < L - 1; i++) {//заполнение массива весов и смещений рандомными числами
		weights[i].PrintMfw();
	}
}
