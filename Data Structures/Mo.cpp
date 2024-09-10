
const int block_size = 450;
struct mo_t {
    vector<int> v;
    vector<int> f;

    mo_t(vector<int> &v_) {
        v = v_;
        int U = compress(v);
        f.assign(U + 1, 0ll);
    }

    int diffs = 0;
    void remove(int id) { // remove value at id from data structure
        int x = v[id];
        f[x]--;
        if(!f[x]) diffs--;
    } 
    void add(int id) { // add value at id from data structure
        int x = v[id];
        f[x]++;
        if(f[x] == 1) diffs++;
    } 
    int get_answer(){ //  extract the current answer of the data structure
        return diffs;
    }

    struct Query {
        int l, r, idx;
        bool operator < (Query other) {
            return make_pair(l / block_size, r) < make_pair(other.l / block_size, other.r);
        }
    };
    
    vector<Query> queries;
    void add_query(int l_, int r_, int id_) {
        queries.emplace_back(l_, r_, id_);
    }

    vector<int> execute() {
        vector<int> answers(queries.size());
        sort(queries.begin(), queries.end());

        int cur_l = 0;
        int cur_r = -1;
        // invariant: data structure will always reflect the range [cur_l, cur_r]
        for (Query q : queries) {
            while (cur_l > q.l) {
                cur_l--;
                add(cur_l);
            }
            while (cur_r < q.r) {
                cur_r++;
                add(cur_r);
            }
            while (cur_l < q.l) {
                remove(cur_l);
                cur_l++;
            }
            while (cur_r > q.r) {
                remove(cur_r);
                cur_r--;
            }
            answers[q.idx] = get_answer();
        }
        return answers;
    }
};