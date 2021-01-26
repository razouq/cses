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

ll MOD = 1e9+7;

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	int n;
	cin>>n;
	
	vector<vector<ll>> mat(n+1, vector<ll>(n+1, 0));
	
	mat[1][1] = 1;
	
	for(int i = 0; i < n; i++) {
		string s;
		cin>>s;
		for(int j = 0; j < n; j++) {
			if(s[j] == '*') {
				mat[i+1][j+1] = -1;		
			}
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(mat[i][j] == -1) continue;
			if(mat[i-1][j] != -1) {
				mat[i][j] += mat[i-1][j];
				mat[i][j] %= MOD;
			}
			
			if(mat[i][j-1] != -1) {
				mat[i][j] += mat[i][j-1];
				mat[i][j] %= MOD;
			}
		}
	}
	
	cout<<max(mat[n][n], 0LL)<<endl;
	
	return 0;
}

