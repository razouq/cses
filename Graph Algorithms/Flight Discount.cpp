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

const ll INF = 1e18L;
ll dis1[100001];
ll dis2[100001];
bool vis[100001];
vector<pair<int, ll>> adj1[100001];
vector<pair<int, ll>> adj2[100001];
vector<tuple<int, int, ll>> edges;

void dij(int start, ll dis[], vector<pair<int, ll>> adj[]) {
	memset(vis, false, sizeof vis);
	for(int i = 0; i < 100001; i++) dis[i] = INF;
	dis[start] = 0;
	
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push({0, start});
	
	while(!pq.empty()) {
		pair<ll, int> top = pq.top();
		pq.pop();
		
		int nodeId = top.S;
		int nodeDistance = top.F;
		
		if(vis[nodeId]) continue;
		vis[nodeId] = true;
		
		for(pair<int, ll> node : adj[nodeId]) {
			int neighbor = node.F;
			ll neighborDistance = node.S;
			if(dis[nodeId] + neighborDistance < dis[neighbor]) {
				dis[neighbor] = dis[nodeId] + neighborDistance;
				pq.push({dis[neighbor], neighbor});
			}
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
	
	for(int i = 0; i < m; i++) {
		int a, b;
		ll c;
		cin>>a>>b>>c;
		
		edges.push_back(make_tuple(a, b, c));
		adj1[a].push_back({b, c});
		adj2[b].push_back({a, c});
	}
	
	dij(1, dis1, adj1);
	dij(n, dis2, adj2);
	
	ll res = INF;
	
	for(auto e : edges) {
		int a = get<0>(e);
		int b = get<1>(e);
		ll c = get<2>(e);
		
		res = min(res, dis1[a] + dis2[b] + c / 2);
	}
	
	cout<<res<<endl;
	
	return 0;
}

