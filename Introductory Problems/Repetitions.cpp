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
	
	string s;
	cin>>s;
	
	int n = s.size();
	int mx = 1;
	int tmp_mx = 1;
	for(int i = 1; i < n; i++) {
		if(s[i] == s[i-1]) {
			tmp_mx ++;
		} else {
			mx = max(tmp_mx, mx);
			tmp_mx = 1;
		}
	}
	mx = max(mx, tmp_mx);
	cout<<mx<<endl;
	
	return 0;
}

