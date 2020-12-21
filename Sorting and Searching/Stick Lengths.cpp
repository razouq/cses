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
	
	vector<ll> p(n+1);
	p[0] = 0;
	for(int i = 1; i < n+1; i++) cin>>p[i];
	
	sort(p.begin(), p.end());
	
	vector<ll> q;
	for(ll item : p) q.PB(item);
	
	for(int i = 1; i < n+1; i++) {
		p[i] += p[i-1];
	}
	
	
	ll ans = LLONG_MAX;
	for(int i = 1; i < n+1; i++) {
		ll leftSum = p[i-1] - p[0];
		ll rightSum = p[n] - p[i];
		
		int leftNbr = i - 1;
		int rightNbr = n - i;
		
		ans = min(ans, leftNbr * q[i] - leftSum + rightSum - rightNbr * q[i]);
	}
	
	cout<<ans<<endl;
	
	return 0;
}

