
//
// Created by brijr on 28-3-20.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int s, vector<int> g[], bool vis[])
{
    vis[s] = true;
    cout << s << " ";
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

    int T;
    cin>>T;
    while(T--) {

        int N, E;
        cin >> N >> E;

        vector<int> g[N];
        bool vis[N];

        memset(vis, false, sizeof(vis));

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0, g, vis);

        cout << endl;
    }

    return 0;
}
