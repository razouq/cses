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

int n;
vector<int> tree[200001];
vector<int> ans(200001);

int bfs(int node) {
	int children = 0;
	for(int i = 0; i < tree[node].size(); i++) {
		children += bfs(tree[node][i]);
	}
	ans[node] = children;
	return children+1;
}

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	cin>>n;
	for(int i = 1; i < n; i++) {
		int a;
		cin>>a;
		tree[a].PB(i+1);
	}
	bfs(1);
	
	for(int i = 1; i <= n; i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}

