struct tree {
    vector<vector<int>> adj, up;
    vector<int> lvl, dad, sz;
    int logn;
 
    tree(int n) {
        lvl.resize(n);
        dad.resize(n);
        sz.resize(n);
        adj.resize(n);
 
        logn = log2(n) + 1;
        up.assign(n, vector<int>(logn));
    }
    
    void add(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    void build_lca(int u, int p) {
        sz[u] = 1;
        dad[u] = p;
        up[u][0] = p;
        for(int j = 1; j < logn; j++) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }
 
        for(int v : adj[u]) {
            if(p == v) continue;
            lvl[v] = lvl[u] + 1;
            build_lca(v, u);
            sz[u] += sz[v];
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

// https://codeforces.com/problemset/problem/519/E