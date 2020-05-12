
//
// Created by brijr on 31-3-20.
//

#include <iostream>
#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

bool vis[MAX];

vector<int> adj[MAX];

vector<pair<int, int>> edges;
int comp[MAX];
void dfs(int s, int c) {
    vis[s] = true;
    comp[s] = c;
    for(int x : adj[s]) {
        if(!vis[x]) {
            dfs(x, c);
        }
    }
}
int main() {


    int t;
    cin >> t;
    while(t--) {
        int n , m;

        for(auto & x : adj) {
            x.clear();
        }
        memset(vis, false, MAX * sizeof(bool));
        memset(comp, -1, MAX * sizeof(int));
        edges.clear();
        cin >> n >> m;
        string s;
        int a, b;
        for(int i = 0; i < m; ++i) {
            cin>> a >> s >> b;
            if(s == "=") {
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
            else {
                edges.emplace_back(a,b);
            }
        }

        int numEg = 0;

        for(int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                dfs(i, numEg ++);
            }
        }

        bool flag = true;
        for(auto & edge : edges) {
            if(comp[edge.first] == comp[edge.second]) {
                flag = false;
                break;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");

    }

}
