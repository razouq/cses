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
	bool visited[n][m];
	memset(visited, false, sizeof visited);
	pair<int, int> start;
	vector<pair<int, int>> end;
	
	// read the grid and find the start
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin>>grid[i][j];
			if(grid[i][j] == 'A') {
				start = {i, j};
			}
			if((i == 0 || i == n-1 || j == 0 || j == m-1) && grid[i][j] == '.') {
				end.PB({i, j});
			}
		}
	}
	
	queue<pair<int, int>> q;
	q.push(start);
	visited[start.F][start.S] = true;
	
	// up, right, down, left
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	string directions = "URDL";	
	int history[n][m];
	
	while(!q.empty()) {
		pair<int, int> node = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++) {
			pair<int, int> nextNode = {node.F + dx[i], node.S + dy[i]};
			if(
				visited[nextNode.F][nextNode.S] ||
				grid[nextNode.F][nextNode.S] == '#' ||
				grid[nextNode.F][nextNode.S] == 'M' ||
				nextNode.F < 0 || nextNode.F >= n ||
				nextNode.S < 0 ||nextNode.S >= m
			) continue;
			
			visited[nextNode.F][nextNode.S] = true;
			history[nextNode.F][nextNode.S] = i;
			q.push(nextNode);
		}
	}
	
	bool solved = false;
	for(pair<int, int> e : end) {
		if(visited[e.F][e.S]) {
			solved = true;
			cout<<"YES"<<endl;
			vector<int> steps;
			
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
			break;
		}
	}
	
	if(!solved) cout<<"NO"<<endl;
	return 0;
}

