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

int n, m, k;

// {node, weight}
vector<pair<ll, int>> g[200001];
int vis[200001];

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	cin>>n>>m>>k;
	
	for(int i = 0; i < m; i++) {
		int a, b;
		ll c;
		cin>>a>>b>>c;
		g[a].push_back({c, b});
	}
	
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > pq;
	
	pq.push({0, 1});
	for(int i = 0; i < 200001; i++) vis[i] = 0;
	
	while(!pq.empty() && vis[n] < k) {
		ll nodeDis = pq.top().F;
		int nodeId = pq.top().S;
		pq.pop();
		vis[nodeId]++;
		if(nodeId == n) cout<<nodeDis<<" ";
		if(vis[nodeId] <= k) {
			for(auto neigh : g[nodeId]) pq.push({nodeDis + neigh.F, neigh.S});
		}
	}
	
	return 0;
}

