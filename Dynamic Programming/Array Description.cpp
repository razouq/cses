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

const ll MOD = 1e9+7;

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	int n, m;
	cin>>n>>m;
	
	vector<ll> v(n);
	for(int i = 0; i < n; i++) cin>>v[i];
	
	ll dp[n][m+1];
	memset(dp, 0, sizeof dp);
	
	if(v[0] == 0) for(int j = 1; j <= m; j++) dp[0][j] = 1;
	else dp[0][v[0]] = 1;
	
	for(int i = 1; i < n; i++) {
		if(v[i] != 0) {
			for(int e = v[i]-1; e <= v[i]+1; e++) {
				if(1 <= e && e <= m) {
					dp[i][v[i]] += dp[i-1][e]; 
				}
			}
		} else {
			// v[i] is 'f' now
			for(int f = 1; f <= m; f++) {
				for(int e = f-1; e <= f+1; e++) {
					if(1 <= e && e <= m) {
						dp[i][f] += dp[i-1][e];
						dp[i][f] %= MOD;
					}
				}
			}
		}
	}
	
	ll res = 0;
	for(int j = 1; j <= m; j++) {
		res += dp[n-1][j];
		res %= MOD;
	}
	cout<<res<<endl;
	return 0;
}

