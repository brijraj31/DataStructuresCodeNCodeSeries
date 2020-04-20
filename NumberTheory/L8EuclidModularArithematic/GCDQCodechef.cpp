
//
// Created by brij on 27/03/20.
//

#include <iostream>
using namespace std;
#define MAXN 100001
int gcdSuf[MAXN];
int gcdPre[MAXN];
int arr[MAXN];
int gcd(int a, int b) {

    while (b > 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
void preProcess(int size) {
    gcdPre[1] = arr[1];
    for(int i = 2; i <= size; ++i) {
        gcdPre[i] = gcd(arr[i], gcdPre[i-1]);
    }
    gcdSuf[size] = arr[size];
    for(int i = size - 1; i >= 1; --i) {
        gcdSuf[i] = gcd(arr[i], gcdSuf[i + 1]);
    }
}
int main() {
    int t;

    cin >> t;
    while (t --) {
        int size, q;
        cin >> size >> q;

        for(int i = 1; i <= size; ++i) {
            cin >> arr[i];
        }
        preProcess(size);

        while (q--) {
            int l,r;
            cin >> l >> r;
            if(l == 1) {
                cout << gcdSuf[r + 1] << '\n';
            } else if(r == size) {
                cout << gcdPre[l - 1] << '\n';
            } else
                cout << gcd(gcdPre[l - 1], gcdSuf[r + 1]) << '\n';
        }

    }

}
