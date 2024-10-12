#include<bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
int adj[501][501], n, m, path[501], ans = 0;
vector<int> vis(501);
bool bfs(){
   queue<int> Q; Q.push(1);
   vis[1] = 1; int ok = 0;
   while(!Q.empty()){
      int a = Q.front(); Q.pop();
      if(a == n){
         ok = 1;
         break;
      }
      for(int i = 1; i <= n; ++i){
         if(!vis[i] && adj[a][i] > 0){
            path[i] = a;
            Q.push(i);
            vis[i] = 1;
         }
      }
   }
   return ok;
}
int32_t main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m;
   for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= n; ++j){
         adj[i][j] = 0;
      }
   }
   for(int i = 0; i < m; ++i){
      int a,b,c; cin>>a>>b>>c;
      adj[a][b] += c;
   }
   while(bfs()){
      fill(vis.begin(),vis.end(), 0);
      int k = n, cnt = 1e18;
      for(int i = path[k]; i != 1; i = path[i]){
         cnt = min(adj[i][k], cnt);
         k = i;
      }
      cnt = min(cnt,adj[1][k]);
      ans += cnt;
      k = n;
      for(int i = path[k]; i != 1; i = path[i]){
         adj[i][k] -= cnt;
         adj[k][i] += cnt;
         k = i;
      }
      adj[1][k] -= cnt;
      adj[k][1] += cnt;
   }
   cout<<ans<<"\n";
}