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
	
	vector<ll> v(n);
	map<ll, ll> mp;
	for(ll &item : v) {
		cin>>item;
		mp[item]++;
	}
	sort(v.begin(), v.end());
	
	
	int nbrOfItems = 0;
	int c = 0;
	for(ll item : v) {
		if(mp[item]) {
			mp[item]--;
			c++;
			nbrOfItems++;
			if(item > (x+1)/2) continue;
			
			auto it = upper_bound(v.begin(), v.end()-(nbrOfItems-c), x-item);
			if(it != v.begin()) {
				int index = it - v.begin() - 1;
				while(!mp[v[index]] && index) {
					index--;
				}
				if(index) {
					mp[v[index]]--;
					nbrOfItems++;
				}
			}
		}
		if(nbrOfItems == n) break;
	}
	
	cout<<c<<endl;	
	
	return 0;
}

