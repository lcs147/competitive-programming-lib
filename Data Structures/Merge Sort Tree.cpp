// not tested not finished not working

template <typename T>
struct mst {
    struct node {
        ordered_set<pair<T, int>> a;
        void set(T v, int id) {
            a.clear();
            a.insert({v, id});
        }
        // not tested
        // void update(int id, T old, T nw) {
        //     a.erase({old, id});
        //     a.insert({nw, id});
        // }
        node operator + (const node other) {
            node e;
            e.a = a;
            for(auto &x: other.a) e.a.insert(x);
            return e;
        }
        int query() {
            return a.size();
        }
    };
 
    // carefull when using lc and rc outside the struct scope =)
    #define lc (n + 1)
    #define rc (n + (m - l + 1) * 2)
 
    void build(int n, int l, int r, vector<T> &v) {
        if (l == r) {
            t[n].set(v[l], l);
            return;
        }
        int m = (l + r) / 2;
        build(lc, l, m, v);
        build(rc, m + 1, r, v);
        t[n] = t[lc] + t[rc];
    }
 
    void update(int n, int l, int r, int id, T old, T nw) {
        if (l > id || r < id) return;
        if (l == r) {
            t[n].update(nw, old, id);
            return;
        }
        int m = (l + r) / 2;
        update(lc, l, m, id, old, nw);
        update(rc, m + 1, r, id, old, nw);
        t[n].update(nw, old, id);
    }

    int query(int n, int l, int r, int i, int j) {
        if (r < i || l > j || l > r) return 0ll;
        if (i <= l && r <= j) return t[n].query();
        int m = (l + r) / 2;
        return query(lc, l, m, i, j) + query(rc, m + 1, r, i, j);
    }

    vector<node> t;
    int n;
    mst(int n) : n(n) {
        t.resize(2 * n);
    };
    
    mst(vector<int> &v) : n(v.size()) {
        t.resize(2 * n);
        build(0, 0, n - 1, v);
    };
 
    void update(int id, int old, int nw) {
        update(0, 0, n - 1, id, old, nw);
    }
 
    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};