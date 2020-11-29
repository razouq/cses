#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define ll long long
#define ull unsigned long long
#define F first
#define S second
#define PB push_back
#define POB pop_back

using namespace std;

int n, m;
int vis[100001];
bool impossible = false;

vector<int> g[100001];

void dfs(int x, int color) {
	vis[x] = color;
	for(int i = 0; i < g[x].size(); i++) {
		if(vis[g[x][i]] == -1) {
			dfs(g[x][i], 1 - color);	
		} else if(vis[g[x][i]] == color) {
			impossible = true;
		}
	}
}

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	cin>>n>>m;
	
	for(int i = 1; i <= n; i++) vis[i] = -1;
	
	for(int i = 0; i < m; i++) {
		int a, b;
		cin>>a>>b;
		g[a].PB(b);
		g[b].PB(a);
	}
	
	for(int i = 1; i <= n; i++) {
		if(vis[i] == -1) {
			dfs(i, 1);
		} 
	}
	
	if(impossible) cout<<"IMPOSSIBLE"<<endl;
	else {
		for(int i = 1; i <= n; i++) {
			cout<<2 - vis[i]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}

