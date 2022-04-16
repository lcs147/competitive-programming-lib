vector<int> vis(n);
auto dfs = [&](auto &dfs, int u) -> void {
    vis[u] = 1;
    for(auto v : adj[u]) {
        if(vis[v] == 0) dfs(dfs, v);
        else if(vis[v] == 1) {
            // cycle from v to u
        }
    }
    vis[u] = 2;
};
for(int i = 0; i < n; i++) {
    if(!vis[i]) {
        dfs(dfs, i);
    }
}