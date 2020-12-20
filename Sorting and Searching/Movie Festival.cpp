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

bool compare(pair<ll, ll> p1, pair<ll, ll> p2) {
	return (p1.S < p2.S || (p1.S == p2.S && p1.F < p2.F));
}

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	int n;
	cin>>n;
	
	vector<pair<ll, ll>> v(n);
	for(pair<ll, ll> &item : v) {
		cin>>item.F>>item.S;
	}
	sort(v.begin(), v.end(), compare);
	
	int ans = 1;
	ll last = v[0].S;
	for(int i = 1; i < n; i++) {
		if(v[i].F >= last) {
			ans++;
			last = v[i].S;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}

