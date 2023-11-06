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
    while (ok){
        std::cout << "LET'S GO!\n";
        NW nw{};
        Network network;
        nw.L = L;
        nw.size = new int[L];
        /*for (int i = 0; i < L; i++) {
            nw.size[i] = 2;
        }*/
        nw.size[0] = 2;
        nw.size[1] = 1;
        network.Init(nw);
        network.SaveWeights();
        network.ReadWeights();
        //network.weights[0].PrintM();
        cout << "Insert neurons\n";
        for (int j = 0; j < nw.size[0]; j++) {
            cin>>network.neurons[0][j];
            //cout<< network.neurons[0][j]<<"\n";
        }

        network.Forward(nw);
        
        for (int i = 0; i < nw.size[L - 1]; i++) {
            cout << network.neurons[L - 1][i] << "\n";
        }
        int jj;
        cout << "laps?\n";
        cin >> jj;
        for (int ii=0; ii<jj;ii++)
        {
            ifstream f;
            f.open("learn.txt");
            for (int i = 0; i < 4; i++)
            {
                network.ReadWeights();

                double* d;
                d = new double[1];
                f >> d[0];
                cout << "Insert neurons\n";
                for (int j = 0; j < nw.size[0]; j++) {
                    f >> network.neurons[0][j];
                    cout<< network.neurons[0][j]<<" ";
                }
                cout << "\n";
                network.Forward(nw);
                double answ = network.neurons[L - 1][0];
                for (int k = 0; k < nw.size[L - 1]; k++) {
                    cout << network.neurons[L - 1][k] << "\n";
                }
                if (abs((answ-d[0]))>0.001)
                {
                    cout << answ << " " << d[0] << "\n";
                    network.BackPropogation(nw, d);
                    network.SaveWeights();
                }

            }
            f.close();
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
        int a=1;
        //std::cin >> a;
        ok = a == 1;
    }
    
}
