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
	
	int c[26] = {0};
	for(int i = 0; i < n; i++) {
		c[s[i] - 'A']++;
	}
	
	int odd = 0;
	for(int i = 0 ; i < 26; i++) {
		if(c[i] % 2 == 1) odd++;
	}
	
	if(odd <= 1) {
		string r = "";
		string o = "";
		for(int i = 0; i < 26; i++) {
			if(c[i] % 2 == 0) {
				for(int j = 0; j < c[i]/2; j++) {
					r += 'A' + i;
				}
			} else  {
				for(int  j = 0; j < c[i]; j++) {
					o += 'A' + i;
				}
			}
		}
		cout<<r<<o;
		reverse(r.begin(), r.end());
		cout<<r<<endl;
	} else {
		cout<<"NO SOLUTION"<<endl;
	}
	
	return 0;
}

