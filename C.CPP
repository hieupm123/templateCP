#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define f first
#define s second
#define ar array
typedef vector<vector<int>> vvi;
typedef vector<int> vi;  
typedef pair<int,int> pi;
typedef tuple<int,int,int> ti;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	vi adj = {1, 2, 3, 4};
	cout<<lower_bound(adj.begin(), adj.end(), 5) - adj.begin()<<"\n";


}