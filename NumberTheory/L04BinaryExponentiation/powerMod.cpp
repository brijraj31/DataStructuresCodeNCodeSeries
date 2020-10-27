//
// Created by brij on 26/03/20.
//

#include <iostream>
#include <cmath>
typedef long long int ll;
using namespace std;

int powerRec(int x, int n) {
    if(n == 0) return 1;


    int mod = (1e9 + 7);
    x = x % mod;

    int temp = powerRec(x, n >> 1);
    temp = temp % mod;
    temp = (1l * temp * temp) % mod;


    if(n & 1) {
        temp = (1l * temp * x) % mod;
    }

    return temp % mod;
}
int powerNBruteRecursive(int x, int n) {

    if(n == 0) return 1;
    return x * powerNBruteRecursive(x, n - 1);
}

int powerNBruteIterative(int x, int n) {
    int res = 1;

    for(int i = 1; i <= n; ++i) {
        res = res * x;
    }
    return res;
}


int powerItertive(int x, int n) {
    int res = 1;
    int mod = 1e9 + 7;
    //1101 = 2^(8) * 2^(4) * 2^(1)



    x = x % mod;

    while(n > 0) {
        if(n & 1)
            res = (1l * res * x) % mod;
        x = (1l * x * x) % mod;
        n >>= 1;
    }

    return res % mod;
}
int main() {
    int x, n;

    cin >> x >> n;
    cout << powerRec(x, n) << "\n";
    cout << powerItertive(x, n) <<"\n";
    cout << pow(x,n);

}




