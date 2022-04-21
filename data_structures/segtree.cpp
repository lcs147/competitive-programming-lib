
template <typename T>
struct segtree {
    struct node {
        int sum = 0;
        int lazy = 0;
        void apply(T v, int l, int r) {
            sum = v * (r - l + 1);
            lazy = v;
        }
        node operator + (const node other) {
            node e;
            e.sum = sum + other.sum;
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
 
    vector<node> t;
    int n;
    segtree(int n) : n(n), t(2 * n) {}
    
    segtree(vector<int> &v) : n(v.size()), t(2 * n) {
        build(0, 0, n - 1, v);
    };
 
    void update(int l, int r, int v) {
        update(0, 0, n - 1, l, r, v);
    }
 
    node query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};