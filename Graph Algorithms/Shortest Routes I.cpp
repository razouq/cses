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

vector<pair<int, ll>> g[100001];
bool vis[100001];
ll distances[100001];

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	memset(distances, -1, sizeof distances);
	memset(vis, false, sizeof vis);
	
	int n, m;
	cin>>n>>m;
	
	for(int i = 0; i < m; i++) {
		int a, b;
		ll c;
		cin>>a>>b>>c;
		
		g[a].PB({b, c});	
	}
	
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	// {distance, node}
	pq.push({0, 1});
	distances[1] = 0;
	
	while(!pq.empty()) {
		pair<ll, int> node = pq.top();
		pq.pop();
		
		if(vis[node.S]) continue;
		vis[node.S] = true;
		
		for(auto neighbor : g[node.S]) {
			if(distances[neighbor.F] == -1 || distances[neighbor.F] > distances[node.S] + neighbor.S) {
				distances[neighbor.F] = distances[node.S] + neighbor.S;
				pq.push({distances[neighbor.F], neighbor.F});
			}
		}
		
	}
	
	for(int i = 1; i <= n; i++) cout<<distances[i]<<" ";
	cout<<endl;
	
	return 0;
}

