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
	
	multiset<ll> distances, traffics;
	
//	distances.insert(1);
//	distances.insert(3);
//	distances.insert(5);
	
//	auto it = distances.lower_bound(3);
//	auto it = distances.end();
//	it--;
//	cout<<*it<<endl;
	
	ll x;
	cin>>x;
	
	int n;
	cin>>n;
	
	traffics.insert(0);
	traffics.insert(x);
	
	distances.insert(x);
	
	while(n--) {
		ll p;
		cin>>p;
			
		auto it1 = traffics.lower_bound(p);
		auto it0 = it1;
		it0--;
		
		ll distance = *it1 - *it0;
		auto it_del_distance = distances.lower_bound(distance);
		it_del_distance--;
		
		distances.insert(p - *it0);
		distances.insert(*it1 - p);
		cout<<"add "<<p - *it0<<" "<<*it1 - p<<endl;
		
		cout<<"to delete"<<*it1 - *it0<<endl;
		auto it_del = distances.lower_bound(*it1 - *it0);
		it_del--;
		distances.erase(it_del);
		traffics.insert(p);
		
		auto ans = distances.end();
		ans--;
		cout<<*ans<<endl;
		
	}
	return 0;
}

