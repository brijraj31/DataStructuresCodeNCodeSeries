#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int phi[1000001];
void initalize(int maxN) {
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
int main() {


    initalize(1000001);

    int t, x;
    cin >> t;
    while(t --) {
        cin >> x;
        cout << phi[x] << '\n';
    }
    return 0;
}