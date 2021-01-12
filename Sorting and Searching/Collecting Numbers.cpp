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
	
	int res = 1;
	map<int, bool> mp;
	for(int i = 0; i < n; i++) {
		int x;
		cin>>x;
		
		if(x != 1) {
			if(!mp[x-1]) {
				res++;
			}
		}
		
		mp[x] = true;
		
	}
	cout<<res<<endl;
	
	return 0;
}

