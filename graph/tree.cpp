struct tree {
    vector<vector<int>> adj, up;
    vector<int> lvl, dad, sz;
    int n, logn;
 
    tree(int n) : n(n) {
        lvl.resize(n);
        dad.resize(n);
        sz.resize(n);
        adj.resize(n);
 
        logn = log2(n) + 1;
    }
    
    void add(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    void dfs(int u, int p) {
        sz[u] = 1;
        dad[u] = p;
        for(int v : adj[u]) {
            if(v == p) continue;
            lvl[v] = lvl[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
 
    void dfs_all() {
        for(int i = 0; i < n; i++) {
            if(sz[i] == 0) {
                dfs(i, i);
            }
        }
    }
 
    void build_lca() {
        logn = log2(n) + 1;
        up.resize(n, vector<int>(logn));
        for(int i = 0; i < n; i++) {
            up[i][0] = dad[i];
        }
        for(int j = 1; j < logn; j++) {
            for(int i = 0; i < n; i++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    };
    
    int lca(int a, int b) {
        if(lvl[a] < lvl[b]) swap(a, b);
 
        int dif = lvl[a] - lvl[b];
        for(int i = logn - 1; i >= 0; i--) {
            if((1 << i) <= dif) {
                a = up[a][i];
                dif -= (1 << i);
            }
        }
        if(a == b) return a;
        for(int i = logn - 1; i >= 0; i--) {
            if(up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }
        return up[a][0];
    };
    
    int dist(int a, int b) {
        return lvl[a] + lvl[b] - 2 * lvl[lca(a, b)];
    };
 
    int kth_ancestor(int u, int k) {
        for(int i = 0; i < logn; i++) {
            if(k & (1 << i)) {
                u = up[u][i];
            }
        }
        return u;
    };
};