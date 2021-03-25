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
	pair<int, int> A, B;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin>>grid[i][j];
			if(grid[i][j] == 'A') {
				A = {i, j};
			} 
			if(grid[i][j] == 'B') {
				B = {i, j};
			}
		}
	}
	
	queue<pair<int, int>> q;
	q.push(A);
	visited[A.F][A.S] = true;
	
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
			// exclude invalide indexes
//			cout<<nextNode.F<<" "<<nextNode.S<<" "<<(visited[nextNode.F][nextNode.S] || grid[nextNode.F][nextNode.S] == '#' || nextNode.F < 0 || nextNode.F >= n || nextNode.S < 0 || nextNode.S >= m)<<endl;
			if(
				visited[nextNode.F][nextNode.S] ||
				grid[nextNode.F][nextNode.S] == '#' ||
				nextNode.F < 0 || nextNode.F >= n || nextNode.S < 0 || nextNode.S >= m
			) continue;
			
			visited[nextNode.F][nextNode.S] = true;
			history[nextNode.F][nextNode.S] = i;
			q.push(nextNode);
		}

		
	}
	if(visited[B.F][B.S]) {
		cout<<"YES"<<endl;
		vector<int> steps;
		while(B != A) {
			// p = 0, 1, 2, 3
			int p = history[B.F][B.S];
			steps.PB(p);
			B = {B.F - dx[p], B.S - dy[p]};
		}
		cout<<steps.size()<<endl;
		for(int i = steps.size() - 1; i >= 0; i--) {
			cout<<directions[steps[i]];
		} 
		cout<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	
	return 0;
}

