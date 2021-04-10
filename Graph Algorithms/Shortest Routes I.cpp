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

vector<pair<int, ll>> grid[100001];

ll distances[100001];

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
		
		grid[a].PB({b, c});	
	}
	
	
	
	memset(distances, -1, sizeof distances);
	
	queue<int> q;
	q.push(1);
	distances[1] = 0;
	
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		// {1, 0}
		
		for(int i = 0; i < grid[node].size(); i++) {
			if(distances[grid[node][i].F] == -1 || distances[grid[node][i].F] > distances[node] + grid[node][i].S) {
				distances[grid[node][i].F] = distances[node] + grid[node][i].S;
				q.push(grid[node][i].F);
			}
		}
		
	}
	
	for(int i = 1; i <= n; i++) cout<<distances[i]<<" ";
	cout<<endl;
	
	return 0;
}

