struct segtree {
    struct node {
        int mx = -oo;
        void apply(T v, int l, int r) {
            if(mx == -oo) mx = v;
            else mx = max(mx, v);
        }
        node operator + (const node other) {
            node e;
            e.mx = max(mx, other.mx);
            return e;
        }
    };
 
    // carefull when using lc and rc outside the struct scope =)
    #define lc (n + 1)
    #define rc (n + (m - l + 1) * 2)
    void push(int n, int l, int r) {
    }
 
    void build(int n, int l, int r, vector<T> &v) {
        if (l == r) {
            t[n].apply(v[l], l, r);
            return;
        }
        int m = (l + r) / 2;
        build(lc, l, m, v);
        build(rc, m + 1, r, v);
        t[n] = t[lc] + t[rc];
    }
 
    void update(int n, int l, int r, int i, int j, T v) {
        push(n, l, r);
        if (l > j || r < i || l > r) return;
        if (i <= l && r <= j) {
            t[n].apply(v, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(lc, l, m, i, j, v);
        update(rc, m + 1, r, i, j, v);
        t[n] = t[lc] + t[rc];
    }
 
    node query(int n, int l, int r, int i, int j) {
        push(n, l, r);
        if (r < i || l > j || l > r) return node();
        if (i <= l && r <= j) return t[n];
        int m = (l + r) / 2;
        return query(lc, l, m, i, j) + query(rc, m + 1, r, i, j);
    }

    // not tested
    int get_first(int n, int l, int r, int i, int j, int x) {
        push(n, l, r);
        if(l > j || r < i || t[n].mx <= x) return -1;
        if(l == r) return l;
        int m = (l + r) / 2;
        int rs = get_first(lc, l, m, i, j, x);
        if(rs != -1) return rs;
        return get_first(rc, m + 1, r, i ,j, x);
    }
    int get_last(int n, int l, int r, int i, int j, int x) {
        push(n, l, r);
        if(l > j || r < i || t[n].mx <= x) return -1;
        if(l == r) return l;
        int m = (l + r) / 2;
        int rs = get_last(rc, m + 1, r, i ,j, x);
        if(rs != -1) return rs;
        return get_last(lc, l, m, i, j, x);
    }
 
    vector<node> t;
    int n;
    segtree(int n) : n(n) {
        t.resize(2 * n);
    };
    
    segtree(vector<int> &v) : n(v.size()) {
        t.resize(2 * n);
        build(0, 0, n - 1, v);
    };
 
    void update(int l, int r, int v) {
        update(0, 0, n - 1, l, r, v);
    }
 
    node query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    int get_last(int l, int r, int x) {
        if(l > r) return -1;
        return get_last(0, 0, n - 1, l, r, x);
    }
    int get_first(int l, int r, int x) {
        if(l > r) return -1;
        return get_first(0, 0, n - 1, l, r, x);
    }
};