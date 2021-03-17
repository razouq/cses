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

ll MOD = 1e9+7;
int n, m;
ll memo[1002][1<<11];

void generate_next_masks(int mask, int index, int next_mask, vector<int>& next_masks) {
//	cout<<"index "<<index<<endl;
	if(index == n+1) {
		next_masks.PB(next_mask);
		return;
	}
	
	if((mask & (1<<index)) != 0) { // the i th position is 1 (not empty)
		// just skip
		generate_next_masks(mask, index+1, next_mask, next_masks);
	}
	
	if((mask & (1<<index)) == 0) { // the i th element in mask is 0 => we can fill it horizontally
		// fill the i th element of next mask with 1
		generate_next_masks(mask, index+1, next_mask + (1<<index), next_masks);
	}
	
	if(index != n && (mask & (1<<index)) == 0 && (mask & (1<<(index+1))) == 0) { // we fill it vertically
							// & no need to update next_mask
		generate_next_masks(mask, index+2, next_mask, next_masks);
	}
}

ll dp(int col, int mask) {
//	cout<<col<<" "<<mask<<endl;
	if(memo[col][mask] != -1) return memo[col][mask];
	
	// base case
	if(col == m+1) {
		if(mask == 0) return 1;
		return 0;
	} 
	
	// generate next masks based on the current mask
	vector<int> next_masks;
	generate_next_masks(mask, 1, 0, next_masks);
	
	ll ans = 0;
	for(int next_mask : next_masks) {
		ans += dp(col+1, next_mask);
		ans %= MOD;
	}
	
	memo[col][mask] = ans;
	return ans;
}

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	cin>>n>>m;
	
	memset(memo, -1, sizeof memo);
	
	cout<<dp(1, 0)<<endl;
	
	return 0;
}

