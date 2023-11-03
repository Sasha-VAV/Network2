#include <iostream>
#include "Matrix.h"
#include "ActivateFunc.h"

int main()
{
    srand(time(NULL));
    
    bool ok = true;
    while (ok){
        std::cout << "LET'S GO!\n";
        Matrix m;
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
        }
        std::cout << "=============================\n";
        Matrix::Sum(d,b,n,d);
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
        }
        std::cout << "=============================\n";
        std::cout << "Continue(1/0)?\n";
        int a;
        std::cin >> a;
        ok = a == 1;
    }
    
}
