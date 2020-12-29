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
	
	ll x;
	cin>>x;
	
	ll sum = 0;
	int last_index = 0;
	int c = 0;
	ll a[n];
	for(int i = 0; i < n; i++) {
		cin>>a[i];
		sum += a[i];
		while(sum > x) {
			sum -= a[last_index];
			last_index++;
		}
		if(sum == x) c++;
	}
	cout<<c<<endl;
	
	return 0;
}

