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

vector<ll> coins;
ll n, x;

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	cin>>n>>x;
	
	coins.resize(n);
	for(ll &coin : coins) cin>>coin;
	
	ll dp[x+1];
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	
	for(int j = 0; j < n; j++) {
		for(int i = 1; i < x+1; i++) {
			if(i - coins[j] >= 0) dp[i] += dp[i - coins[j]];
			dp[i] %= 1000000007;
		}
	}
	
	cout<<dp[x]<<endl;
	
	return 0;
}

