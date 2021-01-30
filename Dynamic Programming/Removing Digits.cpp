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
	int c = 0;
	while(n) {
		int m = n;
		int mx = 0;
		while(m) {
			mx = max(mx, m%10);
			m /= 10;
		}
		n -= mx;
		c++;
	}
	cout<<c<<endl;
	return 0;
}

