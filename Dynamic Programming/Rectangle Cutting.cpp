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

int memo[501][501];

// e >= f
int dp(int e, int f) {
	if(e == f) return 0;
	if(e == 1) return f-1;
	if(f == 1) return e-1;
	if(memo[e][f] != -1) return memo[e][f];
	
	int mn = 100000;
	
	for(int i = 1; i < e; i++) {
		mn = min(mn, dp(e-i, f) + dp(i, f)+1);
	}
	for(int j = 1; j < f; j++) {
		mn = min(mn, dp(e, f-j) + dp(e, j)+1);
	}
	
	memo[e][f] = mn;
	return mn;
}

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	memset(memo, -1, sizeof memo);
	
	int a, b;
	cin>>a>>b;
	
	cout<<dp(a, b)<<endl;
	return 0;
}

