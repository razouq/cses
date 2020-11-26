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
int n, m;
pair<int, int> steps[100001];

// {comming_from, steps}
vector<int> graph[max_size];

int tmp_sol = INT_MAX;

void dfs(int x, int stp, int comming_from) {
//	cout<<x<<endl;
	if(x == n) {
		tmp_sol = stp;
	}
	steps[x] = {stp, comming_from};
	for(int i = 0; i < graph[x].size(); i++) {
		if(steps[graph[x][i]].F > stp + 1 && stp + 1 < tmp_sol) {
			dfs(graph[x][i], stp + 1, x);
		}
	}
}

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	
	for(int i = 0; i < max_size; i++) {
		steps[i].F = INT_MAX;
		steps[i].S = INT_MAX;
//		cout<<steps[i]<<endl;
	}
	

	cin>>n>>m;
	
	for(int i = 0; i < m; i++) {
		int a, b;
		cin>>a>>b;
		graph[a].PB(b);
		graph[b].PB(a);
	}
	
	dfs(1, 0, 0);
	
	if(steps[n].F == INT_MAX) cout<<"IMPOSSIBLE"<<endl;
//	if(false) cout<<"IMPOSSIBLE"<<endl;
	else {	
//		cout<<"----------------------------"<<endl;
//		for(int i = 1; i <= n; i++) cout<<steps[i].F<<" "<<steps[i].S<<endl;
//		cout<<"----------------------------"<<endl;
//		cout<<n<<endl;
//		cout<<steps[n].S<<endl;
//		cout<<steps[steps[n].F].S<<endl;
		
		int r = n;
		vector<int> v;
		while(true) {
//			cout<<r<<endl;
			v.PB(r);
			r = steps[r].S;
			if(r == 0) break;
		}
		cout<<v.size()<<endl;
		for(int i = v.size()-1; i >= 0; i--) cout<<v[i]<<" ";
				
//		int k = 0;
//		while(true) {
//			cout<<r.F<<endl;
//			r = steps[r.F];
//			if(r.F == 0) break;
//			
//			k++;
//			if(k == 6) break;
//		}
	}
	
	return 0;
}

