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
	multiset<ll, greater<ll>> tickets;
	
	while(n--) {
		ll ticket;
		cin>>ticket;
		tickets.insert(ticket);		
	}
	
	while(m--) {
		ll cust;
		cin>>cust;
		auto it = tickets.lower_bound(cust);
		if(it == tickets.end()) {
			cout<<-1<<endl;
		} else {
			cout<<*it<<endl;
			tickets.erase(it);
		}
	}
	return 0;
}

