
//
// Created by brijr on 29-3-20.
//

//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/


#include <iostream>
#include <bits/stdc++.h>


using namespace std;
#define MAX 100001
vector<int> adj[MAX];

bool vis[MAX];
void dfs(int s) {
    vis[s] = true;

    for(int i = 0; i < adj[s].size(); ++i) {
        if(!vis[adj[s][i]]) {
            dfs(adj[s][i]);
        }
    }
}
int main() {

ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < MAX; ++i) {
        vis[i] = false;
    }
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n - 1 != m) {
        cout<<"NO";
        return 0;
    }

    dfs(1);
    bool flag = false;
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            flag = true;
            break;
        }
    }

    if(flag) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }





    return 0;
}

