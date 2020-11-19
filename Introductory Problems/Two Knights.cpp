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
	
	ll n;
	cin>>n;
	
	for(ll i = 1; i <= n; i++) {
		cout<<((i*i) * (i*i-1) - 2 * 2 * 2 * (i-1) * (i-2)) / 2<<endl;
	}
	
	return 0;
}

