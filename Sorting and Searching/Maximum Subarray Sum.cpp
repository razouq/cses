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
	
	vector<ll> x(n);
	for(ll &item : x) cin>>item;
	
	ll curr_sum = 0;
	ll mx = LLONG_MIN;
	
	for(ll item : x) {
		curr_sum += item;
		if(curr_sum > mx) mx = curr_sum;
		if(curr_sum < 0) curr_sum = 0;	
	}
	cout<<mx<<endl;
	return 0;
}

