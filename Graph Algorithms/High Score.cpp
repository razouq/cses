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

const long long INF = 1e12;

bool vis1[2501];
bool vis2[2501];

vector<int> adj1[2501];
vector<int> adj2[2501];

void dfs1(int node) {
	if(vis1[node]) return;
	vis1[node] = true;
	for(int neighbor : adj1[node]) {
		dfs1(neighbor);
	}
}

void dfs2(int node) {
	if(vis2[node]) return;
	vis2[node] = true;
	for(int neighbor : adj2[node]) {
		dfs2(neighbor);
	}
}

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	int n, m;
	cin>>n>>m;
	
	vector<ll> distance(n+1);
	for(int i = 0; i <= n; i++) distance[i] = -INF;
	distance[1] = 0;
	
	vector<tuple<int, int, ll>> edges;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin>>a>>b;
		ll x;
		cin>>x;
		
		adj1[a].PB(b);
		adj2[b].PB(a);
		edges.PB(make_tuple(a, b, x));
	}
	
	dfs1(1);
	dfs2(n);
	
	bool flag = false;
	for(int i = 1; i <= n; i++) {
		for(auto e : edges) {
			int a, b;
			ll x;
			tie(a, b, x) = e;
//			cout<<a<<" "<<b<<" "<<x<<endl;
			if(distance[a] != -INF && distance[b] < distance[a] + x) {
//				cout<<b<<" -> "<<distance[b]<<endl;
				distance[b] = distance[a] + x;
				if(i == n && vis1[b] && vis2[b]) flag = true;
			}
		}
	}
	
	if(flag) cout<<-1<<endl;
	else cout<<distance[n]<<endl;
//	cout<<"--------"<<endl;
//	for(int i = 1; i <= n; i++) cout<<distance[i]<<endl;
	
	return 0;
}

