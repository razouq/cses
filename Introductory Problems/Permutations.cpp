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
	if(n == 2 || n == 3) cout<<"NO SOLUTION"<<endl;
	else if(n == 4) cout<<"3 1 4 2"<<endl;
	else {
		for(int i = 1; i <= n; i+=2) {
			cout<<i<<" ";
		}
		for(int i = 2; i <= n; i+=2) {
			cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}

