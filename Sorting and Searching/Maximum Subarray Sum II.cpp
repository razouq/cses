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
	
	int n, a, b;
	cin>>n>>a>>b;
	
	vector<ll> v(n+1);
	v[0] = 0;
	for(int i = 1; i <= n; i++) {
		cin>>v[i];
		v[i] += v[i-1];
	}
	
	ll ans = v[a];
	
	multiset<ll> ms;
	ms.insert(v[0]); // 0
	for(int i = a+1; i <= n; i++) {
		if(i > b) {
			auto it = ms.find(v[i - (b+1)]);
			ms.erase(it);
		}
		if(i > a) {
			ms.insert(v[i-a]);
		}
		ans = max(ans, v[i] - *ms.begin());
	}
	
	cout<<ans<<endl;
	
	return 0;
}

