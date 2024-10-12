#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long
#define maxx(a,b,c) max(max(a,b),c)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
using ull = unsigned long long;
const int sz = 1e6 + 5;
int adj[sz];
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 1; i <= 10000; ++i){
        if(i * i >= 2000 * 100){
            cout<<i<<"\n";
            break;
        }
    }
}