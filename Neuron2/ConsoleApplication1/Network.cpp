#include "Network.h"
#include <fstream>
#include <iostream>

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
	for (int i = 0; i < L - 1; i++) {//���������� ������� ����� � �������� ���������� �������
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
	std::ofstream fw;
	fw.open("weights.txt");
	for (int i = 0; i < L - 1; i++) {//���������� ������� ����� � �������� ���������� �������
		//fw >> weights[i];
	}
	fw.close();
}

void Network::SaveWeights()
{
	std::ofstream fw;
	fw.open("weights.txt", ios::trunc);
	for (int i = 0; i < L - 1; i++) {//���������� ������� ����� � �������� ���������� �������
		for (int j = 0; j < weights[i].row; j++) {
			for (int k = 0; k < weights[i].col; k++) {
				fw << weights[i].m[j][k] << " ";
			}
			fw << "\n";
		}
		fw << "\n\n";
	}
	for (int i = 0; i < L - 1; i++) {
		for (int j = 0; j < size[i + 1]; j++) {
			fw << bios[i][j] << " ";
		}
		fw << "\n";
	}
	for (int i = 0; i < L - 1; i++) {
		fw << bv[i] << " ";
	}
	fw.close();
}
void Network::SaveWeightsBackup()
{
	std::ofstream f1;
	std::ofstream f2;
	f1.open("weights1.txt", ios::trunc);
	for (int i = 0; i < L - 1; i++) {//���������� ������� ����� � �������� ���������� �������
		for (int j = 0; j < weights[i].row; j++) {
			for (int k = 0; k < weights[i].col; k++) {
				f1 << weights[i].m[j][k] << " ";
			}
			f1 << "\n";
		}
		f1 << "\n\n";
	}
	for (int i = 0; i < L - 1; i++) {
		for (int j = 0; j < size[i + 1]; j++) {
			f1 << bios[i][j] << " ";	
		}
		f1 << "\n";
	}
	for (int i = 0; i < L - 1; i++) {
		f1 << bv[i] << " ";
	}
	f1.close();
	f2.open("weights2.txt", ios::trunc);
	for (int i = 0; i < L - 1; i++) {//���������� ������� ����� � �������� ���������� �������
		for (int j = 0; j < weights[i].row; j++) {
			for (int k = 0; k < weights[i].col; k++) {
				f2 << weights[i].m[j][k] << " ";
			}
			f2 << "\n";
		}
		f2 << "\n\n";
	}
	for (int i = 0; i < L - 1; i++) {
		for (int j = 0; j < size[i + 1]; j++) {
			f2 << bios[i][j] << " ";
		}
		f2 << "\n";
	}
	for (int i = 0; i < L - 1; i++) {
		f2 << bv[i] << " ";
	}
	f2.close();

}
void Network::SaveWeightsBackupAE()
{
	std::ofstream f1;
	std::ofstream f2;
	f1.open("weightsAE1.txt", ios::trunc);
	for (int i = 0; i < L - 1; i++) {//���������� ������� ����� � �������� ���������� �������
		for (int j = 0; j < weights[i].row; j++) {
			for (int k = 0; k < weights[i].col; k++) {
				f1 << weights[i].m[j][k] << " ";
			}
			f1 << "\n";
		}
		f1 << "\n\n";
	}
	for (int i = 0; i < L - 1; i++) {
		for (int j = 0; j < size[i + 1]; j++) {
			f1 << bios[i][j] << " ";
		}
		f1 << "\n";
	}
	for (int i = 0; i < L - 1; i++) {
		f1 << bv[i] << " ";
	}
	f1.close();
	f2.open("weightsAE2.txt", ios::trunc);
	for (int i = 0; i < L - 1; i++) {//���������� ������� ����� � �������� ���������� �������
		for (int j = 0; j < weights[i].row; j++) {
			for (int k = 0; k < weights[i].col; k++) {
				f2 << weights[i].m[j][k] << " ";
			}
			f2 << "\n";
		}
		f2 << "\n\n";
	}
	for (int i = 0; i < L - 1; i++) {
		for (int j = 0; j < size[i + 1]; j++) {
			f2 << bios[i][j] << " ";
		}
		f2 << "\n";
	}
	for (int i = 0; i < L - 1; i++) {
		f2 << bv[i] << " ";
	}
	f2.close();
}
void Network::ReadWeights() {
	std::ifstream fw;
	fw.open("weights.txt");
	for (int i = 0; i < L - 1; i++) {//���������� ������� ����� � �������� ���������� �������
		for (int j = 0; j < weights[i].row; j++) {
			for (int k = 0; k < weights[i].col; k++) {
				fw >> weights[i].m[j][k];
			}
		}
	}

	for (int i = 0; i < L - 1; i++) {
		for (int j = 0; j < L - 1; j++) {
			fw >> bios[i][j];
		}
	}
	for (int i = 0; i < L - 1; i++) {
		fw >> bv[i];
	}
	fw.close();
}

void Network::Forward(NW nw)
{
	/*for (int i = 0; i < L; i++) {
		for (int j = 0; j < nw.size[i]; j++) {
			cout << neurons[i][j] << " ";
		}
		cout << "\n";
	}*/
	for (int i = 0; i < L - 1; i++) {
		Matrix::Multi(weights[i], neurons[i], size[i + 1], neurons[i + 1]);
		Matrix::Sum(neurons[i + 1], bios[i], size[i + 1], bv[i], neurons[i + 1]);
		actF.F(neurons[i + 1], size[i + 1]);
	}
	/*for (int i = 0; i < L; i++) {
		for (int j = 0; j < nw.size[i]; j++) {
			cout << neurons[i][j] << " ";
		}
		cout << "\n";
	}*/
}


void Network::BackPropogation(NW nw, double* a)
{
	for (int i = 0; i < L - 1; i++) {
		Matrix::Multi(weights[i], neurons[i], size[i + 1], neurons[i + 1]);
		Matrix::Sum(neurons[i + 1], bios[i], size[i + 1], bv[i], neurons[i + 1]);
	}
	for (int i = L - 1; i > 0; i--) {//���� � �����

		for (int j = 0; j < size[i]; j++) {//����� �� ������� ���� j�� ������
			//������������ ��� ����
			double s = neurons[i][j];
			double alpha = 0.00001;
			double correct = a[j];
			for (int k = 0; k < size[i - 1]; k++) {
				if (i == L - 1)
					weights[i - 1].m[j][k] += alpha * 2 * (correct - actF.f(s)) * actF.dF(s) * neurons[i - 1][k];
				else if (i == L - 2)
					weights[i - 1].m[j][k] += alpha * 2 * (correct - actF.f(s)) * actF.dF(s) * neurons[i - 1][k];
			}
			bios[i - 1][j] += alpha * 2 * (correct - actF.f(s)) * actF.dF(s);
		}

	}


}

void Network::Activate(NW nw)
{
	for (int i = 0; i < L - 1; i++) {
		actF.F(neurons[i + 1], size[i + 1]);
	}
}

void Network::UpdateWeights(NW nw, int k, double* d)
{
	for (int i = 0; i < L - 1; i++) {
		for (int j = 0; j < size[i]; j++) {
			//weights[k].m[i][j] = -2 * (d[i]) * actF.dF(neurons[i]);
		}
	}
}
