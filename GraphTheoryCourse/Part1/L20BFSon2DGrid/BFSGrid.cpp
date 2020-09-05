#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, M;
bool vis[1001][1001];
int X[]{-1, 0, 1, 0};
int Y[]{0, -1, 0, 1};
int dist[1001][1001];
bool isValid(int x, int y) {
    return ! (x < 1 || x > N || y < 1 || y > M || vis[x][y]);
}

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.emplace(x, y);

    vis[x][y] = 1;
    dist[x][y] = 0;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            if (isValid(p.first + X[i], p.second + Y[i])) {
                q.emplace(p.first + X[i], p.second + Y[i]);
                dist[p.first + X[i]][p.second + Y[i]] = 1 + dist[p.first][p.second];
                vis[p.first + X[i]][p.second + Y[i]] = true;
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    cin >> N >> M;
    bfs(1, 1);

    return 0;
}