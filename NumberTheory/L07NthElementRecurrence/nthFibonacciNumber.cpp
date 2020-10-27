/*
//
// Created by brij on 27/03/20.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll mod = 1e9 + 7;

ll ar[3];
ll I[3][3];
ll T[3][3];

void mul(ll A[3][3], ll B[3][3], int dim) {
    ll C[dim + 1][dim + 1];

    for(int i = 1; i <= dim; ++i) {
        for (int j = 1; j <= dim; ++j) {
            C[i][j] = 0;
            for (int k = 1; k <= dim; ++k) {
                ll temp = (A[i][k] * B[k][j]) % mod;
                C[i][j] = (C[i][j] + temp) % mod;
            }
        }
    }

    for(int i = 1; i <= dim; ++i) {
        for (int j = 1; j <= dim ; ++j) {
            A[i][j] = C[i][j];
        }
    }

}

ll getFib(int n) {
    if(n <= 2) return ar[n];

    I[1][1] = I[2][2] = 1;
    I[1][2] = I[2][1] = 0;

    T[1][1] = 0;
    T[1][2] = T[2][1] = T[2][2] = 1;

    n = n - 1;

    while (n) {
        if(n & 1)
            mul(I, T, 2);

        mul(T, T, 2);
        n >>= 1;
    }

    ll temp1 = (ar[1] * I[1][1]) % mod;
    ll temp2 = (ar[2] * I[2][1]) % mod;

    ll temp = (temp1 + temp2) % mod;

    return (int)temp;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;

    cin >> t;

    while (t--) {
        cin >> ar[1] >> ar[2] >> n , n ++;

        cout << getFib(n) << '\n';
    }
}


*/

/*

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
int solve(int a, int b, int n) {


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string abn_temp;
        getline(cin, abn_temp);

        vector<string> abn = split_string(abn_temp);

        int a = stoi(abn[0]);

        int b = stoi(abn[1]);

        int n = stoi(abn[2]);

        int result = solve(a, b, n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
*/

