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
	
	stack<pair<ll, int>> s;
	for(int i = 0; i < n; i++) {
		ll x;
		cin>>x;
		
		while(!s.empty() && (s.top()).F >= x) {
			s.pop();
		}
		if(s.empty()) {
			cout<<0<<" ";
		}  else {
			cout<<s.top().S<<" ";
		}
		
		s.push({x, i+1});
	}

	return 0;
}

