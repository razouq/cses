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

const int N = 100001;
int n, m;
int s, e;
vector<int> graph[N];
bool vis[N];
int parent[N];

bool dfs(int node, int par) {
	vis[node] = true;
	parent[node] = par;
//	cout<<node<<endl;
	
	for(int i = 0; i < graph[node].size(); i++) {
		// no problem if the adj of this node is his parent
		if(graph[node][i] == par) continue;
		
		if(vis[graph[node][i]]) {
			s = graph[node][i];
			e = node;
			return true;
		} else if(dfs(graph[node][i], node)) return true;
	}
	return false;
}

bool hasCycle() {
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
//			cout<<i<<endl;
			// a cycle is found
			if(dfs(i, -1)) return true;
		}
	}
	return false;
}


int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	cin>>n>>m;
	
	for(int i = 0; i < m; i++) {
		int a, b;
		cin>>a>>b;
		graph[a].PB(b);
		graph[b].PB(a);
	}
	
	if(hasCycle()) {
		vector<int> response;
//		cout<<"start : "<<s<<" end = "<<e<<endl;
		int k = e;
		response.PB(s);
		while(k != s) {
			response.PB(k);
			k = parent[k];
		}
		response.PB(s);
		cout<<response.size()<<endl;
		for(int i = 0; i < response.size(); i++) {
			cout<<response[i]<<" ";
		}
		cout<<endl;
	} else cout<<"IMPOSSIBLE"<<endl;
	
	return 0;
}

