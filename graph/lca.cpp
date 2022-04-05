const int logn = 20;
vector<int> lvl(n);
vector<vector<int>> anc(n, vector<int>(logn));
auto dfs = [&](auto &dfs, int u, int p) -> void {
    anc[u][0] = p;
    for(int j = 1; j < logn; j++) {
        anc[u][j] = anc[anc[u][j - 1]][j - 1];
    }

    for(int v : adj[u]) {
        if(p == v) continue;
        lvl[v] = lvl[u] + 1;
        dfs(dfs, v, u);
    }
};

auto lca = [&](int a, int b) {
    if(lvl[a] < lvl[b]) swap(a, b);

    int dif = lvl[a] - lvl[b];
    for(int i = logn - 1; i >= 0; i--) {
        if((1 << i) <= dif) {
            a = anc[a][i];
            dif -= (1 << i);
        }
    }
    if(a == b) return a;
    for(int i = logn - 1; i >= 0; i--) {
        if(anc[a][i] != anc[b][i]) {
            a = anc[a][i];
            b = anc[b][i];
        }
    }
    return anc[a][0];
};
dfs(dfs, 0, 0);