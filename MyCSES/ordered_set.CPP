#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define double long double
#define int long long
template<class T> using Tree = tree <T,null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
int32_t main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int n,q; cin>>n>>q;
   vector<int> A(n);
   Tree<pair<int,int>> B;
   for(int i = 0; i < n; ++i){
   	cin>>A[i];
   	B.insert({A[i],i + 1});
   }
   for(int i = 0; i < q; ++i){
   	char a; cin>>a;
   	int b,c; cin>>b>>c;
   	if(a == '!'){
   		B.erase({A[b - 1],b});
   		A[b - 1] = c;
   		B.insert({c,b});
   	}else{
   		int e = (int)B.order_of_key({c,INT_MAX});
   		int d = (int)B.order_of_key({b - 1,INT_MAX});
   		cout<<e - d<<"\n";
   	}
   }
}