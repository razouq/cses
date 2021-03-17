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

ll memo[10][20];

ll dp(int last, int index, string s) {
	if(memo[last-'0'][index] != -1) return memo[last-'0'][index];
	
	// base case
	if(index == s.size() - 1) {
		ll ans = 0;
		for(char i = '0'; i <= '9'; i++) {
			if((last != i || s.size()==1) && i <= s[index]) {
				cout<<i<<", "<<s[index]<<endl;
				ans ++;
			}
		}
		memo[last-'0'][index] = ans;
		return ans;
	}
		
	ll ans = 0;
	for(char i = '0'; i <= '9'; i++) {
		if(index == 0 || (last != i && i <= s[index])) {
//			cout<<"i = "<<i<<endl;
			ans += dp(i, index+1, s);
		}
	}
	
	memo[last-'0'][index] = ans;
	cout<<ans<<endl;
	
	return ans;
}

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	ll a, b;
	cin>>a>>b;
	
	memset(memo, -1, sizeof memo);
	cout<<"b = "<<dp('0', 0, to_string(b))<<endl;
	memset(memo, -1, sizeof memo);
	cout<<"a = "<<dp('0', 0, to_string(a))<<endl;
	
	return 0;
}

