
//
// Created by brijr on 29-3-20.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int vis[MAX];
vector<int> adj[MAX];
typedef long long int ll;
const ll MOD = 1e9 + 7;
ll dfs(int s) {
    vis[s] = true;
    ll count = 1 % MOD;

    for(int x : adj[s]) {
        if(!vis[x]) {
            count = (count + dfs(x)) % MOD;
        }
    }
    return count % MOD;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        for(auto& x : adj) {
            x.clear();
        }

        memset(vis, false, sizeof(vis));

        int n, m;
        cin >> n >> m;

        for(int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int countComp = 0;

        ll ans = 1;
        for(int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                countComp ++;
                ans = ( ans * dfs(i)) % MOD;
            }
        }

        cout << countComp << " " << ans <<'\n';

    }

    return 0;


}
