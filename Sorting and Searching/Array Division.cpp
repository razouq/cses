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

int n, k;
vector<ll> v;

bool check(ll sol) {
	// the number of subarrays
	int c = 1;
	// sum of current subarray
	ll s = 0;
	
	for(ll &item : v) {
		if(item > sol) return false;
		// we cannot add another item to the current subarray
		// we have to create new one and reinitialize the sum 's'
		if(s + item > sol) {
			c++;
			s = item;
		} 
		// we can add more items to the current subarray
		else {
			s += item;
		}
	}
	// if the tested solution is lower than the maximum number of subarrays
	if(c <= k) return true;
	return false;
}

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	cin>>n>>k;
	v.resize(n);
	
	ll sum = 0;
	
	for(ll &item : v) {
		cin>>item;
		sum += item;
	}
	
	ll e = 0;
	ll f = sum;
	ll ans = sum;
	while(e <= f) {
		ll mid = (e + f) / 2;
		if(check(mid)) {
			ans = mid;
			f = mid - 1;
		} else {
			e = mid + 1;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}

