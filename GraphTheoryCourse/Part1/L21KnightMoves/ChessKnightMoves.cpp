// Problem Link : https://www.codechef.com/problems/PRGCUP01

/* 

Chess knight move Problem Code: PRGCUP01

Carol is learning chess and has difficulty with knight move. Her teacher gave her an practice. Take two random squares from chess board and try to take a knight from one square to the other with the least number of moves.

Help Carol with a program that evaluates the minimum number of moves a knight needs to travel from one square to another.

 
Input

First line contains an integer T denotes the number of test cases. The T following lines, each line contains start and final squares space separated. Chess board square is described by chess algebraic notation, i.e., a letter followed by a digit, letters from a to h represent columns and digits from 1 to 8 represents rows of chessboard.

 
Output

For each test case, output a single line containing the minimum number of moves a knight needs to travel from a square to another.

 
Example

Input:
2
a1 b1
g8 f6

Output:
3
1
 */

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, M;
bool vis[1001][1001];
int X[]{-1, 1, 2, 2, -1, 1, -2, -2};
int Y[]{-2, -2, -1, 1, 2, 2, -1, 1};
int dist[1001][1001];
bool isValid(int x, int y) {
    return ! (x < 1 || x > N || y < 1 || y > M || vis[x][y]);
}

void bfs(int x, int y, int eX, int eY) {
    queue<pair<int,int>> q;
    q.emplace(x, y);

    vis[x][y] = 1;
    dist[x][y] = 0;
    bool flag = false;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i) {
            if (isValid(p.first + X[i], p.second + Y[i])) {
                q.emplace(p.first + X[i], p.second + Y[i]);
                dist[p.first + X[i]][p.second + Y[i]] = 1 + dist[p.first][p.second];
                vis[p.first + X[i]][p.second + Y[i]] = true;
                if (p.first + X[i] == eX && p.second + Y[i] == eY) {
                    flag = false;
                }
            }
        }
        if (flag) break;
    }

    cout << dist[eX][eY] << '\n';
    
}

int main() {
    N = M = 8;
    int t;
    cin >> t;
    while (t -- > 0) {
        for (int i = 1; i <= 8; ++i) {
            for (int j = 1; j <= 8; ++j) {
                vis[i][j] = false;
            }
        }
        char x;
        cin >> x;
        int stX = x - 'a' + 1;
        cin >> x;
        int stY = x - '0';

    
        cin >> x;
        int eX = x - 'a' + 1;
        cin >> x;
        int eY = x - '0';
        bfs(stX, stY, eX, eY);

    }

    return 0;
}