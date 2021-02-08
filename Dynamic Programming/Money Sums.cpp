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
	vector<int> x(n);
	for(int i = 0; i < n; i++) cin>>x[i];
	sort(x.begin(), x.end());
	bool mp[100001];
	memset(mp, false, sizeof mp);
	
	vector<int> nbrs;
	for(int i = 0; i < n; i++) {
		vector<int> c;
		c.PB(x[i]);
		for(int j = 0; j < nbrs.size(); j++) {
			c.PB(x[i] + nbrs[j]);	
		}
		for(int j = 0; j < c.size(); j++) {
			if(!mp[c[j]]) {
				nbrs.PB(c[j]);	
				mp[c[j]] = true;
			}
		}
	}
	cout<<nbrs.size()<<endl;
	sort(nbrs.begin(), nbrs.end());
	for(int i = 0; i < nbrs.size(); i++) cout<<nbrs[i]<<" "; cout<<endl;
	return 0;
}

