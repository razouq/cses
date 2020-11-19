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

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	ll n;
	cin>>n;
	
	ll MOD = 1e9+7;
	ll res = 1;
	for(ll i = 0; i < n; i++) {
		res *= 2;
		res %= MOD;
	}
	cout<<res<<endl;
	
	return 0;
}

