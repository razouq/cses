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
	vector<ull> v;
	v.PB(9);
	ull p = 1;
	for(ull i = 2; i < 18; i++) {
		p *= 10;
		v.PB(i * p * 9 + v[i-2]);
	}

	int q;
	cin>>q;
	while(q--) {
		ull k;
		cin>>k;
		int index = -1;
		for(int i = 0; i < v.size(); i++) {
			if(k >= v[i]) {
				index = i;
			} else break;
		}
		if(index == -1) {
			cout<<k<<endl;
		} else {
			int size = index + 2;
			ull q = (k - v[index]) / size;
			ull r = (k - v[index]) % size;
			ull nbr = powl(10, size-1) + q - 1;
			if(r == 0) {
				string str = to_string(nbr);
				cout<<str[str.size()-1]<<endl;
			} else {
				nbr ++;
				string str = to_string(nbr);
				cout<<str[r-1]<<endl;
			}
		}
	}	
	
	
	return 0;
}

