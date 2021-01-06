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
	
	int n;
	cin>>n;
	n--;
	vector<string> v;
	vector<string> u;
	v.PB("0");
	u.PB("1");
	
	while(n--) {
		for(int i = u.size()-1; i >= 0; i--) {
			v.PB(u[i]);
		}
		u = v;
		
		for(string &item : v) item = "0" + item;
		for(string &item : u) item = "1" + item;
	}
	
	for(string item : v) cout<<item<<endl;
	for(int i = u.size()-1; i >= 0; i--) cout<<u[i]<<endl;
	cout<<endl;
	
	return 0;
}

