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

ll memo[10][20][2][2];

ll dp(char last, int index, string s, bool mx, bool leading_zero) {
	if(index == s.size()) return 1;
	
	if(memo[last-'0'][index][mx][leading_zero] != -1) return memo[last-'0'][index][mx][leading_zero];
	
	char from = '0';
	char to = mx ? s[index] : '9';
		
	ll ans = 0;
	for(char i = from; i <= to; i++) {
		if(last != i || leading_zero) {
//			cout<<"i = "<<i<<endl;
			ans += dp(i, index+1, s, mx && i == s[index], leading_zero && i == '0');
		}
	}
	
	memo[last-'0'][index][mx][leading_zero] = ans;
//	cout<<ans<<endl;
	
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
	ll res1 = dp('0', 0, to_string(b), true, true);
//	cout<<"b = "<<res1<<endl;
	memset(memo, -1, sizeof memo);
	ll res2 = dp('0', 0, to_string(a-1), true, true);
//	cout<<"a = "<<res2<<endl;
	cout<<res1 - res2<<endl;
	
	return 0;
}

