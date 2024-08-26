
const int oo = 1e18;
template <typename T>
struct segtree {
    struct node {
        int sum = 0, mn = oo, mx = -oo;
        int lazy = 0;
        void set(T v) {
			sum = mn = mx = v;
        }
        void apply(T v, int l, int r) {
            sum = v * (r - l + 1);
			mn = mx = v;
            lazy = v;
        }
        node operator + (const node other) {
            node e;
			e.sum = sum + other.sum;
			e.mn = min(mn, other.mn);
			e.mx = max(mx, other.mx);
            return e;
        }
    };
 
    // carefull when using lc and rc outside the struct scope =)
    #define lc (n + 1)
    #define rc (n + (m - l + 1) * 2)
    void push(int n, int l, int r) {
        if (t[n].lazy == 0) return;
        if (l != r) {
            int m = (l + r) / 2;
            t[lc].apply(t[n].lazy, l, m);
            t[rc].apply(t[n].lazy, m + 1, r);
        }
        t[n].lazy = 0;
    }
 
    void build(int n, int l, int r, const vector<T> &v) {
        if (l == r) {
            t[n].set(v[l]);
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

    int get_first(int n, int l, int r, int i, int j, int x) {
        push(n, l, r);
        if(l > j || r < i || t[n].mn >= x) return -1;
        if(l == r) return l;
        int m = (l + r) / 2;
        int rs = get_first(lc, l, m, i, j, x);
        if(rs != -1) return rs;
        return get_first(rc, m + 1, r, i, j, x);
    }

    int get_last(int n, int l, int r, int i, int j, int x) {
        push(n, l, r);
        if(l > j || r < i || t[n].mn >= x) return -1;
        if(l == r) return l;
        int m = (l + r) / 2;
        int rs = get_last(rc, m + 1, r, i, j, x);
        if(rs != -1) return rs;
        return get_last(lc, l, m, i, j, x);
    }
 
    vector<node> t;
    int n;
    segtree(int n) : n(n) {
        t.resize(2 * n);
    };
    
    segtree(const vector<int> &v) : n(v.size()) {
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