
struct small_to_large {
    vector<vector<int>> adj;
    vector<int> c;
    int n;
 
    small_to_large(int n) : n(n) {
        adj.resize(n);
        c.resize(n);
        f.resize(n);
        s.resize(n);
        q.resize(n);
    }
    
    void add(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<map<int, int>> f;
    vector<o_set<pair<int, int>>> s;
    vector<vector<pair<int, int>>> q;
    int t = 0;
    void merge(int a, int b) {
        if(f[a].size() < f[b].size()) {
            swap(f[a], f[b]);
            s[a].swap(s[b]);
        }
 
        for(auto [x, freq] : f[b]) {
            auto it = s[a].lower_bound({f[a][x], 0});
            if(it != s[a].end() && it->first == f[a][x]) {
                s[a].erase(it);
            }
            
            f[a][x] += freq;
            s[a].insert({f[a][x], t++});
        }
    }
 
    void dfs(int u, int p) {
        f[u][c[u]] = 1;
        s[u].insert({f[u][c[u]], t++});
        
        for(int v : adj[u]) {
            if(v == p) continue;
            dfs(v, u);
            merge(u, v);
        }
 
        sort(q[u].begin(), q[u].end());
        for(auto [x, id] : q[u]) {
            res[id] = s[u].size() - s[u].order_of_key({x, 0});
        }
    }
};