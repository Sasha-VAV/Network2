#include <iostream>
#include "Matrix.h"
#include "ActivateFunc.h"
#include "Network.h"
#include <cstdlib>
#include <math.h>
using namespace std;
int main()
{
	srand(time(NULL));
	int L = 2;
	bool ok = true;
	int aaa = 4;
	int learnact = 2;
	int numoflearns = 0;
	int numoftests = 25000;
	ifstream fc;
	fc.open("network cfg.txt");
	double min_err;
	fc >> min_err;
	double min_act_err;
	fc >> min_act_err;
	fc.close();
	while (ok) {
		std::cout << "LET'S GO!\n";
		NW nw{};
		Network network;
		nw.L = L;
		nw.size = new int[L];
		/*for (int i = 0; i < L; i++) {
			nw.size[i] = 2;
		}*/
		nw.size[0] = 21760;
		nw.size[1] = 1;
		//nw.size[2] = 1;
		network.Init(nw);


		if (aaa == 0) {
			cout << "restart weights?\nask me again-0\nthis time yes but ask me again-1\nthis time no but ask me again-2\nalways yes-3\nalways no-4\n";
			cin >> aaa;
		}
		if (aaa == 1)
		{
			network.SaveWeights();
			aaa = 0;
		}
		else if (aaa == 2) {
			aaa = 0;
		}
		else if (aaa == 3) {
			network.SaveWeights();
		}



		network.ReadWeights();
		//network.weights[0].PrintM();
		if (learnact == 0)
		{
			cout << "Insert neurons\n";
			for (int j = 0; j < nw.size[0]; j++) {
				cin >> network.neurons[0][j];
				//cout<< network.neurons[0][j]<<"\n";
			}

			network.Forward(nw);

			for (int i = 0; i < nw.size[L - 1]; i++) {
				cout << network.neurons[L - 1][i] << "\n";
			}
		}
		if (learnact == 2) {
			ifstream fin;
			fin.open("Test.txt");
			for (int j = 0; j < nw.size[0]; j++) {
				fin >> network.neurons[0][j];
				//cout<< network.neurons[0][j]<<"\n";
			}

			network.Forward(nw);

			if (network.neurons[L - 1][0] < 0.5) {
				cout << "I think that it's a dog, my neuron is: " << network.neurons[L - 1][0] << "\n";
			}
			else {
				cout << "I think that it's a cat, my neuron is: " << network.neurons[L - 1][0] << "\n";
			}
		}
		int jj;

		if (learnact == 1) {
			cout << "laps?\n";
			cin >> jj;
			for (int ii = 0; ii < jj; ii++)
			{
				ifstream f;
				f.open("Dogs.txt");
				double err = 0;
				double kpd = 1;
				double fact_err = 0;
				for (int i = 0; i < numoflearns; i++)
				{
					if (i % 25 == 0 and i!=0) {
						cout << "epoch: " << ii << " current image " << i << " kpd: " << kpd << " err: " << err*100/i << " factical error: "<<fact_err*100/i<<"\n";
					}
					network.ReadWeights();

					double* d;
					d = new double[1];
					double dd;
					f >> dd;
					d[0] = dd;
					/*if (i % 2 == 0) {
						d[0] = 0;
					}
					else {
						d[0] = 1;
					}*/

					//cout<<"\n" << d[0] << "\n\n";
					/*if (jj-ii<16)
						cout << "Insert neurons\n";*/
					for (int j = 0; j < nw.size[0]; j++) {
						f >> network.neurons[0][j];
						//if (jj - ii < 16)
							//cout<< network.neurons[0][j]<<" ";
					}
					/*if (jj - ii < 16)
						cout << "\n";*/
					network.Forward(nw);
					double answ = network.neurons[L - 1][0];
					kpd -= abs(answ - d[0]);
					err += abs(answ - d[0]);
					if (answ < 0.5) {
						if (d[0] == 1)
						{
							fact_err += 1;
						}
					}
					else {
						if (d[0] == 0)
						{
							fact_err += 1;
						}
					}

					/*for (int k = 0; k < nw.size[L - 1]; k++) {
						if (jj - ii < 16)
							cout << network.neurons[L - 1][k] << "\n";
					}*/
					if (abs((answ - d[0])) > 0.001)
					{
						//if (jj - ii < 16)
						//cout << answ << " " << d[0] << "\n";
						network.BackPropogation(nw, d);
						network.SaveWeights();
					}
					

				}
				if (err * 100 / numoflearns <= min_err) {
					min_err = err * 100 / numoflearns;
					network.SaveWeightsBackup();
					ofstream fwc;
					fwc.open("network cfg.txt", ios::trunc);
					fwc << min_err << " " << min_act_err;
					fwc.close();
				}
				if (err * 100 / numoflearns < 0.1 or (numoftests+numoflearns)>25000) {
					cout << "epoch: " << ii << " kpd: " << kpd << " err: " << err * 100 / numoflearns  << "\n";
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\nLEARNING COMPLETED\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
					cin >> err;
					err = err / 0;
				}
				cout << "epoch: " << ii << " kpd: " << kpd << " err: " << err*100 / numoflearns << " factical error " << fact_err *100 / numoflearns << "\n";
				kpd = 1;
				err = 0;
				fact_err = 0;
				
				for (int i = 0; i < numoftests; i++) {
					for (int j = 0; j < nw.size[0]; j++) {
						f >> network.neurons[0][j];
					}
					//network.ReadWeights();
					double* d;
					d = new double[1];
					double dd;
					f >> dd;
					d[0] = dd;
					network.Forward(nw);
					double answ = network.neurons[L - 1][0];
					kpd -= abs(answ - d[0]);
					err += abs(answ - d[0]);
					if (answ < 0.5) {
						if (d[0] == 1)
							fact_err += 1;
					}
					else {
						if (d[0] == 0)
							fact_err += 1;
					}
				}
				cout << "epoch: " << ii << " TEST:: NUMOFTESTS "<< numoftests<< " kpd: " << kpd << " err: " << err * 100 / numoftests << " factical error: "<<fact_err*100/numoftests<<"\n";
				f.close();
				if (fact_err * 100 / numoftests <= min_act_err) {
					min_act_err = fact_err * 100 / numoftests;
					network.SaveWeightsBackupAE();
					ofstream fwc;
					fwc.open("network cfg.txt", ios::trunc);
					fwc << min_err << " " << min_act_err;
					fwc.close();
					if (min_act_err == 0) {
						numoftests *= 2;
					}
				}
				
			}
		}


		/*Matrix m;
		int M = 2;
		m.Init(M,3);
		m.Rand();
		m.PrintM();
		int n = 3;
		double* d;
		double* c;
		double* b;
		b = new double[M] {0.003, 0.004};
		c = new double[n] {0.003, 0.006,0.007};
		d = new double[M];
		Matrix::Multi(m, c, n, d);
		for (int i = 0; i < M; i++) {
			std::cout << d[i] << "\n";
		}*/
		std::cout << "=============================\n";
		/*Matrix::Sum(d,b,n,d);
		for (int i = 0; i < M; i++) {
			std::cout << d[i] << "\n";
		}
		std::cout << "=============================\n";
		ActivateFunc f;
		f.set();
		f.F(d,M);
		for (int i = 0; i < M; i++) {
			std::cout << d[i] << "\n";
		}
		std::cout << "=============================\n";
		f.dFM(d, M);
		for (int i = 0; i < M; i++) {
			std::cout << d[i] << "\n";
		}*/
		std::cout << "=============================\n";
		std::cout << "Continue(1/0)?\n";
		int a = 1;
		std::cin >> a;
		ok = a == 1;
	}

}
