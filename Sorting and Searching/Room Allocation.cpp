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

//	<<client go, client come>, client id>
	vector<pair<pair<ll, ll>, int>> v(n);
	for(int i = 0; i < n; i++) {
		ll a, b;
		cin>>a>>b;
		v[i].S = i;
		v[i].F = {a, b};
	}
	
	sort(v.begin(), v.end());
	
//	<client go, room id>
	priority_queue<pair<ll, int>> pq;
	int room = 1;
	vector<int> ans(n);
	for(int i = 0; i < n; i++) {
		if(pq.empty()) {
			pq.push({-v[i].F.S, room});
			ans[v[i].S] = room;
		} else {
			pair<ll, int> top = pq.top();
			if(-top.F < v[i].F.F) {
				pq.pop();
				pq.push({-v[i].F.S, top.S});
				ans[v[i].S] = top.S;
			} else {
				room++;
				ans[v[i].S] = room;
				pq.push({-v[i].F.S, room});
			}
		}
	}
	cout<<room<<endl;
	for(int el : ans) {
		cout<<el<<" ";
	} cout<<endl;
	
	return 0;
}

