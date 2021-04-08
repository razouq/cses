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
	
	int n, m;
	cin>>n>>m;
	
	char grid[n][m];
	pair<int, int> start;
	vector<pair<int, int>> end;
	
	// read the grid and find the start
	queue<pair<int, int>> q;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin>>grid[i][j];
			// add monsters first
			if(grid[i][j] == 'M') {
				q.push({i, j});
			}
			if(grid[i][j] == 'A') {
				start = {i, j};
			}
			if((i == 0 || i == n-1 || j == 0 || j == m-1) && grid[i][j] == '.') {
				end.PB({i, j});
			}
		}
	}
	
	q.push(start);
	
	// up, right, down, left
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	string directions = "URDL";	
	int history[n][m];
	
	while(!q.empty()) {
		pair<int, int> node = q.front();
		q.pop();
		
		if(grid[node.F][node.S] == 'A' && 
			(node.F == 0 || node.F == n-1 || node.S == 0 || node.S == m-1)) {
			
			cout<<"YES"<<endl;
			vector<int> steps;
			
			pair<int, int> e = node;
			while(e != start) {
				int p = history[e.F][e.S];
				steps.PB(p);
				e = {e.F - dx[p], e.S - dy[p]};
			} 
			reverse(steps.begin(), steps.end());
			cout<<steps.size()<<endl;
			for(int step : steps) {
				cout<<directions[step];
			}
			cout<<endl;
			return 0;
		}
		
		for(int i = 0; i < 4; i++) {
			pair<int, int> nextNode = {node.F + dx[i], node.S + dy[i]};
			if(
				grid[nextNode.F][nextNode.S] == '#' ||
				grid[nextNode.F][nextNode.S] == 'M' ||
				grid[nextNode.F][nextNode.S] == 'A' ||
				nextNode.F < 0 || nextNode.F >= n ||
				nextNode.S < 0 ||nextNode.S >= m
			) continue;
			
			grid[nextNode.F][nextNode.S] = grid[node.F][node.S];
			history[nextNode.F][nextNode.S] = i;
			q.push(nextNode);
		}
	}
	
	
	cout<<"NO"<<endl;
	return 0;
}

