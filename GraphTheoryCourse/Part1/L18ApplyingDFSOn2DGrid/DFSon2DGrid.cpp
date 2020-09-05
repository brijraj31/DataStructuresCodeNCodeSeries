#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, M;
bool vis[1001][1001];

bool isValid(int x, int y) {
    return ! (x < 1 || x > N || y < 1 || y > M || vis[x][y]);
}

void dfs(int x, int y) {
    vis[x][y] = true;
    cout << x << " " << y << "\n";

    if (isValid(x - 1, y)) 
        dfs(x - 1, y);
    
    if (isValid(x + 1, y)) 
        dfs(x + 1, y);

    if (isValid(x, y - 1))
        dfs(x, y - 1);

    if (isValid(x, y + 1))
        dfs(x, y + 1);
}
int main() {
    cin >> N >> M;

    dfs(1, 1);

    return 0;
}