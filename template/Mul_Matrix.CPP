vector<vi> mul(vector<vi> a, vector<vi> b){
    vector<vi> ans(a.size(), vi(b[0].size()));
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < b[0].size(); ++j){
            for(int k = 0; k < a[0].size(); ++k){
                ans[i][j] += (a[i][k] * b[k][j]);
                ans[i][j] %= mod;
            }
        }
    }
    return ans;
}
vector<vi> modP(vector<vi> a, int b){
    vector<vi> ans(a.size(), vi(a.size()));
    for(int i = 0; i < a.size(); ++i){
        ans[i][i] = 1;
    }
    while(b){
        if(b & 1){
            ans = mul(ans, a);
        }
        a = mul(a, a);
        b /= 2;
    }
    return ans;
}