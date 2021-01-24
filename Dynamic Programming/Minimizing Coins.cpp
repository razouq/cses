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
	
	int n, x;
	cin>>n>>x;
	
	vector<int> coins(n);
	for(int &coin : coins) cin>>coin;
	
	int mx = 1000001;
	vector<int> v(1000001, -1);
	
	v[0] = 0;
	
	for(int i = 0; i < mx; i++) {
		if(v[i] != -1) {
			for(int j = 0; j < n; j++) {
				if(i + coins[j] < mx) {
					if(v[i + coins[j]] == -1) {
						v[i + coins[j]] = v[i] + 1;
					}
					else {
						v[i + coins[j]] = min(v[i + coins[j]], v[i] + 1);
					}
				}
			}
		} 
	}
	cout<<v[x]<<endl;
	return 0;
}

