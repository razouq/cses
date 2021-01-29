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
	
	int n, x;
	cin>>n>>x;
	
	vector<pair<int, int>> v(n);
	// price
	for(int i = 0; i < n; i++) cin>>v[i].F;
	// pages
	for(int i = 0; i < n; i++) cin>>v[i].S;
	
	sort(v.begin(), v.end());
	
	int mat[n][x+1];
	
	for(int j = 0; j <= x; j++) {
		if(j < v[0].F) {
			mat[0][j] = 0;
		} else {
			mat[0][j] = v[0].S;
		}
	}
	
	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= x; j++) {
			if(j < v[i].F) mat[i][j] = mat[i-1][j];
			else {
				mat[i][j] = max(mat[i-1][j], v[i].S + mat[i-1][j-v[i].F]);
			}
		}
	}
	
	cout<<mat[n-1][x]<<endl;
	return 0;
}

