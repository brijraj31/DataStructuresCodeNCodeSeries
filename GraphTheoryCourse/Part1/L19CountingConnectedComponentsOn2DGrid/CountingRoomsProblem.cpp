#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, M;
bool vis[1001][1001];
char arr[1001][1001];
int X[]{-1, 0, 1, 0};
int Y[]{0, -1, 0, 1};
bool isValid(int x, int y) {
    return ! (x < 1 || x > N || y < 1 || y > M || vis[x][y] || arr[x][y] == '#');
}

void dfs(int x, int y) {
    vis[x][y] = true;
    

    for (int i = 0; i < 4; ++i) {
        int newX = x + X[i];
        int newY = y + Y[i];

        if (isValid(newX, newY))
            dfs(newX, newY);
    }
}
int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> arr[i][j];
        }
    }
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (isValid(i, j)) {
                dfs(i, j);
                count ++;
            }
        }
    }
    cout << count << '\n';
    return 0;
}

/* 
5 8
########
#..#...#
####.#.#
#..#...#
########

 */