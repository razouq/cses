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
	
	int n, m;
	cin>>n>>m;
	
	ll k;
	cin>>k;
	
	vector<ll> a(n);
	vector<ll> b(m);
	
	for(ll &item : a) cin>>item;
	for(ll &item : b) cin>>item;
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int e = 0, f = 0;
	int c = 0;
	while(e < n && f < m) {
		if(b[f] - k <= a[e] && a[e] <= b[f] + k) {
			c++;
			e++;
			f++;
		} else if(a[e] < b[f] - k) {
			e++;
		} else {
			f++;
		}
	}
	cout<<c<<endl;
	
	return 0;
}

