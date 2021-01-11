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
	
	vector<ll> v(n);
	for(ll &item : v) cin>>item;
	
	sort(v.begin(), v.end());
	
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		if(v[i] > sum + 1) break;
		sum += v[i];
	}
	cout<<sum + 1<<endl;
	
	return 0;
}

