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

vector<int> graph[200002];
int dp[200002][2];

void solve(int node, int parent) {
	vector<int> arr;
	dp[node][0] = dp[node][1] = 0;
	
	bool leaf = true;
	
	for(int i = 0; i < graph[node].size(); i++) {
		if(graph[node][i] != parent) {
			leaf = false;
			solve(graph[node][i], node);
		}
	}
	if(leaf) return;
	
	for(int i = 0; i < graph[node].size(); i++) {
		if(graph[node][i] != parent) {
			arr.PB(max(dp[graph[node][i]][0], dp[graph[node][i]][1]));
		}
	}
	int sum = 0;
	for(int i = 0; i < arr.size(); i++) {
		sum += arr[i];
	}
	
	
	// do not take an edge from node to one of his children
	dp[node][0] = sum;
	
	int c = 0;
	for(int i = 0; i < graph[node].size(); i++) {
		if(graph[node][i] == parent) continue;
		
		dp[node][1] = max(dp[node][1], 1 + dp[graph[node][c]][0] + sum - arr[c]);
		c++;
	}
}

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>n;
	for(int i = 0; i < n-1; i++) {
		int a, b;
		cin>>a>>b;
		
		graph[a].PB(b);
		graph[b].PB(a);
	}
	
	solve(1, 0);
	cout<<max(dp[1][0], dp[1][1])<<endl;
	return 0;
}

