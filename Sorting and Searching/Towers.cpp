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
	
	multiset<ll> towers;
	
//	towers.insert(1);
//	towers.insert(3);
//	
//	auto it = towers.upper_bound(4);
//	if(it != towers.end())
//		cout<<*it<<endl;
//	else cout<<"not found"<<endl;
	
	while(n--) {
		ll k;
		cin>>k;
		auto it = towers.upper_bound(k);
		if(it != towers.end()) {
			towers.erase(it);
		} 
		towers.insert(k);
	}
	
	cout<<towers.size()<<endl;
	
	return 0;
}

