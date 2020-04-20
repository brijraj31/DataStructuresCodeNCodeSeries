


#include <bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; ++i)
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


void primeFacor(int N) {
    for(int i = 2; i * i <= N; ++i) {
        if( N % i == 0) {
            int cnt = 0;
            while(N % i == 0)
                cnt ++ , N /= i;
                cout << i << " ^ " << cnt << endl;

        }
    }

    if(N > 1) {
        cout << N << " ^ "<< 1 << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    primeFacor(n);

}



