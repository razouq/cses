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

string grid[8];
int sol = 0;

void solve(int x, map<int, bool> a, map<int, bool> b, map<int, bool> e, map<int, bool> f) {
	for(int y = 0; y < 8; y++) {
		if(grid[x][y] == '.' && !a[x] && !b[y] && !e[y-x] && !f[y+x]) {
			
			if(x == 7) {
				sol++;
			}
			if(x < 7) {
				map<int, bool> a1(a);
				map<int, bool> b1(b);
				map<int, bool> e1(e);
				map<int, bool> f1(f);
				a1[x] = true;
				b1[y] = true;
				e1[y-x] = true;
				f1[y+x] = true;
				solve(x+1, a1, b1, e1, f1);
			}
		}
	}
}

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	for(int i = 0 ; i < 8; i++) {
		cin>>grid[i];
	}
	map<int, bool> a;
	map<int, bool> b;
	map<int, bool> e;
	map<int, bool> f;
	solve(0, a, b, e, f);
	cout<<sol<<endl;
	return 0;
}

