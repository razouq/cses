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

const ll INF = 1e18;
int parent[2505];
ll distances[2505];

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	int n, m;
	cin>>n>>m;
	
	vector<tuple<int, int, ll>> edges;
	
	for(int i = 0; i < m; i++) {
		int a, b;
		ll c;
		cin>>a>>b>>c;
		edges.push_back(make_tuple(a, b, c));
	}
	for(int i = 1; i <= n; i++) {
		distances[i] = INF;
		parent[i] = 0;
	}

	distances[1] = 0;
	int nodeCycle;
	for(int i = 1; i <= n; i++) {
		nodeCycle = 0;
		for(auto tp : edges) {
			int a = get<0>(tp);
			int b = get<1>(tp);
			ll c = get<2>(tp);
			if(distances[a] + c < distances[b]) {
				distances[b] = distances[a] + c;
				parent[b] = a;
				nodeCycle = b;
			}
		}
	}
	
	if(nodeCycle) {
		cout<<"YES"<<endl;
		vector<int> res;
//		for(int i = 1; i <= n; i++) 
		nodeCycle = parent[nodeCycle];
		for(int x = nodeCycle;; x = parent[x]) {
			res.push_back(x);
//			cout<<x<<endl;
			if(x == nodeCycle && res.size() > 1) break;
		}
		
		reverse(res.begin(), res.end());
		for(auto nd : res) cout<<nd<<" ";
		cout<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	
	return 0;
}

