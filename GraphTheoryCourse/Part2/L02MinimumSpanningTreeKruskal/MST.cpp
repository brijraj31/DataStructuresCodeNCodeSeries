// Problem Link https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct edge {
    int a;
    int b;
    int w;
};

bool comp(edge edge1 , edge edge2) {
    return edge1.w < edge2.w;
}
edge ar[100001];
int par[10001];

int findParent(int a) {
    return (par[a] == -1 ? a : findParent(par[a]));
}

void unionSet(int a, int b) {
    if(a < b) {
        par[b] = a;
    }
    else {
        par[a] = b;
    }
}
int main() {
    
    int n, m, a, b , w;
    cin >> n >> m;

    for(int i = 0; i <= n; ++i) par[i] = -1; // initialize parent array

    for(int i = 0; i < m; ++i) {
        cin >> ar[i].a >> ar[i].b >> ar[i].w;
    }

    sort(ar, ar + m, comp);
    int sum = 0;
    for(int i = 0; i < m; ++i) {
        a = findParent(ar[i].a);
        b = findParent(ar[i].b);

        if(a != b) {
            sum += ar[i].w;
            unionSet(a, b);
        }
    }
    cout << sum;
    return 0;
}

