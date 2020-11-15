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
	ll res = 0;
	
	ll a = 5;
	
	while(n >= a) {
		res += n / a;
//		cout<<n/a<<endl;
		a *= 5;
	}
	
	cout<<res<<endl;
	
	return 0;
}

