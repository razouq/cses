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
	
	int t;
	cin>>t;
	
	while(t--) {
		ll a, b;
		cin>>a>>b;
		if(a > b) swap(a, b);
		
		if((a+b) % 3 == 0 && a >= b / 2) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}

