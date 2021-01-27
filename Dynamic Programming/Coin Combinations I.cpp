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

ll memo[1000001];

ll dp(int e) {
	if(memo[e] != -1) return memo[e];
	if(e == 0) return 1;
	ll r = 0;
//	cout<<"dp("<<e<<")"<<endl;
	for(int i = 0; i < n; i++) {
		if(e - coins[i] >= 0) {
			r += dp(e - coins[i]);
			r %= 1000000007;
		}
	}
	memo[e] = r;
	return r;
}

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	memset(memo, -1, sizeof memo);
	
	cin>>n>>x;
	
	coins.resize(n);
	for(ll &coin : coins) cin>>coin;
	
	cout<<dp(x)<<endl;
	
	return 0;
}

