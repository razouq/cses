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

int n, m;
int res = 0;
string grid[1000];

void dfs(int x, int y) {
	grid[x][y] = '#';
	// right
	if(y+1 < m && grid[x][y+1] == '.') dfs(x, y+1);
	// left
	if(y-1 >= 0 && grid[x][y-1] == '.') dfs(x, y-1);
	// up
	if(x-1 >= 0 && grid[x-1][y] == '.') dfs(x-1, y);
	// down
	if(x+1 < n && grid[x+1][y] == '.') dfs(x+1, y);
	return;  
}

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	cin>>n>>m;
	
	for(int i = 0; i < n; i++) cin>>grid[i];
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(grid[i][j] == '.') {
				res++;
				dfs(i, j);
			}
			
		}
	}
	
	cout<<res<<endl;
	return 0;
}

