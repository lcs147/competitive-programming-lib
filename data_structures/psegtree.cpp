// point update, range query
struct psegtree {
    struct node {
        int sum = 0;
        node operator + (node other) {
            node e;
            e.sum = sum + other.sum;
            return e;
        }
    };

    vector<node> t;
    int n;
    psegtree(int n): n(n) {
        t.assign(2 * n, node());
    }
    void update(int p, node v) {
        for(t[p += n] = v; p /= 2; )
            t[p] = t[p * 2] + t[p * 2 + 1];
    }
    void add(int p, node v) {
        p += n;
        t[p] = t[p] + v;
        while(p /= 2) t[p] = t[p * 2] + t[p * 2 + 1];
    }
    node query(int l, int r) {
        node cl, cr;
        for(l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if(l & 1) cl = cl + t[l++];
            if(r & 1) cr = t[--r] + cr;
        }
        return cl + cr;
    }
};