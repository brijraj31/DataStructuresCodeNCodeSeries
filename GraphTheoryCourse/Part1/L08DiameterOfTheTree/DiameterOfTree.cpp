
//
// Created by brijr on 30-3-20.
//

/*https://www.spoj.com/problems/PT07Z/*/

#include <iostream>
#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

vector<int> adj[MAX];
bool vis[MAX] = {false};
int diaEnd = -1;
int maxDepth = -1;
void dfs(int s, int d) {
    vis[s] = true;

    if(d > maxDepth) {
        maxDepth = d;
        diaEnd = s;
    }


    for(int x : adj[s]) {
        if(!vis[x]) {
            dfs(x, d + 1);
        }
    }


}
int main() {

    int n;
    cin >> n;
    int u, v;
    for(int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    memset(vis, false, MAX * sizeof(bool));
    maxDepth = -1;
    int temp = diaEnd;
    diaEnd = -1;
    dfs(temp, 0);

    cout << maxDepth;
    return 0;
}
