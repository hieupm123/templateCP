void euler(int a){
    vis[a] = 1;
    ans.push_back(a);
    for(auto i : adj[a]){
        if(vis[i]) continue;
        euler(i);
        ans.push_back(a);
    }
}