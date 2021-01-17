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
	
	int n, k;
	cin>>n>>k;
	
	set<ll> st;
	map<ll, int> mp;
	vector<ll> v(n);
	ll res = 0;
	int last_index = 0;
	for(int i = 0; i < n; i++) {
		cin>>v[i];
		mp[v[i]]++;
		st.insert(v[i]);
		if(st.size() <= k) {
			res += i - last_index + 1;
		} else {
			while(st.size() > k) {
				mp[v[last_index]]--;
				if(!mp[v[last_index]]) {
					st.erase(v[last_index]);
				}
				last_index++;
			}
			res += i - last_index + 1;
		}
	}
	cout<<res<<endl;
	return 0;
}

