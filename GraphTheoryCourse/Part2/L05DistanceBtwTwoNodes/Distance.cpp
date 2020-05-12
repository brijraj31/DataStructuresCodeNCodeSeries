#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define pb push_back
vector<int> ar[1001];
const int maxN = 10;

int level[1001], LCA[1001][maxN + 1];


void dfs(int node = 1, int lvl = 0, int par = -1) {
    level[node] = lvl;
    LCA[node][0] = par;

    for(int child : ar[node]) {
        if(child != par) {
            dfs(child, lvl + 1, node);
        }
    }
}
void initialize(int n) {
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < maxN; ++j) {
            LCA[i][j] = -1;
        }
    }
    
    dfs();

    for(int i = 0; i < maxN; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(LCA[j][i - 1] != -1) {
                int par = LCA[j][i - 1];
                LCA[j][i] = LCA[par][i - 1];
            }
        }
    }
}

int getLCA(int a, int b) {
    if(level[b] < level[a]) swap(a, b);

    int d = level[b] - level[a];

    while(d > 0) {
        int i = log2(d);
        b = LCA[b][i];

        d -= (1 << i);
    }

    if(a == b) return a;

    for(int i = maxN - 1; i >= 0; --i) {
        if(LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i])) {
            a = LCA[a][i] , b = LCA[b][i];
        }
    }

    return LCA[a][0];
}

int getDist(int a, int b) {
    int lca = getLCA(a, b);

    return level[a] + level[b] - 2 * level[lca];
}
int main() {


    int n, a , b, q;

    cin >> n;
    for(int i = 1; i < n; ++i)
        cin >> a >> b , ar[a].pb(b) , ar[b].pb(a);

    initialize(n);
    
    
    cin >> q;
    while(q --) {
        cin >> a >> b;
        cout << getDist(a, b) <<'\n';
    }

    return 0;
}
/*
10
1 2 
1 3
2 6
2 9
3 4
6 8
9 5
4 10
4 7
10
1 1
1 4
6 3
*/