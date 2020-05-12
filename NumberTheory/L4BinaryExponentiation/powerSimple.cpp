//
// Created by brij on 28/03/20.
//


#include <iostream>


int powerRec(int x, int n) {
    if(n == 0) return 0;
    return x * powerRec(x, n - 1);
}

int powerIterative(int x, int n) {
    int res = 1;
    for(int i = 1; i <= n; ++i) {
        res = res * x;
    }
    return res;
}


int powFastIter(int x, int n) {

    // 2^13, 1101 = 2^16 * 2^(4) * 2^(1),
    int res = 1;

    while (n > 0) {
        if(n & 1) {
            res = res * x;
        }


        x = x * x;
        n >>= 1;
    }

}
int powFastRec(int x, int n) {

    if(n== 0)
        return 1;

    int temp = powFastRec(x, n >> 1);

    temp = temp * temp;

    if(n & 1) {
        temp = temp * x;
    }
    return temp;
}



// a^n % m

// 10^9

// (a * b) % m = ((a % m ) * (b % m)) % m

// print your answer % 1000000007