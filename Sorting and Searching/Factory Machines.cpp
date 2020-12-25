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
 
vector<ll> v;
int n;
ll t;
 
ll sum(ll x) {
	ll res = 0LL;
	for(ll item : v) {
		res += x / item;
		if(res > t) break;
	}
	return res;
}
 
int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	cin>>n;
	cin>>t;
	
	v.resize(n);
	
	for(ll &item : v) cin>>item;
	
	ll mx = 1e18;
	ll mn = 0;
	
	while(mn <= mx) {
		ll mid = mn + (mx - mn) / 2;
		ll s = sum(mid);
		
		if(s >= t) {
			mx = mid - 1;
		} else {
			mn = mid + 1;
		}
	}

	 cout<<mn<<endl;
	
	return 0;
}
