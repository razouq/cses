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
 
ll subsetSum(ll n, ll sum) {
	vector<vector<ll>> dp(n,vector<ll>(sum+1,0));
  	dp[0][0] = 1;
  	for (int i = 1; i < n; i++) {
    		for (int j = 0; j <= sum; j++) {
      			dp[i][j] = dp[i-1][j];
      			int left = j-i;
      			if (left >= 0) {
				(dp[i][j] += dp[i-1][left]) %= MOD;
      			}
    		}
  	}
  	
  	return dp[n-1][sum];
} 
 
int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	ll n;
	cin>>n;
	
	ll m = n * (n+1) / 2;
	if(m % 2 != 0) cout<<0<<endl;
	else {
		// search the sum = m
		m /= 2;
		
		cout<<subsetSum(n, m)<<endl;
	} 
	
	return 0;
}
