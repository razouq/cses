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
	
	ll n;
	cin>>n;
	
	ll sum = n * (1+n) / 2;
	
	if(sum % 2) cout<<"NO"<<endl;
	else {
		ll s = 0;
		vector<ll> arr1, arr2;
		for(ll i = n; i >= 1; i--) {
			if(s + i <= sum / 2) {
				s += i;
				arr1.PB(i);
			} else {
				arr2.PB(i);
			}
		}
		if(s != sum / 2) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			cout<<arr1.size()<<endl;
			for(int i = 0; i < arr1.size(); i++) {
				cout<<arr1[i]<<" ";
			}
			cout<<endl;
			cout<<arr2.size()<<endl;
			for(int i = 0; i < arr2.size(); i++) {
				cout<<arr2[i]<<" ";
			}
			cout<<endl;
		}
	}
	
	return 0;
}

