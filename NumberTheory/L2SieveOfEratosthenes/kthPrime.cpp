
//
// Created by brij on 26/03/20.
//



#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define ii pair <int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n';
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

vi primes;

bool ar[90000001];

void sieve() {
    int maxN = 90000000;
    ar[0] = ar[1] = true;

    for (int i = 2; i * i <= maxN; ++i) {
        if(!ar[i]) {
            //primes.pb(i); Here it would be false can you guess why??

            for(int j = i * i; j <= maxN; j += i) {
                ar[j] = true;
            }
        }
    }

    for (int i = 2; i <= maxN; ++i) {
        if(!ar[i]) primes.pb(i);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int q, n;
    cin >> q;

    while (q--)
        cin >> n , cout << primes[n - 1] << endl;
}


