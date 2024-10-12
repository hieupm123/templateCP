struct DSU {
	vector<int> dsu, len;
	DSU(int N) {
        dsu = vector<int>(N + 5);
        len = vector<int>(N + 5, 1);
        for(int i = 0; i <= N; ++i){
            dsu[i] = i;
        }
    }
    int find(int a){
        while(a != dsu[a]){
            a = dsu[a];
        }
        return a;
    }
    void join(int a, int b){
        a = find(a); b = find(b);
        if(a == b) return;
        if(len[a] > len[b]) swap(a,b);
        dsu[a] = b;
        len[b] += len[a];
    }
};