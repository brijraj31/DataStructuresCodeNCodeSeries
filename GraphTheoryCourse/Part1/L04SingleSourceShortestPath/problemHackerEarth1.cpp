
//
// Created by brijr on 29-3-20.
//


/*https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/*/


#include <iostream>
#include <bits/stdc++.h>


using namespace std;
#define MAX 100001
vector<int> adj[MAX];

bool vis[MAX];
int dis[MAX];
int id[MAX];
void dfs(int s) {
    vis[s] = true;

    for(int i = 0; i < adj[s].size(); ++i) {
        if(!vis[adj[s][i]]) {
            dis[adj[s][i]] = dis[s] + 1;
            dfs(adj[s][i]);
        }
    }
}
int main() {

ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < MAX; ++i) {
        vis[i] = false;
        dis[i] = INT_MAX;
        id[i] = INT_MAX;
    }
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q;
    cin >> q;
    for(int i = 1; i <= q; ++i) {
        cin >> id[i];
    }


    dis[1] = 0;
    dfs(1);

    int min = INT_MAX;
    int gid = INT_MAX;
    for(int i = 1; i <= q; ++i) {
        int node = id[i];
        int d = dis[node];
        if(d <= min) {
            if(d == min) {
                if(node < gid) {
                    gid = node;
                }
            }
            else {
                min = d;
                gid = node;
            }
        }
    }



    cout << gid;
    return 0;
}
