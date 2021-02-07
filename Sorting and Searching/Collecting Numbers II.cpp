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
	
	int n, m;
	cin>>n>>m;
	
	int res = 1;
	vector<int> v(n);
	map<int, bool> mp;
	for(int i = 0; i < n; i++) {
		cin>>v[i];
		
		if(v[i] != 1) {
			if(!mp[v[i]-1]) {
				res++;
			}
		}
		mp[v[i]] = true;
	}
	cout<<res<<endl;
	while(m--) {
		int a, b;
		cin>>a>>b;
		if(v[a-1] > v[b-1]) res--;
		else res++;
		swap(v[a-1], v[b-1]);
		cout<<res<<endl;
	}
	
	return 0;
}

