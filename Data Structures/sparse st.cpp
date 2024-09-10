
const int oo = 1e18;
template <typename T>
struct segtree {
    struct node {
        int mx = 0;
        int lazy = 0;
        node *l = nullptr, *r = nullptr;
        void apply(T v, int l_, int r_) {
            if(l == nullptr) l = new node();
            if(r == nullptr) r = new node();

            mx += v;
            lazy += v;
        }
        node(node *l_, node *r_): l(l_), r(r_) {
            mx = l->mx + r->mx;
        }
    };
 
    // carefull when using lc and rc outside the struct scope =)
    #define lc t[n].l;
    #define rc t[n].r
    void push(int n, int l, int r) {
        if (t[n].lazy == 0) return;
        if (l != r) {
            int m = (l + r) / 2;
            t[n].l->apply(t[n].lazy, l, m);
            t[n].r->apply(t[n].lazy, m + 1, r);
        }
        t[n].lazy = 0;
    }
 
    node* update(node *no, int l, int r, int i, int j, T v) {
        if (l > j || r < i || l > r) return nullptr;
        push(n, l, r);
        if (i <= l && r <= j) {
            t[n].apply(v, l, r);
            return t[n];
        }
        int m = (l + r) / 2;
        auto lc = update(no->l, l, m, i, j, v);
        auto rc = update(no->r, m + 1, r, i, j, v);
        return = lc + rc;
    }
 
    int query(node *no, int l, int r, int i, int j) {
        push(n, l, r);
        if (r < i || l > j || l > r) return 0;
        if (i <= l && r <= j) return no->sum;
        int m = (l + r) / 2;
        return max(query(lc, l, m, i, j), query(rc, m + 1, r, i, j));
    }
 
    vector<node> t;
    int n;
    segtree(int n) : n(n) {
        t.resize(2 * n);
    };
    
    segtree(const vector<T> &v) : n(v.size()) {
        t.resize(2 * n);
        build(0, 0, n - 1, v);
    };
 
    void update(int l, int r, int v) {
        update(0, 0, n - 1, l, r, v);
    }
 
    node query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};