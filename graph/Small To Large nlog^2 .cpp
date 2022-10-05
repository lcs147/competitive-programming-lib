 
struct small_to_large {
    vector<vector<int>> adj;
    vector<int> c;
    int n;
 
    small_to_large(int n) : n(n) {
        adj.resize(n);
        c.resize(n);
        f.resize(n);
        q.resize(n);
    }
    
    void add(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<map<int, int>> f;
    vector<vector<pair<int, int>>> q;
    void merge(int a, int b) {
        if(f[a].size() < f[b].size()) {
            swap(f[a], f[b]);
        }
        for(auto [x, freq] : f[b]) {   
            f[a][x] += freq;
        }
    }
 
    void dfs(int u, int p) {
        f[u][c[u]] = 1;
        
        for(int v : adj[u]) {
            if(v == p) continue;
            dfs(v, u);
            merge(u, v);
        }
 
        for(auto [x, id] : q[u]) {
            if(f[u].count(x)) {
                res[id] = f[u][x] - 1;
            }
        }
    }
    void dfs_all() {
        for(int i = 0; i < n; i++) if(f[i].size() == 0) dfs(i, i);
    }
};