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
	
	for(int i = 0; i < n; i++) cin>>x[i];
	
	
	ll sum = 0;
	ll dp[n][n];
	// dp[l][r] max of score1 - score2 in the sub array [l..r]
	for(int i = 0; i < n; i++) {
		dp[i][i] = x[i];
		sum += x[i];
	}
	
	for(int i = n-2; i >= 0; i--) {
		for(int j = i+1; j < n; j++)  {
			dp[i][j] = max(x[i] - dp[i+1][j], x[j] - dp[i][j-1]);
		}
	}
	
	cout<<dp[0][n-1] + (sum - dp[0][n-1]) / 2<<endl;
	
	
	return 0;
}

