// const int mod = sqrt(numeric_limits<int>::max()) - 7;
const int mod = 1e18 + 7;
auto dijkstra = [](auto &g, int s) {
    const int oo = 1e18, n = g.size();
    vi d(n, oo), cnt(n, 0), mn(n, 0), mx(n, 0);

    cnt[s] = 1;
    set<pair<int, int>> q = {mp(d[s] = 0, s)};
    while(sz(q)) {
        auto [du, u] = *q.begin();
        q.erase(q.begin());
        for(auto &[v, w, id]: g[u]) {
            if(du + w == d[v]) {
                cnt[v] += cnt[u];
                if(cnt[v] >= mod) cnt[v] -= mod;
                ckmin(mn[v], mn[u] + 1);
                ckmax(mx[v], mx[u] + 1);
            }
            if(du + w < d[v]) {
                q.erase({d[v], v});
                mn[v] = mn[u] + 1;
                mx[v] = mx[u] + 1;
                cnt[v] = cnt[u];
                q.insert({d[v] = du + w, v});
            }
        }
    }
    return mp(d, p);
};


auto [d, p] = dijkstra(adj, s);

auto get_path = [&](int t) {
    vi path;
    while(t != -1) {
        path.pb(t);
        t = p[t];
    }
    reverse(all(path));
    return path;
};

auto path = get_path(t);
