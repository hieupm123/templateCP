#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define f first
#define s second
#define ar array
#define pb push_back
typedef vector<vector<int>> vvi;
typedef vector<int> vi;  
typedef pair<int,int> pi;
typedef tuple<int,int,int> ti;
const int sz = 1e9 + 9;
struct Hash{
    string s;
    vector<ar<int, 2>> h, p;
    ar<int, 2> mod = {sz, 1000008041};
    ar<int, 2> pp = {311, 271};
    Hash(){
    }
    Hash(string _s){
        s = _s;
        h.resize(_s.size() + 5);
        p.resize(_s.size() + 5);
        p[0] = {1, 1};
        for(int i = 1; i <= s.size(); ++i){
            for(int j = 0; j < 2; ++j){
                p[i][j] = p[i - 1][j] * pp[j];
                p[i][j] %= mod[j];
            }
        }
    }
    void gen(){
        // cout<<s<<"\n";
        for(int i = 1; i <= s.size(); ++i){
            for(int j = 0; j < 2; ++j){
                h[i][j] = h[i - 1][j] + (s[i - 1] - '0') * p[i][j];
                h[i][j] %= mod[j];
            }
        }
    }
    ar<int, 2> get(int l, int r){
        ar<int, 2> ans;
        for(int i = 0; i < 2; ++i){
            ans[i] = (h[r][i] - h[l - 1][i] + mod[i]) % mod[i];
            ans[i] *= modPow(p[l][i], mod[i] - 2, mod[i]);
            ans[i] %= mod[i];
        }
        return ans;
    }
};