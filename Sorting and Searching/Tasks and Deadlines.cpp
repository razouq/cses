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
	
	vector<pair<ll, ll>> v(n);
	for(pair<ll, ll> &p : v) cin>>p.F>>p.S;
	sort(v.begin(), v.end());
	
	ll score = 0;
	ll soFar = 0;
	
	for(pair<ll, ll> &p : v) {
		soFar += p.F;
		score += p.S - soFar;
	}
	
	cout<<score<<endl;
	
	return 0;
}

