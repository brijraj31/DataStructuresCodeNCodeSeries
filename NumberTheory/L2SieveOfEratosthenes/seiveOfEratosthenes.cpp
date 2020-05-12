
//
// Created by brij on 26/03/20.
//

# include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    bool *seive = new bool[n + 1];
    for(int i = 0; i <= n; ++i) {
        seive[i] = true;
    }

    seive[0] = seive[1] = false;

    for (int i = 2; i * i <= n ; ++i) {
        if(seive[i]) {
            for (int j = i * i; j <= n; j += i) {
                seive[j] = false;
            }
        }
    }


    for(int i = 2; i <= n; ++i) {
        if(seive[i]) {
            cout << i << "\n";
        }
    }

}
