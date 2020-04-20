#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int parent[MAXN];
int Rank[MAXN];


int findParent(int u) {
    if(parent[u] < 0) return u;
    return parent[u] = findParent(parent[u]);
}


void merge(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if(a == b) return;

    if(Rank[a] > Rank[b]) {
        //make 'a' as parent of 'b'
        parent[b] = a;
        // update the rank of 'a'
        Rank[a] += Rank[b];
    }
    else {
        parent[a] = b;
        Rank[b] += Rank[a];
    }
}

int main() {
    int n , m;
    cin >> n >> m;
    
    memset(parent, -1, MAXN * sizeof(int));
    memset(Rank, 1, MAXN * sizeof(Rank));

    int u, v;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v;

        u = findParent(u), v = findParent(v);

        merge(u, v);
    }



    return 0;
}