#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
// const int inf = 1e18, sz = 1e3;
string s1, s2;
int dp[5001][5001];
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>s1>>s2;
    for(int i = 1; i <= (int)s1.size(); ++i){
    	for(int j = 1; j <= (int)s2.size(); ++j){
    		if(s1[i - 1] == s2[j - 1]){
    			dp[i][j] = dp[i - 1][j - 1] + 1;
    		}else{
    			dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
    		}
    	}
    }
    cout<<dp[(int)s1.size()][(int)s2.size()];
}
