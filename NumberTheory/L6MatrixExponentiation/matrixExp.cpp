/*
//
// Created by brij on 27/03/20.
//

#include <iostream>

using namespace std;

#define MOD 1000000007
#define matSize 50
typedef long long int ll;

ll MAT[matSize][matSize];
void matrixMul(ll A[][matSize], ll B[][matSize], int dim) {

    ll C[matSize][matSize];

    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < dim; ++k) {
                ll temp = (A[i][k] * B[k][j]) % MOD;
                C[i][j] = (C[i][j] + temp) % MOD;
            }
        }
    }

    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim ; ++j) {
            A[i][j] = C[i][j];
        }
    }

}

void matExp(ll A[][matSize], int dim, int n) {
    ll I[matSize][matSize];

    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            I[i][j] = (i == j ? 1 : 0);
        }
    }

    while (n > 0) {
        if(n & 1)
            matrixMul(I, A, dim);

        matrixMul(A, A, dim);
        n >>= 1;
    }

    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            A[i][j] = I[i][j] % MOD;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t --) {
        int m, n;
        cin >> m >> n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> MAT[i][j];
            }
        }
        matExp(MAT, m, n);

        for(int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << MAT[i][j] <<" ";
            }
            cout << '\n';
        }
    }
    return 0;
}

*/
