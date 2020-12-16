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
	
	for(int &item : v) cin>>item;
	sort(v.begin(), v.end());
	
	int res = 1;
	for(int i = 1; i < n; i++) {
		if(v[i] != v[i-1]) res++;
	}
	cout<<res<<endl;
	
	return 0;
}

