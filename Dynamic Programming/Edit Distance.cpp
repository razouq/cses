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
	
	string a, b;
	cin>>a>>b;
	
	if(a.size() < b.size()) swap(a, b);
	
	int n = a.size();
	int m = b.size();
		
	vector<vector<int>> mat(n+1, vector<int> (m+1, 0));
	for(int i = 0; i <= n; i++) mat[i][0] = i;
	for(int i = 0; i <= m; i++) mat[0][i] = i;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int diff = (a[i-1] != b[j-1]);
			mat[i][j] = min(mat[i-1][j] + 1, mat[i][j-1] + 1);
			mat[i][j] = min(mat[i][j], mat[i-1][j-1] + diff);
		}
	}
	
	cout<<mat[n][m]<<endl;
	return 0;
}

