struct HopcroftKarp {
    static const int oo = 1e9;
    int n;
    vector<int> l, r, d;
    vector<vector<int>> g;
    HopcroftKarp(int _n, int _m) {
        n = _n;
        int p = _n + _m + 1;
        g.resize(p);
        l.resize(p, -1);
        r.resize(p, -1);
        d.resize(p, 0);
    }
    void add_edge(int u, int v) {
        g[u].push_back(v + n); //right id is increased by n, so is l[u]
    }
    bool bfs() {
        queue<int> q;
        for (int u = 1; u <= n; u++) {
            if (l[u] == -1) d[u] = 0, q.push(u);
            else d[u] = oo;
        }
        d[0] = oo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : g[u]) {
                if (d[r[v]] == oo) {
                    d[r[v]] = d[u] + 1;
                    q.push(r[v]);
                }
            }
        }
        return d[0] != oo;
    }
    bool dfs(int u) {
        if (u == -1) return true;
        for (auto v : g[u]) {
            if(d[r[v]] == d[u] + 1 && dfs(r[v])) {
                l[u] = v;
                r[v] = u;
                return true;
            }
        }
        d[u] = oo;
        return false;
    }
    int maximum_matching() {
        int ans = 0;
        while (bfs()) {
            for(int u = 1; u <= n; u++) if (!l[u] && dfs(u)) ans++;
        }
        return ans;
    }
};