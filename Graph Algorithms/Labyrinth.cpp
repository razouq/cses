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
string grid[1001];
int xa, xb, ya, yb;
string shortestPath = "";
ll shortestPathSize = LLONG_MAX;
ll steps[1001][1001];

void dfs(int x, int y, string path, int stp) {
	
	if(shortestPathSize == abs(xa-xb) + abs(ya-yb)) return;
	
	steps[x][y] = stp;
	if(x == xb && y == yb && shortestPathSize > path.size()) {
		shortestPathSize = path.size();
		shortestPath = path;
		return;
	}
	
	// right
	if(y+1 < m && (grid[x][y+1] == '.' || grid[x][y+1] == 'B') && steps[x][y+1] > stp+1) {
		dfs(x, y+1, path+"R", stp+1);
	}
	// left
	if(y-1 >= 0 && (grid[x][y-1] == '.' || grid[x][y-1] == 'B') && steps[x][y-1] > stp+1) {
		dfs(x, y-1, path+"L", stp+1);
	}
	// up
	if(x-1 >= 0 && (grid[x-1][y] == '.' || grid[x-1][y] == 'B') && steps[x-1][y] > stp+1) {
		dfs(x-1, y, path+"U", stp+1);
	}
	// down
	if(x+1 < n && (grid[x+1][y] == '.' || grid[x+1][y] == 'B') && steps[x+1][y] > stp+1) {
		dfs(x+1, y, path+"D", stp+1);
	}
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
			if(grid[i][j] == 'A') {
				xa = i;
				ya = j;
				steps[i][j] = 0;
			}
			if(grid[i][j] == 'B') {
				xb = i;
				yb = j;
				steps[i][j] = LLONG_MAX;
			} else {
				steps[i][j] = LLONG_MAX;
			}
		}
	}
	
	dfs(xa, ya, "", 0);
	
	if(shortestPath.size() != 0) {
		cout<<"YES"<<endl;
		cout<<shortestPath.size()<<endl;
		cout<<shortestPath<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	
	return 0;
}

