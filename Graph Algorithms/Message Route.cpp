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

const int max_size = 1e5+1;
vector<int> graph[max_size];
bool visited[max_size];
int previousNode[max_size];

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	int n, m;
	cin>>n>>m;
	
	memset(visited, false, sizeof visited);
	memset(previousNode, 0, sizeof previousNode);
	
	for(int i = 0; i < m; i++) {
		int a, b;
		cin>>a>>b;
		graph[a].PB(b);
		graph[b].PB(a);
	}
	
	int start = 1;
	int end = n;
	
	visited[1] = true;
	queue<int> q;
	q.push(1);
	previousNode[1] = 0;
	
	while(!q.empty()) {
		int nbr = q.front();
		q.pop();
		
		for(int i = 0; i < graph[nbr].size(); i++) {
			if(!visited[graph[nbr][i]]) {
				visited[graph[nbr][i]] = true;
				q.push(graph[nbr][i]);
				previousNode[graph[nbr][i]] = nbr;
			}
		}
	}
	
	if(visited[n]) {
		vector<int> v;
		while(end != start) {
			v.PB(end);
			end = previousNode[end];
		}
		v.PB(start);
		cout<<v.size()<<endl;
		reverse(v.begin(), v.end());
		for(int i = 0; i < v.size(); i++) cout<<v[i]<<" ";
		cout<<endl;
	} else cout<<"IMPOSSIBLE"<<endl;
	
	return 0;
}

