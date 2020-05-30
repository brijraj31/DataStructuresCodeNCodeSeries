/*
//
// Created by brijr on 29-3-20.
//

/* https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph */



#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int s, vector<int> g[], bool vis[])
{
    vis[s] = true;
    //cout << s << " ";
    for(int i = 0; i < g[s].size(); ++i) {
        if(!vis[g[s][i]]) {
            dfs(g[s][i], g, vis);
        }
    }
    // Your code here

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, E;
    cin >> N >> E;

    vector<int> g[N + 1];
    bool vis[N + 1];

    memset(vis, false, sizeof(vis));

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int count = 0;
    for(int i = 1; i <= N; ++i)
        if(!vis[i])
            dfs(i, g, vis), count ++;

    cout << count << '\n';

    return 0;
}





