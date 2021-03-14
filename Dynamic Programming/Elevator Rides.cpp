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
	ll x;
	cin>>x;
	vector<ll> p(n);
	for(int i = 0; i < n; i++) cin>>p[i];
	
	vector<pair<ll, ll>> sol(1<<n); // {rides, weight of last ride}
	sol[0] = {1, 0};
	
	for(ll i = 1; i < (1<<n); i++) {
		// 000...0001 (1 => in the group)
		// 000...1100
		// 111...1111
		sol[i] = {n+1, 0};
		for(int j = 0; j < n; j++) {
			if(i&(1<<j)) { // p[j] exists in the group
				auto option = sol[i^(1<<j)];
				if(option.S + p[j] <= x) {
					option.S += p[j];
				} else { // new ride
					option.F++;
					option.S = p[j];
				}
				sol[i] = min(sol[i], option);
			}
		}
	}
//	for(int i = 0; i < (1<<n); i++) cout<<sol[i].F<<" "<<sol[i].S<<endl;
	cout<<sol[(1<<n)-1].F<<endl;
	
	return 0;
}

