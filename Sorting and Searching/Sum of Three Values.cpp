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
	
//	pair<ll, ll> p = {10, 0};
//	auto it = lower_bound(v.begin(), v.end(), p);
//	if(it == v.end()) cout<<"not found"<<endl;
//	cout<<(*it).F<<" "<<(*it).S<<endl;
	
	bool found = false;
	for(ll i = 0; i < v.size(); i++) {
		for(ll j = i+1; j < v.size(); j++) {
			ll sum = v[i].F + v[j].F;
			if(sum >= x) continue;
			pair<ll, ll> p = {x - sum, 0};
			auto it = lower_bound(v.begin(), v.end(), p);
			while(it != v.end() && (*it).F == x - sum) {
				if((*it).S != v[i].S && (*it).S != v[j].S) {
					cout<<v[i].S<<" "<<v[j].S<<" "<<(*it).S<<endl;
					
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

