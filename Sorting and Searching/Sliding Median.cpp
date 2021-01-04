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
	
	int n, k;
	cin>>n>>k;
	
	priority_queue<pair<int, int>> maxHeap; 
    	priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> minHeap;
    	
    	vector<int> a(n);
    	
    	int sizeOfMinHeap = 0;
    	int maxSizeOfMinHeap = k / 2;
    	for(int i = 0; i < n; i++) {
    		cin>>a[i];
		
		if(sizeOfMinHeap < maxSizeOfMinHeap) {
			maxHeap.push({a[i], i});
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			sizeOfMinHeap++;
		} else {
			minHeap.push({a[i], i});
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}

		if(i >= k-1) {
			// clean the heaps
			while(!minHeap.empty() && minHeap.top().S <= i - k) minHeap.pop();
			while(!maxHeap.empty() && maxHeap.top().S <= i - k) maxHeap.pop();
			
			cout<<maxHeap.top().F<<" ";
			
			if(a[i-k+1] > maxHeap.top().F) sizeOfMinHeap--;
		}
	} 
    	
	return 0;
}
