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

string decToBinary(ll m) {
	string s = "";
	while(m > 0) {
		s += m%2 ? '1' : '0';
		m /= 2;
	}
	reverse(s.begin(), s.end());
	return s;
}

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	int n;
	cin>>n;
	
	ll p[n];
	ll minDiff = 0;
	for(int i = 0; i < n; i++) {
		cin>>p[i];
		minDiff += p[i];
	}
	
	ll limit = powl(2, n+1);
	
	for(ll i = 1; i < limit; i++) {
		string b = decToBinary(i);
		ll sum1 = 0;
		ll sum2 = 0;
		for(int j = 0; j < n; j++) {
			if(j < b.size() && b[j] == '0') {
				sum1 += p[j];
			} else {
				sum2 += p[j];
			}
		}
		minDiff = min(minDiff, abs(sum1 - sum2));
	}
	
	cout<<minDiff<<endl;
	return 0;
}

