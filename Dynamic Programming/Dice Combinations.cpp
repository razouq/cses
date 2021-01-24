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

ll v[1000001];
ll MOD = 1000000007;

ll dp(int n) {
	if(v[n] != -1) return v[n];
	ll res = 0;
	
	for(int i = 6; i > 0; i--) {
		if(n - i < 0) continue;
		res += dp(n-i) % MOD;
		res %= MOD;
	}
	
	return v[n] = res;
}

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	int n;
	cin>>n;
	
	for(int i = 0; i <= 1000001; i++) {
		v[i] = -1;
	}
	v[0] = 1;
	
	cout<<dp(n)<<endl;
	
	return 0;
}

