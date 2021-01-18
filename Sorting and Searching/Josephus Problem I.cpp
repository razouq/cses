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
	
	multiset<int> ms;
	
	for(int i = 1; i <= n; i++) {
		ms.insert(i);
	}
	
	bool skip = true;
	while(true) {
		if(ms.empty()) break;
		if(ms.size() == 1) {
			auto it = ms.begin();
			cout<<*it<<endl;
			break;
		}
		auto it = ms.begin();
		if(skip) it++;
		int c = (ms.size() + !skip) / 2;
		while(c) {
			cout<<*it<<" ";
			auto ot = it;
			it++;
			it++;
			c--;
			auto end = ms.end();
			end--;
			if(c == 0 && ot == end) skip = true;
			else skip = false;
			ms.erase(ot);
		}
	}
	
	
	
	
	
	return 0;
}

