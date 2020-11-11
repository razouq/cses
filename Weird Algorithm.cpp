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
	cout<<n;
	while(n != 1) {
		if(n % 2 == 1) {
			n = n * 3 + 1;
		} else {
			n /= 2;
		}
		cout<<" "<<n;
	} 
	cout<<endl;
	
	return 0;
}

