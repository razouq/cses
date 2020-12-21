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
	
	int from = 0;
	int ans = 0;
	map<ll, int> mp;
	for(int i = 1; i <= n; i++) {
		ll item;
		cin>>item;
		from = max(from, mp[item]);
		ans = max(ans, i - from);
		mp[item] = i;
	}
	
	cout<<ans<<endl;
	
	return 0;
}
