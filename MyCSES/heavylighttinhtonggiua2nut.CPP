// Bạn được cung cấp một cây có gốc bao gồm n nút. Các nút được đánh số 1,2,…,n và nút 1 là gốc. Mỗi nút có một giá trị.

// Nhiệm vụ của bạn là xử lý các loại truy vấn sau:
// thay đổi giá trị của nút s thành x
// tính tổng các giá trị trên đường dẫn từ gốc đến nút s

#include<bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
const int M = 2e5 + 100;
vector<int> A(M), adj[M], D(M), tree[M], sg[M], vis(M), table(M), tb2(M);
vector<pair<int,int>> adj1[M];
vector<int> de(M);
int cnt = 1,n,q;
void init(){
   for(int i = 1; i <= cnt - 1; ++i){
      sg[i].resize((int)tree[i].size() * 4);
   }
}
void dfs(int a){
   vis[a] = 1;
   for(int i = 0; i < (int)adj[a].size(); ++i){
      int b = adj[a][i];
      if(!vis[b]){
         dfs(b);
         de[a] += de[b];
         D[b] = a;
         adj1[a].push_back({de[b],b});
      }
   }
   sort(adj1[a].begin(),adj1[a].end());
   reverse(adj1[a].begin(),adj1[a].end());
   de[a]++;
 
}
void dfs1(int a){
   vis[a] = 1;
   int ok = 0;
   tree[cnt].push_back(a);
   table[a] = cnt;
   tb2[a] = tree[cnt].size() - 1;
   for(int i = 0; i < (int)adj1[a].size(); ++i){
      int b = adj1[a][i].second;
      if(!vis[b]){
         ok = 1;
         dfs1(b);
      }
   }
   if(!ok){
      ++cnt;
   }
}
void build(int a,int l, int r, int ct){
   if(l == r){
      sg[a][ct] = A[tree[a][l]];
   }else{
      int mid = (l + r) / 2;
      build(a,l,mid,2 * ct);
      build(a,mid + 1,r,2 * ct + 1);
      sg[a][ct] = sg[a][2 * ct] + sg[a][2 * ct + 1];
   }
}
void up(int pv, int l, int r, int ct, int a, int b){
   if(a > r || a < l){
      return;
   }
   if(l == r){
      sg[pv][ct] = b;
      return;
   }
   int mid = (l + r) / 2;
   up(pv,l,mid,2 * ct,a,b);
   up(pv,mid + 1,r,2 * ct + 1,a,b);
   sg[pv][ct] = sg[pv][2 * ct] + sg[pv][2 * ct + 1];
}
int query(int pv, int l, int r, int ct,int b){
   if(0 > r || b < l){
      return 0;
   }
   if(0 <= l && b >= r){
      return sg[pv][ct];
   }
   int mid = (l + r) / 2;
   return query(pv,l,mid,2 * ct,b) + query(pv,mid + 1,r,2 * ct + 1,b);
}
int query1(int b){
   int ans = 0;
   while(true){
      int pv = table[b];
      int a = tb2[b];
      if(tree[pv][0] == 1){
         ans += query(pv,0,(int)tree[pv].size() - 1,1,a);
         break;
      }else{
         ans += query(pv,0,(int)tree[pv].size() - 1,1,a);
         b = D[tree[pv][0]];
      }
   }
   return ans;
}
int32_t main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>q;
   for(int i = 1; i <= n; ++i){
      cin>>A[i];
   }
   for(int i = 0; i < n - 1; ++i){
      int a,b; cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
   }
   D[1] = 1;
   dfs(1);
   fill(vis.begin(),vis.end(),0);
   dfs1(1);
   init();
   de.clear();
   for(int i = 1; i <= cnt - 1; ++i){
      int a = (int)tree[i].size() - 1;
      build(i,0,a,1);
   }
   for(int i = 0; i < q; ++i){
      int a; cin>>a;
      if(a == 1){
         int b,c; cin>>b>>c;
         int pv = table[b];
         // cout<<pv<<" "<<tb2[b]<<"\n";
         up(pv,0,(int)tree[pv].size() - 1,1,tb2[b],c);
      }else{
         int b; cin>>b;
         cout<<query1(b)<<"\n";
      }
   }
   // for(int i = 1; i <= n; ++i){
   //    cout<<query1(i)<<" ";
   // }
}