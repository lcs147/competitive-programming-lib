
template <size_t n>
struct pst {
    struct node {
        int sum = 0;
        node *l = nullptr, *r = nullptr;
        node(int sum_): sum(sum_) {}
        node(node *l_, node *r_): l(l_), r(r_) {
            sum = l->sum + r->sum;
        }
    };

    vector<node*> roots;
    pst(const vector<int> &a) {
        roots = {build(a)};
    }
    int new_copy(int t) {
        roots.emplace_back(roots[t]);
        return cur_time() - 1;
    }

    node *build(const vector<int> &a, int l = 0, int r = n - 1) {
        if(l == r) {
            if(l >= a.size()) return new node(0);
            return new node(a[l]);
        }
        int m = (l + r) / 2; 
        auto lc = build(a, l, m);
        auto rc = build(a, m + 1, r);
        return new node(lc, rc);
    }
    int query(int i, int j, node *no, int l = 0, int r = n - 1) {
        if(r < i || l > j || l > r) return 0ll;
        if(i <= l && r <= j) return no->sum;
        int m = (l + r) / 2;
        int lc = query(i, j, no->l, l, m);
        int rc = query(i, j, no->r, m + 1, r);
        return lc + rc;
    }
    node* update(int id, int val, node *no, int l = 0, int r = n - 1) {
        if(id > r || id < l) return no;
        if(l == r) return new node(val);

        int m = (l + r) / 2; 
        auto lc = update(id, val, no->l, l, m);
        auto rc = update(id, val, no->r, m + 1, r);
        return new node(lc, rc);
    }

    int query_range(int time, int l, int r) {
        return query(l, r, roots[time]);
    }
    int update_item(int prev_time, int id, int v) {
        // Updates the array item at a given index and time
        roots.emplace_back(update(id, v, roots[prev_time]));
        return cur_time() - 1;
    }
    int cur_time() {
        return roots.size();
    }
};