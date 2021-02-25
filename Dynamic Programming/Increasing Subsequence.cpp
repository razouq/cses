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
	
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin>>v[i];
	
	vector<int> tail(n);
	int len = 1;
	tail[0] = v[0];
	
	for(int i = 1; i < n; i++) {
		if(v[i] > tail[len-1]) {
			tail[len] = v[i];
			len++;
		} else {
			auto it = lower_bound(tail.begin(), tail.begin() + len, v[i]);
			*it = v[i];
		}
	}
	
	cout<<len<<endl;
	
	return 0;
}

