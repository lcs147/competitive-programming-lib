struct dsu {
    vector<int> p;
    int n;
    dsu(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    void join(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        p[x] = y;
    }
    bool same(int a, int b) {
        a = find(a); b = find(b);
        return a == b;
    }
};