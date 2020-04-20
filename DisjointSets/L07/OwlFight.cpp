// Problem Link :https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/owl-fight/



#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define MAXN 100001
typedef long long int ll;



int parent[MAXN] = {0};


int findSetTer(int a) {
    vector<int> v;

    while(parent[a] > 0) {
        v.push_back(a);
        a = parent[a];
    }

    for(int i = 0; i < v.size(); ++i) 
        parent[v[i]] = a;     // make all entries points to a

    return a;    

}

int findSetRec(int a) {

    if(parent[a] < 0) return a;

    return parent[a] = findSetRec(parent[a]);

}
void unionSet(int u, int v) {
    if(u > v) {
        int temp = u;
        u = v;
        v = temp;
    }
    parent[v] += parent[u];
    parent[u] = v;
}

int main() {
    memset(parent, -1, MAXN * sizeof(int));
    int n, m;
    cin >> n >> m;

    int u, v;

    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        u = findSetRec(u) , v = findSetRec(v);
        if(u != v) unionSet(u, v);
    }

	int q;
	cin >> q;
	for(int i = 0; i < q; ++i) {
		int u, v;
		cin >> u >> v;

		int a = findSetRec(u);
		int b = findSetRec(v);
		if(a == b) cout << "TIE\n";
		else {
			if(a > b) {
				cout << u << '\n';
			}
			else {
				cout << v << '\n';
			}
		}
	}
    
}