
template <typename T, class F = function<T(const T &, const T &)>>
struct SparseTable {
    int n, max_log;
    vector<vector<T>> mat;
    F merge;

    SparseTable(const vector<T> &a, const F &f) : merge(f) {
        n = a.size();
        max_log = 32 - __builtin_clz(n);

        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                mat[j][i] = merge(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int from, int to) {
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return merge(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};