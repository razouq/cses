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

bool visited[100001];
vector<int> graph[100001];

void dfs(int x) {
	visited[x] = true;
	for(int i = 0; i < graph[x].size(); i++) {
		if(!visited[graph[x][i]]) {
			dfs(graph[x][i]);
		}
	}
}

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	int n, m;
	cin>>n>>m;
	
	int c = 0;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin>>x>>y;
		graph[x].PB(y);
		graph[y].PB(x);
	}
	
	vector<int> sol;
	
	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			sol.PB(i);
			dfs(i);
		}
	}
	
	cout<<sol.size()-1<<endl;
	
	for(int i = 0; i < sol.size()-1; i++) {
		cout<<sol[i]<<" "<<sol[i+1]<<endl;
	}
	
	return 0;
}

