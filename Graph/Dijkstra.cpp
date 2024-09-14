int n, m; cin >> n >> m;

vector<vector<pii>> adj(n);
while(m--) {
    int a, b, w; cin >> a >> b >> w;
    a--; b--;
    adj[a].pb(b, w);
}

const int oo = 1e18;
auto dijkstra = [&](int s) {
    vi d(n, oo), p(n, -1);
    set<pii> q = {mp(d[s] = 0, s)};
    while(sz(q)) {
        auto [du, u] = *q.begin();
        q.erase(q.begin());
        for(auto &[v, w]: adj[u]) {
            if(du + w < d[v]) {
                q.erase({d[v], v});
                p[v] = u;
                q.insert({d[v] = du + w, v});
            }
        }
    }
    return mp(d, p);
};


auto [d, p] = dijkstra(s);

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