#include <iostream>

using namespace std;


int phi[1000001];

void initialize(int maxN) {
    for(int i = 0; i <= maxN; ++i) {
        phi[i] = i;
    }

    for(int i = 2; i <= maxN; ++i) {
        if(phi[i] == i) { // this is a prime no.

            for(int j = i; j <= maxN; j += i) {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }
} 

int getCount(int d, int N) {
    return phi[N/d];
}
int main() {
    initialize(1000000);
    int q, N;

    cin >> q;

    while (q -- ) {
        cin >> N;
        int res = 0;

        for (int i = 1; i * i <= N; ++i) {
            if (N % i == 0) {
                int d1 = i;
                int d2 = N / i;

                res += d1 * getCount(d1, N);

                if (d1 != d2) 
                    res += d2 * getCount(d2, N);
            }
        }

        cout << res << '\n';
    }
    return 0;
}