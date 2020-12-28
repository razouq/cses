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
	
	vector<pair<ll, ll>> v(n);
	ll index = 1;
	for(pair<ll, ll> &item : v) {
		cin>>item.F;
		item.S = index;
		index++;
	}
	
	sort(v.begin(), v.end());
	
	vector<pair<ll, pair<ll, ll>>> u;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			u.PB({v[i].F + v[j].F, {v[i].S, v[j].S}});
		}
	}
	sort(u.begin(), u.end());
	
	bool found = false;
	for(ll i = 0; i < v.size(); i++) {
		for(ll j = i+1; j < v.size(); j++) {
			ll sum = v[i].F + v[j].F;
			pair<ll, pair<ll, ll>> p = {x - sum, {0, 0}};
			auto it = lower_bound(u.begin(), u.end(), p);
			while(it != u.end() && (*it).F == x - sum) {
				if((*it).S.F != v[i].S && (*it).S.S != v[i].S && (*it).S.F != v[j].S && (*it).S.S != v[j].S) {
					cout<<v[i].S<<" "<<v[j].S<<" "<<(*it).S.F<<" "<<(*it).S.S<<endl;
					found = true;
					break;
				}
				it++;
			}
			if(found) break;
		}
		if(found) break;
	}
	if(!found) cout<<"IMPOSSIBLE"<<endl;
	return 0;
}

