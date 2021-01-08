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
	
	int ans = max(pow(2, n) - 1, 1.0);
	cout<<ans<<endl;
	
	stack<int> s;
	stack<int> a;
	stack<int> d;
	
	for(int i = n; i > 0; i--) s.push(i+1);
	
	for(int i = 1; i <= ans; i++) {
		// S & D
		if((i % 3 == 1 && n % 2 == 1) || (i % 3 == 2 && n % 2 == 0)) {
			if(s.empty()) {
				int k = d.top();
				d.pop();
				s.push(k);
				cout<<"3 1"<<endl;
			} else if(d.empty()) {
				int k = s.top();
				s.pop();
				d.push(k);
				cout<<"1 3"<<endl;
			} else {
				if(d.top() < s.top()) {
					int k = d.top();
					d.pop();
					s.push(k);
					cout<<"3 1"<<endl;
				} else {
					int k = s.top();
					s.pop();
					d.push(k);
					cout<<"1 3"<<endl;
				}
			}
		}
		// S & A
		else if((i % 3 == 2 && n % 2 == 1) || (i % 3 == 1 && n % 2 == 0)) {
			
			if(s.empty()) {
				int k = a.top();
				a.pop();
				s.push(k);
				cout<<"2 1"<<endl;
			} else if(a.empty()) {
				int k = s.top();
				s.pop();
				a.push(k);
				cout<<"1 2"<<endl;
			} else {
				if(a.top() < s.top()) {
					int k = a.top();
					a.pop();
					s.push(k);
					cout<<"2 1"<<endl;
				} else {
					int k = s.top();
					s.pop();
					a.push(k);
					cout<<"1 2"<<endl;
				}
			}
		}
		// A & D
		else {
			if(a.empty()) {
				int k = d.top();
				d.pop();
				a.push(k);
				cout<<"3 2"<<endl;
			} else if(d.empty()) {
				int k = a.top();
				a.pop();
				d.push(k);
				cout<<"2 3"<<endl;
			} else {
				if(d.top() < a.top()) {
					int k = d.top();
					d.pop();
					a.push(k);
					cout<<"3 2"<<endl;
				} else {
					int k = a.top();
					a.pop();
					d.push(k);
					cout<<"2 3"<<endl;
				}
			}
		}
	}
	return 0;
}

