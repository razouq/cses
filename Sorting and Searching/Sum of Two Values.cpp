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
	
	map<ll, vector<int>> mp;
	vector<ll> v(n);
	for(int i = 0; i < n; i++) {
		cin>>v[i];
		mp[v[i]].PB(i+1);
	}
	
	bool found = false;
	for(ll item : v) {
		if(item != x - item && mp[item].size() && mp[x-item].size()) {
			cout<<mp[item][0]<<" "<<mp[x-item][0]<<endl;
			found = true;
		}
		else if(item == x - item && mp[item].size() >= 2) {
			cout<<mp[item][0]<<" "<<mp[item][1]<<endl;
			found = true;
		}
		if(found) break;
	}
	
	if(!found) cout<<"IMPOSSIBLE"<<endl;
	
	
	return 0;
}

