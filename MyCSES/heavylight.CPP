// Bạn được cung cấp một cây bao gồm n nút. Các nút được đánh số 1,2,…,n. Mỗi nút có một giá trị.

// Nhiệm vụ của bạn là xử lý các loại truy vấn sau:
// thay đổi giá trị của nút s thành x
// tìm giá trị lớn nhất trên đường đi giữa các nút a và b.

#include<bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
const int M = 2e5 + 100;
const int inf = 1e18;
vector<int> adj[M],A(M), tree[M],C(M),vis(M),sg[M],tb(M),tb1(M),def(M);
int dp[M][25], ct = 1;
vector<pair<int,int>> adj1[M];
void init(){
   for(int i = 1; i < ct; ++i){
      sg[i].resize((int)tree[i].size() * 4);
   }
}
void dfs(int a){
   vis[a] = 1;
   for(int i = 1; i <= 20; ++i){
      dp[a][i] = dp[dp[a][i - 1]][i - 1];
   }
   for(int i = 0; i < (int)adj[a].size(); ++i){
      int b = adj[a][i];
      if(dp[a][0] != b){
         dp[b][0] = a;
         def[b] = def[a] + 1;
         dfs(b);
         C[a] += C[b];
         adj1[a].push_back({C[b],b});
      }
   }
   C[a]++;
   sort(adj1[a].begin(),adj1[a].end());
   reverse(adj1[a].begin(),adj1[a].end());
}
void dfs1(int a){
   vis[a] = 1;
   tree[ct].push_back(a);
   tb[a] = ct;
   tb1[a] = (int)tree[ct].size() - 1;
   int ok = 0;
   for(int i = 0; i < (int)adj1[a].size(); ++i){
      int b = adj1[a][i].second;
      if(!vis[b]){
         ok = 1;
         dfs1(b);
      }
   }  
   if(!ok) ++ct;
}
int lca(int a, int b){
   if(def[a] > def[b]){
      swap(a,b);
   }
   int k = def[b] - def[a];
   for(int i = 0; i <= 20; ++i){
      if(k & (1 << i)){
         b = dp[b][i];
      }
   }
   if(a == b){
      return a;
   }
   for(int i = 20; i >= 0; --i){
      if(dp[a][i] != dp[b][i]){
         a = dp[a][i];
         b = dp[b][i];
      }
   }
   return dp[a][0];
}
void build(int l, int r, int cnt, int pv){
   if(l == r){
      sg[pv][cnt] = A[tree[pv][l]];
   }else{
      int mid = (l + r) / 2;
      build(l,mid,2 * cnt,pv);
      build(mid + 1,r,2 * cnt + 1,pv);
      sg[pv][cnt] = max(sg[pv][2 * cnt],sg[pv][2 * cnt + 1]);
   }
}
void up(int l, int r, int cnt, int pv, int a, int b){
   if(a < l || a > r){
      return;
   }
   if(l == r){
      sg[pv][cnt] = b;
      return;
   }
   int mid = (l + r) / 2;
   up(l,mid,2 * cnt,pv,a,b);
   up(mid + 1,r,2 * cnt + 1,pv,a,b);
   sg[pv][cnt] = max(sg[pv][2 * cnt],sg[pv][2 * cnt + 1]);
}
int query(int l, int r, int cnt, int pv, int a, int b){
   if(b < l || a > r){
      return -inf;
   }
   if(a <= l && b >= r){
      return sg[pv][cnt];
   }
   int mid = (l + r) / 2;
   return max(query(l,mid,2 * cnt,pv,a,b),query(mid + 1,r,2 * cnt + 1,pv,a,b));
}
int query2(int a, int b){
   int ans = -inf;
   while(true){
      int pv = (int)tree[tb[b]].size() - 1;
      if(tb[a] == tb[b]){
         return max(ans,query(0,pv,1,tb[a],tb1[a],tb1[b]));
      }else{
         ans = max(ans,query(0,pv,1,tb[b],0,tb1[b]));
         b = dp[tree[tb[b]][0]][0];
      }
   }
}
int query1(int a, int b){
   int c = lca(a,b);
   return max(query2(c,a),query2(c,b));
}
int32_t main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int n,q; cin>>n>>q; 
   for(int i = 1; i <= n; ++i){
      cin>>A[i];
   }
   for(int i = 0; i < n - 1; ++i){
      int a,b; cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
   }
   dp[1][0] = 1; def[1] = 1;
   dfs(1);
   fill(vis.begin(),vis.end(),0);
   dfs1(1);
   init();
   for(int i = 1; i < ct; ++i){
      build(0,(int)tree[i].size() - 1,1,i);
   }
   for(int i = 0; i < q; ++i){
      int a,b,c; cin>>a>>b>>c;
      if(a == 1){
         int pv = tb[b];
         up(0,(int)tree[pv].size() - 1,1,pv,tb1[b],c);
      }else{
         cout<<query1(b,c)<<" ";
      }
   }
 
}