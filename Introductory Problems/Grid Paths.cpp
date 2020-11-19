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
 
string s;
bool visited[9][9];
int sol = 0;
 
 
void solve(int x, int y, int step) {
	if(x == 7 && y == 1) {
		if(step == 48) sol++;
		return;
	}

	if((visited[x-1][y] && visited[x+1][y] && !visited[x][y-1] && !visited[x][y+1])
	 || (!visited[x-1][y] && !visited[x+1][y] && visited[x][y-1] && visited[x][y+1])) {
		return;
	}
	
	visited[x][y] = true;
	
	// right
	if(y+1 < 8 && !visited[x][y+1] && (s[step] == '?' || s[step] == 'R')) {
		solve(x, y+1, step+1);
	}
	
	// left
	if(y-1 > 0 && !visited[x][y-1] && (s[step] == '?' || s[step] == 'L')) {
		solve(x, y-1, step+1);
	}
	
	// up
	if(x-1 > 0 && !visited[x-1][y] && (s[step] == '?' || s[step] == 'U')) {
		solve(x-1, y, step+1);
	}
	
	// down
	if(x+1 < 8 && !visited[x+1][y] && (s[step] == '?' || s[step] == 'D')) {
		solve(x+1, y, step+1);
	}
	
	visited[x][y] = false;
	
}
 
int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>s;
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			if(i == 0 || j == 0 || i == 8 || j == 8) {
				visited[i][j] = true;
			}
		}
	}
	solve(1, 1, 0);
	cout<<sol<<endl;
	return 0;
}
