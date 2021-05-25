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

ll distances[501][501];
const ll MX = 1e12;

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	int n, m, q;
	cin>>n>>m>>q;
	
	for(int i = 1; i < n+1; i++) 
		for(int j = 1; j < n+1; j++)
			distances[i][j] = MX;
	
	for(int i = 0; i < m; i++) {
		int a, b;
		ll c;
		cin>>a>>b>>c;
		distances[a][a] = 0;
		distances[b][b] = 0;
		distances[a][b] = min(distances[a][b], c);
		distances[b][a] = min(distances[b][a], c);
	}
	
	for(int k = 1; k < n+1; k++) {
		for(int i = 1; i < n+1; i++) {
			for(int j = 1; j < n+1; j++) {
				distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
			}
		}
	}
	
	while(q--) {
		int a, b;
		cin>>a>>b;
		ll mx = LLONG_MAX;
		cout<<((distances[a][b] < MX) ? distances[a][b] : -1)<<endl;
	}
	
	return 0;
}

