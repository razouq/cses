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
	sort(s.begin(), s.end());
	string p = s;
	vector<string> res;
	do {
		res.PB(s);
		next_permutation(s.begin(), s.end());
	} while(s != p);
	
	cout<<res.size()<<endl;
	for(int i = 0; i < res.size(); i++) {
		cout<<res[i]<<endl;
	}
	
	
	return 0;
}

