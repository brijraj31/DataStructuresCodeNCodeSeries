
//
// Created by brij on 27/03/20.
//

#include <iostream>
#define MAXN 1000001
using namespace std;
int prime[MAXN];
void preProcessing() {
    for (int i = 0; i < MAXN; ++i) {
        prime[i] = -1;
    }

    prime[1] = 1;
    for(int i = 2; i < MAXN; ++i) {
        if(prime[i] == -1) {
            for(int j = i; j < MAXN; j += i) {
                if(prime[j] == -1) {
                    prime[j] = i;
                }
            }
        }
    }

    
/*for(int i = 1; i < 100; ++i) {
        cout << i << ' ' <<prime[i] << '\n';
    }*/

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    preProcessing();

    int n;
    cin >> n;
    int i = n;
    while (prime[i] != i) {
        int count = 0;
        int p = prime[i];
        int temp = p;
        while (p == temp) {
            count ++;
            i = i / p;
            temp = prime[i];
        }
        cout << p << " ^ " << count <<'\n';

    }

    if(i > 1) cout << i << " ^ " << 1;
    return 0;
}
