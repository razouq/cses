/*
 Author: Hamza Hasbi
 @Copyrights: __Morty
*/
#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
 #pragma GCC optimize("O3")
#endif
#define ll long long
#define ld long double
#define ull unsigned long long
#define uld unsigned long double
#define ud unsigned double
#define uf unsigned float
#define pi 2 * acos(0.0)
#define module cin.ignore()
//inline long long lcm(ll a,ll b) {return a * b / __gcd(a,b);}
//inline long long gcd(ll a,ll b) {return 1LL * b == 0 ? a : gcd(1LL*b, a * 1LL % b * 1LL);}
inline bool IsPowerOfTwo (ull x){ return (x != 0) && ((x & (x - 1)) == 0);}
using namespace std;
void READ() {
 #ifndef ONLINE_JUDGE
   freopen("IO/Input.in", "r", stdin);
  #endif
}
int n, m;
char grid[1000][1000];
pair<int, char> vis[1000][1000];
pair<int, int>b, e;
 
void dfs(int px, int py, int steps) {

  if (px + 1 < n && grid[px + 1][py] != '#') {
    if (vis[px + 1][py].first > steps + 1) {
      vis[px + 1][py] = {steps + 1, 'D'};
      dfs(px + 1, py, steps + 1);
    }
 
  }
  if (px - 1 >= 0 && grid[px - 1][py] != '#') {
    if (vis[px - 1][py].first > steps + 1) {
      vis[px - 1][py] = {steps + 1, 'U'};
      dfs(px - 1, py, steps + 1);
    }
  }
  if (py + 1 < m && grid[px][py + 1] != '#') {
    if (vis[px][py + 1].first > steps + 1) {
      vis[px][py + 1] = {steps + 1, 'R'};
      dfs(px, py + 1, steps + 1);
 
    }
  }
  if (py - 1 >= 0 && grid[p.first][py - 1] != '#') {
    if (vis[px][py - 1].first > steps + 1)  {
      vis[px][py - 1] = {steps + 1, 'L'};
      dfs({px, py - 1}, steps + 1);
 
    }
  }
 
}
int main() {
    // auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
      scanf("%s", grid[i]);
      for(int j = 0; j < m; ++j) {
        if (grid[i][j] == 'A') b = {i, j};
        if (grid[i][j] == 'B') e = {i, j};
      }
    }
 
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; ++j) {
        vis[i][j] = {INT_MAX, '*'};
      }
    }
 
    vis[b.first][b.second] = {INT_MAX, '*'};
    dfs(b.F, b.S, 0);
 
 
    if (vis[e.first][e.second].first == INT_MAX) printf("NO\n");
    else {
      printf("YES\n");
      printf("%d\n", vis[e.first][e.second].first);
      auto res = vis[e.first][e.second];
      auto fin = e;
      string path = "";
      while(true) {
        if (fin == b || fin.first < 0 || fin.second < 0 || fin.first > n || fin.second > m) break;
        path += res.second;
        if (res.second == 'U') {
          fin.first += 1;
        } else if (res.second == 'D') {
          fin.first -= 1;
        } else if (res.second == 'L') {
          fin.second += 1;
        } else {
          fin.second -= 1;
        }
        res = vis[fin.first][fin.second];
      }
      reverse(path.begin(), path.end());
      printf("%s", path.c_str());
    }

    return 0;
}
