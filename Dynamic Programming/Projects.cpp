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
	
	vector<ll> a(n), b(n), p(n);
	map<ll, int> mp_pos;
	for(int i = 0; i < n; i++) {
		cin>>a[i]>>b[i]>>p[i];
		b[i]++;
		mp_pos[a[i]] = 0;
		mp_pos[b[i]] = 0;
	}
	
	int position = 0;
	for(auto item : mp_pos) {
		mp_pos[item.F] = position;
//		cout<<item.F<<" "<<mp_pos[item.F]<<endl;
		position++;
	}
	
	vector<vector<pair<ll, ll>>> projects(position);
	for(int i = 0; i < n; i++) {
//		cout<<i<<endl;
		projects[mp_pos[b[i]]].PB({mp_pos[a[i]], p[i]});
	}
	
//	for(int i = 0; i < projects.size(); i++) {
//		cout<<i<<" : ";
//		for(int j = 0; j < projects[i].size(); j++) {
//			cout<<projects[i][j].F<<" "<<projects[i][j].S<<" ";
//		}
//		cout<<endl;
//	}

	vector<ll> dp(position, 0);
	for(int i = 0; i < dp.size(); i++) {
		if(i > 0) dp[i] = dp[i-1];
		for(auto v : projects[i]) {
			// price + what I earnt before starting this project
			dp[i] = max(dp[i], v.S + dp[v.F]);
		}
//		cout<<dp[i]<<", ";
	}
//	cout<<endl;
	cout<<dp[dp.size()-1]<<endl;
	
	return 0;
}

