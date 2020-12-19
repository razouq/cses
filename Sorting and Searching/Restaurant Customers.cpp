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
	
	vector<pair<ll, ll>> v;

	for(int i = 0; i < n; i++) {
		ll a, b;
		cin>>a>>b;
		v.PB({a, 1});
		v.PB({b, 2});
	}
	
	sort(v.begin(), v.end());
	
	ll mx = 0;
	ll tmpMx = 0;
	for(pair<ll, ll> p : v) {
		if(p.S == 1) {
			tmpMx++;
		} else {
			tmpMx--;
		}
		if(tmpMx > mx) mx = tmpMx;
	}
	
	cout<<mx<<endl;
	
	return 0;
}

