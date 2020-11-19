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
	
	int t;
	cin>>t;
	while(t--) {
		ll x, y;
		cin>>x>>y;
		ll mx = max(x, y);
		ll r = 1 + 2 * mx * (mx - 1) / 2;
		if(mx % 2 == 1) {
			r += y - x;
		} else {
			r += x - y;
		}
		cout<<r<<endl;
	}
	
	return 0;
}

