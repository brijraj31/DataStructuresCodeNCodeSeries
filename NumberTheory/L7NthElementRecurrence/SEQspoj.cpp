
//
// Created by brij on 27/03/20.
//

#include <iostream>

using namespace std;
int MAT[10][10];
int IMAT[10][10];
int brr[1][10];
int coeff[10];
int tempMAT[10][10];
const int mod = 1e9;

void matMul(int r1, int r2, int c1, int c2, int A[][10], int B[][10]) {

    for(int i = 0; i < r1; ++i) {
        for(int j = 0; j < c2; ++j) {
            tempMAT[i][j] = 0;
            for (int k = 0; k < c1; ++k) {
                int temp = (1l * A[i][k] * B[k][j]) % mod;
                tempMAT[i][j] = (1l * tempMAT[i][j] + temp) % mod;
            }
        }
    }

}


int nthTerm(int k, int n) {

    for(int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if(i - j - 1 == 0) {
                MAT[i][j] = 1;
            } else MAT[i][j] = 0;
        }
    }
    for(int i = k - 1, j = 0; i >= 0; --i, j++) {
        MAT[i][k - 1] = coeff[j];
    }

    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < k; ++j) {
            if(i == j) {
                IMAT[i][j] = 1;
            } else IMAT[i][j] = 0;
        }
    }
    if(n <= k) {
        return brr[0][n - 1];
    }
    n = n - k;
    while (n > 0) {
        if(n & 1) {
            matMul(k,k,k,k, IMAT, MAT);
            for (int i = 0; i < k; ++i) {
                for (int j = 0; j < k; ++j) {
                    IMAT[i][j] = tempMAT[i][j];
                }
            }
        }

        matMul(k, k, k, k, MAT, MAT);

        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                MAT[i][j] = tempMAT[i][j];
            }
        }

        n >>= 1;
    }


    matMul(1, k, k , k, brr, IMAT);

    return tempMAT[0][k-1];

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {

        int k;
        cin >> k;

        for(int i = 0; i < k; ++i) {
            cin >> brr[0][i];
        }


        for (int i = 0; i < k; ++i) {
            cin >> coeff[i];
        }

        int n;
        cin >> n;

        cout << nthTerm(k, n) <<'\n';

    }

}
