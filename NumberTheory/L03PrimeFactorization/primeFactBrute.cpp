
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

void primeFact(int n) {
    for(int i = 2; i <= n; ++i) {
        if(n % i == 0) {
            int cnt = 0;
            while (n % i == 0) cnt++ , n /= i;
            cout << i << " ^ " << cnt << endl;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    primeFact(n);

    return 0;

}


