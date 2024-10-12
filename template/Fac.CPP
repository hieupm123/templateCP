const int sz = 2e6 + 6;
vi spf(sz);
unordered_set<int> fac[sz];
void seive(){
    spf[0] = 0; spf[1] = 1;
    for(int i = 2; i < sz; ++i){
        spf[i] = 1;
    }
    for(int i = 2; i < sz; ++i){
        if(spf[i] == 1){
            for(int j = i; j < sz; j += i){
                spf[j] = i;
            }
        }
    }
}
void get_fac(){
    for(int i = 1; i < sz; ++i){
        int x = i;
        while(x != 1){
            fac[i].insert(spf[x]);
            x /= spf[x];
        }
    }
}