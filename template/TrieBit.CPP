struct node{
    int to[2];
    int cnt;
    node(){
        to[0] = to[1] = -1;
        cnt = 0;
    }
};
vector<node> adj;
void add(int a){
    int v = 0;
    for(int i = 30; i >= 0; --i){
        int b = (a >> i) & 1;
        if(adj[v].to[b] == -1){
            adj[v].to[b] = adj.size();
            adj.push_back(node());
        }
        ++adj[v].cnt;
        v = adj[v].to[b];
    }
    ++adj[v].cnt;
}
int modPow(int a, int b, int mod){
	int ans = 1;
	while(b){
		if(b & 1){
			ans = ans * a;
			ans %= mod;
		}
		a = a * a;
		a %= mod;
		b /= 2;
	}
	return ans;
}
int res = 0;
void dfs(int a, int k){
    int tmp = k + 1;
    if(adj[a].to[1] != -1 && adj[a].to[0] != -1){
        res = res + adj[adj[a].to[1]].cnt * adj[adj[a].to[0]].cnt * (tmp + 1 - (tmp % 2 == 1));
        res %= mod;
        res = res + adj[adj[a].to[1]].cnt * adj[adj[a].to[0]].cnt * (tmp + (tmp % 2 == 1));
        res %= mod;
    }
    if(adj[a].to[0] == -1 && adj[a].to[1] == -1){
        res = res + adj[a].cnt * adj[a].cnt * tmp;
        res %= mod;
    }   
    if(adj[a].to[0] != -1){
        dfs(adj[a].to[0], k);
    }
    if(adj[a].to[1] != -1){
        dfs(adj[a].to[1], k + 1);
    }
}