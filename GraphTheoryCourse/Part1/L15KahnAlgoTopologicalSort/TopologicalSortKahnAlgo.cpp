#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void topSort(vector<int>* adj, vector<int> inDeg, int n) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (inDeg[i] == 0) {
            q.push(i);
        }
    }
    vector<int> order;
    while (!q.empty()) {
        int curr =  q.front();
        q.pop();
        order.push_back(curr);

        for (int child : adj[curr]) {
            inDeg[child] --; // decreasing the indegree of child or removing the parent -> child edge
            if (inDeg[child] == 0) {
                q.emplace(child);
            }
        }
    }

    cout << "TopSort : ";
    for (int x : order) {
        cout << x << " ";
    }
}

int main() {
    int n, m, x, y;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> inDeg(n + 1, 0);

    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        inDeg[y]++;
    }

    topSort(adj, inDeg, n);
}

/* 
9 10
1 2
3 4
1 8
2 9
2 5
4 5
4 8
5 9
5 7
6 7

TopSort : 1 3 6 2 4 5 8 9 7
 */