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
	
	int n;
	cin>>n;
	
	map<ll, int> mp;
	mp[0] = 1;
	ll sum = 0;
	ll res = 0;
	for(int i = 0; i < n; i++) {
		ll a;
		cin>>a;
		sum += a;
		sum %= n;
		sum += n;
		if(mp.find(sum % n) != mp.end()) {
			res += mp[sum % n];	
		}
		mp[sum % n]++;
	}
	cout<<res<<endl;
	return 0;
}

