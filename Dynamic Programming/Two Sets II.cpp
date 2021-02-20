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

const ll MOD = 1e9+7;

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	int n;
	cin>>n;
	
	int m = n * (n+1) / 2;
	if(m % 2 != 0) cout<<0<<endl;
	else {
		m /= 2;
		vector<ll> v(m+1, 0);
		
		for(int i = 1; i <= n; i++) v[i] = 1;
		
		for(int i = 2; i <= m; i++) {
			for(int j = 1; j < i && i+j <= m; j++) {
				v[i+j] += v[j];
			}
		}
		
		for(int i = 1; i <= m; i++) cout<<i<<" = "<<v[i]<<endl;
		
		cout<<v[m]/2<<endl;
	} 
	
	
	
	return 0;
}

